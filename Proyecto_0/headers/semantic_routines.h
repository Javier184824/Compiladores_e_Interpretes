#ifndef SEMANTIC_ROUTINES_H
#define SEMANTIC_ROUTINES_H

#include "semantic_records.h"

char *get_temp(void);

char *extract_expr(expr_rec expr);
char *extract_op(op_rec op);

#define extract(x) _Generic((x), \
    expr_rec: extract_expr,      \
    op_rec: extract_op           \
)(x)

void start(void);
void finish(void);

void assign(expr_rec target, expr_rec source);

op_rec process_op(void);

expr_rec gen_infix(
    expr_rec e1,
    op_rec op,
    expr_rec e2
);

void read_id(expr_rec in_var);

expr_rec process_id(void);

expr_rec process_literal(void);

void write_expr(expr_rec out_expr);

expr_rec gen_conditional(expr_rec condition,expr_rec if_true, expr_rec if_false);

#endif