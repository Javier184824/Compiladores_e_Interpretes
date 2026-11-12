#include <stdio.h>
#include <stdlib.h>

int remove_comments(const char *source_file_path, const char *output_file_path) {
    FILE *source_fptr = fopen(source_file_path, "r");
    if (source_fptr == NULL) {
        fprintf(stderr, "Error opening the source file: %s\n", source_file_path);
        return EXIT_FAILURE;
    }

    FILE *output_fptr = fopen(output_file_path, "w");
    if (output_fptr == NULL) {
        fprintf(stderr, "Error creating the output file: %s\n", output_file_path);
        fclose(source_fptr);
        return EXIT_FAILURE;
    }

    int current_char;
    while ((current_char = fgetc(source_fptr)) != EOF) {
        if (current_char == '/') {
            current_char = fgetc(source_fptr);
            if (current_char == '/') {
                do {
                    current_char = fgetc(source_fptr);
                } 
                while (current_char != '\n' && current_char != EOF);
                fputc(current_char, output_fptr);
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

    return EXIT_SUCCESS;
}