#include <stdio.h>
#include <stdlib.h>
#include "parser/typedef_support.h"
#include "preprocessors/comment_remover.h"

#define OUTPUT_FILE_NO_COMMENTS "output_no_comments"

int yyparse();  // Uncomment this if using the command: make main

extern FILE *yyin;  // Uncomment this if using the command: make main 
extern int yydebug; // Uncomment this if using the command: make main 

//int match_word(FILE *source_fptr, const char *word);  // Uncomment this if using the command: make preprocessor

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "The program needs at least one argument to work correctly\n");
        return EXIT_FAILURE;
    }

    if (remove_comments(argv[1], OUTPUT_FILE_NO_COMMENTS)) {
        return EXIT_FAILURE;
    }
    
    FILE *source_fptr = fopen(OUTPUT_FILE_NO_COMMENTS, "r");
    if (source_fptr == NULL) {
        fprintf(stderr, "Error opening the source file\n");
        return EXIT_FAILURE;
    }

    yydebug = 0;
    
    yyin = source_fptr;

    int resultado = yyparse();// Uncomment this if using the command: make main

    free_typedef_support();
    fclose(source_fptr);

    return resultado;
}