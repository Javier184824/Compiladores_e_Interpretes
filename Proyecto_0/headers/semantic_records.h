#ifndef SEMANTIC_RECORDS_H
#define SEMANTIC_RECORDS_H

#define MAXIDLEN 33

typedef char string[MAXIDLEN];

typedef struct operator { /* for operators*/
    enum op { PLUS, MINUS } operator;
} op_rec;

/* expression types */
enum expr { INDEXPR, LITERALEXPR, TEMPEXPR};

/* for <primary> and <expression> */
typedef struct expression {
    enum expr kind;
    union {
        string name; /* for INDEXPR, TEMPEXPR */
        int val; /* for LITERALEXPR */
    };
} expr_rec;


#endif