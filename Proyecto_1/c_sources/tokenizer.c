#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../headers/tokenizer.h"
#include "../headers/define_preprocessor.h"
#include "../headers/include_preprocessor.h"

int remove_comments(const char* source_file_path, const char *output_file_path) {
    char current_char = ' ';
    FILE *source_fptr = fopen(source_file_path, "r");
    FILE *output_fptr = fopen(output_file_path, "w");
    if (source_fptr == NULL || output_fptr == NULL) {
        return 0;
    }
    if (feof(source_fptr)) {
        return 0;
    }
    while ((current_char = fgetc(source_fptr)) != EOF) {
        if (current_char == '/') {
            current_char = fgetc(source_fptr);
            if (current_char == '/') {
                do {
                    current_char = fgetc(source_fptr);
                } 
                while (current_char != '\n' && current_char != EOF);
            }
            else if (current_char == '*') {
                do {
                    current_char = fgetc(source_fptr);
                    if (current_char == '*') {
                        current_char = fgetc(source_fptr);
                        if (current_char == '/') {
                            break;
                        }
                    }
                }
                while (current_char != EOF);
            }
            else {
                if (current_char != EOF) {
                    ungetc(current_char, source_fptr);
                }
            }
        }
        else {
            fputc(current_char, output_fptr);
        }
    }
    fclose(source_fptr);
    fclose(output_fptr);
}

int preprocess(const char *source_file_path, const char *output_file_path) {
    remove_comments(source_file_path, "tmp/comment_removed");
    solve_defines("tmp/comment_removed", "tmp/defines_solved");
    solve_includes("tmp/defines_solved", output_file_path);

    remove("tmp/comment_removed");
    remove("tmp/defines_solved");

    return 1;
}

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

void guardar_token(int codigo, CategoriaToken categoria)
{
    token_actual.codigo = codigo;
    token_actual.categoria = categoria;

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
    token_actual.linea = yylineno;

    contador_tokens[categoria]++;
    if (categoria != ERROR) total_tokens++;
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


int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo_fuente>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Crear archivo temporal */
    char nombre_temporal[] = "tmp/preprocesadoXXXXXX";

    int fd = mkstemp(nombre_temporal);

    if (fd == -1) {
        perror("Error creando archivo temporal");
        return EXIT_FAILURE;
    }

    close(fd);

    if (!preprocess(argv[1], nombre_temporal)) {
        fprintf(stderr, "Error durante el preprocesamiento\n");
        return EXIT_FAILURE;
    }

    #if 0
    // ====== PARA PRUEBAS ======== -- lun
    // FASE 1: Preprocesamiento 
    if (!preprocess(argv[1], nombre_temporal)) {
        fprintf(stderr, "Error durante el preprocesamiento\n");
        return EXIT_FAILURE;
    }

    // FASE 2: Abrir resultado del preprocesamiento 
    FILE *archivo_preprocesado = fopen(nombre_temporal, "r");

    if (archivo_preprocesado == NULL) {
        perror("Error abriendo archivo preprocesado");
        return EXIT_FAILURE;
    }

    yyin = archivo_preprocesado;

    if (archivo_preprocesado == NULL) {
        perror("Error abriendo archivo preprocesado");
        return EXIT_FAILURE;
    }

	// ====== fin PRUEBAS ======== -- lun

    source_code = fopen("texs/source_code.tex", "w");

    if (source_code == NULL) {
        perror("Error creando source_code.tex");
        fclose(archivo_preprocesado);
        return EXIT_FAILURE;
    }

    //borrar - lun
    fprintf(source_code, "\\begin{frame}[fragile]{Código fuente}\n");
    fprintf(source_code, "\\begin{verbatim}\n");

    /* FASE 3: Obtener los tokens uno por uno */
    Token token;

    do {
        token = Get_Token();

        if (token.codigo != TOKEN_EOF) {
            
            fprintf(source_code, "%s", token.lexema);

            printf(
				"linea=%d, codigo=%d, lexema=%s",
				token.linea,
				token.codigo,
				token.lexema
			);

            if (token.codigo == TOKEN_INTEGER) {
                printf(", valor=%lld", token.valor_entero);
            }

            if (token.codigo == TOKEN_FLOAT) {
                printf(", valor=%Lf", token.valor_flotante);
            }

            printf("\n");
        }

    } while (token.codigo != TOKEN_EOF);
    
    //borrar !! -- lun
    fprintf(source_code, "\\end{verbatim}\n");
    fprintf(source_code, "\\end{frame}\n");

    printf(
        "Archivo preprocesado: %s\n",
        nombre_temporal
    );


    FILE *stats = fopen("token_stats.dat", "w");

    if (stats == NULL) {
        perror("Error creando token_stats.dat");
        return EXIT_FAILURE;
    }

    fprintf(stats, "Category Quantity\n");
    fprintf(stats, "Keyword %d\n", contador_tokens[KEYWORD]);
    fprintf(stats, "Identifier %d\n", contador_tokens[IDENTIFIER]);
    fprintf(stats, "Literal %d\n", contador_tokens[LITERAL]);
    fprintf(stats, "String %d\n", contador_tokens[STRING]);
    fprintf(stats, "Operator %d\n", contador_tokens[OPERATOR]);
    fprintf(stats, "Punctuator %d\n", contador_tokens[PUNCTUATOR]);

    fclose(stats);


    FILE *stats2 = fopen("texs/pie_chart.tex", "w");

    if (stats2 == NULL) {
        perror("Error creando pie_chart.tex");
        return EXIT_FAILURE;
    }

    fprintf(stats2, 
        "\\begin{tikzpicture}[scale=0.8]\n"
        "\t\\pie[\n"
        "\t\ttext=legend,\n" 
        "\t\tbefore number=,\n" 
        "\t\tafter number=\\%%\n"
        "\t]{\n"
    );

    if (contador_tokens[KEYWORD] > 0)
        fprintf(stats2, "\t\t%.2f/Keyword,\n", 100.0 * contador_tokens[KEYWORD] / total_tokens);

    if (contador_tokens[IDENTIFIER] > 0)
        fprintf(stats2, "\t\t%.2f/Identifier,\n", 100.0 * contador_tokens[IDENTIFIER] / total_tokens);

    if (contador_tokens[LITERAL] > 0)
        fprintf(stats2, "\t\t%.2f/Literal,\n", 100.0 * contador_tokens[LITERAL] / total_tokens);

    if (contador_tokens[STRING] > 0)
        fprintf(stats2, "\t\t%.2f/String,\n", 100.0 * contador_tokens[STRING] / total_tokens);

    if (contador_tokens[OPERATOR] > 0)
        fprintf(stats2, "\t\t%.2f/Operator,\n", 100.0 * contador_tokens[OPERATOR] / total_tokens);

    if (contador_tokens[PUNCTUATOR] > 0)
        fprintf(stats2, "\t\t%.2f/Punctuator\n", 100.0 * contador_tokens[PUNCTUATOR] / total_tokens);

    fprintf(stats2, "\t}\n");
    fprintf(stats2, "\\end{tikzpicture}\n");


    fclose(stats2);
    #endif

    return EXIT_SUCCESS;
}