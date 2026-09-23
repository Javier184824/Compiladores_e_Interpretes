#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../headers/scanner.h"
#include "../headers/semantic_records.h"

char token_buffer[MAXIDLEN];
char command_buffer[MAXCOMMANDLEN];
static int buffer_index = 0;
int line = 1;

void get_file(char *filename);
void clear_buffer(void);
void buffer_char(int c);
token check_reserved(void);
void lexical_error(int c);

FILE *source;

void get_file(char *filename) {
    source = fopen(filename, "r");

    if (source == NULL) {
        printf("Could not open source file\n");
        exit(EXIT_FAILURE);
    }
}

void clear_buffer(void) {
    buffer_index = 0;
    token_buffer[0] = '\0';
}

void buffer_char(int c) {
    
    if (buffer_index >= MAXIDLEN - 1) {
        fprintf(stderr,
            "Identifier %s... is too long at line %d\n",
            token_buffer, line);

        remove("data_file");
        remove("bss_file");
        remove("text_file");
        
        exit(EXIT_FAILURE);
    }

    token_buffer[buffer_index++] = (char)c;
    token_buffer[buffer_index] = '\0';
}

token check_reserved(void) {
    if (strcmp(token_buffer, "begin") == 0)
        return BEGIN;

    if (strcmp(token_buffer, "end") == 0)
        return END;

    if (strcmp(token_buffer, "read") == 0)
        return READ;

    if (strcmp(token_buffer, "write") == 0)
        return WRITE;

    if (strcmp(token_buffer, "SCANEOF") == 0)
        return SCANEOF;

    return ID;
}

void lexical_error(int c) {
    fprintf(stderr,
            "Lexical error at line %d: invalid character '%c'\n",
            line, c);
    remove("data_file");
    remove("bss_file");
    remove("text_file");
    exit(EXIT_FAILURE);
}

token scanner(void) {
    int in_char, c;
    clear_buffer();
    if (feof(source))
        return SCANEOF;
    while((in_char = fgetc(source)) != EOF) {
        if (in_char == '\n') {
            line++;
        }
        else if (isspace(in_char))
            continue;
        else if (isalpha(in_char)) {
            buffer_char(in_char);
            for (c = fgetc(source); isalnum(c) || c == '_'; c = fgetc(source))
                buffer_char(c);
            if (c != EOF)
                ungetc(c, source);
            return check_reserved();
        }
        else if (isdigit(in_char)) {
            buffer_char(in_char);
            for (c = fgetc(source); isdigit(c); c = fgetc(source))
                buffer_char(c);
            if (c != EOF)
                ungetc(c, source);
            return INTLITERAL;
        }
        else if (in_char == '(')
            return LPAREN;
        else if (in_char == ')')
            return RPAREN;
        else if (in_char == ';')
            return SEMICOLON;
        else if (in_char == ',')
            return COMMA;
        else if (in_char == '|')
            return CONDITIONAL;
        else if (in_char == '+')
            return PLUSOP;
        else if (in_char == ':') {
            c = fgetc(source);
            if (c == '=')
                return ASSIGNOP;
            else {
                if (c != EOF)
                    ungetc(c, source);
                lexical_error(in_char);
            }
        }
        else if (in_char == '-') {
            c = fgetc(source);
            if (c == '-') {
                do {
                    in_char = fgetc(source);
                    if (in_char == '\n') {
                        line++;
                    }
                } 
                while (in_char != '\n' && in_char != EOF);
                if (in_char == EOF)
                    return SCANEOF;
            }
            else {
                if (c != EOF)
                    ungetc(c, source);
                return MINUSOP;
            }
        }
        else if (in_char == '_' && buffer_index == 0) {
            fprintf(stderr, "Lexical error at line %d: Identifier starting with a \'_\'\n", line);
            remove("data_file");
            remove("bss_file");
            remove("text_file");
            exit(EXIT_FAILURE);
        }
        else
            lexical_error(in_char);
    }
    return SCANEOF;
}

char* extract_token(token t) {
    switch (t) {
        case BEGIN:
            return "BEGIN";
            break;
        case END:
            return "END";
            break;
        case READ:
            return "READ";
            break;
        case WRITE:
            return "WRITE";
            break;
        case ID:
            return "ID";
            break;
        case INTLITERAL:
            return "INTLITERAL";
            break;
        case LPAREN:
            return "LPAREN";
            break;
        case RPAREN:
            return "RPAREN";
            break;
        case SEMICOLON:
            return "SEMICOLON";
            break;
        case COMMA:
            return "COMMA";
            break;
        case ASSIGNOP:
            return "ASSIGNOP";
            break;
        case PLUSOP:
            return "PLUSOP";
            break;
        case MINUSOP:
            return "MINUSOP";
            break;
        case CONDITIONAL:
            return "CONDITIONAL";
            break;
        case SCANEOF:
            return "SCANEOF";
            break;
    }
}