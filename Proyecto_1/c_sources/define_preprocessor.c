/*
 * define_preprocessor.c
 *
 * A minimal C preprocessor that resolves *simple* #define directives,
 * i.e. plain name -> value substitutions:
 *
 *     #define PI 3.14159
 *     #define GREETING "hello"
 *     #define DEBUG          (no value -> expands to nothing, acts as a flag)
 *
 * Every occurrence of the defined name elsewhere in the file is
 * replaced by its value, and the #define line itself is removed from
 * the output (same as a real preprocessor).
 *
 * Function-like macros, e.g. #define SQUARE(x) ((x)*(x)), are NOT
 * supported. If one is found, its #define line is left untouched in
 * the output (with a warning on stderr) instead of being processed.
 *
 * #undef NAME is also supported, to remove a previous definition.
 *
 * To behave sensibly, substitution:
 *   - only replaces whole identifiers/tokens, never part of a bigger
 *     identifier (e.g. #define MAX 100 will NOT touch "MAX_SIZE")
 *   - is skipped inside "string literals", 'char literals', and
 *     // line comments / block comments, just like a real
 *     preprocessor would skip them there
 *   - is definition-order sensitive: a name only gets substituted in
 *     the text that comes AFTER its #define (matching real C
 *     semantics), and a #define's value is itself expanded against
 *     whatever is already defined at that point, so simple chains
 *     work:
 *         #define A 5
 *         #define B A      -> B expands to 5
 *
 * Usage:
 *   ./define_preprocessor <input_file> [-o output_file]
 *
 * Not supported (by design, since only "simple" #define was asked for):
 *   - function-like macros (#define NAME(args) ...)
 *   - multi-line macros using backslash-newline continuation
 *   - #ifdef / #ifndef / #if / #else / #endif conditional compilation
 */

#define _POSIX_C_SOURCE 200809L  /* for strdup() under strict C99 */

#include "define_preprocessor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ---- growable string buffer ------------------------------------------ */

void sb_init(StrBuf *sb) {
    sb->cap = 4096;
    sb->len = 0;
    sb->data = malloc(sb->cap);
    sb->data[0] = '\0';
}

void sb_ensure(StrBuf *sb, size_t extra) {
    if (sb->len + extra + 1 > sb->cap) {
        while (sb->len + extra + 1 > sb->cap) sb->cap *= 2;
        sb->data = realloc(sb->data, sb->cap);
    }
}

void sb_append_n(StrBuf *sb, const char *s, size_t n) {
    sb_ensure(sb, n);
    memcpy(sb->data + sb->len, s, n);
    sb->len += n;
    sb->data[sb->len] = '\0';
}

void sb_append(StrBuf *sb, const char *s) {
    sb_append_n(sb, s, strlen(s));
}

void sb_append_char(StrBuf *sb, char c) {
    sb_append_n(sb, &c, 1);
}

void sb_free(StrBuf *sb) {
    free(sb->data);
    sb->data = NULL;
    sb->len = sb->cap = 0;
}

/* ---- define table ----------------------------------------------------- */

void dt_init(DefineTable *dt) {
    dt->cap = 32;
    dt->count = 0;
    dt->items = malloc(dt->cap * sizeof(Define));
}

int dt_find(DefineTable *dt, const char *name) {
    for (size_t i = 0; i < dt->count; i++) {
        if (strcmp(dt->items[i].name, name) == 0) return (int)i;
    }
    return -1;
}

/* Add or overwrite a definition (redefinition is allowed, like cpp -- a
 * warning is printed if the new value differs from the old one). */
void dt_set(DefineTable *dt, const char *name, const char *value) {
    int idx = dt_find(dt, name);
    if (idx >= 0) {
        if (strcmp(dt->items[idx].value, value) != 0) {
            fprintf(stderr, "warning: '%s' redefined (was \"%s\", now \"%s\")\n",
                    name, dt->items[idx].value, value);
        }
        free(dt->items[idx].value);
        dt->items[idx].value = strdup(value);
        return;
    }
    if (dt->count >= dt->cap) {
        dt->cap *= 2;
        dt->items = realloc(dt->items, dt->cap * sizeof(Define));
    }
    dt->items[dt->count].name = strdup(name);
    dt->items[dt->count].value = strdup(value);
    dt->count++;
}

void dt_undef(DefineTable *dt, const char *name) {
    int idx = dt_find(dt, name);
    if (idx < 0) return; /* undef of something not defined: silently ignore, like cpp allows */
    free(dt->items[idx].name);
    free(dt->items[idx].value);
    /* swap-remove */
    dt->items[idx] = dt->items[dt->count - 1];
    dt->count--;
}

void dt_free(DefineTable *dt) {
    for (size_t i = 0; i < dt->count; i++) {
        free(dt->items[i].name);
        free(dt->items[i].value);
    }
    free(dt->items);
}

/* ---- token/text helpers ----------------------------------------------- */

int is_ident_start(char c) { return isalpha((unsigned char)c) || c == '_'; }
int is_ident_char(char c)  { return isalnum((unsigned char)c) || c == '_'; }

/*
 * Scan a span of plain text [text, text+len) and append it to `out`,
 * replacing any whole identifier that matches an entry in `dt` with
 * its value. String literals, char literals, line comments and block
 * comments within the span are copied through verbatim, with no
 * substitution performed inside them (matching how a real
 * preprocessor treats them).
 *
 * `in_block_comment` is an in/out flag so block comments can be
 * tracked across multiple calls (i.e. across lines) by the caller.
 */
void append_expanded(StrBuf *out, const char *text, size_t len,
                             DefineTable *dt, int *in_block_comment) {
    size_t i = 0;
    while (i < len) {
        if (*in_block_comment) {
            /* copy verbatim until we find the closing comment marker */
            if (i + 1 < len && text[i] == '*' && text[i + 1] == '/') {
                sb_append_n(out, text + i, 2);
                i += 2;
                *in_block_comment = 0;
            } else {
                sb_append_char(out, text[i]);
                i++;
            }
            continue;
        }

        char c = text[i];

        /* line comment: copy rest of span verbatim */
        if (c == '/' && i + 1 < len && text[i + 1] == '/') {
            sb_append_n(out, text + i, len - i);
            break;
        }

        /* block comment start */
        if (c == '/' && i + 1 < len && text[i + 1] == '*') {
            sb_append_n(out, text + i, 2);
            i += 2;
            *in_block_comment = 1;
            continue;
        }

        /* string literal: copy verbatim until closing quote (honor \") */
        if (c == '"') {
            sb_append_char(out, c);
            i++;
            while (i < len) {
                sb_append_char(out, text[i]);
                if (text[i] == '\\' && i + 1 < len) {
                    i++;
                    sb_append_char(out, text[i]);
                    i++;
                    continue;
                }
                if (text[i] == '"') { i++; break; }
                i++;
            }
            continue;
        }

        /* char literal: same idea */
        if (c == '\'') {
            sb_append_char(out, c);
            i++;
            while (i < len) {
                sb_append_char(out, text[i]);
                if (text[i] == '\\' && i + 1 < len) {
                    i++;
                    sb_append_char(out, text[i]);
                    i++;
                    continue;
                }
                if (text[i] == '\'') { i++; break; }
                i++;
            }
            continue;
        }

        /* identifier: candidate for macro substitution */
        if (is_ident_start(c)) {
            size_t start = i;
            i++;
            while (i < len && is_ident_char(text[i])) i++;
            size_t idlen = i - start;

            char name[256];
            if (idlen < sizeof(name)) {
                memcpy(name, text + start, idlen);
                name[idlen] = '\0';
                int idx = dt_find(dt, name);
                if (idx >= 0) {
                    sb_append(out, dt->items[idx].value);
                    continue;
                }
            }
            /* not a known macro (or name too long): copy as-is */
            sb_append_n(out, text + start, idlen);
            continue;
        }

        /* anything else: copy through */
        sb_append_char(out, c);
        i++;
    }
}

/* Trim leading/trailing whitespace of a NUL-terminated string in place,
 * returning a pointer to the (possibly shifted) start. */
char *trim(char *s) {
    while (isspace((unsigned char)*s)) s++;
    if (*s == '\0') return s;
    char *end = s + strlen(s) - 1;
    while (end > s && isspace((unsigned char)*end)) *end-- = '\0';
    return s;
}

/*
 * Try to parse `line` (a single physical line, no trailing newline) as
 * a #define or #undef directive.
 *
 * Returns:
 *   1  -> it was a supported directive, already applied to `dt`
 *   0  -> not a directive at all (ordinary line)
 *  -1  -> it *was* a #define, but for a function-like macro, which
 *         this tool does not support; caller should leave the line
 *         untouched in the output instead of consuming it.
 */
int handle_directive_line(const char *line, DefineTable *dt) {
    const char *p = line;
    while (isspace((unsigned char)*p)) p++;
    if (*p != '#') return 0;
    p++;
    while (isspace((unsigned char)*p)) p++;

    if (strncmp(p, "define", 6) == 0 && (isspace((unsigned char)p[6]))) {
        p += 6;
        while (isspace((unsigned char)*p)) p++;

        if (!is_ident_start(*p)) return 0; /* malformed, treat as ordinary line */
        const char *name_start = p;
        while (is_ident_char(*p)) p++;
        size_t name_len = (size_t)(p - name_start);

        if (*p == '(') {
            /* function-like macro -- not supported */
            return -1;
        }

        char name[256];
        if (name_len >= sizeof(name)) return 0;
        memcpy(name, name_start, name_len);
        name[name_len] = '\0';

        while (*p == ' ' || *p == '\t') p++;
        char valbuf[4096];
        strncpy(valbuf, p, sizeof(valbuf) - 1);
        valbuf[sizeof(valbuf) - 1] = '\0';
        char *value = trim(valbuf); /* may be "" for a flag-style define */

        /* expand any already-known macros used inside the new value,
         * so simple chains (#define B A) resolve at definition time */
        StrBuf expanded;
        sb_init(&expanded);
        int dummy_comment_state = 0;
        append_expanded(&expanded, value, strlen(value), dt, &dummy_comment_state);

        dt_set(dt, name, expanded.data);
        sb_free(&expanded);
        return 1;
    }

    if (strncmp(p, "undef", 5) == 0 && (isspace((unsigned char)p[5]))) {
        p += 5;
        while (isspace((unsigned char)*p)) p++;
        if (!is_ident_start(*p)) return 0;
        const char *name_start = p;
        while (is_ident_char(*p)) p++;
        size_t name_len = (size_t)(p - name_start);
        char name[256];
        if (name_len >= sizeof(name)) return 0;
        memcpy(name, name_start, name_len);
        name[name_len] = '\0';
        dt_undef(dt, name);
        return 1;
    }

    /* Some other preprocessor directive this tool doesn't understand
     * (#ifdef, #ifndef, #if, #elif, #else, #endif, #include, #pragma,
     * #error, ...). Leave it completely untouched -- in particular,
     * do NOT macro-expand its contents (e.g. the name after #ifdef
     * must stay literal, not be replaced by its #define value). */
    if (is_ident_start(*p)) return -1;

    return 0;
}

/* ---- main driver -------------------------------------------------------- */

char *read_whole_file(const char *path, size_t *out_len) {
    FILE *f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "error: could not open '%s'\n", path);
        exit(EXIT_FAILURE);
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (size < 0) {
        fclose(f);
        fprintf(stderr, "error: could not read '%s'\n", path);
        exit(EXIT_FAILURE);
    }
    char *buf = malloc((size_t)size + 1);
    size_t n = fread(buf, 1, (size_t)size, f);
    buf[n] = '\0';
    fclose(f);
    if (out_len) *out_len = n;
    return buf;
}

void process(const char *content, size_t len, StrBuf *out) {
    DefineTable dt;
    dt_init(&dt);
    int in_block_comment = 0;

    size_t i = 0;
    while (i < len) {
        /* find extent of this physical line */
        size_t line_start = i;
        while (i < len && content[i] != '\n') i++;
        size_t line_end = i; /* exclusive, points at '\n' or len */
        int has_newline = (i < len);
        if (has_newline) i++; /* consume '\n' */

        size_t line_len = line_end - line_start;

        if (!in_block_comment) {
            /* copy into a small NUL-terminated buffer to test for a directive */
            char linebuf[4096];
            size_t copy_len = line_len < sizeof(linebuf) - 1 ? line_len : sizeof(linebuf) - 1;
            memcpy(linebuf, content + line_start, copy_len);
            linebuf[copy_len] = '\0';

            DefineTable *dtp = &dt;
            int directive = handle_directive_line(linebuf, dtp);
            if (directive == 1) {
                /* consumed: emit nothing for this line (just the newline,
                 * to keep line numbers stable in the output) */
                if (has_newline) sb_append_char(out, '\n');
                continue;
            } else if (directive == -1) {
                fprintf(stderr,
                        "note: directive not processed, leaving line as-is: %s\n",
                        trim(linebuf));
                sb_append_n(out, content + line_start, line_len);
                if (has_newline) sb_append_char(out, '\n');
                continue;
            }
        }

        /* ordinary line (or continuation of a block comment): expand macros */
        append_expanded(out, content + line_start, line_len, &dt, &in_block_comment);
        if (has_newline) sb_append_char(out, '\n');
    }

    dt_free(&dt);
}

void usage(const char *prog) {
    fprintf(stderr, "usage: %s <input_file> [-o output_file]\n", prog);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = NULL;
    const char *output_file = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return EXIT_FAILURE; }
            output_file = argv[++i];
        } else if (!input_file) {
            input_file = argv[i];
        } else {
            usage(argv[0]);
            return EXIT_FAILURE;
        }
    }

    if (!input_file) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    size_t len;
    char *content = read_whole_file(input_file, &len);

    StrBuf out;
    sb_init(&out);
    process(content, len, &out);

    FILE *f = stdout;
    if (output_file) {
        f = fopen(output_file, "w");
        if (!f) {
            fprintf(stderr, "error: could not open output file '%s'\n", output_file);
            return EXIT_FAILURE;
        }
    }
    fwrite(out.data, 1, out.len, f);
    if (f != stdout) fclose(f);

    sb_free(&out);
    free(content);
    return EXIT_SUCCESS;
}