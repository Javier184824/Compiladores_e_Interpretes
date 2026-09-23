#ifndef SCANNER_H
#define SCANNER_H

#define MAXIDLEN 33
#define MAXCOMMANDLEN 256

extern char token_buffer[MAXIDLEN];
extern char command_buffer[MAXCOMMANDLEN];
extern int line;
extern int in_char;

typedef enum token_types {
    BEGIN, END, READ, WRITE, ID, INTLITERAL,
    LPAREN, RPAREN, SEMICOLON, COMMA, ASSIGNOP,
    PLUSOP, MINUSOP, CONDITIONAL, SCANEOF
} token;

token scanner(void);
char* extract_token(token t);
void get_file(char *filename);

#endif