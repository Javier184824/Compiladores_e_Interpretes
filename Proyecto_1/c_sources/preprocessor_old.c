#if 0

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../headers/preprocessor.h"

char buffer[MAX_BUFFER_SIZE];
Preprocess preprocesses_array[MAX_PREPROCESSES];
int buffer_index = 0;
int preprocesses_index = 0;
int line = 1;
FILE *source;

void get_file(char *filename) {
    source = fopen(filename, "r");
    if (source == NULL) {
        printf("Could not open source file\n");
        exit(EXIT_FAILURE);
    }
}

void buffer_char(char c) {
    buffer[buffer_index] = c;
    buffer_index++;
    if (buffer_index >= MAX_BUFFER_SIZE) {
        exit(EXIT_FAILURE);
    }
}

void insert_preprocess(PreprocessCode code, int line, char *lexema) {
    Preprocess p = {code, line, "", "", ""};
    strcpy(p.lexema, lexema);
    preprocesses_array[preprocesses_index] = p;
    preprocesses_index++;
    if (preprocesses_index >= MAX_BUFFER_SIZE) {
        exit(EXIT_FAILURE);
    }
}

void print_preprocess(Preprocess p) {
    printf("code = %d, line = %d, lexema = %s, arg_0 = %s, arg_1 = %s\n", p.code, p.line, p.lexema, p.argument_0, p.argument_1);
}

void clear_buffer(void) {
    memset(buffer, 0, sizeof(buffer));
    buffer_index = 0;
}

PreprocessCode check_reserved(void) {
    if (strcmp(buffer, "include") == 0)
        return INCLUDE;
    if (strcmp(buffer, "define") == 0)
        return DEFINE;
    return INVALID;
}

int get_define_arguments(Preprocess *preprocess) {
    char c;
    // First argument
    clear_buffer();
    c = fgetc(source);
    for (c; c != '\n' && isspace(c); c = fgetc(source))
        continue;
    for (c; isalpha(c) || c == '_' || c == '-'; c = fgetc(source))
        buffer_char(c);
    memset(preprocess->argument_0, 0, sizeof(preprocess->argument_0));
    strcpy(preprocess->argument_0, buffer);

    // Second argument
    clear_buffer();
    c = fgetc(source);
    for (c; c != '\n' && isspace(c); c = fgetc(source))
        continue;
    for (c; isalnum(c) || c == '_' || c == '\"'; c = fgetc(source))
        buffer_char(c);
    memset(preprocess->argument_1, 0, sizeof(preprocess->argument_1));
    strcpy(preprocess->argument_1, buffer);

    clear_buffer();
}

int get_include_argument(Preprocess *preprocess) {
    char c;
    // First argument
    clear_buffer();
    for (c = fgetc(source); c != '\n' && isspace(c); c = fgetc(source))
        continue;
    if (c == '<' || c == '\"') {
        for (c = fgetc(source); isalpha(c) || c == '_' || c == '-' || c == '.'; c = fgetc(source))
            buffer_char(c);
    }
    memset(preprocess->argument_0, 0, sizeof(preprocess->argument_0));
    strcpy(preprocess->argument_0, buffer);
}

int get_parameters(Preprocess *preprocess) {
    switch (preprocess->code) {
        case INCLUDE:
            get_include_argument(preprocess);
            break;
        case DEFINE:
            get_define_arguments(preprocess);
            break;
    }
}

void get_preprocess(void) {
    int current_char, c;
    PreprocessCode code;
    clear_buffer();
    if (feof(source))
        return;
    while((current_char = fgetc(source)) != EOF) {
        if (current_char == '\n') {
            clear_buffer();
            line++;
        }
        else if (isspace(current_char))
            continue;
        else if (current_char == '#') {
            c = fgetc(source);
            for (c; c != '\n' && isspace(c); c = fgetc(source))
                continue;
            for (c; isalpha(c); c = fgetc(source))
                buffer_char(c);
            code = check_reserved();
            insert_preprocess(code, line, buffer);
            get_parameters(&preprocesses_array[preprocesses_index - 1]);
        }
    }
}

int remove_comments(char output_file_path[]) {
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

void replace_strings(FILE* output, const int starting_line, char *string_to_find, char *string_to_replace) {
    int current_char, c;
    int current_line = 1;
    clear_buffer();
    if (feof(source))
        return;
    while((current_char = fgetc(source)) != EOF) {
        if (current_char == '\n') {
            if (current_line > starting_line) {
                if (buffer_index == 0) {
                    fputc(current_char, output);
                }
                else if (strcmp(buffer, string_to_find) == 0) {
                    fputs(string_to_replace, output);
                    fputc(current_char, output);
                }
                else {
                    fputs(buffer, output);
                    fputc(current_char, output);
                }
                current_line++;
                clear_buffer();
            }
            else {
                fputc(current_char, output);
            }
        }
        else if (isspace(current_char)) {
            if (current_line > starting_line) {
                if (buffer_index == 0) {
                    fputc(current_char, output);
                }
                else if (strcmp(buffer, string_to_find) == 0) {
                    fputs(string_to_replace, output);
                    fputc(current_char, output);
                }
                else {
                    fputs(buffer, output);
                    fputc(current_char, output);
                }
                clear_buffer();
            }
            else {
                fputc(current_char, output);
            }
        }
        else {
            buffer_char(current_char);
        }
    }
    if (buffer_index == 0) {
        fputc(current_char, output);
    }
    else if (strcmp(buffer, string_to_find) == 0) {
        fputs(string_to_replace, output);
    }
    else {
        fputs(buffer, output);
    }
    clear_buffer();
}

void write_on_file(FILE *source, FILE *output) {
    int current_char, c;
    if (feof(source))
        return;
    while((current_char = fgetc(source)) != EOF) {
        fputc(current_char, output);
    }
    fputc('\n', output);
}

int main(void) {
    FILE *output = fopen("tmp/inserted.c", "w");
    FILE *foreign = fopen("test/do_nothing.c", "r");
    get_file("test/hello_world.c");
    write_on_file(foreign, output);
    write_on_file(source, output);
    fclose(output);
    //remove_comments("tmp/no_comments.c");
    //fclose(source);
    //get_file("tmp/no_comments.c");
    //get_preprocess();
    //for (int i = 0; i < preprocesses_index; i++) {
    //    print_preprocess(preprocesses_array[i]);
    //}
    return 0;
}

#endif