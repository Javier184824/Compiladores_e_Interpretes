%{
#include "../parser/parser_test.h"
%}

/* Tell flex to automatically maintain the integer variable 'yylineno' */
%option yylineno

%%
[0-9]+          { return NUMBER; }
"+"             { return PLUS; }
"-"             { return MINUS; }
\n              { /* Ignore newlines, but yylineno increments automatically */ }
[ \t]           { /* Ignore whitespace */ }
.               { return yytext[0]; } /* Catch-all for unexpected characters */
%%

int yywrap(void) {
    return 1;
}
