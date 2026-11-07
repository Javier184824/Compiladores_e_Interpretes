
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "../headers/define_preprocessor.h"
#include "../headers/include_preprocessor.h"

typedef enum {
    TOKEN_EOF = 0,

    /* Palabras reservadas de C */
    TOKEN_AUTO,
    TOKEN_BREAK,
    TOKEN_CASE,
    TOKEN_CHAR_KEYWORD,
    TOKEN_CONST,
    TOKEN_CONTINUE,
    TOKEN_DEFAULT,
    TOKEN_DO,
    TOKEN_DOUBLE_KEYWORD,
    TOKEN_ELSE,
    TOKEN_ENUM,
    TOKEN_EXTERN,
    TOKEN_FLOAT_KEYWORD,
    TOKEN_FOR,
    TOKEN_GOTO,
    TOKEN_IF,
    TOKEN_INT_KEYWORD,
    TOKEN_LONG,
    TOKEN_REGISTER,
    TOKEN_RETURN,
    TOKEN_SHORT,
    TOKEN_SIGNED,
    TOKEN_SIZEOF,
    TOKEN_STATIC,
    TOKEN_STRUCT,
    TOKEN_SWITCH,
    TOKEN_TYPEDEF,
    TOKEN_UNION,
    TOKEN_UNSIGNED,
    TOKEN_VOID,
    TOKEN_VOLATILE,
    TOKEN_WHILE,

    /* Palabras reservadas adicionales */
    TOKEN_ASM,
    TOKEN_FORTRAN,
    TOKEN_INLINE,
    TOKEN_RESTRICT,
    TOKEN_BOOL_KEYWORD,
    TOKEN_COMPLEX,
    TOKEN_IMAGINARY,
    TOKEN_ALIGNAS,
    TOKEN_ALIGNOF,
    TOKEN_ATOMIC,
    TOKEN_GENERIC,
    TOKEN_NORETURN,
    TOKEN_STATIC_ASSERT,
    TOKEN_THREAD_LOCAL,
    TOKEN_CONSTEXPR,
    TOKEN_FALSE,
    TOKEN_NULLPTR,
    TOKEN_TRUE,
    TOKEN_TYPEOF,
    TOKEN_TYPEOF_UNQUAL,
    TOKEN_BITINT,
    TOKEN_DECIMAL32,
    TOKEN_DECIMAL64,
    TOKEN_DECIMAL128,

    /* Identificadores y literales */
    TOKEN_ID,
    TOKEN_INTEGER,
    TOKEN_FLOAT,
    TOKEN_CHARACTER,
    TOKEN_STRING,

    /* Operadores */
    TOKEN_LOGICAL_AND,
    TOKEN_LOGICAL_OR,
    TOKEN_BITWISE_AND,
    TOKEN_BITWISE_OR,
    TOKEN_BITWISE_XOR,
    TOKEN_BITWISE_NOT,
    TOKEN_NOT,
    TOKEN_INCREMENT,
    TOKEN_DECREMENT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULT,
    TOKEN_DIV,
    TOKEN_MOD,
    TOKEN_EQUAL,
    TOKEN_DIFFERENT,
    TOKEN_LESS,
    TOKEN_GREATER,
    TOKEN_LESS_EQUAL,
    TOKEN_GREATER_EQUAL,
    TOKEN_ASSIGN,
    TOKEN_PLUS_ASSIGN,
    TOKEN_MINUS_ASSIGN,
    TOKEN_MULT_ASSIGN,
    TOKEN_DIV_ASSIGN,
    TOKEN_MOD_ASSIGN,
    TOKEN_AND_ASSIGN,
    TOKEN_OR_ASSIGN,
    TOKEN_XOR_ASSIGN,
    TOKEN_LEFT_SHIFT,
    TOKEN_RIGHT_SHIFT,
    TOKEN_LEFT_SHIFT_ASSIGN,
    TOKEN_RIGHT_SHIFT_ASSIGN,

    /* Puntuadores */
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_CURLY,
    TOKEN_RIGHT_CURLY,
    TOKEN_LEFT_SQUARE,
    TOKEN_RIGHT_SQUARE,
    TOKEN_ARROW,
    TOKEN_QUESTION,
    TOKEN_COLON,
    TOKEN_DOUBLE_COLON,
    TOKEN_ELLIPSIS,
    TOKEN_PERIOD,
    TOKEN_COMMA,
    TOKEN_SEMICOLON,
    TOKEN_HASH,
    TOKEN_DOUBLE_HASH,

    TOKEN_LEXICAL_ERROR
} TokenCode;

typedef enum {
    ERROR,
    KEYWORD,
    IDENTIFIER,
    LITERAL,
    STRING,
    OPERATOR,
    PUNCTUATOR
} CategoriaToken;

typedef struct {
    int codigo;
    CategoriaToken categoria;
    char *lexema;
    long long valor_entero;
    long double valor_flotante;
    int linea;
} Token;

Token token_actual;
int contador_tokens[7] = {0};
int total_tokens = 0;

FILE *source_code;

Token Get_Token(void);
void guardar_token(int codigo, CategoriaToken categoria);
void limpiar_separadores(const char *origen, char *destino);
long long convertir_entero(const char *lexema);

// para presentación

const char *nombres_categorias[] = {
    "Error",
    "Keyword",
    "Identifier",
    "Literal",
    "String",
    "Operator",
    "Punctuator"
};

bool linea_abierta = false;
void paste_in_latex(const char *texto);
void newline_latex(void);
void endline_latex(void);
void spacing(const char *texto);
void escribir_token(Token token);
%}

%option noyywrap
%option yylineno

DIGITO      [0-9]
HEXDIGITO   [0-9a-fA-F]
OCTDIGITO   [0-7]
BINDIGITO   [01]
DIGITOS_DEC     {DIGITO}([']?{DIGITO})*
DIGITOS_HEX     {HEXDIGITO}([']?{HEXDIGITO})*
DIGITOS_OCT     {OCTDIGITO}([']?{OCTDIGITO})*
DIGITOS_BIN     {BINDIGITO}([']?{BINDIGITO})*
LETRA       [a-zA-Z_]
ID          {LETRA}({LETRA}|{DIGITO})*
/* Entero */
SUFIJO_LONG     ([lL]|ll|LL)
SUFIJO_BIT      (wb|WB)
SUFIJO_ENTERO   ([uU]({SUFIJO_LONG}|{SUFIJO_BIT})?|({SUFIJO_LONG}|{SUFIJO_BIT})[uU]?)?
ENTERO          (0[xX]{DIGITOS_HEX}|0[bB]{DIGITOS_BIN}|0([']?{OCTDIGITO})*|[1-9]([']?{DIGITO})*){SUFIJO_ENTERO}
/* Flotante */
EXPONENTE_DEC       [eE][+-]?{DIGITOS_DEC}
EXPONENTE_HEX       [pP][+-]?{DIGITOS_DEC}
SUFIJO_FLOAT_DEC    (f|F|l|L|df|DF|dd|DD|dl|DL)
SUFIJO_FLOAT_HEX    [fFlL]

FLOAT_DECIMAL   (({DIGITOS_DEC}\.{DIGITOS_DEC}?|\.{DIGITOS_DEC}){EXPONENTE_DEC}?|{DIGITOS_DEC}{EXPONENTE_DEC}){SUFIJO_FLOAT_DEC}?
FLOAT_HEX       0[xX]({DIGITOS_HEX}\.{DIGITOS_HEX}?|\.{DIGITOS_HEX}|{DIGITOS_HEX}){EXPONENTE_HEX}{SUFIJO_FLOAT_HEX}?
FLOTANTE        ({FLOAT_DECIMAL}|{FLOAT_HEX})


ESCAPE_CHAR     (\\['"?\\abfnrtv]|\\{OCTDIGITO}{1,3}|\\x{HEXDIGITO}+|\\u{HEXDIGITO}{4}|\\U{HEXDIGITO}{8})
CCHAR           ([^'\\\n]|{ESCAPE_CHAR})
CHAR_SIMPLE     (u8|u|U|L)?'{CCHAR}'
CHAR_MULTIPLE   L?'{CCHAR}{CCHAR}+
CARACTER        ({CHAR_SIMPLE}|{CHAR_MULTIPLE})

ESCAPE_STRING   (\\['"?\\abfnrtv]|\\{OCTDIGITO}{1,3}|\\x{HEXDIGITO}+|\\u{HEXDIGITO}{4}|\\U{HEXDIGITO}{8})
SCHAR           ([^"\\\n]|{ESCAPE_STRING})
STRING          (u8|u|U|L)?\"{SCHAR}*\"

%%

    /* Palabras reservadas */
"auto"          { guardar_token(TOKEN_AUTO, KEYWORD); return TOKEN_AUTO; }
"break"         { guardar_token(TOKEN_BREAK, KEYWORD); return TOKEN_BREAK; }
"case"          { guardar_token(TOKEN_CASE, KEYWORD); return TOKEN_CASE; }
"char"          { guardar_token(TOKEN_CHAR_KEYWORD, KEYWORD); return TOKEN_CHAR_KEYWORD; }
"const"         { guardar_token(TOKEN_CONST, KEYWORD); return TOKEN_CONST; }
"continue"      { guardar_token(TOKEN_CONTINUE, KEYWORD); return TOKEN_CONTINUE; }
"default"       { guardar_token(TOKEN_DEFAULT, KEYWORD); return TOKEN_DEFAULT; }
"do"            { guardar_token(TOKEN_DO, KEYWORD); return TOKEN_DO; }
"double"        { guardar_token(TOKEN_DOUBLE_KEYWORD, KEYWORD); return TOKEN_DOUBLE_KEYWORD; }
"else"          { guardar_token(TOKEN_ELSE, KEYWORD); return TOKEN_ELSE; }
"enum"          { guardar_token(TOKEN_ENUM, KEYWORD); return TOKEN_ENUM; }
"extern"        { guardar_token(TOKEN_EXTERN, KEYWORD); return TOKEN_EXTERN; }
"float"         { guardar_token(TOKEN_FLOAT_KEYWORD, KEYWORD); return TOKEN_FLOAT_KEYWORD; }
"for"           { guardar_token(TOKEN_FOR, KEYWORD); return TOKEN_FOR; }
"goto"          { guardar_token(TOKEN_GOTO, KEYWORD); return TOKEN_GOTO; }
"if"            { guardar_token(TOKEN_IF, KEYWORD); return TOKEN_IF; }
"int"           { guardar_token(TOKEN_INT_KEYWORD, KEYWORD); return TOKEN_INT_KEYWORD; }
"long"          { guardar_token(TOKEN_LONG, KEYWORD); return TOKEN_LONG; }
"register"      { guardar_token(TOKEN_REGISTER, KEYWORD); return TOKEN_REGISTER; }
"return"        { guardar_token(TOKEN_RETURN, KEYWORD); return TOKEN_RETURN; }
"short"         { guardar_token(TOKEN_SHORT, KEYWORD); return TOKEN_SHORT; }
"signed"        { guardar_token(TOKEN_SIGNED, KEYWORD); return TOKEN_SIGNED; }
"sizeof"        { guardar_token(TOKEN_SIZEOF, KEYWORD); return TOKEN_SIZEOF; }
"static"        { guardar_token(TOKEN_STATIC, KEYWORD); return TOKEN_STATIC; }
"struct"        { guardar_token(TOKEN_STRUCT, KEYWORD); return TOKEN_STRUCT; }
"switch"        { guardar_token(TOKEN_SWITCH, KEYWORD); return TOKEN_SWITCH; }
"typedef"       { guardar_token(TOKEN_TYPEDEF, KEYWORD); return TOKEN_TYPEDEF; }
"union"         { guardar_token(TOKEN_UNION, KEYWORD); return TOKEN_UNION; }
"unsigned"      { guardar_token(TOKEN_UNSIGNED, KEYWORD); return TOKEN_UNSIGNED; }
"void"          { guardar_token(TOKEN_VOID, KEYWORD); return TOKEN_VOID; }
"volatile"      { guardar_token(TOKEN_VOLATILE, KEYWORD); return TOKEN_VOLATILE; }
"while"         { guardar_token(TOKEN_WHILE, KEYWORD); return TOKEN_WHILE; }

    /* Palabras reservadas adicionales */
"asm"           { guardar_token(TOKEN_ASM, KEYWORD); return TOKEN_ASM; }
"fortran"       { guardar_token(TOKEN_FORTRAN, KEYWORD); return TOKEN_FORTRAN; }
"inline"        { guardar_token(TOKEN_INLINE, KEYWORD); return TOKEN_INLINE; }
"restrict"      { guardar_token(TOKEN_RESTRICT, KEYWORD); return TOKEN_RESTRICT; }
"_Bool"         { guardar_token(TOKEN_BOOL_KEYWORD, KEYWORD); return TOKEN_BOOL_KEYWORD; }
"_Complex"      { guardar_token(TOKEN_COMPLEX, KEYWORD); return TOKEN_COMPLEX; }
"_Imaginary"    { guardar_token(TOKEN_IMAGINARY, KEYWORD); return TOKEN_IMAGINARY; }
"_Alignas"      { guardar_token(TOKEN_ALIGNAS, KEYWORD); return TOKEN_ALIGNAS; }
"_Alignof"      { guardar_token(TOKEN_ALIGNOF, KEYWORD); return TOKEN_ALIGNOF; }
"_Atomic"       { guardar_token(TOKEN_ATOMIC, KEYWORD); return TOKEN_ATOMIC; }
"_Generic"      { guardar_token(TOKEN_GENERIC, KEYWORD); return TOKEN_GENERIC; }
"_Noreturn"     { guardar_token(TOKEN_NORETURN, KEYWORD); return TOKEN_NORETURN; }
"_Static_assert" { guardar_token(TOKEN_STATIC_ASSERT, KEYWORD); return TOKEN_STATIC_ASSERT; }
"_Thread_local" { guardar_token(TOKEN_THREAD_LOCAL, KEYWORD); return TOKEN_THREAD_LOCAL; }
"alignas"       { guardar_token(TOKEN_ALIGNAS, KEYWORD); return TOKEN_ALIGNAS; }
"alignof"       { guardar_token(TOKEN_ALIGNOF, KEYWORD); return TOKEN_ALIGNOF; }
"bool"          { guardar_token(TOKEN_BOOL_KEYWORD, KEYWORD); return TOKEN_BOOL_KEYWORD; }
"constexpr"     { guardar_token(TOKEN_CONSTEXPR, KEYWORD); return TOKEN_CONSTEXPR; }
"false"         { guardar_token(TOKEN_FALSE, KEYWORD); return TOKEN_FALSE; }
"nullptr"       { guardar_token(TOKEN_NULLPTR, KEYWORD); return TOKEN_NULLPTR; }
"static_assert" { guardar_token(TOKEN_STATIC_ASSERT, KEYWORD); return TOKEN_STATIC_ASSERT; }
"thread_local"  { guardar_token(TOKEN_THREAD_LOCAL, KEYWORD); return TOKEN_THREAD_LOCAL; }
"true"          { guardar_token(TOKEN_TRUE, KEYWORD); return TOKEN_TRUE; }
"typeof"        { guardar_token(TOKEN_TYPEOF, KEYWORD); return TOKEN_TYPEOF; }
"typeof_unqual" { guardar_token(TOKEN_TYPEOF_UNQUAL, KEYWORD); return TOKEN_TYPEOF_UNQUAL; }
"_BitInt"       { guardar_token(TOKEN_BITINT, KEYWORD); return TOKEN_BITINT; }
"_Decimal32"    { guardar_token(TOKEN_DECIMAL32, KEYWORD); return TOKEN_DECIMAL32; }
"_Decimal64"    { guardar_token(TOKEN_DECIMAL64, KEYWORD); return TOKEN_DECIMAL64; }
"_Decimal128"   { guardar_token(TOKEN_DECIMAL128, KEYWORD); return TOKEN_DECIMAL128; }

    /* Literales e identificadores */
{FLOTANTE} {
    char numero_limpio[strlen(yytext) + 1];

    guardar_token(TOKEN_FLOAT, LITERAL);
    limpiar_separadores(yytext, numero_limpio);
    token_actual.valor_flotante = strtold(numero_limpio, NULL);

    return TOKEN_FLOAT;
}

{ENTERO} {
    guardar_token(TOKEN_INTEGER, LITERAL);
    token_actual.valor_entero = convertir_entero(yytext);

    return TOKEN_INTEGER;
}

{CARACTER}      { guardar_token(TOKEN_CHARACTER, LITERAL); return TOKEN_CHARACTER; }
{STRING}        { guardar_token(TOKEN_STRING, STRING); return TOKEN_STRING; }
{ID}            { guardar_token(TOKEN_ID, IDENTIFIER); return TOKEN_ID; }

    /* Operadores */
"&&"            { guardar_token(TOKEN_LOGICAL_AND, OPERATOR); return TOKEN_LOGICAL_AND; }
"||"            { guardar_token(TOKEN_LOGICAL_OR, OPERATOR); return TOKEN_LOGICAL_OR; }
"&"             { guardar_token(TOKEN_BITWISE_AND, OPERATOR); return TOKEN_BITWISE_AND; }
"|"             { guardar_token(TOKEN_BITWISE_OR, OPERATOR); return TOKEN_BITWISE_OR; }
"^"             { guardar_token(TOKEN_BITWISE_XOR, OPERATOR); return TOKEN_BITWISE_XOR; }
"~"             { guardar_token(TOKEN_BITWISE_NOT, OPERATOR); return TOKEN_BITWISE_NOT; }
"!"             { guardar_token(TOKEN_NOT, OPERATOR); return TOKEN_NOT; }
"++"            { guardar_token(TOKEN_INCREMENT, OPERATOR); return TOKEN_INCREMENT; }
"--"            { guardar_token(TOKEN_DECREMENT, OPERATOR); return TOKEN_DECREMENT; }
"+"             { guardar_token(TOKEN_PLUS, OPERATOR); return TOKEN_PLUS; }
"-"             { guardar_token(TOKEN_MINUS, OPERATOR); return TOKEN_MINUS; }
"*"             { guardar_token(TOKEN_MULT, OPERATOR); return TOKEN_MULT; }
"/"             { guardar_token(TOKEN_DIV, OPERATOR); return TOKEN_DIV; }
"%"             { guardar_token(TOKEN_MOD, OPERATOR); return TOKEN_MOD; }
"=="            { guardar_token(TOKEN_EQUAL, OPERATOR); return TOKEN_EQUAL; }
"!="            { guardar_token(TOKEN_DIFFERENT, OPERATOR); return TOKEN_DIFFERENT; }
"<="            { guardar_token(TOKEN_LESS_EQUAL, OPERATOR); return TOKEN_LESS_EQUAL; }
">="            { guardar_token(TOKEN_GREATER_EQUAL, OPERATOR); return TOKEN_GREATER_EQUAL; }
"<"             { guardar_token(TOKEN_LESS, OPERATOR); return TOKEN_LESS; }
">"             { guardar_token(TOKEN_GREATER, OPERATOR); return TOKEN_GREATER; }
"="             { guardar_token(TOKEN_ASSIGN, OPERATOR); return TOKEN_ASSIGN; }
"+="            { guardar_token(TOKEN_PLUS_ASSIGN, OPERATOR); return TOKEN_PLUS_ASSIGN; }
"-="            { guardar_token(TOKEN_MINUS_ASSIGN, OPERATOR); return TOKEN_MINUS_ASSIGN; }
"*="            { guardar_token(TOKEN_MULT_ASSIGN, OPERATOR); return TOKEN_MULT_ASSIGN; }
"/="            { guardar_token(TOKEN_DIV_ASSIGN, OPERATOR); return TOKEN_DIV_ASSIGN; }
"%="            { guardar_token(TOKEN_MOD_ASSIGN, OPERATOR); return TOKEN_MOD_ASSIGN; }
"&="            { guardar_token(TOKEN_AND_ASSIGN, OPERATOR); return TOKEN_AND_ASSIGN; }
"|="            { guardar_token(TOKEN_OR_ASSIGN, OPERATOR); return TOKEN_OR_ASSIGN; }
"^="            { guardar_token(TOKEN_XOR_ASSIGN, OPERATOR); return TOKEN_XOR_ASSIGN; }
"<<="           { guardar_token(TOKEN_LEFT_SHIFT_ASSIGN, OPERATOR); return TOKEN_LEFT_SHIFT_ASSIGN; }
">>="           { guardar_token(TOKEN_RIGHT_SHIFT_ASSIGN, OPERATOR); return TOKEN_RIGHT_SHIFT_ASSIGN; }
"<<"            { guardar_token(TOKEN_LEFT_SHIFT, OPERATOR); return TOKEN_LEFT_SHIFT; }
">>"            { guardar_token(TOKEN_RIGHT_SHIFT, OPERATOR); return TOKEN_RIGHT_SHIFT; }

    /* Puntuadores */
"("             { guardar_token(TOKEN_LEFT_PAREN, PUNCTUATOR); return TOKEN_LEFT_PAREN; }
")"             { guardar_token(TOKEN_RIGHT_PAREN, PUNCTUATOR); return TOKEN_RIGHT_PAREN; }
"{"             { guardar_token(TOKEN_LEFT_CURLY, PUNCTUATOR); return TOKEN_LEFT_CURLY; }
"}"             { guardar_token(TOKEN_RIGHT_CURLY, PUNCTUATOR); return TOKEN_RIGHT_CURLY; }
"["             { guardar_token(TOKEN_LEFT_SQUARE, PUNCTUATOR); return TOKEN_LEFT_SQUARE; }
"]"             { guardar_token(TOKEN_RIGHT_SQUARE, PUNCTUATOR); return TOKEN_RIGHT_SQUARE; }
"->"            { guardar_token(TOKEN_ARROW, PUNCTUATOR); return TOKEN_ARROW; }
"?"             { guardar_token(TOKEN_QUESTION, PUNCTUATOR); return TOKEN_QUESTION; }
"::"            { guardar_token(TOKEN_DOUBLE_COLON, PUNCTUATOR); return TOKEN_DOUBLE_COLON; }
":"             { guardar_token(TOKEN_COLON, PUNCTUATOR); return TOKEN_COLON; }
"..."           { guardar_token(TOKEN_ELLIPSIS, PUNCTUATOR); return TOKEN_ELLIPSIS; }
"."             { guardar_token(TOKEN_PERIOD, PUNCTUATOR); return TOKEN_PERIOD; }
","             { guardar_token(TOKEN_COMMA, PUNCTUATOR); return TOKEN_COMMA; }
";"             { guardar_token(TOKEN_SEMICOLON, PUNCTUATOR); return TOKEN_SEMICOLON; }
"##"            { guardar_token(TOKEN_DOUBLE_HASH, PUNCTUATOR); return TOKEN_DOUBLE_HASH; }
"#"             { guardar_token(TOKEN_HASH, PUNCTUATOR); return TOKEN_HASH; }

    /* Digraphs: devuelven el mismo token que el puntuador equivalente. */
"<%"            { guardar_token(TOKEN_LEFT_CURLY, PUNCTUATOR); return TOKEN_LEFT_CURLY; }
"%>"            { guardar_token(TOKEN_RIGHT_CURLY, PUNCTUATOR); return TOKEN_RIGHT_CURLY; }
"<:"            { guardar_token(TOKEN_LEFT_SQUARE, PUNCTUATOR); return TOKEN_LEFT_SQUARE; }
":>"            { guardar_token(TOKEN_RIGHT_SQUARE, PUNCTUATOR); return TOKEN_RIGHT_SQUARE; }
"%:%:"          { guardar_token(TOKEN_DOUBLE_HASH, PUNCTUATOR); return TOKEN_DOUBLE_HASH; }
"%:"            { guardar_token(TOKEN_HASH, PUNCTUATOR); return TOKEN_HASH; }

[ ]+     { spacing(yytext); }
\t       { spacing(yytext); }
[\r\v\f] { /* hola */ }
\n       { endline_latex(); }

. {
    guardar_token(TOKEN_LEXICAL_ERROR, ERROR);
    return TOKEN_LEXICAL_ERROR;
}

%%

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
    remove_comments(source_file_path, "/tmp/comment_removed");
    solve_defines("/tmp/comment_removed", "/tmp/defines_solved");
    solve_includes("/tmp/defines_solved", output_file_path);

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

void paste_in_latex(const char *texto)
{
    for (; *texto != '\0'; texto++) {
        switch (*texto) {
            case ' ':  
                fputs("\\ ", source_code); 
                break;

            case '\t': 
                fputs("\\SrcTab{}", source_code); 
                break;

            case '\\': 
                fputs("\\textbackslash{}", source_code); 
                break;

            case '{':  
                fputs("\\{", source_code); 
                break;

            case '}':  
                fputs("\\}", source_code); 
                break;

            case '$':  
                fputs("\\$", source_code); 
                break;

            case '&':  
                fputs("\\&", source_code); 
                break;

            case '#':  
                fputs("\\#", source_code); 
                break;

            case '_':  
                fputs("\\_", source_code); 
                break;

            case '%':  
                fputs("\\%", source_code); 
                break;

            case '^':  
                fputs("\\textasciicircum{}", source_code); 
                break;

            case '~':  
                fputs("\\textasciitilde{}", source_code);  break;
            default:   fputc(*texto, source_code);
        }
    }
}

void newline_latex(void) {
    if (!linea_abierta) {
        fputs("\\SrcLine{", source_code);
        linea_abierta = true;
    }
}

void endline_latex(void) {
    newline_latex();
    fputs("}\n", source_code);
    linea_abierta = false;
}


// para escribir el token con su comando correcto
void escribir_token(Token token) {
    if (linea_abierta) {
        fputs("\\SrcBreak{}", source_code);
    }

    newline_latex();
    fprintf(source_code, "\\%s{", nombres_categorias[token.categoria]);
    paste_in_latex(token.lexema);
    fputs("}", source_code);
}

// para los tabs y espacios
void spacing(const char *texto) {
    newline_latex();
    paste_in_latex(texto);
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
    char nombre_temporal[] = "/tmp/preprocesadoXXXXXX";

    int fd = mkstemp(nombre_temporal);

    if (fd == -1) {
        perror("Error creando archivo temporal");
        return EXIT_FAILURE;
    }

    close(fd);

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

    if (archivo_preprocesado == NULL) {
        perror("Error abriendo archivo preprocesado");
        return EXIT_FAILURE;
    }

    yyin = archivo_preprocesado;
	// ====== fin PRUEBAS ======== -- lun

    source_code = fopen("latex_aux/source_code.tex", "w");

    if (source_code == NULL) {
        perror("Error creando source_code.tex");
        fclose(archivo_preprocesado);
        return EXIT_FAILURE;
    }

    /* FASE 3: Obtener los tokens uno por uno */
    Token token;

    do {
        token = Get_Token();

        if (token.codigo != TOKEN_EOF) {
            escribir_token(token);

            /*
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
            */
        }

    } while (token.codigo != TOKEN_EOF);

    fclose(archivo_preprocesado);

    if (linea_abierta) {
        endline_latex();
    }

    fclose(source_code);

    /*
    printf(
        "Archivo preprocesado: %s\n",
        nombre_temporal
    );
    */

    FILE *stats = fopen("latex_aux/token_stats.dat", "w");

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


    FILE *stats2 = fopen("latex_aux/pie_chart.tex", "w");

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

    system("pdflatex -output-directory=results latex_aux/presentation.tex");


    fclose(stats2);

    return EXIT_SUCCESS;
}