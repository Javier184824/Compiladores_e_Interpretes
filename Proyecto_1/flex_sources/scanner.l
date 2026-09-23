%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../headers/tokenizer.h"
#include "../headers/preprocessor.h"
%}

%option noyywrap

DIGITO              [0-9]
HEXDIGITO           [0-9a-fA-F]
OCTDIGITO           [0-7]
BINDIGITO           [01]
DIGITOS_DEC         {DIGITO}([']?{DIGITO})*
DIGITOS_HEX         {HEXDIGITO}([']?{HEXDIGITO})*
DIGITOS_OCT         {OCTDIGITO}([']?{OCTDIGITO})*
DIGITOS_BIN         {BINDIGITO}([']?{BINDIGITO})*
LETRA               [a-zA-Z_]
ID                  {LETRA}({LETRA}|{DIGITO})*

/* Entero */
SUFIJO_LONG         ([lL]|ll|LL)
SUFIJO_BIT          (wb|WB)
SUFIJO_ENTERO       ([uU]({SUFIJO_LONG}|{SUFIJO_BIT})?|({SUFIJO_LONG}|{SUFIJO_BIT})[uU]?)?
ENTERO              (0[xX]{DIGITOS_HEX}|0[bB]{DIGITOS_BIN}|0([']?{OCTDIGITO})*|[1-9]([']?{DIGITO})*){SUFIJO_ENTERO}

/* Flotante */
EXPONENTE_DEC       [eE][+-]?{DIGITOS_DEC}
EXPONENTE_HEX       [pP][+-]?{DIGITOS_DEC}
SUFIJO_FLOAT_DEC    (f|F|l|L|df|DF|dd|DD|dl|DL)
SUFIJO_FLOAT_HEX    [fFlL]

FLOAT_DECIMAL       (({DIGITOS_DEC}\.{DIGITOS_DEC}?|\.{DIGITOS_DEC}){EXPONENTE_DEC}?|{DIGITOS_DEC}{EXPONENTE_DEC}){SUFIJO_FLOAT_DEC}?
FLOAT_HEX           0[xX]({DIGITOS_HEX}\.{DIGITOS_HEX}?|\.{DIGITOS_HEX}|{DIGITOS_HEX}){EXPONENTE_HEX}{SUFIJO_FLOAT_HEX}?
FLOTANTE            ({FLOAT_DECIMAL}|{FLOAT_HEX})

WS                  [ \t]*
WS1                 [ \t]+
ESCAPE_CHAR         (\\['"?\\abfnrtv]|\\{OCTDIGITO}{1,3}|\\x{HEXDIGITO}+|\\u{HEXDIGITO}{4}|\\U{HEXDIGITO}{8})
CCHAR               ([^'\\\n]|{ESCAPE_CHAR})
CHAR_SIMPLE         (u8|u|U|L)?'{CCHAR}'
CHAR_MULTIPLE       L?'{CCHAR}{CCHAR}+
CARACTER            ({CHAR_SIMPLE}|{CHAR_MULTIPLE})

ESCAPE_STRING       (\\['"?\\abfnrtv]|\\{OCTDIGITO}{1,3}|\\x{HEXDIGITO}+|\\u{HEXDIGITO}{4}|\\U{HEXDIGITO}{8})
SCHAR               ([^"\\\n]|{ESCAPE_STRING})
STRING              (u8|u|U|L)?\"{SCHAR}*\"

SYSTEM_INCLUDE      ^{WS}"#"{WS}"include"{WS}"<"[^>]+">"
LOCAL_INCLUDE       ^{WS}"#"{WS}"include"{WS}\"[^"]+\"
FUNCTION_MACRO      ^{WS}"#"{WS}"define"{WS1}{ID}"("[^)]*")"
OBJECT_MACRO        ^{WS}"#"{WS}"define"{WS1}{ID}({WS1}.*)?

SINGLE_LINE_COMMENT "//".*
MULTILINE_COMMENT   "/*"([^*]|\*+[^*/])*\*+"/"

%%

{SYSTEM_INCLUDE} { guardar_token(TOKEN_SYSTEM_INCLUDE); return TOKEN_SYSTEM_INCLUDE; }

{LOCAL_INCLUDE} { guardar_token(TOKEN_LOCAL_INCLUDE); return TOKEN_LOCAL_INCLUDE; }

{FUNCTION_MACRO} { guardar_token(FUNCTION_MACRO); return FUNCTION_MACRO; }

{OBJECT_MACRO} { guardar_token(OBJECT_MACRO); return OBJECT_MACRO; }

{SINGLE_LINE_COMMENT} { guardar_token(SINGLE_LINE_COMMENT); return SINGLE_LINE_COMMENT; }

{MULTILINE_COMMENT} { guardar_token(MULTILINE_COMMENT); return MULTILINE_COMMENT; }

    /* Palabras reservadas */
"auto"          { guardar_token(TOKEN_AUTO); return TOKEN_AUTO; }
"break"         { guardar_token(TOKEN_BREAK); return TOKEN_BREAK; }
"case"          { guardar_token(TOKEN_CASE); return TOKEN_CASE; }
"char"          { guardar_token(TOKEN_CHAR_KEYWORD); return TOKEN_CHAR_KEYWORD; }
"const"         { guardar_token(TOKEN_CONST); return TOKEN_CONST; }
"continue"      { guardar_token(TOKEN_CONTINUE); return TOKEN_CONTINUE; }
"default"       { guardar_token(TOKEN_DEFAULT); return TOKEN_DEFAULT; }
"do"            { guardar_token(TOKEN_DO); return TOKEN_DO; }
"double"        { guardar_token(TOKEN_DOUBLE_KEYWORD); return TOKEN_DOUBLE_KEYWORD; }
"else"          { guardar_token(TOKEN_ELSE); return TOKEN_ELSE; }
"enum"          { guardar_token(TOKEN_ENUM); return TOKEN_ENUM; }
"extern"        { guardar_token(TOKEN_EXTERN); return TOKEN_EXTERN; }
"float"         { guardar_token(TOKEN_FLOAT_KEYWORD); return TOKEN_FLOAT_KEYWORD; }
"for"           { guardar_token(TOKEN_FOR); return TOKEN_FOR; }
"goto"          { guardar_token(TOKEN_GOTO); return TOKEN_GOTO; }
"if"            { guardar_token(TOKEN_IF); return TOKEN_IF; }
"int"           { guardar_token(TOKEN_INT_KEYWORD); return TOKEN_INT_KEYWORD; }
"long"          { guardar_token(TOKEN_LONG); return TOKEN_LONG; }
"register"      { guardar_token(TOKEN_REGISTER); return TOKEN_REGISTER; }
"return"        { guardar_token(TOKEN_RETURN); return TOKEN_RETURN; }
"short"         { guardar_token(TOKEN_SHORT); return TOKEN_SHORT; }
"signed"        { guardar_token(TOKEN_SIGNED); return TOKEN_SIGNED; }
"sizeof"        { guardar_token(TOKEN_SIZEOF); return TOKEN_SIZEOF; }
"static"        { guardar_token(TOKEN_STATIC); return TOKEN_STATIC; }
"struct"        { guardar_token(TOKEN_STRUCT); return TOKEN_STRUCT; }
"switch"        { guardar_token(TOKEN_SWITCH); return TOKEN_SWITCH; }
"typedef"       { guardar_token(TOKEN_TYPEDEF); return TOKEN_TYPEDEF; }
"union"         { guardar_token(TOKEN_UNION); return TOKEN_UNION; }
"unsigned"      { guardar_token(TOKEN_UNSIGNED); return TOKEN_UNSIGNED; }
"void"          { guardar_token(TOKEN_VOID); return TOKEN_VOID; }
"volatile"      { guardar_token(TOKEN_VOLATILE); return TOKEN_VOLATILE; }
"while"         { guardar_token(TOKEN_WHILE); return TOKEN_WHILE; }

    /* Palabras reservadas adicionales */
"asm"           { guardar_token(TOKEN_ASM); return TOKEN_ASM; }
"fortran"       { guardar_token(TOKEN_FORTRAN); return TOKEN_FORTRAN; }
"inline"        { guardar_token(TOKEN_INLINE); return TOKEN_INLINE; }
"restrict"      { guardar_token(TOKEN_RESTRICT); return TOKEN_RESTRICT; }
"_Bool"         { guardar_token(TOKEN_BOOL_KEYWORD); return TOKEN_BOOL_KEYWORD; }
"_Complex"      { guardar_token(TOKEN_COMPLEX); return TOKEN_COMPLEX; }
"_Imaginary"    { guardar_token(TOKEN_IMAGINARY); return TOKEN_IMAGINARY; }
"_Alignas"      { guardar_token(TOKEN_ALIGNAS); return TOKEN_ALIGNAS; }
"_Alignof"      { guardar_token(TOKEN_ALIGNOF); return TOKEN_ALIGNOF; }
"_Atomic"       { guardar_token(TOKEN_ATOMIC); return TOKEN_ATOMIC; }
"_Generic"      { guardar_token(TOKEN_GENERIC); return TOKEN_GENERIC; }
"_Noreturn"     { guardar_token(TOKEN_NORETURN); return TOKEN_NORETURN; }
"_Static_assert" { guardar_token(TOKEN_STATIC_ASSERT); return TOKEN_STATIC_ASSERT; }
"_Thread_local" { guardar_token(TOKEN_THREAD_LOCAL); return TOKEN_THREAD_LOCAL; }
"alignas"       { guardar_token(TOKEN_ALIGNAS); return TOKEN_ALIGNAS; }
"alignof"       { guardar_token(TOKEN_ALIGNOF); return TOKEN_ALIGNOF; }
"bool"          { guardar_token(TOKEN_BOOL_KEYWORD); return TOKEN_BOOL_KEYWORD; }
"constexpr"     { guardar_token(TOKEN_CONSTEXPR); return TOKEN_CONSTEXPR; }
"false"         { guardar_token(TOKEN_FALSE); return TOKEN_FALSE; }
"nullptr"       { guardar_token(TOKEN_NULLPTR); return TOKEN_NULLPTR; }
"static_assert" { guardar_token(TOKEN_STATIC_ASSERT); return TOKEN_STATIC_ASSERT; }
"thread_local"  { guardar_token(TOKEN_THREAD_LOCAL); return TOKEN_THREAD_LOCAL; }
"true"          { guardar_token(TOKEN_TRUE); return TOKEN_TRUE; }
"typeof"        { guardar_token(TOKEN_TYPEOF); return TOKEN_TYPEOF; }
"typeof_unqual" { guardar_token(TOKEN_TYPEOF_UNQUAL); return TOKEN_TYPEOF_UNQUAL; }
"_BitInt"       { guardar_token(TOKEN_BITINT); return TOKEN_BITINT; }
"_Decimal32"    { guardar_token(TOKEN_DECIMAL32); return TOKEN_DECIMAL32; }
"_Decimal64"    { guardar_token(TOKEN_DECIMAL64); return TOKEN_DECIMAL64; }
"_Decimal128"   { guardar_token(TOKEN_DECIMAL128); return TOKEN_DECIMAL128; }

    /* Literales e identificadores */
{FLOTANTE} {
    char numero_limpio[strlen(yytext) + 1];

    guardar_token(TOKEN_FLOAT);
    limpiar_separadores(yytext, numero_limpio);
    token_actual.valor_flotante = strtold(numero_limpio, NULL);

    return TOKEN_FLOAT;
}

{ENTERO} {
    guardar_token(TOKEN_INTEGER);
    token_actual.valor_entero = convertir_entero(yytext);

    return TOKEN_INTEGER;
}

{CARACTER}      { guardar_token(TOKEN_CHARACTER); return TOKEN_CHARACTER; }
{STRING}        { guardar_token(TOKEN_STRING); return TOKEN_STRING; }
{ID}            { guardar_token(TOKEN_ID); return TOKEN_ID; }

    /* Operadores */
"&&"            { guardar_token(TOKEN_LOGICAL_AND); return TOKEN_LOGICAL_AND; }
"||"            { guardar_token(TOKEN_LOGICAL_OR); return TOKEN_LOGICAL_OR; }
"&"             { guardar_token(TOKEN_BITWISE_AND); return TOKEN_BITWISE_AND; }
"|"             { guardar_token(TOKEN_BITWISE_OR); return TOKEN_BITWISE_OR; }
"^"             { guardar_token(TOKEN_BITWISE_XOR); return TOKEN_BITWISE_XOR; }
"~"             { guardar_token(TOKEN_BITWISE_NOT); return TOKEN_BITWISE_NOT; }
"!"             { guardar_token(TOKEN_NOT); return TOKEN_NOT; }
"++"            { guardar_token(TOKEN_INCREMENT); return TOKEN_INCREMENT; }
"--"            { guardar_token(TOKEN_DECREMENT); return TOKEN_DECREMENT; }
"+"             { guardar_token(TOKEN_PLUS); return TOKEN_PLUS; }
"-"             { guardar_token(TOKEN_MINUS); return TOKEN_MINUS; }
"*"             { guardar_token(TOKEN_MULT); return TOKEN_MULT; }
"/"             { guardar_token(TOKEN_DIV); return TOKEN_DIV; }
"%"             { guardar_token(TOKEN_MOD); return TOKEN_MOD; }
"=="            { guardar_token(TOKEN_EQUAL); return TOKEN_EQUAL; }
"!="            { guardar_token(TOKEN_DIFFERENT); return TOKEN_DIFFERENT; }
"<="            { guardar_token(TOKEN_LESS_EQUAL); return TOKEN_LESS_EQUAL; }
">="            { guardar_token(TOKEN_GREATER_EQUAL); return TOKEN_GREATER_EQUAL; }
"<"             { guardar_token(TOKEN_LESS); return TOKEN_LESS; }
">"             { guardar_token(TOKEN_GREATER); return TOKEN_GREATER; }
"="             { guardar_token(TOKEN_ASSIGN); return TOKEN_ASSIGN; }
"+="            { guardar_token(TOKEN_PLUS_ASSIGN); return TOKEN_PLUS_ASSIGN; }
"-="            { guardar_token(TOKEN_MINUS_ASSIGN); return TOKEN_MINUS_ASSIGN; }
"*="            { guardar_token(TOKEN_MULT_ASSIGN); return TOKEN_MULT_ASSIGN; }
"/="            { guardar_token(TOKEN_DIV_ASSIGN); return TOKEN_DIV_ASSIGN; }
"%="            { guardar_token(TOKEN_MOD_ASSIGN); return TOKEN_MOD_ASSIGN; }
"&="            { guardar_token(TOKEN_AND_ASSIGN); return TOKEN_AND_ASSIGN; }
"|="            { guardar_token(TOKEN_OR_ASSIGN); return TOKEN_OR_ASSIGN; }
"^="            { guardar_token(TOKEN_XOR_ASSIGN); return TOKEN_XOR_ASSIGN; }
"<<="           { guardar_token(TOKEN_LEFT_SHIFT_ASSIGN); return TOKEN_LEFT_SHIFT_ASSIGN; }
">>="           { guardar_token(TOKEN_RIGHT_SHIFT_ASSIGN); return TOKEN_RIGHT_SHIFT_ASSIGN; }
"<<"            { guardar_token(TOKEN_LEFT_SHIFT); return TOKEN_LEFT_SHIFT; }
">>"            { guardar_token(TOKEN_RIGHT_SHIFT); return TOKEN_RIGHT_SHIFT; }

    /* Puntuadores */
"("             { guardar_token(TOKEN_LEFT_PAREN); return TOKEN_LEFT_PAREN; }
")"             { guardar_token(TOKEN_RIGHT_PAREN); return TOKEN_RIGHT_PAREN; }
"{"             { guardar_token(TOKEN_LEFT_CURLY); return TOKEN_LEFT_CURLY; }
"}"             { guardar_token(TOKEN_RIGHT_CURLY); return TOKEN_RIGHT_CURLY; }
"["             { guardar_token(TOKEN_LEFT_SQUARE); return TOKEN_LEFT_SQUARE; }
"]"             { guardar_token(TOKEN_RIGHT_SQUARE); return TOKEN_RIGHT_SQUARE; }
"->"            { guardar_token(TOKEN_ARROW); return TOKEN_ARROW; }
"?"             { guardar_token(TOKEN_QUESTION); return TOKEN_QUESTION; }
"::"            { guardar_token(TOKEN_DOUBLE_COLON); return TOKEN_DOUBLE_COLON; }
":"             { guardar_token(TOKEN_COLON); return TOKEN_COLON; }
"..."           { guardar_token(TOKEN_ELLIPSIS); return TOKEN_ELLIPSIS; }
"."             { guardar_token(TOKEN_PERIOD); return TOKEN_PERIOD; }
","             { guardar_token(TOKEN_COMMA); return TOKEN_COMMA; }
";"             { guardar_token(TOKEN_SEMICOLON); return TOKEN_SEMICOLON; }
"##"            { guardar_token(TOKEN_DOUBLE_HASH); return TOKEN_DOUBLE_HASH; }
"#"             { guardar_token(TOKEN_HASH); return TOKEN_HASH; }

    /* Digraphs: devuelven el mismo token que el puntuador equivalente. */
"<%"            { guardar_token(TOKEN_LEFT_CURLY); return TOKEN_LEFT_CURLY; }
"%>"            { guardar_token(TOKEN_RIGHT_CURLY); return TOKEN_RIGHT_CURLY; }
"<:"            { guardar_token(TOKEN_LEFT_SQUARE); return TOKEN_LEFT_SQUARE; }
":>"            { guardar_token(TOKEN_RIGHT_SQUARE); return TOKEN_RIGHT_SQUARE; }
"%:%:"          { guardar_token(TOKEN_DOUBLE_HASH); return TOKEN_DOUBLE_HASH; }
"%:"            { guardar_token(TOKEN_HASH); return TOKEN_HASH; }

[ \t\r\n\v\f]+  { /* Ignorar whitespace. */ }

. {
    guardar_token(TOKEN_LEXICAL_ERROR);
    return TOKEN_LEXICAL_ERROR;
}

%%
