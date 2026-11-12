#include <stdio.h>
#include <stdlib.h>
#include "parser/typedef_support.h"
#include "preprocessors/include_solver.h"
#include "preprocessors/define_solver.h"
#include "preprocessors/comment_remover.h"

#define OUTPUT_FILE_INCLUDES_SOLVED "output_includes_solved"
#define OUTPUT_FILE_DEFINES_SOLVED "output_defines_solved"
#define OUTPUT_FILE_NO_COMMENTS "output_no_comments"

int yyparse();

extern FILE *yyin;
extern int yydebug;
extern char *filepath;

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "The program is getting more than 1 argument.\nCorrect format: ./c_parser [input_filepath]\n");
        return EXIT_FAILURE;
    }
    else if (argc == 1) {
        fprintf(stderr, "The program needs at least 1 argument to work:\nCorrect format: ./c_parser [input_filepath]\n");
        return EXIT_FAILURE;
    }

    filepath = argv[1];

    solve_includes(argv[1], OUTPUT_FILE_INCLUDES_SOLVED);

    if (solve_defines(OUTPUT_FILE_INCLUDES_SOLVED, OUTPUT_FILE_DEFINES_SOLVED)) {
        return EXIT_FAILURE;
    }
    
    if (remove_comments(OUTPUT_FILE_DEFINES_SOLVED, OUTPUT_FILE_NO_COMMENTS)) {
        return EXIT_FAILURE;
    }
    
    FILE *source_fptr = fopen(OUTPUT_FILE_NO_COMMENTS, "r");
    if (source_fptr == NULL) {
        fprintf(stderr, "Error opening the source file\n");
        return EXIT_FAILURE;
    }

    yydebug = 0;
    
    yyin = source_fptr;

    int result = yyparse();

    free_typedef_support();
    fclose(source_fptr);

    system("rm -f output_defines_solved output_includes_solved output_no_comments");

    return result;
}