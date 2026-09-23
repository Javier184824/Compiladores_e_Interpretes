#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/generate.h"

FILE *data_file;
FILE *bss_file;
FILE *text_file;
FILE *output_file;
char *output_filename;
static int skip_counter = 0;
static int skip_pending = -1;

void set_output_file(char *filename) {
    output_filename = "a.asm";
}

void get_temp_files() {

    data_file = fopen("data_file", "w");
    bss_file = fopen("bss_file", "w");
    text_file = fopen("text_file", "w");

    if (data_file == NULL || bss_file == NULL || text_file == NULL) {
        printf("Temporary files not initialized in get_temp_files\n");
        exit(EXIT_FAILURE);
    }

    fprintf(data_file, 
        "section .data\n"
        "\tint_format db \"%%d\", 0\n"
        "\tchar_format db \"%%c\", 0\n"
    );

    fprintf(bss_file, 
        "section .bss\n"
    );

    fprintf(text_file,
        "section .text\n"
        "\tdefault rel\n"
        "\textern printf\n"
        "\textern scanf\n"
        "\textern atoi\n"
        "\tglobal main\n"
        "main:\n"
        "\tpush rbp\n"
    );
}

void close_temp_files() {

    fclose(data_file);
    fclose(bss_file);
    fclose(text_file);

    output_file = fopen(output_filename, "w");
    data_file = fopen("data_file", "r");
    bss_file = fopen("bss_file", "r");
    text_file = fopen("text_file", "r");

    if (data_file == NULL ||bss_file == NULL || text_file == NULL || output_file == NULL) {
        printf("Temporary files not found in close_temp_files");
        exit(EXIT_FAILURE);
    }

    int character;
    while ((character = fgetc(data_file)) != EOF) {
        fputc(character, output_file);
    }
    while ((character = fgetc(bss_file)) != EOF) {
        fputc(character, output_file);
    }
    while ((character = fgetc(text_file)) != EOF) {
        fputc(character, output_file);
    }

    fclose(data_file);
    fclose(bss_file);
    fclose(text_file);
    fclose(output_file);

    remove("data_file");
    remove("bss_file");
    remove("text_file");
}

// para quitar los "&" de los Temp
char *remove_amp(char *name) {

    char *new_name = malloc(strlen(name) + 1);

    if (new_name == NULL) {
        printf("Could not allocate memory in remove_amp function\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_name, name);

    for (int i = 0; new_name[i] != '\0'; i++) {
        if (new_name[i] == '&') {
            new_name[i] = '_';
        }
    }

    return new_name;
}

int is_number(char *str) {

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }

    return 1;
}

void generate(char *op, char *og_param_1, char *og_param_2, char *og_param_3) {

    if (data_file == NULL || bss_file == NULL || text_file == NULL) {
        get_temp_files();
    }

    char *param_1 = remove_amp(og_param_1);
    char *param_2 = remove_amp(og_param_2);
    char *param_3 = remove_amp(og_param_3);

    int after_skipped = skip_pending;
    skip_pending = -1;

    // montaña de ifs... lo lamento.
    if (strcmp(op, "Declare") == 0) {
        // en .bss
        fprintf(bss_file, "\t%s resb 4\n", param_1);

    } else if (strcmp(op, "Halt") == 0) {
        // halt

        fprintf(text_file, 
            "\tpop rbp\n"
            "\tret"
        );

        close_temp_files();

    } else if (strcmp(op, "Add") == 0) {
        // addition

        if (is_number(param_1)) {
            fprintf(text_file, "\tmov rax, %s\n", param_1);
        } else {
            fprintf(text_file, "\tmov rax, [%s]\n", param_1);
        }

        if (is_number(param_2)) {
            fprintf(text_file, "\tadd rax, %s\n", param_2);
        } else {
            fprintf(text_file, "\tadd rax, [%s]\n", param_2);
        }

        fprintf(text_file, "\tmov [%s], rax\n", param_3);
        fprintf(text_file, "\n");

    } else if (strcmp(op, "Sub") == 0) {
        // substraction

        if (is_number(param_1)) {
            fprintf(text_file, "\tmov rax, %s\n", param_1);
        } else {
            fprintf(text_file, "\tmov rax, [%s]\n", param_1);
        }

        if (is_number(param_2)) {
            fprintf(text_file, "\tsub rax, %s\n", param_2);
        } else {
            fprintf(text_file, "\tsub rax, [%s]\n", param_2);
        }
        fprintf(text_file, "\tmov [%s], rax\n", param_3);
        fprintf(text_file, "\n");

    } else if (strcmp(op, "Read") == 0) {
        // read

        fprintf(text_file, 
            "\tmov rdi, int_format\n"
        );

        if (is_number(param_1)) {
            fprintf(text_file, 
                "\tlea rsi, %s\n", 
                param_1
            );
        } else {
            fprintf(text_file, 
                "\tlea rsi, [%s]\n", 
                param_1
            );
        }
        
        fprintf(text_file,
            "\txor rax, rax\n"
            "\tcall scanf\n"
        );
        fprintf(text_file, "\n");

    } else if (strcmp(op, "Write") == 0) {
        // write

        fprintf(text_file, 
            "\tmov rdi, int_format\n"
        );

        if (is_number(param_1)) {
            fprintf(text_file, 
                "\tmov rsi, %s\n", 
                param_1
            );
        } else {
            fprintf(text_file, 
                "\tmov rsi, [%s]\n", 
                param_1
            );
        }
        
        fprintf(text_file,
            "\txor rax, rax\n"
            "\tcall printf\n"
            "\tmov rdi, char_format\n"
            "\tmov rsi, 10\n"
            "\txor rax, rax\n"
            "\tcall printf\n"
        );
        fprintf(text_file, "\n");

    } else if (strcmp(op, "Store") == 0) {
        // store

        if (is_number(param_1)) {
            fprintf(text_file, "\tmov rax, %s\n", param_1);
        } else {
            fprintf(text_file, "\tmov rax, [%s]\n", param_1);
        }

        fprintf(text_file, "\tmov [%s], rax\n", param_2);
        fprintf(text_file, "\n");

    } else if (strcmp(op, "Skip") == 0) {
        // skip
        
        int actual_skip = skip_counter++;

        if (is_number(param_1)){
            fprintf(text_file, "\tmov rax, %s\n", param_1);
        } else {
            fprintf(text_file, "\tmov rax, [%s]\n", param_1);
        }
        fprintf(text_file, "\tcmp rax, 0\n");
        fprintf(text_file, "\tjne .skip_%d\n", actual_skip);
        fprintf(text_file, "\n");
        skip_pending = actual_skip;

    }

    if (after_skipped != -1) {
        fprintf(text_file, ".skip_%d:\n", after_skipped);
        
    }

    free(param_1);
    free(param_2);
    free(param_3);
    
}