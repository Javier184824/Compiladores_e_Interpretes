/*
 * include_preprocessor.c
 *
 * A minimal C preprocessor that resolves #include directives.
 * It reads a source file, and whenever it finds a line of the form:
 *
 *     #include "file.h"
 *
 * it recursively inlines the contents of that file in place of the
 * directive -- and recursively resolves #include directives found
 * inside THAT file too (i.e. includes-of-includes are handled).
 * Only quoted includes ("file.h") are treated as includes to resolve;
 * angle-bracket includes (<file.h>) are left untouched in the output.
 *
 * Usage:
 *   ./include_preprocessor <input_file> [-o output_file]
 *
 * Notes:
 *   - "file.h" includes are resolved relative to the directory of the
 *     file that contains the #include (so if a/b.h includes "c.h", it
 *     looks for a/c.h -- not the current working directory of the
 *     program).
 *   - Circular includes (A includes B includes A) are detected using
 *     an inclusion stack and reported as an error instead of recursing
 *     forever.
 *   - If an included file cannot be found, the #include line is left
 *     untouched in the output (with a warning printed to stderr)
 *     instead of aborting the whole run.
 *   - Lines are copied verbatim except for #include lines, which are
 *     replaced by the expanded contents of the included file. A marker
 *     comment is emitted around each expansion so you can see where
 *     content came from (this can be turned off, see EMIT_MARKERS).
 */

#define _POSIX_C_SOURCE 200809L  /* for strdup() under strict C99 */

#include "../headers/include_preprocessor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX_LINE        4096
#define MAX_PATH_LEN    1024
#define MAX_STACK_DEPTH  128
#define EMIT_MARKERS     1   /* 1 = print "// begin/end include" markers */

/* ---- global state -------------------------------------------------- */

/* Stack of files currently being processed (for circular-include
 * detection) - stores fully/partially resolved paths as opened. */
static char *inclusion_stack[MAX_STACK_DEPTH];
static int   inclusion_depth = 0;

/* ---- utility functions ---------------------------------------------- */

void die(const char *msg) {
    fprintf(stderr, "error: %s\n", msg);
    exit(EXIT_FAILURE);
}

int file_exists(const char *path) {
    struct stat st;
    return stat(path, &st) == 0 && S_ISREG(st.st_mode);
}

/* Return a newly-malloc'd copy of the directory part of `path`
 * (without trailing slash), or "." if there is no directory part. */
char *dirname_of(const char *path) {
    const char *slash = strrchr(path, '/');
    char *result;
    if (!slash) {
        result = malloc(2);
        strcpy(result, ".");
        return result;
    }
    size_t len = (size_t)(slash - path);
    result = malloc(len + 1);
    memcpy(result, path, len);
    result[len] = '\0';
    return result;
}

/* Join dir + "/" + file into a newly malloc'd string. */
char *join_path(const char *dir, const char *file) {
    size_t len = strlen(dir) + strlen(file) + 2;
    char *result = malloc(len);
    if (strcmp(dir, ".") == 0)
        snprintf(result, len, "%s", file);
    else
        snprintf(result, len, "%s/%s", dir, file);
    return result;
}

/* Trim trailing \r or \n from a line read via fgets. */
void strip_newline(char *line) {
    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
        line[--len] = '\0';
    }
}

/*
 * Parse a line to see if it's a quoted #include directive, i.e.
 *     #include "file.h"
 * (<angle.h> includes are intentionally not treated as includes to
 * resolve -- they are left untouched in the output, same as any other
 * line, since this preprocessor only handles "quoted" includes.)
 * Returns 1 if it is, 0 otherwise.
 * On success, fills `filename` with the name between the quotes.
 */
int parse_include_line(const char *line, char *filename, size_t fnsize) {
    const char *p = line;
    while (isspace((unsigned char)*p)) p++;
    if (*p != '#') return 0;
    p++;
    while (isspace((unsigned char)*p)) p++;
    if (strncmp(p, "include", 7) != 0) return 0;
    p += 7;
    if (!isspace((unsigned char)*p)) return 0;
    while (isspace((unsigned char)*p)) p++;

    if (*p != '"') return 0; /* not a quoted include -- leave line as-is */
    p++;
    const char *start = p;
    while (*p && *p != '"') p++;
    if (*p != '"') return 0; /* malformed, no closing quote */

    size_t len = (size_t)(p - start);
    if (len == 0 || len >= fnsize) return 0;
    memcpy(filename, start, len);
    filename[len] = '\0';
    return 1;
}

/* Resolve an #include filename to an actual path on disk, or return
 * NULL if it could not be found. `current_dir` is the directory of the
 * file that contains the #include -- this is the only place searched. */
char *resolve_include_path(const char *filename, const char *current_dir) {
    char *candidate = join_path(current_dir, filename);
    if (file_exists(candidate)) return candidate;
    free(candidate);
    return NULL;
}

int already_on_stack(const char *resolved_path) {
    for (int i = 0; i < inclusion_depth; i++) {
        if (strcmp(inclusion_stack[i], resolved_path) == 0) return 1;
    }
    return 0;
}

void process_file(const char *path, const char *output_path) {
    if (inclusion_depth >= MAX_STACK_DEPTH) {
        die("include nesting too deep (possible circular include?)");
    }
    if (already_on_stack(path)) {
        fprintf(stderr, "error: circular include detected involving '%s'\n", path);
        fprintf(stderr, "       inclusion chain:\n");
        for (int i = 0; i < inclusion_depth; i++)
            fprintf(stderr, "         -> %s\n", inclusion_stack[i]);
        fprintf(stderr, "         -> %s (repeats)\n", path);
        exit(EXIT_FAILURE);
    }

    FILE *in = fopen(path, "r");
    FILE *out = fopen(output_path, "w");
    if (!in) {
        fprintf(stderr, "error: could not open '%s': %s\n", path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (!out) {
        fprintf(stderr, "error: could not open '%s': %s\n", output_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    inclusion_stack[inclusion_depth++] = strdup(path);
    char *current_dir = dirname_of(path);

    char line[MAX_LINE];
    long lineno = 0;
    while (fgets(line, sizeof(line), in)) {
        lineno++;
        strip_newline(line);

        char filename[MAX_PATH_LEN];
        if (parse_include_line(line, filename, sizeof(filename))) {
            char *resolved = resolve_include_path(filename, current_dir);
            if (!resolved) {
                fprintf(stderr, "warning: %s:%ld: cannot find include file '%s' "
                                "-- leaving line as-is\n",
                        path, lineno, filename);
                fprintf(out, "%s\n", line);
            } else {
                process_file(resolved, output_path);  /* recursive resolution */
                free(resolved);
            }
        } else {
            fprintf(out, "%s\n", line);
        }
    }

    fclose(in);
    free(current_dir);
    free(inclusion_stack[--inclusion_depth]);
}

/* ---- main / CLI ------------------------------------------------------ */
#if 0
void usage(const char *prog) {
    fprintf(stderr,
        "usage: %s <input_file> [-o output_file]\n",
        prog);
}


int main(int argc, char **argv) {
    if (argc < 2) {
        return EXIT_FAILURE;
    }

    const char *input_file = NULL;
    const char *output_file = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 >= argc) die("-o requires an argument");
            output_file = argv[++i];
        } else if (!input_file) {
            input_file = argv[i];
        } else {
            usage(argv[0]);
            return EXIT_FAILURE;
        }
    }

    if (!input_file) {
        return EXIT_FAILURE;
    }

    FILE *out = stdout;
    if (output_file) {
        out = fopen(output_file, "w");
        if (!out) {
            fprintf(stderr, "error: could not open output file '%s'\n", output_file);
            return EXIT_FAILURE;
        }
    }

    process_file(input_file, out);

    if (out != stdout) fclose(out);
    return EXIT_SUCCESS;
}
    #endif