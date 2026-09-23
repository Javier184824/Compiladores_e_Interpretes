#include <stdlib.h>
#include <stdio.h>

int remove_comments(FILE *source, char output_file_path[]) {
    char current_char = ' ';
    FILE *output_fptr = fopen(output_file_path, "w");
    if (feof(source)) {
        return 0;
    }
    while ((current_char = fgetc(source)) != EOF) {
        if (current_char == '/') {
            current_char = fgetc(source);
            if (current_char == '/') {
                do {
                    current_char = fgetc(source);
                } 
                while (current_char != '\n' && current_char != EOF);
            }
            else if (current_char == '*') {
                do {
                    current_char = fgetc(source);
                    if (current_char == '*') {
                        current_char = fgetc(source);
                        if (current_char == '/') {
                            break;
                        }
                    }
                }
                while (current_char != EOF);
            }
            else {
                if (current_char != EOF) {
                    ungetc(current_char, source);
                }
            }
        }
        else {
            fputc(current_char, output_fptr);
        }
    }
    fclose(output_fptr);
}