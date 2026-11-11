/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_PARSER_H_INCLUDED
# define YY_YY_PARSER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 11 "parser/parser.y"

    #include "typedef_support.h"

#line 53 "parser/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 301,                 /* "invalid token"  */
    TOKEN_ID = 63,                 /* TOKEN_ID  */
    TOKEN_TYPE_NAME = 300,         /* TOKEN_TYPE_NAME  */
    TOKEN_INTEGER = 64,            /* TOKEN_INTEGER  */
    TOKEN_FLOAT = 65,              /* TOKEN_FLOAT  */
    TOKEN_CHARACTER = 66,          /* TOKEN_CHARACTER  */
    TOKEN_STRING = 67,             /* TOKEN_STRING  */
    TOKEN_SIZEOF = 29,             /* TOKEN_SIZEOF  */
    TOKEN_ARROW = 107,             /* TOKEN_ARROW  */
    TOKEN_INCREMENT = 75,          /* TOKEN_INCREMENT  */
    TOKEN_DECREMENT = 76,          /* TOKEN_DECREMENT  */
    TOKEN_LEFT_SHIFT = 97,         /* TOKEN_LEFT_SHIFT  */
    TOKEN_RIGHT_SHIFT = 98,        /* TOKEN_RIGHT_SHIFT  */
    TOKEN_LESS_EQUAL = 86,         /* TOKEN_LESS_EQUAL  */
    TOKEN_GREATER_EQUAL = 87,      /* TOKEN_GREATER_EQUAL  */
    TOKEN_EQUAL = 82,              /* TOKEN_EQUAL  */
    TOKEN_DIFFERENT = 83,          /* TOKEN_DIFFERENT  */
    TOKEN_LOGICAL_AND = 68,        /* TOKEN_LOGICAL_AND  */
    TOKEN_LOGICAL_OR = 69,         /* TOKEN_LOGICAL_OR  */
    TOKEN_MULT_ASSIGN = 91,        /* TOKEN_MULT_ASSIGN  */
    TOKEN_DIV_ASSIGN = 92,         /* TOKEN_DIV_ASSIGN  */
    TOKEN_MOD_ASSIGN = 93,         /* TOKEN_MOD_ASSIGN  */
    TOKEN_PLUS_ASSIGN = 89,        /* TOKEN_PLUS_ASSIGN  */
    TOKEN_MINUS_ASSIGN = 90,       /* TOKEN_MINUS_ASSIGN  */
    TOKEN_LEFT_SHIFT_ASSIGN = 99,  /* TOKEN_LEFT_SHIFT_ASSIGN  */
    TOKEN_RIGHT_SHIFT_ASSIGN = 100, /* TOKEN_RIGHT_SHIFT_ASSIGN  */
    TOKEN_AND_ASSIGN = 94,         /* TOKEN_AND_ASSIGN  */
    TOKEN_XOR_ASSIGN = 96,         /* TOKEN_XOR_ASSIGN  */
    TOKEN_OR_ASSIGN = 95,          /* TOKEN_OR_ASSIGN  */
    TOKEN_TYPEDEF = 33,            /* TOKEN_TYPEDEF  */
    TOKEN_EXTERN = 18,             /* TOKEN_EXTERN  */
    TOKEN_STATIC = 30,             /* TOKEN_STATIC  */
    TOKEN_AUTO = 7,                /* TOKEN_AUTO  */
    TOKEN_REGISTER = 25,           /* TOKEN_REGISTER  */
    TOKEN_INLINE = 41,             /* TOKEN_INLINE  */
    TOKEN_RESTRICT = 42,           /* TOKEN_RESTRICT  */
    TOKEN_BOOL_KEYWORD = 43,       /* TOKEN_BOOL_KEYWORD  */
    TOKEN_COMPLEX = 44,            /* TOKEN_COMPLEX  */
    TOKEN_ALIGNAS = 46,            /* TOKEN_ALIGNAS  */
    TOKEN_ALIGNOF = 47,            /* TOKEN_ALIGNOF  */
    TOKEN_ATOMIC = 48,             /* TOKEN_ATOMIC  */
    TOKEN_GENERIC = 49,            /* TOKEN_GENERIC  */
    TOKEN_NORETURN = 50,           /* TOKEN_NORETURN  */
    TOKEN_STATIC_ASSERT = 51,      /* TOKEN_STATIC_ASSERT  */
    TOKEN_THREAD_LOCAL = 52,       /* TOKEN_THREAD_LOCAL  */
    TOKEN_CHAR_KEYWORD = 10,       /* TOKEN_CHAR_KEYWORD  */
    TOKEN_SHORT = 27,              /* TOKEN_SHORT  */
    TOKEN_INT_KEYWORD = 23,        /* TOKEN_INT_KEYWORD  */
    TOKEN_LONG = 24,               /* TOKEN_LONG  */
    TOKEN_SIGNED = 28,             /* TOKEN_SIGNED  */
    TOKEN_UNSIGNED = 35,           /* TOKEN_UNSIGNED  */
    TOKEN_FLOAT_KEYWORD = 19,      /* TOKEN_FLOAT_KEYWORD  */
    TOKEN_DOUBLE_KEYWORD = 15,     /* TOKEN_DOUBLE_KEYWORD  */
    TOKEN_CONST = 11,              /* TOKEN_CONST  */
    TOKEN_VOLATILE = 37,           /* TOKEN_VOLATILE  */
    TOKEN_VOID = 36,               /* TOKEN_VOID  */
    TOKEN_STRUCT = 31,             /* TOKEN_STRUCT  */
    TOKEN_UNION = 34,              /* TOKEN_UNION  */
    TOKEN_ENUM = 17,               /* TOKEN_ENUM  */
    TOKEN_ELLIPSIS = 111,          /* TOKEN_ELLIPSIS  */
    TOKEN_CASE = 9,                /* TOKEN_CASE  */
    TOKEN_DEFAULT = 13,            /* TOKEN_DEFAULT  */
    TOKEN_IF = 22,                 /* TOKEN_IF  */
    TOKEN_ELSE = 16,               /* TOKEN_ELSE  */
    TOKEN_SWITCH = 32,             /* TOKEN_SWITCH  */
    TOKEN_WHILE = 38,              /* TOKEN_WHILE  */
    TOKEN_DO = 14,                 /* TOKEN_DO  */
    TOKEN_FOR = 20,                /* TOKEN_FOR  */
    TOKEN_GOTO = 21,               /* TOKEN_GOTO  */
    TOKEN_CONTINUE = 12,           /* TOKEN_CONTINUE  */
    TOKEN_BREAK = 8,               /* TOKEN_BREAK  */
    TOKEN_RETURN = 26,             /* TOKEN_RETURN  */
    TOKEN_LEFT_PAREN = 101,        /* TOKEN_LEFT_PAREN  */
    TOKEN_RIGHT_PAREN = 102,       /* TOKEN_RIGHT_PAREN  */
    TOKEN_LEFT_CURLY = 103,        /* TOKEN_LEFT_CURLY  */
    TOKEN_RIGHT_CURLY = 104,       /* TOKEN_RIGHT_CURLY  */
    TOKEN_LEFT_SQUARE = 105,       /* TOKEN_LEFT_SQUARE  */
    TOKEN_RIGHT_SQUARE = 106,      /* TOKEN_RIGHT_SQUARE  */
    TOKEN_QUESTION = 108,          /* TOKEN_QUESTION  */
    TOKEN_COLON = 109,             /* TOKEN_COLON  */
    TOKEN_PERIOD = 112,            /* TOKEN_PERIOD  */
    TOKEN_COMMA = 113,             /* TOKEN_COMMA  */
    TOKEN_SEMICOLON = 114,         /* TOKEN_SEMICOLON  */
    TOKEN_BITWISE_AND = 70,        /* TOKEN_BITWISE_AND  */
    TOKEN_BITWISE_OR = 71,         /* TOKEN_BITWISE_OR  */
    TOKEN_BITWISE_XOR = 72,        /* TOKEN_BITWISE_XOR  */
    TOKEN_BITWISE_NOT = 73,        /* TOKEN_BITWISE_NOT  */
    TOKEN_NOT = 74,                /* TOKEN_NOT  */
    TOKEN_PLUS = 77,               /* TOKEN_PLUS  */
    TOKEN_MINUS = 78,              /* TOKEN_MINUS  */
    TOKEN_MULT = 79,               /* TOKEN_MULT  */
    TOKEN_DIV = 80,                /* TOKEN_DIV  */
    TOKEN_MOD = 81,                /* TOKEN_MOD  */
    TOKEN_LESS = 84,               /* TOKEN_LESS  */
    TOKEN_GREATER = 85,            /* TOKEN_GREATER  */
    TOKEN_ASSIGN = 88              /* TOKEN_ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef ParserValue YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_H_INCLUDED  */
