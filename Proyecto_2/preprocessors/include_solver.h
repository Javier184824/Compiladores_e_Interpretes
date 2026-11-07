#ifndef INCLUDE_PREPROCESSOR_H
#define INCLUDE_PREPROCESSOR_H

#include <stddef.h>
#include <stdio.h>

/* Las cadenas devueltas por dirname_of, join_path y resolve_include_path
 * deben liberarse con free cuando no sean NULL. */
void die(const char *msg);
int file_exists(const char *path);
char *dirname_of(const char *path);
char *join_path(const char *dir, const char *file);
void strip_newline(char *line);
int parse_include_line(const char *line, char *filename, size_t fnsize);
char *resolve_include_path(const char *filename, const char *current_dir);
int already_on_stack(const char *resolved_path);
void solve_includes(const char *path, const char *output_path);
void usage(const char *prog);

#endif /* INCLUDE_PREPROCESSOR_H */
