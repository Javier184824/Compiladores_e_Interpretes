#ifndef TYPEDEF_SUPPORT_H
#define TYPEDEF_SUPPORT_H

typedef struct NameList {
    const char *name;
    struct NameList *next;
} NameList;

typedef union ParserValue {
    const char *text;
    int is_typedef;
    NameList *names;
} ParserValue;

/* Valor que el scanner entrega al parser. */
extern ParserValue yylval;

/* Guarda una copia del texto hasta terminar el análisis. */
const char *save_identifier(const char *text);

/* Consulta de nombres definidos mediante typedef. */
int is_typedef_name(const char *name);

/* Construcción de listas de declaradores. */
NameList *make_name_list(const char *name);
NameList *join_name_lists(NameList *first, NameList *second);
void free_name_list(NameList *list);

/* Registra los nombres si la declaración contiene typedef. */
void finish_declaration(int is_typedef, NameList *names);

/* Libera la memoria al finalizar. */
void free_typedef_support(void);

#endif