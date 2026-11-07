#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef enum {
    TOKEN_EOF = 0,

    /* Palabras para preprocesadores */
    TOKEN_SYSTEM_INCLUDE,
    TOKEN_LOCAL_INCLUDE,
    FUNCTION_MACRO,
    OBJECT_MACRO,
    SINGLE_LINE_COMMENT,
    MULTILINE_COMMENT,

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
    PREPROCESS,
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

extern char *yytext;
extern int yylineno;
extern FILE *yyin;
extern int yylex (void);

static Token token_actual;
static int contador_tokens[7] = {0};
static int total_tokens = 0;
static FILE *source_code;

int remove_comments(const char* source_file_path, const char *output_file_path);
int preprocess(const char *source_file_path, const char *output_file_path);
Token Get_Token(void);
void guardar_token(int codigo, CategoriaToken categoria);
void limpiar_separadores(const char *origen, char *destino);
long long convertir_entero(const char *lexema);

#endif