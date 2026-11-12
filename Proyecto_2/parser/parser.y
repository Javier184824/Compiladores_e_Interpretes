%{
#include <stdio.h>
#include "location.h"
#include "typedef_support.h"

int yylex(void);
void yyerror(const char *s);

extern int yylineno; 
%}
%code requires {
    #include "typedef_support.h"
}

%define api.value.type {ParserValue}

%define parse.trace
%define parse.error detailed
%define parse.lac full
%locations

%token TOKEN_SYSTEM_INCLUDE 1
%token TOKEN_LOCAL_INCLUDE 2
%token FUNCTION_MACRO 3
%token OBJECT_MACRO 4
%token SINGLE_LINE_COMMENT 5
%token MULTILINE_COMMENT 6

%token <text> TOKEN_ID 63
%token <text> TOKEN_TYPE_NAME 300
%token TOKEN_INTEGER 64
%token TOKEN_FLOAT 65
%token TOKEN_CHARACTER 66
%token TOKEN_STRING 67
%token TOKEN_SIZEOF 29

%token TOKEN_ARROW 107
%token TOKEN_INCREMENT 75
%token TOKEN_DECREMENT 76
%token TOKEN_LEFT_SHIFT 97
%token TOKEN_RIGHT_SHIFT 98
%token TOKEN_LESS_EQUAL 86
%token TOKEN_GREATER_EQUAL 87
%token TOKEN_EQUAL 82
%token TOKEN_DIFFERENT 83
%token TOKEN_LOGICAL_AND 68
%token TOKEN_LOGICAL_OR 69
%token TOKEN_MULT_ASSIGN 91
%token TOKEN_DIV_ASSIGN 92
%token TOKEN_MOD_ASSIGN 93
%token TOKEN_PLUS_ASSIGN 89
%token TOKEN_MINUS_ASSIGN 90
%token TOKEN_LEFT_SHIFT_ASSIGN 99
%token TOKEN_RIGHT_SHIFT_ASSIGN 100
%token TOKEN_AND_ASSIGN 94
%token TOKEN_XOR_ASSIGN 96
%token TOKEN_OR_ASSIGN 95

%token TOKEN_TYPEDEF 33
%token TOKEN_EXTERN 18
%token TOKEN_STATIC 30
%token TOKEN_AUTO 7
%token TOKEN_REGISTER 25

%token TOKEN_INLINE 41
%token TOKEN_RESTRICT 42
%token TOKEN_BOOL_KEYWORD 43
%token TOKEN_COMPLEX 44

%token TOKEN_ALIGNAS 46
%token TOKEN_ALIGNOF 47
%token TOKEN_ATOMIC 48
%token TOKEN_GENERIC 49
%token TOKEN_NORETURN 50
%token TOKEN_STATIC_ASSERT 51
%token TOKEN_THREAD_LOCAL 52

%token TOKEN_CHAR_KEYWORD 10
%token TOKEN_SHORT 27
%token TOKEN_INT_KEYWORD 23
%token TOKEN_LONG 24
%token TOKEN_SIGNED 28
%token TOKEN_UNSIGNED 35
%token TOKEN_FLOAT_KEYWORD 19
%token TOKEN_DOUBLE_KEYWORD 15
%token TOKEN_CONST 11
%token TOKEN_VOLATILE 37
%token TOKEN_VOID 36
%token TOKEN_STRUCT 31
%token TOKEN_UNION 34
%token TOKEN_ENUM 17
%token TOKEN_ELLIPSIS 111

%token TOKEN_CASE 9
%token TOKEN_DEFAULT 13
%token TOKEN_IF 22
%token TOKEN_ELSE 16
%token TOKEN_SWITCH 32
%token TOKEN_WHILE 38
%token TOKEN_DO 14
%token TOKEN_FOR 20
%token TOKEN_GOTO 21
%token TOKEN_CONTINUE 12
%token TOKEN_BREAK 8
%token TOKEN_RETURN 26

%token TOKEN_LEFT_PAREN 101
%token TOKEN_RIGHT_PAREN 102
%token TOKEN_LEFT_CURLY 103
%token TOKEN_RIGHT_CURLY 104
%token TOKEN_LEFT_SQUARE 105
%token TOKEN_RIGHT_SQUARE 106
%token TOKEN_QUESTION 108
%token TOKEN_COLON 109
%token TOKEN_PERIOD 112
%token TOKEN_COMMA 113
%token TOKEN_SEMICOLON 114

%token TOKEN_BITWISE_AND 70
%token TOKEN_BITWISE_OR 71
%token TOKEN_BITWISE_XOR 72
%token TOKEN_BITWISE_NOT 73
%token TOKEN_NOT 74
%token TOKEN_PLUS 77
%token TOKEN_MINUS 78
%token TOKEN_MULT 79
%token TOKEN_DIV 80
%token TOKEN_MOD 81
%token TOKEN_LESS 84
%token TOKEN_GREATER 85
%token TOKEN_ASSIGN 88
%type <text> declarator direct_declarator

%type <is_typedef> declaration_specifiers
%type <is_typedef> storage_class_specifier

%type <names> init_declarator init_declarator_list

%destructor { free_name_list($$); } <names>
%start translation_unit


%%

primary_expression
        : TOKEN_ID
        | TOKEN_INTEGER
        | TOKEN_FLOAT
        | TOKEN_CHARACTER
        | str_sequence
        | TOKEN_LEFT_PAREN expression TOKEN_RIGHT_PAREN
        | generic_selection
        ;

include_manager
        :TOKEN_SYSTEM_INCLUDE
        |TOKEN_LOCAL_INCLUDE
        ;

define_manager
        :FUNCTION_MACRO
        |OBJECT_MACRO
        ;

comment_manager
        :SINGLE_LINE_COMMENT
        |MULTILINE_COMMENT
        ;

str_sequence
        :TOKEN_STRING
        |TOKEN_STRING str_sequence
        ;

static_assert_declaration
    : TOKEN_STATIC_ASSERT TOKEN_LEFT_PAREN
      constant_expression TOKEN_COMMA str_sequence
      TOKEN_RIGHT_PAREN TOKEN_SEMICOLON
    ;

generic_selection
    : TOKEN_GENERIC TOKEN_LEFT_PAREN
      assignment_expression TOKEN_COMMA
      generic_assoc_list TOKEN_RIGHT_PAREN
    ;

generic_assoc_list
    : generic_association
    | generic_assoc_list TOKEN_COMMA generic_association
    ;

generic_association
    : type_name TOKEN_COLON assignment_expression
    | TOKEN_DEFAULT TOKEN_COLON assignment_expression
    ;

postfix_expression
        : primary_expression
        | TOKEN_LEFT_PAREN type_name TOKEN_RIGHT_PAREN TOKEN_LEFT_CURLY initializer_list TOKEN_RIGHT_CURLY
        | TOKEN_LEFT_PAREN type_name TOKEN_RIGHT_PAREN TOKEN_LEFT_CURLY initializer_list TOKEN_COMMA TOKEN_RIGHT_CURLY
        | postfix_expression TOKEN_LEFT_SQUARE expression TOKEN_RIGHT_SQUARE
        | postfix_expression TOKEN_LEFT_PAREN TOKEN_RIGHT_PAREN
        | postfix_expression TOKEN_LEFT_PAREN argument_expression_list TOKEN_RIGHT_PAREN
        | postfix_expression TOKEN_PERIOD TOKEN_ID
        | postfix_expression TOKEN_ARROW TOKEN_ID
        | postfix_expression TOKEN_INCREMENT
        | postfix_expression TOKEN_DECREMENT
        ;

argument_expression_list
        : assignment_expression
        | argument_expression_list TOKEN_COMMA assignment_expression
        ;

unary_expression
        : postfix_expression
        | TOKEN_INCREMENT unary_expression
        | TOKEN_DECREMENT unary_expression
        | unary_operator cast_expression
        | TOKEN_SIZEOF unary_expression
        | TOKEN_SIZEOF TOKEN_LEFT_PAREN type_name TOKEN_RIGHT_PAREN
        | TOKEN_ALIGNOF TOKEN_LEFT_PAREN type_name TOKEN_RIGHT_PAREN
        ;

unary_operator
        : TOKEN_BITWISE_AND
        | TOKEN_MULT
        | TOKEN_PLUS
        | TOKEN_MINUS
        | TOKEN_BITWISE_NOT
        | TOKEN_NOT
        ;

cast_expression
        : unary_expression
        | TOKEN_LEFT_PAREN type_name TOKEN_RIGHT_PAREN cast_expression
        ;

multiplicative_expression
        : cast_expression
        | multiplicative_expression TOKEN_MULT cast_expression
        | multiplicative_expression TOKEN_DIV cast_expression
        | multiplicative_expression TOKEN_MOD cast_expression
        ;

additive_expression
        : multiplicative_expression
        | additive_expression TOKEN_PLUS multiplicative_expression
        | additive_expression TOKEN_MINUS multiplicative_expression
        ;

shift_expression
        : additive_expression
        | shift_expression TOKEN_LEFT_SHIFT additive_expression
        | shift_expression TOKEN_RIGHT_SHIFT additive_expression
        ;

relational_expression
        : shift_expression
        | relational_expression TOKEN_LESS shift_expression
        | relational_expression TOKEN_GREATER shift_expression
        | relational_expression TOKEN_LESS_EQUAL shift_expression
        | relational_expression TOKEN_GREATER_EQUAL shift_expression
        ;

equality_expression
        : relational_expression
        | equality_expression TOKEN_EQUAL relational_expression
        | equality_expression TOKEN_DIFFERENT relational_expression
        ;

and_expression
        : equality_expression
        | and_expression TOKEN_BITWISE_AND equality_expression
        ;

exclusive_or_expression
        : and_expression
        | exclusive_or_expression TOKEN_BITWISE_XOR and_expression
        ;

inclusive_or_expression
        : exclusive_or_expression
        | inclusive_or_expression TOKEN_BITWISE_OR exclusive_or_expression
        ;

logical_and_expression
        : inclusive_or_expression
        | logical_and_expression TOKEN_LOGICAL_AND inclusive_or_expression
        ;

logical_or_expression
        : logical_and_expression
        | logical_or_expression TOKEN_LOGICAL_OR logical_and_expression
        ;

conditional_expression
        : logical_or_expression
        | logical_or_expression TOKEN_QUESTION expression TOKEN_COLON conditional_expression
        ;

assignment_expression
        : conditional_expression
        | unary_expression assignment_operator assignment_expression
        ;

assignment_operator
        : TOKEN_ASSIGN
        | TOKEN_MULT_ASSIGN
        | TOKEN_DIV_ASSIGN
        | TOKEN_MOD_ASSIGN
        | TOKEN_PLUS_ASSIGN
        | TOKEN_MINUS_ASSIGN
        | TOKEN_LEFT_SHIFT_ASSIGN
        | TOKEN_RIGHT_SHIFT_ASSIGN
        | TOKEN_AND_ASSIGN
        | TOKEN_XOR_ASSIGN
        | TOKEN_OR_ASSIGN
        ;

expression
        : assignment_expression
        | expression TOKEN_COMMA assignment_expression
        ;

constant_expression
        : conditional_expression
        ;

declaration
        : declaration_specifiers TOKEN_SEMICOLON
        | declaration_specifiers init_declarator_list TOKEN_SEMICOLON { finish_declaration($1, $2); }
        | error TOKEN_SEMICOLON { /* very important one */ yyerrok; }
        | static_assert_declaration
        ;

declaration_specifiers
    : storage_class_specifier { $$ = $1; }
    | storage_class_specifier declaration_specifiers { $$ = $1 || $2; }
    | type_specifier { $$ = 0; }
    | type_specifier declaration_specifiers { $$ = $2; }
    | type_qualifier { $$ = 0; }
    | type_qualifier declaration_specifiers { $$ = $2; }
    | function_specifier { $$ = 0; }
    | function_specifier declaration_specifiers { $$ = $2; }
    | alignment_specifier { $$ = 0; }
    | alignment_specifier declaration_specifiers { $$ = $2; }
    ;

init_declarator_list
    : init_declarator { $$ = $1; }
    | init_declarator_list TOKEN_COMMA init_declarator { $$ = join_name_lists($1, $3); }
    ;

init_declarator
    : declarator { $$ = make_name_list($1); }
    | declarator TOKEN_ASSIGN initializer { $$ = make_name_list($1); }
    ;

storage_class_specifier
    : TOKEN_TYPEDEF      { $$ = 1; }
    | TOKEN_EXTERN       { $$ = 0; }
    | TOKEN_STATIC       { $$ = 0; }
    | TOKEN_AUTO         { $$ = 0; }
    | TOKEN_REGISTER     { $$ = 0; }
    | TOKEN_THREAD_LOCAL { $$ = 0; }
    ;

type_specifier
        : TOKEN_VOID
        | TOKEN_CHAR_KEYWORD
        | TOKEN_SHORT
        | TOKEN_INT_KEYWORD
        | TOKEN_LONG
        | TOKEN_FLOAT_KEYWORD
        | TOKEN_DOUBLE_KEYWORD
        | TOKEN_SIGNED
        | TOKEN_UNSIGNED
        | TOKEN_BOOL_KEYWORD
        | TOKEN_COMPLEX
        | atomic_type_specifier
        | struct_or_union_specifier
        | enum_specifier
        | TOKEN_TYPE_NAME
        ;

alignment_specifier
    : TOKEN_ALIGNAS TOKEN_LEFT_PAREN type_name TOKEN_RIGHT_PAREN
    | TOKEN_ALIGNAS TOKEN_LEFT_PAREN constant_expression TOKEN_RIGHT_PAREN
    ;

function_specifier
    : TOKEN_INLINE
    | TOKEN_NORETURN
    ;

struct_or_union_specifier
        : struct_or_union TOKEN_ID TOKEN_LEFT_CURLY struct_declaration_list TOKEN_RIGHT_CURLY
        | struct_or_union TOKEN_LEFT_CURLY struct_declaration_list TOKEN_RIGHT_CURLY
        | struct_or_union TOKEN_ID
        ;

struct_or_union
        : TOKEN_STRUCT
        | TOKEN_UNION
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : specifier_qualifier_list struct_declarator_list TOKEN_SEMICOLON
        | static_assert_declaration
        | specifier_qualifier_list TOKEN_SEMICOLON
        | error TOKEN_SEMICOLON { yyerrok; }
        ;

specifier_qualifier_list
        : type_specifier specifier_qualifier_list
        | type_specifier
        | type_qualifier specifier_qualifier_list
        | type_qualifier
        ;

struct_declarator_list
        : struct_declarator
        | struct_declarator_list TOKEN_COMMA struct_declarator
        ;

struct_declarator
        : declarator
        | TOKEN_COLON constant_expression
        | declarator TOKEN_COLON constant_expression
        ;

enum_specifier
        : TOKEN_ENUM TOKEN_LEFT_CURLY enumerator_list TOKEN_RIGHT_CURLY
        | TOKEN_ENUM TOKEN_LEFT_CURLY enumerator_list TOKEN_COMMA TOKEN_RIGHT_CURLY
        | TOKEN_ENUM TOKEN_ID TOKEN_LEFT_CURLY enumerator_list TOKEN_COMMA TOKEN_RIGHT_CURLY
        | TOKEN_ENUM TOKEN_ID TOKEN_LEFT_CURLY enumerator_list TOKEN_RIGHT_CURLY
        | TOKEN_ENUM TOKEN_ID
        ;

enumerator_list
        : enumerator
        | enumerator_list TOKEN_COMMA enumerator
        ;

enumerator
        : TOKEN_ID
        | TOKEN_ID TOKEN_ASSIGN constant_expression
        ;

type_qualifier
        : TOKEN_CONST
        | TOKEN_VOLATILE
        | TOKEN_RESTRICT
        | TOKEN_ATOMIC
        ;

atomic_type_specifier
    : TOKEN_ATOMIC TOKEN_LEFT_PAREN type_name TOKEN_RIGHT_PAREN
    ;

declarator
    : pointer direct_declarator { $$ = $2; }
    | direct_declarator { $$ = $1; }
    ;

direct_declarator
    : TOKEN_ID { $$ = $1; }
    | TOKEN_LEFT_PAREN declarator TOKEN_RIGHT_PAREN { $$ = $2; }
    | direct_declarator array_suffix { $$ = $1; }
    | direct_declarator TOKEN_LEFT_PAREN parameter_type_list TOKEN_RIGHT_PAREN { $$ = $1; }
    | direct_declarator TOKEN_LEFT_PAREN identifier_list TOKEN_RIGHT_PAREN { $$ = $1; }
    | direct_declarator TOKEN_LEFT_PAREN TOKEN_RIGHT_PAREN { $$ = $1; }
    ;


pointer
        : TOKEN_MULT
        | TOKEN_MULT type_qualifier_list
        | TOKEN_MULT pointer
        | TOKEN_MULT type_qualifier_list pointer
        ;

type_qualifier_list
        : type_qualifier
        | type_qualifier_list type_qualifier
        ;


parameter_type_list
        : parameter_list
        | parameter_list TOKEN_COMMA TOKEN_ELLIPSIS
        ;

parameter_list
        : parameter_declaration
        | parameter_list TOKEN_COMMA parameter_declaration
        ;

parameter_declaration
        : declaration_specifiers declarator
        | declaration_specifiers abstract_declarator
        | declaration_specifiers
        ;

identifier_list
        : TOKEN_ID
        | identifier_list TOKEN_COMMA TOKEN_ID
        ;

type_name
        : specifier_qualifier_list
        | specifier_qualifier_list abstract_declarator
        ;

abstract_declarator
        : pointer
        | direct_abstract_declarator
        | pointer direct_abstract_declarator
        ;

direct_abstract_declarator
    : TOKEN_LEFT_PAREN abstract_declarator TOKEN_RIGHT_PAREN
    | array_suffix
    | direct_abstract_declarator array_suffix
    | TOKEN_LEFT_PAREN TOKEN_RIGHT_PAREN
    | TOKEN_LEFT_PAREN parameter_type_list TOKEN_RIGHT_PAREN
    | direct_abstract_declarator TOKEN_LEFT_PAREN TOKEN_RIGHT_PAREN
    | direct_abstract_declarator TOKEN_LEFT_PAREN parameter_type_list TOKEN_RIGHT_PAREN
    ;


array_suffix
    : TOKEN_LEFT_SQUARE type_qualifier_list_opt assignment_expression_opt TOKEN_RIGHT_SQUARE
    | TOKEN_LEFT_SQUARE TOKEN_STATIC type_qualifier_list_opt assignment_expression TOKEN_RIGHT_SQUARE
    | TOKEN_LEFT_SQUARE type_qualifier_list TOKEN_STATIC assignment_expression TOKEN_RIGHT_SQUARE
    | TOKEN_LEFT_SQUARE type_qualifier_list_opt TOKEN_MULT TOKEN_RIGHT_SQUARE
    ;

type_qualifier_list_opt
    : %empty
    | type_qualifier_list
    ;

assignment_expression_opt
    : %empty
    | assignment_expression
    ;

initializer
        : assignment_expression
        | TOKEN_LEFT_CURLY initializer_list TOKEN_RIGHT_CURLY
        | TOKEN_LEFT_CURLY initializer_list TOKEN_COMMA TOKEN_RIGHT_CURLY
        ;

initializer_list
    : initializer
    | designation initializer
    | initializer_list TOKEN_COMMA initializer
    | initializer_list TOKEN_COMMA designation initializer
    ;

designation
    : designator_list TOKEN_ASSIGN
    ;

designator_list
    : designator
    | designator_list designator
    ;

designator
    : TOKEN_LEFT_SQUARE constant_expression TOKEN_RIGHT_SQUARE
    | TOKEN_PERIOD TOKEN_ID
    ;

statement
        : labeled_statement
        | compound_statement
        | expression_statement
        | selection_statement
        | iteration_statement
        | jump_statement
        | error TOKEN_SEMICOLON { yyerrok; }
        ;

labeled_statement
        : TOKEN_ID TOKEN_COLON statement
        | TOKEN_CASE constant_expression TOKEN_COLON statement
        | TOKEN_DEFAULT TOKEN_COLON statement
        ;

compound_statement
    : TOKEN_LEFT_CURLY TOKEN_RIGHT_CURLY
    | TOKEN_LEFT_CURLY block_item_list TOKEN_RIGHT_CURLY
    ;

block_item_list
    : block_item
    | block_item_list block_item
    ;

block_item
    : declaration
    | statement
    ;

declaration_list
        : declaration
        | declaration_list declaration
        ;

statement_list
        : statement
        | statement_list statement
        ;

expression_statement
        : TOKEN_SEMICOLON
        | expression TOKEN_SEMICOLON
        ;

selection_statement
        : TOKEN_IF TOKEN_LEFT_PAREN expression TOKEN_RIGHT_PAREN statement
        | TOKEN_IF TOKEN_LEFT_PAREN expression TOKEN_RIGHT_PAREN statement TOKEN_ELSE statement
        | TOKEN_SWITCH TOKEN_LEFT_PAREN expression TOKEN_RIGHT_PAREN statement
        ;

iteration_statement
        : TOKEN_WHILE TOKEN_LEFT_PAREN expression TOKEN_RIGHT_PAREN statement
        | TOKEN_DO statement TOKEN_WHILE TOKEN_LEFT_PAREN expression TOKEN_RIGHT_PAREN TOKEN_SEMICOLON
        | TOKEN_FOR TOKEN_LEFT_PAREN declaration expression_statement TOKEN_RIGHT_PAREN statement
        | TOKEN_FOR TOKEN_LEFT_PAREN declaration expression_statement expression TOKEN_RIGHT_PAREN statement
        | TOKEN_FOR TOKEN_LEFT_PAREN expression_statement expression_statement TOKEN_RIGHT_PAREN statement
        | TOKEN_FOR TOKEN_LEFT_PAREN expression_statement expression_statement expression TOKEN_RIGHT_PAREN statement
        ;

jump_statement
        : TOKEN_GOTO TOKEN_ID TOKEN_SEMICOLON
        | TOKEN_CONTINUE TOKEN_SEMICOLON
        | TOKEN_BREAK TOKEN_SEMICOLON
        | TOKEN_RETURN TOKEN_SEMICOLON
        | TOKEN_RETURN expression TOKEN_SEMICOLON
        ;

translation_unit
        : external_declaration
        | translation_unit external_declaration
        ;

external_declaration
        : function_definition
        | declaration
        | include_manager 
        | define_manager 
        ;


function_definition
        : declaration_specifiers declarator declaration_list compound_statement
        | declaration_specifiers declarator compound_statement
        | declarator declaration_list compound_statement
        | declarator compound_statement
        ;

/*
function_definition
        : declaration_specifiers declarator compound_statement
        | declarator compound_statement
        ;
*/        


%%
void yyerror(const char *s) {
    fprintf(stderr, "Error in line %d:%d %s\n",
        yylloc.first_line,
        yylloc.first_column,
        s);
}