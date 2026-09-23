#ifndef PARSING_H
#define PARSING_H

#include "scanner.h"
#include "semantic_records.h"

extern token current_token;

token next_token(void);
void match(token t);
void id_list(void);
void add_op(op_rec *result); //*
void primary(expr_rec *result); //*
void expression(expr_rec *result); //*
void expr_list(void);
void ident(expr_rec *result); //**
void statement(void);
void statement_list(void);
void program(void);
void system_goal(void);
void syntax_error(token tok);


#endif