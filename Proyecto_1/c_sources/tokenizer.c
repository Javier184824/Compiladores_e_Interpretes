#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/tokenizer.h"

void limpiar_separadores(const char *origen, char *destino)
{
    while (*origen != '\0') {
        if (*origen != '\'') {
            *destino = *origen;
            destino++;
        }

        origen++;
    }

    *destino = '\0';
}

long long convertir_entero(const char *lexema)
{
    char numero_limpio[strlen(lexema) + 1];

    limpiar_separadores(lexema, numero_limpio);

    if (numero_limpio[0] == '0' &&
        (numero_limpio[1] == 'b' || numero_limpio[1] == 'B')) {
        return strtoll(numero_limpio + 2, NULL, 2);
    }

    return strtoll(numero_limpio, NULL, 0);
}

void guardar_token(int codigo)
{
    token_actual.codigo = codigo;

    if (token_actual.lexema != NULL) {
        free(token_actual.lexema);
    }

    token_actual.lexema = malloc(strlen(yytext) + 1);

    if (token_actual.lexema == NULL) {
        fprintf(stderr, "Error reservando memoria\n");
        exit(EXIT_FAILURE);
    }

    strcpy(token_actual.lexema, yytext);

    token_actual.valor_entero = 0;
    token_actual.valor_flotante = 0.0;
}

Token Get_Token(void)
{
    int codigo = yylex();

    if (codigo == 0) {
        if (token_actual.lexema != NULL) {
            free(token_actual.lexema);
            token_actual.lexema = NULL;
        }

        token_actual.codigo = TOKEN_EOF;
        token_actual.valor_entero = 0;
        token_actual.valor_flotante = 0.0;
    }

    return token_actual;
}