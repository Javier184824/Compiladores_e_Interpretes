%{
#include <stdio.h>
#include <stdlib.h>

// Declare functions to prevent compiler warnings
int yylex(void);
void yyerror(const char *s);

// Gain access to the line number tracked by Flex
extern int yylineno; 
%}

%token NUMBER PLUS MINUS

%%
/* Simple grammar expecting: number + number */
program:
    expression
    ;

expression:
    NUMBER PLUS NUMBER
    | NUMBER MINUS NUMBER
    ;
%%

// CUSTOMIZED ERROR FUNCTION
void yyerror(const char *s) {
    // Prints "Syntax Error at line X: syntax error"
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, s);
}

int main(void) {
    return yyparse();
}
