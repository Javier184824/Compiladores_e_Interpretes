#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../headers/scanner.h"
#include "../headers/parser.h"
#include "../headers/semantic_records.h"
#include "../headers/semantic_routines.h"
#include "../headers/generate.h"

token current_token;
static token lookahead;
static int has_lookahead = 0;

token next_token(void) {
    if (!has_lookahead) {
        lookahead = scanner();
        has_lookahead = 1;
    }

    return lookahead;
}

void match(token t) {
    token received = next_token();
    char* token = extract_token(t);
    
    if (received == t) {
        current_token = received;
        has_lookahead = 0;
    }
    else {
        fprintf(stderr, "Syntax error at line %d: expected token %s\n", line, token);
        syntax_error(received);
    }
}

void syntax_error(token tok) {
    char* token = extract_token(tok);
    fprintf(stderr,
            "Syntax error at line %d: unexpected token %s\n",
            line, token);
    remove("data_file");
    remove("bss_file");
    remove("text_file");
    exit(EXIT_FAILURE);
}

//read(a, b, c) 
// a, b, c lista de identificadores
void id_list(void)
{
    expr_rec id; // placeholder
    //match(ID); esto ya lo hace ident
    ident(&id); 
    read_id(id); // rutina semantica

    while (next_token() == COMMA) { //procesar el resot de ids
        match(COMMA); 
        ///match(ID); esto ya lo hace ident
        ident(&id);
        read_id(id);
    }
}

// reconoce operador (+, -)
void add_op(op_rec *result){
    token tok = next_token();
    if (tok == PLUSOP||tok==MINUSOP) {
        match(tok);
        *result = process_op(); //guardar op_rec generado
    } else {
        syntax_error(tok);
    }
}

void primary(expr_rec *result){
    token tok = next_token();
    switch (tok){
        case LPAREN:
            expr_rec e1, e2, e3; //Se crean e1, 2 y 3 por si hubiese e1 | e2 | e3
            match(LPAREN);
            expression(&e1); //Cuidado acá
            if(next_token()==CONDITIONAL){
                match(CONDITIONAL);
                expression(&e2);
                match(CONDITIONAL);
                expression(&e3);
                match(RPAREN);
                *result = gen_conditional(e1, e2, e3);
            }
            else{
            match(RPAREN);
            *result = e1; //Como e1 fue consumido previamente por expression, se devuelve e1 en vez de llamar a expression porque ya se llamó
            }

            break;
        case ID:
            match(ID);
            *result = process_id(); //convertir a expr_rec
            break;
        case INTLITERAL:
            match(INTLITERAL);
            *result = process_literal(); //convertir a expre_rec
            break;
        default:
            syntax_error(tok);
            break;
    }
}

void expression(expr_rec *result) {
    expr_rec left_operand, right_operand;
    op_rec op;

    primary(& left_operand);
    while(next_token() == PLUSOP || next_token() == MINUSOP) {
        add_op(& op);
        primary(& right_operand);
        left_operand = gen_infix(left_operand, op, right_operand);
    }
    *result = left_operand;
}

// write(a + b, x, n)
void expr_list(void){
    expr_rec expresion; // placeholder

    expression(&expresion); // a + b
    write_expr(expresion); // write

    while(next_token()==COMMA){ // x, luego n, etc
        match(COMMA);
        expression(&expresion);
        write_expr(expresion); 
    }
}

// ID 
void ident(expr_rec *result) {
    match(ID);
    *result = process_id();
}


void statement(void)
{
    token tok = next_token();
    switch (tok) {
        case ID: 
            expr_rec target;
            expr_rec source;
            ident(&target);
            match(ASSIGNOP);
            expression(&source);
            assign(target, source);
            match(SEMICOLON);
            break;

        case READ:
            match(READ);
            match(LPAREN);
            id_list();
            match(RPAREN);
            match(SEMICOLON);
            break;
        case WRITE:
            match(WRITE);
            match(LPAREN);
            expr_list();
            match(RPAREN);
            match(SEMICOLON);
            break;
        default:
            syntax_error(tok);
            break;
    }
}

void statement_list(void)
{
    statement();

    while (1) {
        switch (next_token()) {
            case ID:
            case READ:
            case WRITE:
                statement();
                break;

            default:
                return;
        }
    }
}

void program(void)
{
    start();
    match(BEGIN);
    statement_list();
    match(END);
}

void system_goal(void)
{
    program();
    match(SCANEOF);
    finish();
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    get_file(argv[1]);
    set_output_file(argv[2]);

    system_goal();

    snprintf(command_buffer, MAXCOMMANDLEN, "nasm -f elf64 a.asm -o a.o");
    system(command_buffer);
    
    snprintf(command_buffer, MAXCOMMANDLEN, "gcc -no-pie a.o -o %s", argv[2]);
    system(command_buffer);
    
    snprintf(command_buffer, MAXCOMMANDLEN, "rm a.o");
    system(command_buffer);
    
    snprintf(command_buffer, MAXCOMMANDLEN, "./%s", argv[2]);
    system(command_buffer);

    return 0;
}