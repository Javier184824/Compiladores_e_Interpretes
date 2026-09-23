#include <stdio.h>
#include <string.h>

#include "../headers/scanner.h"
#include "../headers/semantic_records.h"
#include "../headers/semantic_routines.h"
#include "../headers/symbol_table.h"
#include "../headers/generate.h"

extern token current_token;
/* paginas 21 a 23 */

/* allocates temporaries */
char *get_temp (void) {
    /* max temporary allocated so far */
    static int max_temp = 0;
    static char tempname[MAXIDLEN];

    max_temp++;
    sprintf(tempname, "Temp&%d", max_temp);
    check_id(tempname);
    return tempname;
}


/*Se viene codigo sin e porque la e del tclado esta MALA, M LLEVA*/
char *extract_op(op_rec op)//Extract OP extrae el oprador de suma o rsta (repito, E MALA)
{
    switch (op.operator){
    case PLUS:
        return "Add";
    case MINUS:
        return "Sub";
    default:
        return "";
    }
}

char *extract_expr(expr_rec expr){
    static string buffers[4];
    static int current_buffer = 0;

    char *result = buffers[current_buffer];
    current_buffer = (current_buffer + 1) % 4;

    switch (expr.kind){
    case INDEXPR:
    case TEMPEXPR:
        strcpy(result, expr.name);
        break;
    case LITERALEXPR:
        sprintf(result,"%d", expr.val);
        break;
    default:
        result[0]='\0';
        break;
    }
    return result;
}
/* auxiliary routines for defining semantic routines */

void start(void) {
    /* semantic initializations, none needed.*/
}

void finish(void) {
    /*generate code to finish program */
    generate("Halt", "", "", "");
}

void assign(expr_rec target, expr_rec source) {
    /* generate code for assignment */
    generate("Store", extract(source), target.name, "");
}

op_rec process_op(void) {
    /* Produce operator descriptor */
    op_rec o;

    if (current_token == PLUSOP)
        o.operator = PLUS;
    else
        o.operator = MINUS;
    return o;
}

expr_rec gen_infix(expr_rec e1, op_rec op, expr_rec e2) {
    expr_rec e_rec;
    /* An expr_rec with temp variant set- */
    e_rec.kind = TEMPEXPR;

    /* 
    Generate code for infix operation.
    Get result temp and set up semantic record for result
    */

    // constant folding
    
    if (e1.kind == LITERALEXPR && e2.kind == LITERALEXPR) {

        if (op.operator == PLUS) e_rec.val = e1.val + e2.val;
        else
        if (op.operator == MINUS) e_rec.val = e1.val - e2.val;

        e_rec.kind = LITERALEXPR;

        //fin constant folding

    } else {
        strcpy(e_rec.name, get_temp());
        generate(extract(op), extract(e1), extract(e2), e_rec.name);
    }
    
    return e_rec;
}

void read_id(expr_rec in_var) {
    /* generate code for read*/
    generate ("Read", in_var.name, "Integer", "");
}

expr_rec process_id(void) {
    expr_rec t;
    /*
    Declare ID and build a corresponding semantic record.
    */
    check_id(token_buffer);
    t.kind = INDEXPR;
    strcpy(t.name, token_buffer);
    return t;
}

expr_rec process_literal(void) {
    expr_rec t;

    /*
    Convert literal to a numeric representation and build 
    semantic record.
    */
    t.kind = LITERALEXPR;
    (void) sscanf(token_buffer, "%d", & t.val);
    return t;
}

void write_expr(expr_rec out_expr) {
    generate("Write", extract(out_expr), "Integer", "");
}

expr_rec gen_conditional(expr_rec condition,expr_rec if_true,expr_rec if_false) {
    expr_rec result;

    result.kind = TEMPEXPR;
    strcpy(result.name, get_temp());

    generate("Store",
             extract(if_true),
             result.name,
             "");

    generate("Skip",
             extract(condition),
             "",
             "");

    generate("Store",
             extract(if_false),
             result.name,
             "");

    return result;
}
