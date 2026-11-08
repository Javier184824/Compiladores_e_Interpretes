#include <stdio.h>
#include <stdlib.h>

int yyparse();  // Uncomment this if using the command: make main

extern FILE *yyin;  // Uncomment this if using the command: make main 
extern int yydebug; // Uncomment this if using the command: make main 

//int match_word(FILE *source_fptr, const char *word);  // Uncomment this if using the command: make preprocessor

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "The program needs at least one argument to work correctly\n");
        return EXIT_FAILURE;
    }
    FILE *source_fptr = fopen(argv[1], "r");
    if (source_fptr == NULL) {
        fprintf(stderr, "Error opening the source file\n");
        return EXIT_FAILURE;
    }

    yydebug = 0;
    
    yyin = source_fptr;

    return yyparse(); // Uncomment this if using the command: make main
}