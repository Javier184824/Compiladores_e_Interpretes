#include <stdio.h>
#include <stdlib.h>

//int yyparse();
int match_word(FILE *source_fptr, const char *word);

int main(int argc, char *argv[]) {
    //return yyparse();
    FILE *source_fptr = fopen("inputs/input.txt", "r");
    if (source_fptr == NULL) {
        fprintf(stderr, "Error opening the source file\n");
        return EXIT_FAILURE;
    }
    printf("%d\n", match_word(source_fptr, "hola"));
    return 0;
}