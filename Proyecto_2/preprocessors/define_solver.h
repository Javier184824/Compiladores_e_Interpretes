#ifndef DEFINE_PREPROCESSOR_H
#define DEFINE_PREPROCESSOR_H

#include <stddef.h>

typedef struct {
    char *data;
    size_t len;
    size_t cap;
} StrBuf;

typedef struct {
    char *name;
    char *value; /* always fully expanded already-known-macros at store time */
} Define;

typedef struct {
    Define *items;
    size_t count;
    size_t cap;
} DefineTable;

/* Declaraciones de las funciones implementadas en define_preprocessor.c. */
void sb_init(StrBuf *sb);
void sb_ensure(StrBuf *sb, size_t extra);
void sb_append_n(StrBuf *sb, const char *s, size_t n);
void sb_append(StrBuf *sb, const char *s);
void sb_append_char(StrBuf *sb, char c);
void sb_free(StrBuf *sb);
void dt_init(DefineTable *dt);
int dt_find(DefineTable *dt, const char *name);
void dt_set(DefineTable *dt, const char *name, const char *value);
void dt_undef(DefineTable *dt, const char *name);
void dt_free(DefineTable *dt);
int is_ident_start(char c);
int is_ident_char(char c);
void append_expanded(StrBuf *out, const char *text, size_t len,
                             DefineTable *dt, int *in_block_comment);
char *trim(char *s);
int handle_directive_line(const char *line, DefineTable *dt);
char *read_whole_file(const char *path, size_t *out_len);
void process(const char *content, size_t len, StrBuf *out);
int solve_defines(const char *input_file, const char* output_file);

#endif /* DEFINE_PREPROCESSOR_H */
