/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser/parser.y"

#include <stdio.h>
#include "location.h"
#include "typedef_support.h"

int yylex(void);
void yyerror(const char *s);

extern int yylineno; 

#line 82 "parser/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_ID = 3,                   /* TOKEN_ID  */
  YYSYMBOL_TOKEN_TYPE_NAME = 4,            /* TOKEN_TYPE_NAME  */
  YYSYMBOL_TOKEN_INTEGER = 5,              /* TOKEN_INTEGER  */
  YYSYMBOL_TOKEN_FLOAT = 6,                /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_CHARACTER = 7,            /* TOKEN_CHARACTER  */
  YYSYMBOL_TOKEN_STRING = 8,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_SIZEOF = 9,               /* TOKEN_SIZEOF  */
  YYSYMBOL_TOKEN_ARROW = 10,               /* TOKEN_ARROW  */
  YYSYMBOL_TOKEN_INCREMENT = 11,           /* TOKEN_INCREMENT  */
  YYSYMBOL_TOKEN_DECREMENT = 12,           /* TOKEN_DECREMENT  */
  YYSYMBOL_TOKEN_LEFT_SHIFT = 13,          /* TOKEN_LEFT_SHIFT  */
  YYSYMBOL_TOKEN_RIGHT_SHIFT = 14,         /* TOKEN_RIGHT_SHIFT  */
  YYSYMBOL_TOKEN_LESS_EQUAL = 15,          /* TOKEN_LESS_EQUAL  */
  YYSYMBOL_TOKEN_GREATER_EQUAL = 16,       /* TOKEN_GREATER_EQUAL  */
  YYSYMBOL_TOKEN_EQUAL = 17,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_DIFFERENT = 18,           /* TOKEN_DIFFERENT  */
  YYSYMBOL_TOKEN_LOGICAL_AND = 19,         /* TOKEN_LOGICAL_AND  */
  YYSYMBOL_TOKEN_LOGICAL_OR = 20,          /* TOKEN_LOGICAL_OR  */
  YYSYMBOL_TOKEN_MULT_ASSIGN = 21,         /* TOKEN_MULT_ASSIGN  */
  YYSYMBOL_TOKEN_DIV_ASSIGN = 22,          /* TOKEN_DIV_ASSIGN  */
  YYSYMBOL_TOKEN_MOD_ASSIGN = 23,          /* TOKEN_MOD_ASSIGN  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 24,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 25,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_LEFT_SHIFT_ASSIGN = 26,   /* TOKEN_LEFT_SHIFT_ASSIGN  */
  YYSYMBOL_TOKEN_RIGHT_SHIFT_ASSIGN = 27,  /* TOKEN_RIGHT_SHIFT_ASSIGN  */
  YYSYMBOL_TOKEN_AND_ASSIGN = 28,          /* TOKEN_AND_ASSIGN  */
  YYSYMBOL_TOKEN_XOR_ASSIGN = 29,          /* TOKEN_XOR_ASSIGN  */
  YYSYMBOL_TOKEN_OR_ASSIGN = 30,           /* TOKEN_OR_ASSIGN  */
  YYSYMBOL_TOKEN_TYPEDEF = 31,             /* TOKEN_TYPEDEF  */
  YYSYMBOL_TOKEN_EXTERN = 32,              /* TOKEN_EXTERN  */
  YYSYMBOL_TOKEN_STATIC = 33,              /* TOKEN_STATIC  */
  YYSYMBOL_TOKEN_AUTO = 34,                /* TOKEN_AUTO  */
  YYSYMBOL_TOKEN_REGISTER = 35,            /* TOKEN_REGISTER  */
  YYSYMBOL_TOKEN_INLINE = 36,              /* TOKEN_INLINE  */
  YYSYMBOL_TOKEN_RESTRICT = 37,            /* TOKEN_RESTRICT  */
  YYSYMBOL_TOKEN_BOOL_KEYWORD = 38,        /* TOKEN_BOOL_KEYWORD  */
  YYSYMBOL_TOKEN_COMPLEX = 39,             /* TOKEN_COMPLEX  */
  YYSYMBOL_TOKEN_ALIGNAS = 40,             /* TOKEN_ALIGNAS  */
  YYSYMBOL_TOKEN_ALIGNOF = 41,             /* TOKEN_ALIGNOF  */
  YYSYMBOL_TOKEN_ATOMIC = 42,              /* TOKEN_ATOMIC  */
  YYSYMBOL_TOKEN_GENERIC = 43,             /* TOKEN_GENERIC  */
  YYSYMBOL_TOKEN_NORETURN = 44,            /* TOKEN_NORETURN  */
  YYSYMBOL_TOKEN_STATIC_ASSERT = 45,       /* TOKEN_STATIC_ASSERT  */
  YYSYMBOL_TOKEN_THREAD_LOCAL = 46,        /* TOKEN_THREAD_LOCAL  */
  YYSYMBOL_TOKEN_CHAR_KEYWORD = 47,        /* TOKEN_CHAR_KEYWORD  */
  YYSYMBOL_TOKEN_SHORT = 48,               /* TOKEN_SHORT  */
  YYSYMBOL_TOKEN_INT_KEYWORD = 49,         /* TOKEN_INT_KEYWORD  */
  YYSYMBOL_TOKEN_LONG = 50,                /* TOKEN_LONG  */
  YYSYMBOL_TOKEN_SIGNED = 51,              /* TOKEN_SIGNED  */
  YYSYMBOL_TOKEN_UNSIGNED = 52,            /* TOKEN_UNSIGNED  */
  YYSYMBOL_TOKEN_FLOAT_KEYWORD = 53,       /* TOKEN_FLOAT_KEYWORD  */
  YYSYMBOL_TOKEN_DOUBLE_KEYWORD = 54,      /* TOKEN_DOUBLE_KEYWORD  */
  YYSYMBOL_TOKEN_CONST = 55,               /* TOKEN_CONST  */
  YYSYMBOL_TOKEN_VOLATILE = 56,            /* TOKEN_VOLATILE  */
  YYSYMBOL_TOKEN_VOID = 57,                /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_STRUCT = 58,              /* TOKEN_STRUCT  */
  YYSYMBOL_TOKEN_UNION = 59,               /* TOKEN_UNION  */
  YYSYMBOL_TOKEN_ENUM = 60,                /* TOKEN_ENUM  */
  YYSYMBOL_TOKEN_ELLIPSIS = 61,            /* TOKEN_ELLIPSIS  */
  YYSYMBOL_TOKEN_CASE = 62,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 63,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_IF = 64,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 65,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_SWITCH = 66,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_WHILE = 67,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 68,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_FOR = 69,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_GOTO = 70,                /* TOKEN_GOTO  */
  YYSYMBOL_TOKEN_CONTINUE = 71,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_BREAK = 72,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_RETURN = 73,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_LEFT_PAREN = 74,          /* TOKEN_LEFT_PAREN  */
  YYSYMBOL_TOKEN_RIGHT_PAREN = 75,         /* TOKEN_RIGHT_PAREN  */
  YYSYMBOL_TOKEN_LEFT_CURLY = 76,          /* TOKEN_LEFT_CURLY  */
  YYSYMBOL_TOKEN_RIGHT_CURLY = 77,         /* TOKEN_RIGHT_CURLY  */
  YYSYMBOL_TOKEN_LEFT_SQUARE = 78,         /* TOKEN_LEFT_SQUARE  */
  YYSYMBOL_TOKEN_RIGHT_SQUARE = 79,        /* TOKEN_RIGHT_SQUARE  */
  YYSYMBOL_TOKEN_QUESTION = 80,            /* TOKEN_QUESTION  */
  YYSYMBOL_TOKEN_COLON = 81,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_PERIOD = 82,              /* TOKEN_PERIOD  */
  YYSYMBOL_TOKEN_COMMA = 83,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_SEMICOLON = 84,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_BITWISE_AND = 85,         /* TOKEN_BITWISE_AND  */
  YYSYMBOL_TOKEN_BITWISE_OR = 86,          /* TOKEN_BITWISE_OR  */
  YYSYMBOL_TOKEN_BITWISE_XOR = 87,         /* TOKEN_BITWISE_XOR  */
  YYSYMBOL_TOKEN_BITWISE_NOT = 88,         /* TOKEN_BITWISE_NOT  */
  YYSYMBOL_TOKEN_NOT = 89,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_PLUS = 90,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 91,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULT = 92,                /* TOKEN_MULT  */
  YYSYMBOL_TOKEN_DIV = 93,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_MOD = 94,                 /* TOKEN_MOD  */
  YYSYMBOL_TOKEN_LESS = 95,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_GREATER = 96,             /* TOKEN_GREATER  */
  YYSYMBOL_TOKEN_ASSIGN = 97,              /* TOKEN_ASSIGN  */
  YYSYMBOL_YYACCEPT = 98,                  /* $accept  */
  YYSYMBOL_primary_expression = 99,        /* primary_expression  */
  YYSYMBOL_str_sequence = 100,             /* str_sequence  */
  YYSYMBOL_static_assert_declaration = 101, /* static_assert_declaration  */
  YYSYMBOL_generic_selection = 102,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 103,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 104,      /* generic_association  */
  YYSYMBOL_postfix_expression = 105,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 106, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 107,         /* unary_expression  */
  YYSYMBOL_unary_operator = 108,           /* unary_operator  */
  YYSYMBOL_cast_expression = 109,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 110, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 111,      /* additive_expression  */
  YYSYMBOL_shift_expression = 112,         /* shift_expression  */
  YYSYMBOL_relational_expression = 113,    /* relational_expression  */
  YYSYMBOL_equality_expression = 114,      /* equality_expression  */
  YYSYMBOL_and_expression = 115,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 116,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 117,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 118,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 119,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 120,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 121,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 122,      /* assignment_operator  */
  YYSYMBOL_expression = 123,               /* expression  */
  YYSYMBOL_constant_expression = 124,      /* constant_expression  */
  YYSYMBOL_declaration = 125,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 126,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 127,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 128,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 129,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 130,           /* type_specifier  */
  YYSYMBOL_alignment_specifier = 131,      /* alignment_specifier  */
  YYSYMBOL_function_specifier = 132,       /* function_specifier  */
  YYSYMBOL_struct_or_union_specifier = 133, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 134,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 135,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 136,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 137, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 138,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 139,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 140,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 141,          /* enumerator_list  */
  YYSYMBOL_enumerator = 142,               /* enumerator  */
  YYSYMBOL_type_qualifier = 143,           /* type_qualifier  */
  YYSYMBOL_atomic_type_specifier = 144,    /* atomic_type_specifier  */
  YYSYMBOL_declarator = 145,               /* declarator  */
  YYSYMBOL_direct_declarator = 146,        /* direct_declarator  */
  YYSYMBOL_pointer = 147,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 148,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 149,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 150,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 151,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 152,          /* identifier_list  */
  YYSYMBOL_type_name = 153,                /* type_name  */
  YYSYMBOL_abstract_declarator = 154,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 155, /* direct_abstract_declarator  */
  YYSYMBOL_array_suffix = 156,             /* array_suffix  */
  YYSYMBOL_type_qualifier_list_opt = 157,  /* type_qualifier_list_opt  */
  YYSYMBOL_assignment_expression_opt = 158, /* assignment_expression_opt  */
  YYSYMBOL_initializer = 159,              /* initializer  */
  YYSYMBOL_initializer_list = 160,         /* initializer_list  */
  YYSYMBOL_designation = 161,              /* designation  */
  YYSYMBOL_designator_list = 162,          /* designator_list  */
  YYSYMBOL_designator = 163,               /* designator  */
  YYSYMBOL_statement = 164,                /* statement  */
  YYSYMBOL_labeled_statement = 165,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 166,       /* compound_statement  */
  YYSYMBOL_block_item_list = 167,          /* block_item_list  */
  YYSYMBOL_block_item = 168,               /* block_item  */
  YYSYMBOL_declaration_list = 169,         /* declaration_list  */
  YYSYMBOL_expression_statement = 170,     /* expression_statement  */
  YYSYMBOL_selection_statement = 171,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 172,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 173,           /* jump_statement  */
  YYSYMBOL_translation_unit = 174,         /* translation_unit  */
  YYSYMBOL_external_declaration = 175,     /* external_declaration  */
  YYSYMBOL_function_definition = 176       /* function_definition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1953

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  263
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  449

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,    34,    72,    62,
      47,    55,    71,    63,    68,    54,    65,    60,    32,    53,
      69,    70,    64,    49,    50,    35,    73,    48,    51,     9,
      33,    58,    66,    31,    59,    52,    57,    56,    67,     2,
       2,    36,    37,    38,    39,     2,    40,    41,    42,    43,
      44,    45,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     5,     6,     7,     8,    19,    20,
      85,    86,    87,    88,    89,    11,    12,    90,    91,    92,
      93,    94,    17,    18,    95,    96,    15,    16,    97,    24,
      25,    21,    22,    23,    28,    30,    29,    13,    14,    26,
      27,    74,    75,    76,    77,    78,    79,    10,    80,    81,
       2,    61,    82,    83,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   139,   139,   140,   141,   142,   143,   144,   145,   149,
     150,   154,   160,   166,   167,   171,   172,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   189,   190,   194,
     195,   196,   197,   198,   199,   200,   204,   205,   206,   207,
     208,   209,   213,   214,   218,   219,   220,   221,   225,   226,
     227,   231,   232,   233,   237,   238,   239,   240,   241,   245,
     246,   247,   251,   252,   256,   257,   261,   262,   266,   267,
     271,   272,   276,   277,   281,   282,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   300,   301,   305,
     309,   310,   311,   312,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   329,   330,   334,   335,   339,   340,
     341,   342,   343,   344,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   366,
     367,   371,   372,   376,   377,   378,   382,   383,   387,   388,
     392,   393,   394,   395,   399,   400,   401,   402,   406,   407,
     411,   412,   413,   417,   418,   419,   420,   421,   425,   426,
     430,   431,   435,   436,   437,   438,   442,   446,   447,   451,
     452,   453,   454,   455,   456,   461,   462,   463,   464,   468,
     469,   474,   475,   479,   480,   484,   485,   486,   490,   491,
     495,   496,   500,   501,   502,   506,   507,   508,   509,   510,
     511,   512,   517,   518,   519,   520,   524,   525,   529,   530,
     534,   535,   536,   540,   541,   542,   543,   547,   551,   552,
     556,   557,   561,   562,   563,   564,   565,   566,   567,   571,
     572,   573,   577,   578,   582,   583,   587,   588,   592,   593,
     602,   603,   607,   608,   609,   613,   614,   615,   616,   617,
     618,   622,   623,   624,   625,   626,   630,   631,   635,   636,
     641,   642,   643,   644
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "TOKEN_ID", "TOKEN_TYPE_NAME",
  "TOKEN_INTEGER", "TOKEN_FLOAT", "TOKEN_CHARACTER", "TOKEN_STRING",
  "TOKEN_SIZEOF", "TOKEN_ARROW", "TOKEN_INCREMENT", "TOKEN_DECREMENT",
  "TOKEN_LEFT_SHIFT", "TOKEN_RIGHT_SHIFT", "TOKEN_LESS_EQUAL",
  "TOKEN_GREATER_EQUAL", "TOKEN_EQUAL", "TOKEN_DIFFERENT",
  "TOKEN_LOGICAL_AND", "TOKEN_LOGICAL_OR", "TOKEN_MULT_ASSIGN",
  "TOKEN_DIV_ASSIGN", "TOKEN_MOD_ASSIGN", "TOKEN_PLUS_ASSIGN",
  "TOKEN_MINUS_ASSIGN", "TOKEN_LEFT_SHIFT_ASSIGN",
  "TOKEN_RIGHT_SHIFT_ASSIGN", "TOKEN_AND_ASSIGN", "TOKEN_XOR_ASSIGN",
  "TOKEN_OR_ASSIGN", "TOKEN_TYPEDEF", "TOKEN_EXTERN", "TOKEN_STATIC",
  "TOKEN_AUTO", "TOKEN_REGISTER", "TOKEN_INLINE", "TOKEN_RESTRICT",
  "TOKEN_BOOL_KEYWORD", "TOKEN_COMPLEX", "TOKEN_ALIGNAS", "TOKEN_ALIGNOF",
  "TOKEN_ATOMIC", "TOKEN_GENERIC", "TOKEN_NORETURN", "TOKEN_STATIC_ASSERT",
  "TOKEN_THREAD_LOCAL", "TOKEN_CHAR_KEYWORD", "TOKEN_SHORT",
  "TOKEN_INT_KEYWORD", "TOKEN_LONG", "TOKEN_SIGNED", "TOKEN_UNSIGNED",
  "TOKEN_FLOAT_KEYWORD", "TOKEN_DOUBLE_KEYWORD", "TOKEN_CONST",
  "TOKEN_VOLATILE", "TOKEN_VOID", "TOKEN_STRUCT", "TOKEN_UNION",
  "TOKEN_ENUM", "TOKEN_ELLIPSIS", "TOKEN_CASE", "TOKEN_DEFAULT",
  "TOKEN_IF", "TOKEN_ELSE", "TOKEN_SWITCH", "TOKEN_WHILE", "TOKEN_DO",
  "TOKEN_FOR", "TOKEN_GOTO", "TOKEN_CONTINUE", "TOKEN_BREAK",
  "TOKEN_RETURN", "TOKEN_LEFT_PAREN", "TOKEN_RIGHT_PAREN",
  "TOKEN_LEFT_CURLY", "TOKEN_RIGHT_CURLY", "TOKEN_LEFT_SQUARE",
  "TOKEN_RIGHT_SQUARE", "TOKEN_QUESTION", "TOKEN_COLON", "TOKEN_PERIOD",
  "TOKEN_COMMA", "TOKEN_SEMICOLON", "TOKEN_BITWISE_AND",
  "TOKEN_BITWISE_OR", "TOKEN_BITWISE_XOR", "TOKEN_BITWISE_NOT",
  "TOKEN_NOT", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULT", "TOKEN_DIV",
  "TOKEN_MOD", "TOKEN_LESS", "TOKEN_GREATER", "TOKEN_ASSIGN", "$accept",
  "primary_expression", "str_sequence", "static_assert_declaration",
  "generic_selection", "generic_assoc_list", "generic_association",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "alignment_specifier", "function_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "atomic_type_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "array_suffix", "type_qualifier_list_opt",
  "assignment_expression_opt", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "declaration_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-376)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-107)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     785,   -56,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,   -20,   -14,  -376,    13,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,    37,    67,   199,  -376,  -376,    52,  1869,  1869,  1869,
    1869,  -376,    63,  -376,  1869,  -376,  1660,   127,    54,   475,
    -376,  -376,  -376,   935,  1893,  1333,    80,    95,   129,  -376,
    -376,  -376,   199,  -376,    85,  -376,   408,  -376,  -376,  -376,
    -376,   142,  1433,  -376,   539,  -376,    52,  -376,  1660,  1718,
     196,  -376,   127,  -376,  -376,  -376,  -376,  -376,  -376,   234,
    1372,  1424,  1424,   174,   182,   935,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,   165,  -376,  1333,  -376,   243,
     189,   302,    68,   306,   201,   207,   210,   280,    -1,  -376,
     226,  1893,   100,  1893,   237,   246,   250,    95,   232,     3,
    -376,  -376,  -376,  -376,    67,  -376,  1098,  -376,  1660,  1433,
     258,  -376,  1558,  -376,    99,   262,   279,  1333,   284,   295,
     296,   297,   845,   298,   370,   290,   291,  1170,  -376,  -376,
     472,  -376,  -376,   255,  -376,  -376,  -376,  -376,   631,  -376,
    -376,  -376,  -376,  -376,   281,  -376,  -376,  -376,  -376,    56,
     301,   294,  -376,    -7,   166,   272,  1436,  -376,   935,  -376,
     935,  -376,  -376,  1893,  1333,    20,   304,   378,  -376,  -376,
    1189,  1333,   379,  -376,  1333,  1333,  1333,  1333,  1333,  1333,
    1333,  1333,  1333,  1333,  1333,  1333,  1333,  1333,  1333,  1333,
    1333,  1333,  1333,  -376,  -376,  1498,   156,  -376,   171,  -376,
    -376,  -376,  -376,   234,   112,  1333,  -376,    24,  -376,  1074,
    -376,  -376,  -376,  1600,  -376,  -376,  -376,  1333,  -376,   257,
    -376,   303,  -376,   845,   305,   845,  1333,  1333,  1333,   307,
     320,   723,   308,  -376,  -376,  -376,   275,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  1333,  1333,
    -376,  -376,  -376,   997,  -376,    33,  -376,  -376,  1832,  -376,
     385,   166,  1333,  1333,   310,  -376,   311,   318,   319,   321,
     315,  -376,  1209,  -376,  -376,    22,  -376,   228,  -376,  -376,
    -376,  -376,   243,   243,   189,   189,   302,   302,   302,   302,
      68,    68,   306,   201,   207,   210,   280,   206,  -376,   324,
     325,   171,  1775,  -376,   326,  -376,    35,  -376,  -376,  -376,
    1333,   399,  -376,   140,  1098,   -15,  -376,  -376,  -376,   139,
    -376,  1333,  -376,   845,  -376,    78,    83,    96,  -376,   329,
    1228,  1228,  -376,  -376,  -376,  -376,  -376,  -376,  -376,   328,
     331,  -376,  -376,   332,   332,  -376,   843,  1074,  -376,  -376,
    1333,  -376,  1333,  -376,  -376,  -376,   330,   333,  -376,   334,
    -376,  -376,   342,  -376,  -376,  -376,  -376,  -376,  -376,   845,
     845,   845,  1333,  1281,  1320,  -376,  -376,   323,   115,  -376,
     340,   167,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  1098,
     349,  -376,  -376,   131,   845,   132,   845,   157,  1333,  -376,
     843,  1333,  -376,  1055,  -376,   845,   338,  -376,   845,  -376,
     845,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,   169,   128,   108,   109,   110,   111,   112,   131,
     164,   123,   124,     0,   165,   132,     0,   113,   115,   116,
     117,   118,   121,   122,   119,   120,   162,   163,   114,   136,
     137,     0,     0,   175,    93,   259,     0,    94,    96,   102,
     100,   126,     0,   127,    98,   125,     0,   168,     0,     0,
     256,   258,    92,     0,     0,     0,   157,     0,     0,   165,
     179,   177,   176,    90,     0,   104,     0,    95,    97,   103,
     101,   135,     0,    99,     0,   238,     0,   263,     0,     0,
     206,   171,   167,     1,   257,     2,     3,     4,     5,     9,
       0,     0,     0,     0,     0,     0,    36,    40,    41,    38,
      39,    37,    17,     6,     8,    29,    42,     0,    44,    48,
      51,    54,    59,    62,    64,    66,    68,    70,    72,    89,
       0,   145,   190,   147,     0,     0,     0,     0,   160,     0,
     158,   170,   180,   178,     0,    91,     0,   261,     0,     0,
       0,   141,     0,   138,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   232,   240,
      42,    74,    87,     0,   236,   237,   222,   223,     0,   234,
     224,   225,   226,   227,   106,   239,   262,   188,   174,   187,
       0,   181,   183,     0,   206,   207,   208,    10,     0,    33,
       0,    30,    31,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   144,     0,   192,   191,   193,   196,
     146,   129,   166,     0,     0,     0,   153,     0,   105,     0,
     210,   107,   260,     0,   143,   134,   139,     0,   142,     0,
     148,   150,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   253,   254,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    76,     0,     0,
     241,   233,   235,     0,   185,   192,   186,   172,     0,   173,
       0,   207,     0,     0,    37,   209,     0,     0,     0,     0,
       0,     7,     0,    24,    21,     0,    27,     0,    23,    45,
      46,    47,    49,    50,    52,    53,    57,    58,    55,    56,
      60,    61,    63,    65,    67,    69,    71,     0,   198,     0,
       0,   194,     0,   197,     0,   156,     0,   161,   154,   159,
       0,     0,   213,     0,     0,     0,   218,   133,   151,     0,
     140,     0,   229,     0,   231,     0,     0,     0,   228,     0,
       0,     0,   251,   255,    75,    88,   182,   184,   189,     0,
       0,   205,   202,    34,     0,    35,     0,     0,    43,    22,
       0,    20,     0,   199,   195,   200,     0,     0,   155,     0,
     221,   211,     0,   214,   217,   219,   149,   152,   230,     0,
       0,     0,     0,     0,     0,   203,   204,     0,     0,    13,
       0,     0,    28,    73,   201,    11,   220,   212,   215,     0,
     242,   244,   245,     0,     0,     0,     0,     0,     0,    12,
       0,     0,    18,     0,   216,     0,     0,   247,     0,   249,
       0,    16,    14,    15,    19,   243,   246,   248,   250
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -376,  -376,   -79,   -61,  -376,  -376,    -5,  -376,  -376,    55,
    -376,   -83,   148,   153,  -170,   152,   198,   205,   209,   215,
     208,  -376,   -48,   -67,  -376,   -72,   -47,   150,    12,  -376,
     292,  -376,   -50,  -376,  -376,  -376,  -376,   299,  -128,   -46,
    -376,    87,  -376,   322,  -219,   -33,  -376,   -30,   -39,     2,
     -64,   -54,  -376,   163,  -376,   -23,   -85,  -211,   -34,   285,
    -376,  -135,    93,  -375,  -376,   126,  -118,  -376,   -13,  -376,
     309,   406,  -229,  -376,  -376,  -376,  -376,   424,  -376
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   102,   103,    34,   104,   408,   409,   105,   305,   160,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   161,   162,   278,   163,   120,    35,    76,    64,
      65,    37,    38,    39,    40,    41,    42,   142,   143,   122,
     249,   250,    43,   129,   130,    44,    45,    46,    47,    48,
      62,   329,   181,   182,   183,   410,   330,   228,   229,   186,
     296,   342,   343,   344,   345,   346,   165,   166,   167,   168,
     169,    78,   170,   171,   172,   173,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,   241,    58,   121,   121,   119,    66,   119,   126,    82,
     187,   141,    36,    81,   246,   331,   185,   419,   339,   221,
     123,   123,   121,   195,   203,   180,   144,   128,    52,   132,
     124,   125,   361,    77,   260,    61,     2,   227,   128,   123,
      56,   316,   317,   318,   319,   121,   174,    60,    81,    67,
      68,    69,    70,   137,    53,     2,    73,     2,   419,     2,
      54,    36,   123,   340,   133,   176,    71,   341,   289,   240,
       2,   121,   196,   121,   331,   224,   290,   230,   141,   222,
     236,   141,   394,   211,   212,   266,   237,    55,   123,   121,
     123,   179,   121,   144,   286,   301,   144,   379,   128,   119,
     254,   338,     2,   279,   174,   380,   123,   283,   106,   123,
     106,    80,   388,    57,   251,   246,   195,   339,   195,   295,
     291,   309,   310,   311,   226,   242,    32,   300,    32,   307,
     283,   403,   404,   306,    80,   352,    63,   354,   121,    72,
     121,    32,     2,   121,    33,   189,   191,   192,    33,   284,
     327,    60,   132,   399,   334,   123,   127,   123,   400,    33,
     123,   279,   106,   213,   214,   297,   279,   298,   134,   135,
     299,   401,   240,    32,   225,   197,   198,   199,    80,   279,
     247,   285,   141,   248,   355,   356,   357,   119,   337,   335,
     429,    33,    33,   121,   333,   336,    75,   144,   430,   119,
     348,    79,   106,    10,   131,    80,   436,   438,    59,   393,
     123,   364,   365,    32,   279,   279,    75,   391,   139,   378,
     247,    26,    27,   392,   164,   369,   370,   226,   175,   184,
     225,    33,   440,    10,    80,   398,    10,   179,    59,   200,
     279,    59,    89,   201,   432,   332,    82,   202,   193,    80,
     433,    26,    27,    58,    26,    27,   194,   418,   132,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   240,   386,   207,
     208,   420,   421,   422,   434,   285,   217,   382,   175,   279,
     106,    33,   119,   389,   218,   179,   219,   333,   418,   220,
     179,   223,   106,   119,   397,   293,   437,   381,   439,    10,
     240,   279,   231,   412,    59,   209,   210,   445,   164,   251,
     447,   232,   448,   215,   216,   240,   121,    26,    27,   235,
     423,   425,   427,   233,   413,   204,   205,   206,   279,   280,
     349,   350,   244,   123,   179,    85,   252,    86,    87,    88,
      89,    90,   240,    91,    92,   312,   313,   106,   279,   363,
     253,   441,   314,   315,   443,   255,   240,   320,   321,   256,
     257,   258,   261,   262,   263,   264,   287,   288,   136,   302,
     121,   303,   308,    93,   351,    94,   353,   359,   368,   371,
     372,   358,   362,   373,   374,   106,   375,   123,   376,   383,
     384,   387,   390,   402,   428,   414,   106,   405,   377,     1,
     406,   360,     3,   416,   435,   322,    95,   415,   239,   417,
     340,   431,   446,   323,   341,   442,   238,    96,   324,   326,
      97,    98,    99,   100,   101,   325,   396,   106,   243,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,   234,
      14,   367,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   292,
     411,   395,   138,    84,     0,    83,     1,   282,     2,     3,
       0,     0,     0,     0,    74,     0,     0,     0,     0,     0,
       0,  -106,  -106,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,     0,     0,   136,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,     0,     0,     0,
     145,     0,   146,     3,    86,    87,    88,    89,    90,    32,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,   277,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      93,    14,    94,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,   147,   148,   149,     0,   150,   151,   152,   153,   154,
     155,   156,   157,    95,     0,    74,   158,     0,     0,     0,
       0,     0,     0,   159,    96,     0,     0,    97,    98,    99,
     100,   101,   145,     0,   146,     3,    86,    87,    88,    89,
      90,     0,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    93,    14,    94,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,    95,     0,    74,   281,     0,
       0,     0,     0,     0,     0,   159,    96,     0,     0,    97,
      98,    99,   100,   101,     1,     0,    85,     3,    86,    87,
      88,    89,    90,     0,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    93,    14,    94,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,     1,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,    96,     0,
       0,    97,    98,    99,   100,   101,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   259,     3,   146,     0,
      86,    87,    88,    89,    90,     0,    91,    92,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
      10,    11,    12,     0,     0,    14,    93,     0,    94,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,   407,   147,   148,   149,
       0,   150,   151,   152,   153,   154,   155,   156,   157,    95,
       0,    74,     0,     0,     0,     0,     0,     0,     0,   159,
      96,     0,     0,    97,    98,    99,   100,   101,    85,     3,
      86,    87,    88,    89,    90,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,     0,    93,    14,    94,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    97,    98,    99,   100,   101,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     0,    14,
       0,    15,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    85,     0,
      86,    87,    88,    89,    90,     0,    91,    92,     0,     0,
       0,   283,   328,     0,     0,    80,     0,    85,     0,    86,
      87,    88,    89,    90,     0,    91,    92,     0,     0,    33,
       0,     0,     0,     0,     0,     0,    93,     0,    94,     0,
       0,    85,     0,    86,    87,    88,    89,    90,     0,    91,
      92,     0,     0,     0,     0,    93,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,   239,   444,   340,     0,     0,     0,   341,     0,    93,
      96,    94,     0,    97,    98,    99,   100,   101,    95,     0,
     239,     0,   340,     0,     0,     0,   341,     0,     0,    96,
       0,     0,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,    95,    85,   239,    86,    87,    88,    89,    90,
       0,    91,    92,    96,     0,     0,    97,    98,    99,   100,
     101,     0,    85,     0,    86,    87,    88,    89,    90,     0,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    85,    94,    86,    87,    88,    89,    90,     0,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    85,    94,    86,    87,    88,    89,    90,     0,    91,
      92,     0,     0,     0,    95,     0,     0,     0,     0,     0,
      93,     0,    94,     0,   265,    96,     0,     0,    97,    98,
      99,   100,   101,    95,   304,     0,     0,     0,     0,    93,
       0,    94,     0,     0,    96,     0,     0,    97,    98,    99,
     100,   101,     0,    95,    85,   377,    86,    87,    88,    89,
      90,     0,    91,    92,    96,     0,     0,    97,    98,    99,
     100,   101,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,    96,     0,     0,    97,    98,    99,   100,
     101,     0,    93,    85,    94,    86,    87,    88,    89,    90,
       0,    91,    92,     0,     0,     0,    85,     0,    86,    87,
      88,    89,    90,     0,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,   424,     0,     0,     0,
       0,    93,     0,    94,     0,     0,    96,     0,     0,    97,
      98,    99,   100,   101,    93,    85,    94,    86,    87,    88,
      89,    90,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,   426,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,     0,    95,    97,    98,
      99,   100,   101,    93,     0,    94,     0,     0,    96,     0,
       0,    97,    98,    99,   100,   101,     0,    85,     0,    86,
      87,    88,    89,    90,   140,    91,    92,     3,     0,    85,
       0,    86,    87,    88,    89,    90,   188,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
      97,    98,    99,   100,   101,    93,     0,    94,     0,     0,
      10,    11,    12,     0,     0,    14,     0,    93,    16,    94,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,     0,     0,   190,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,    96,
      95,     0,    97,    98,    99,   100,   101,     0,     0,     0,
       0,    96,     0,     0,    97,    98,    99,   100,   294,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,     0,    15,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   140,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   328,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,    10,    11,    12,     0,     0,
      14,   140,     0,    16,     3,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,     0,    10,    11,    12,
       0,     0,    14,     0,     0,    16,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     1,     0,     0,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   347,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   177,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,     0,    15,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    14,     0,    15,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     3,    14,     0,    15,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   366,     0,     0,     0,     3,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,    14,     0,    15,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      10,    11,    12,     0,     0,    14,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31
};

static const yytype_int16 yycheck[] =
{
      33,   136,    32,    53,    54,    53,    36,    55,    55,    48,
      89,    72,     0,    47,   142,   226,    80,   392,   237,    20,
      53,    54,    72,    95,   107,    79,    72,     3,    84,    62,
      53,    54,   261,    46,   152,    33,     3,   122,     3,    72,
       3,   211,   212,   213,   214,    95,    76,    80,    82,    37,
      38,    39,    40,    66,    74,     3,    44,     3,   433,     3,
      74,    49,    95,    78,    62,    78,     3,    82,    75,   136,
       3,   121,    95,   123,   285,   121,    83,   123,   139,    80,
      77,   142,    97,    15,    16,   157,    83,    74,   121,   139,
     123,    79,   142,   139,   179,    75,   142,    75,     3,   147,
     147,    77,     3,    83,   134,    83,   139,    74,    53,   142,
      55,    78,    77,    76,   144,   243,   188,   336,   190,   186,
     184,   204,   205,   206,   122,   138,    74,   194,    74,   201,
      74,   360,   361,   200,    78,   253,    84,   255,   188,    76,
     190,    74,     3,   193,    92,    90,    91,    92,    92,   179,
     222,   184,   185,    75,   233,   188,    76,   190,    75,    92,
     193,    83,   107,    95,    96,   188,    83,   190,    83,    84,
     193,    75,   239,    74,    74,    10,    11,    12,    78,    83,
      81,   179,   243,    84,   256,   257,   258,   235,   235,    77,
      75,    92,    92,   243,   228,    83,    46,   243,    83,   247,
     247,    74,   147,    37,    75,    78,    75,    75,    42,   344,
     243,   278,   279,    74,    83,    83,    66,    77,    76,   302,
      81,    55,    56,    83,    74,   292,   293,   225,    78,    33,
      74,    92,    75,    37,    78,   353,    37,   225,    42,    74,
      83,    42,     8,    78,    77,    74,   285,    82,    74,    78,
      83,    55,    56,   283,    55,    56,    74,   392,   291,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   344,   332,    90,
      91,   399,   400,   401,   419,   283,    85,    81,   138,    83,
     235,    92,   340,   340,    87,   283,    86,   331,   433,    19,
     288,    75,   247,   351,   351,    33,   424,    79,   426,    37,
     377,    83,    75,   380,    42,    13,    14,   435,   168,   349,
     438,    75,   440,    17,    18,   392,   376,    55,    56,    97,
     402,   403,   404,    83,   382,    92,    93,    94,    83,    84,
      83,    84,    84,   376,   332,     3,    84,     5,     6,     7,
       8,     9,   419,    11,    12,   207,   208,   302,    83,    84,
      81,   428,   209,   210,   431,    81,   433,   215,   216,    74,
      74,    74,    74,     3,    84,    84,    75,    83,    97,    75,
     430,     3,     3,    41,    81,    43,    81,    67,     3,    79,
      79,    84,    84,    75,    75,   340,    75,   430,    83,    75,
      75,    75,     3,    74,    81,    75,   351,    79,    76,     1,
      79,   261,     4,    79,    65,   217,    74,    84,    76,    77,
      78,    81,    84,   218,    82,   430,   134,    85,   219,   221,
      88,    89,    90,    91,    92,   220,   349,   382,   139,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,   127,
      42,   288,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,   184,
     377,   345,    66,    49,    -1,     0,     1,   168,     3,     4,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    97,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    74,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    97,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    -1,    -1,    88,    89,    90,
      91,    92,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    88,
      89,    90,    91,    92,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,     1,    -1,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,
      -1,    88,    89,    90,    91,    92,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     1,     4,     3,    -1,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      37,    38,    39,    -1,    -1,    42,    41,    -1,    43,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    63,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    88,    89,    90,    91,    92,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    43,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    88,    89,    90,    91,    92,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    44,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     3,    -1,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    74,    75,    -1,    -1,    78,    -1,     3,    -1,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    76,    77,    78,    -1,    -1,    -1,    82,    -1,    41,
      85,    43,    -1,    88,    89,    90,    91,    92,    74,    -1,
      76,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,    85,
      -1,    -1,    88,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    74,     3,    76,     5,     6,     7,     8,     9,
      -1,    11,    12,    85,    -1,    -1,    88,    89,    90,    91,
      92,    -1,     3,    -1,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,     3,    43,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,     3,    43,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    84,    85,    -1,    -1,    88,    89,
      90,    91,    92,    74,    75,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,    -1,    85,    -1,    -1,    88,    89,    90,
      91,    92,    -1,    74,     3,    76,     5,     6,     7,     8,
       9,    -1,    11,    12,    85,    -1,    -1,    88,    89,    90,
      91,    92,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    88,    89,    90,    91,
      92,    -1,    41,     3,    43,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    41,    -1,    43,    -1,    -1,    85,    -1,    -1,    88,
      89,    90,    91,    92,    41,     3,    43,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    74,    88,    89,
      90,    91,    92,    41,    -1,    43,    -1,    -1,    85,    -1,
      -1,    88,    89,    90,    91,    92,    -1,     3,    -1,     5,
       6,     7,     8,     9,     1,    11,    12,     4,    -1,     3,
      -1,     5,     6,     7,     8,     9,    74,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      88,    89,    90,    91,    92,    41,    -1,    43,    -1,    -1,
      37,    38,    39,    -1,    -1,    42,    -1,    41,    45,    43,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      74,    -1,    88,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    90,    91,    92,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,    -1,
      42,     1,    -1,    45,     4,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     4,    42,    -1,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,     4,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    44,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    42,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    74,    92,   101,   125,   126,   129,   130,   131,
     132,   133,   134,   140,   143,   144,   145,   146,   147,   174,
     175,   176,    84,    74,    74,    74,     3,    76,   145,    42,
     143,   147,   148,    84,   127,   128,   145,   126,   126,   126,
     126,     3,    76,   126,    76,   125,   126,   166,   169,    74,
      78,   156,   146,     0,   175,     3,     5,     6,     7,     8,
       9,    11,    12,    41,    43,    74,    85,    88,    89,    90,
      91,    92,    99,   100,   102,   105,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     124,   130,   137,   143,   153,   153,   124,    76,     3,   141,
     142,    75,   143,   147,    83,    84,    97,   166,   169,    76,
       1,   101,   135,   136,   137,     1,     3,    62,    63,    64,
      66,    67,    68,    69,    70,    71,    72,    73,    77,    84,
     107,   120,   121,   123,   125,   164,   165,   166,   167,   168,
     170,   171,   172,   173,   145,   125,   166,     3,    75,   126,
     149,   150,   151,   152,    33,   148,   157,   100,    74,   107,
      74,   107,   107,    74,    74,   123,   153,    10,    11,    12,
      74,    78,    82,   109,    92,    93,    94,    90,    91,    13,
      14,    15,    16,    95,    96,    17,    18,    85,    87,    86,
      19,    20,    80,    75,   137,    74,   147,   154,   155,   156,
     137,    75,    75,    83,   141,    97,    77,    83,   128,    76,
     121,   159,   166,   135,    84,    77,   136,    81,    84,   138,
     139,   145,    84,    81,   124,    81,    74,    74,    74,     1,
     164,    74,     3,    84,    84,    84,   123,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    97,   122,    83,
      84,    77,   168,    74,   145,   147,   154,    75,    83,    75,
      83,   148,   157,    33,    92,   121,   158,   153,   153,   153,
     121,    75,    75,     3,    75,   106,   121,   123,     3,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   112,   112,
     113,   113,   114,   115,   116,   117,   118,   123,    75,   149,
     154,   155,    74,   156,   100,    77,    83,   124,    77,   142,
      78,    82,   159,   160,   161,   162,   163,    77,   124,    83,
      84,    81,   164,    81,   164,   123,   123,   123,    84,    67,
     125,   170,    84,    84,   121,   121,    61,   151,     3,   121,
     121,    79,    79,    75,    75,    75,    83,    76,   109,    75,
      83,    79,    81,    75,    75,    75,   149,    75,    77,   124,
       3,    77,    83,   159,    97,   163,   139,   124,   164,    75,
      75,    75,    74,   170,   170,    79,    79,    63,   103,   104,
     153,   160,   121,   120,    75,    84,    79,    77,   159,   161,
     164,   164,   164,   123,    75,   123,    75,   123,    81,    75,
      83,    81,    77,    83,   159,    65,    75,   164,    75,   164,
      75,   121,   104,   121,    77,   164,    84,   164,   164
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    98,    99,    99,    99,    99,    99,    99,    99,   100,
     100,   101,   102,   103,   103,   104,   104,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   109,   109,   110,   110,   110,   110,   111,   111,
     111,   112,   112,   112,   113,   113,   113,   113,   113,   114,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   124,
     125,   125,   125,   125,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   131,
     131,   132,   132,   133,   133,   133,   134,   134,   135,   135,
     136,   136,   136,   136,   137,   137,   137,   137,   138,   138,
     139,   139,   139,   140,   140,   140,   140,   140,   141,   141,
     142,   142,   143,   143,   143,   143,   144,   145,   145,   146,
     146,   146,   146,   146,   146,   147,   147,   147,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   151,   152,   152,
     153,   153,   154,   154,   154,   155,   155,   155,   155,   155,
     155,   155,   156,   156,   156,   156,   157,   157,   158,   158,
     159,   159,   159,   160,   160,   160,   160,   161,   162,   162,
     163,   163,   164,   164,   164,   164,   164,   164,   164,   165,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   171,   171,   172,   172,   172,   172,   172,
     172,   173,   173,   173,   173,   173,   174,   174,   175,   175,
     176,   176,   176,   176
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     7,     6,     1,     3,     3,     3,     1,     6,     7,
       4,     3,     4,     3,     3,     2,     2,     1,     3,     1,
       2,     2,     2,     2,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     3,     2,     1,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     1,     1,     5,     4,     2,     1,     1,     1,     2,
       3,     1,     2,     2,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     6,     5,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     4,     2,     1,     1,
       3,     2,     4,     4,     3,     1,     2,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     2,     1,     1,     2,     3,     1,     2,     2,     3,
       3,     4,     4,     5,     5,     4,     0,     1,     0,     1,
       1,     3,     4,     1,     2,     3,     4,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     3,     2,     3,     1,     2,     1,     1,     1,     2,
       1,     2,     5,     7,     5,     5,     7,     6,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_init_declarator_list: /* init_declarator_list  */
#line 132 "parser/parser.y"
            { free_name_list(((*yyvaluep).names)); }
#line 2173 "parser/parser.c"
        break;

    case YYSYMBOL_init_declarator: /* init_declarator  */
#line 132 "parser/parser.y"
            { free_name_list(((*yyvaluep).names)); }
#line 2179 "parser/parser.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 91: /* declaration: declaration_specifiers init_declarator_list TOKEN_SEMICOLON  */
#line 310 "parser/parser.y"
                                                                      { finish_declaration((yyvsp[-2].is_typedef), (yyvsp[-1].names)); }
#line 2490 "parser/parser.c"
    break;

  case 92: /* declaration: error TOKEN_SEMICOLON  */
#line 311 "parser/parser.y"
                                { /* very important one */ yyerrok; }
#line 2496 "parser/parser.c"
    break;

  case 94: /* declaration_specifiers: storage_class_specifier  */
#line 316 "parser/parser.y"
                              { (yyval.is_typedef) = (yyvsp[0].is_typedef); }
#line 2502 "parser/parser.c"
    break;

  case 95: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 317 "parser/parser.y"
                                                     { (yyval.is_typedef) = (yyvsp[-1].is_typedef) || (yyvsp[0].is_typedef); }
#line 2508 "parser/parser.c"
    break;

  case 96: /* declaration_specifiers: type_specifier  */
#line 318 "parser/parser.y"
                     { (yyval.is_typedef) = 0; }
#line 2514 "parser/parser.c"
    break;

  case 97: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 319 "parser/parser.y"
                                            { (yyval.is_typedef) = (yyvsp[0].is_typedef); }
#line 2520 "parser/parser.c"
    break;

  case 98: /* declaration_specifiers: type_qualifier  */
#line 320 "parser/parser.y"
                     { (yyval.is_typedef) = 0; }
#line 2526 "parser/parser.c"
    break;

  case 99: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 321 "parser/parser.y"
                                            { (yyval.is_typedef) = (yyvsp[0].is_typedef); }
#line 2532 "parser/parser.c"
    break;

  case 100: /* declaration_specifiers: function_specifier  */
#line 322 "parser/parser.y"
                         { (yyval.is_typedef) = 0; }
#line 2538 "parser/parser.c"
    break;

  case 101: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 323 "parser/parser.y"
                                                { (yyval.is_typedef) = (yyvsp[0].is_typedef); }
#line 2544 "parser/parser.c"
    break;

  case 102: /* declaration_specifiers: alignment_specifier  */
#line 324 "parser/parser.y"
                          { (yyval.is_typedef) = 0; }
#line 2550 "parser/parser.c"
    break;

  case 103: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 325 "parser/parser.y"
                                                 { (yyval.is_typedef) = (yyvsp[0].is_typedef); }
#line 2556 "parser/parser.c"
    break;

  case 104: /* init_declarator_list: init_declarator  */
#line 329 "parser/parser.y"
                      { (yyval.names) = (yyvsp[0].names); }
#line 2562 "parser/parser.c"
    break;

  case 105: /* init_declarator_list: init_declarator_list TOKEN_COMMA init_declarator  */
#line 330 "parser/parser.y"
                                                       { (yyval.names) = join_name_lists((yyvsp[-2].names), (yyvsp[0].names)); }
#line 2568 "parser/parser.c"
    break;

  case 106: /* init_declarator: declarator  */
#line 334 "parser/parser.y"
                 { (yyval.names) = make_name_list((yyvsp[0].text)); }
#line 2574 "parser/parser.c"
    break;

  case 107: /* init_declarator: declarator TOKEN_ASSIGN initializer  */
#line 335 "parser/parser.y"
                                          { (yyval.names) = make_name_list((yyvsp[-2].text)); }
#line 2580 "parser/parser.c"
    break;

  case 108: /* storage_class_specifier: TOKEN_TYPEDEF  */
#line 339 "parser/parser.y"
                         { (yyval.is_typedef) = 1; }
#line 2586 "parser/parser.c"
    break;

  case 109: /* storage_class_specifier: TOKEN_EXTERN  */
#line 340 "parser/parser.y"
                         { (yyval.is_typedef) = 0; }
#line 2592 "parser/parser.c"
    break;

  case 110: /* storage_class_specifier: TOKEN_STATIC  */
#line 341 "parser/parser.y"
                         { (yyval.is_typedef) = 0; }
#line 2598 "parser/parser.c"
    break;

  case 111: /* storage_class_specifier: TOKEN_AUTO  */
#line 342 "parser/parser.y"
                         { (yyval.is_typedef) = 0; }
#line 2604 "parser/parser.c"
    break;

  case 112: /* storage_class_specifier: TOKEN_REGISTER  */
#line 343 "parser/parser.y"
                         { (yyval.is_typedef) = 0; }
#line 2610 "parser/parser.c"
    break;

  case 113: /* storage_class_specifier: TOKEN_THREAD_LOCAL  */
#line 344 "parser/parser.y"
                         { (yyval.is_typedef) = 0; }
#line 2616 "parser/parser.c"
    break;

  case 143: /* struct_declaration: error TOKEN_SEMICOLON  */
#line 395 "parser/parser.y"
                                { yyerrok; }
#line 2622 "parser/parser.c"
    break;

  case 167: /* declarator: pointer direct_declarator  */
#line 446 "parser/parser.y"
                                { (yyval.text) = (yyvsp[0].text); }
#line 2628 "parser/parser.c"
    break;

  case 168: /* declarator: direct_declarator  */
#line 447 "parser/parser.y"
                        { (yyval.text) = (yyvsp[0].text); }
#line 2634 "parser/parser.c"
    break;

  case 169: /* direct_declarator: TOKEN_ID  */
#line 451 "parser/parser.y"
               { (yyval.text) = (yyvsp[0].text); }
#line 2640 "parser/parser.c"
    break;

  case 170: /* direct_declarator: TOKEN_LEFT_PAREN declarator TOKEN_RIGHT_PAREN  */
#line 452 "parser/parser.y"
                                                    { (yyval.text) = (yyvsp[-1].text); }
#line 2646 "parser/parser.c"
    break;

  case 171: /* direct_declarator: direct_declarator array_suffix  */
#line 453 "parser/parser.y"
                                     { (yyval.text) = (yyvsp[-1].text); }
#line 2652 "parser/parser.c"
    break;

  case 172: /* direct_declarator: direct_declarator TOKEN_LEFT_PAREN parameter_type_list TOKEN_RIGHT_PAREN  */
#line 454 "parser/parser.y"
                                                                               { (yyval.text) = (yyvsp[-3].text); }
#line 2658 "parser/parser.c"
    break;

  case 173: /* direct_declarator: direct_declarator TOKEN_LEFT_PAREN identifier_list TOKEN_RIGHT_PAREN  */
#line 455 "parser/parser.y"
                                                                           { (yyval.text) = (yyvsp[-3].text); }
#line 2664 "parser/parser.c"
    break;

  case 174: /* direct_declarator: direct_declarator TOKEN_LEFT_PAREN TOKEN_RIGHT_PAREN  */
#line 456 "parser/parser.y"
                                                           { (yyval.text) = (yyvsp[-2].text); }
#line 2670 "parser/parser.c"
    break;

  case 228: /* statement: error TOKEN_SEMICOLON  */
#line 567 "parser/parser.y"
                                { yyerrok; }
#line 2676 "parser/parser.c"
    break;


#line 2680 "parser/parser.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 655 "parser/parser.y"

void yyerror(const char *s) {
    fprintf(stderr, "Error in line %d:%d %s\n",
        yylloc.first_line,
        yylloc.first_column,
        s);
}
