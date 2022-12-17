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
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"
#include "Calculate.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;
//FILE * MIPScode;


void yyerror(const char* s);
// TODO: Update scope variable to handle multiple scopes
char currentScope[50] = "global"; // "global" or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks
char funcParams[50][50];
char funcType[50];
char funParType[][50];
int parIdx = 0;
int paramIdx = 0;
int funcOp = 0;
int elseTrue=0; //0=No,1=Yes
int condFalseIF=0;

#line 106 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE = 3,                       /* TYPE  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_SEMICOLON = 5,                  /* SEMICOLON  */
  YYSYMBOL_EQ = 6,                         /* EQ  */
  YYSYMBOL_PLUS_OP = 7,                    /* PLUS_OP  */
  YYSYMBOL_SUB_OP = 8,                     /* SUB_OP  */
  YYSYMBOL_MULT_OP = 9,                    /* MULT_OP  */
  YYSYMBOL_DIV_OP = 10,                    /* DIV_OP  */
  YYSYMBOL_CAR_OP = 11,                    /* CAR_OP  */
  YYSYMBOL_LeftPar = 12,                   /* LeftPar  */
  YYSYMBOL_RightPar = 13,                  /* RightPar  */
  YYSYMBOL_LeftCurly = 14,                 /* LeftCurly  */
  YYSYMBOL_RightCurly = 15,                /* RightCurly  */
  YYSYMBOL_LeftBracket = 16,               /* LeftBracket  */
  YYSYMBOL_RightBracket = 17,              /* RightBracket  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_EQ_COND = 19,                   /* EQ_COND  */
  YYSYMBOL_GREATER = 20,                   /* GREATER  */
  YYSYMBOL_LESS = 21,                      /* LESS  */
  YYSYMBOL_GREATER_EQ = 22,                /* GREATER_EQ  */
  YYSYMBOL_LESS_EQ = 23,                   /* LESS_EQ  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_DOT = 25,                       /* DOT  */
  YYSYMBOL_CHAR = 26,                      /* CHAR  */
  YYSYMBOL_QUOTE = 27,                     /* QUOTE  */
  YYSYMBOL_NUMBER = 28,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 29,                     /* FLOAT  */
  YYSYMBOL_WRITE = 30,                     /* WRITE  */
  YYSYMBOL_WRITELN = 31,                   /* WRITELN  */
  YYSYMBOL_READ = 32,                      /* READ  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_BOOL = 37,                      /* BOOL  */
  YYSYMBOL_TRUE = 38,                      /* TRUE  */
  YYSYMBOL_FALSE = 39,                     /* FALSE  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_Program = 41,                   /* Program  */
  YYSYMBOL_DeclList = 42,                  /* DeclList  */
  YYSYMBOL_Decl = 43,                      /* Decl  */
  YYSYMBOL_VarDecl = 44,                   /* VarDecl  */
  YYSYMBOL_ArrayDecl = 45,                 /* ArrayDecl  */
  YYSYMBOL_IfStmt = 46,                    /* IfStmt  */
  YYSYMBOL_47_1 = 47,                      /* @1  */
  YYSYMBOL_ElseStmt = 48,                  /* ElseStmt  */
  YYSYMBOL_WhileStmt = 49,                 /* WhileStmt  */
  YYSYMBOL_CONDITIONWHILE = 50,            /* CONDITIONWHILE  */
  YYSYMBOL_CONDITIONIF = 51,               /* CONDITIONIF  */
  YYSYMBOL_TestExpr = 52,                  /* TestExpr  */
  YYSYMBOL_TestOp = 53,                    /* TestOp  */
  YYSYMBOL_Block = 54,                     /* Block  */
  YYSYMBOL_StmtList = 55,                  /* StmtList  */
  YYSYMBOL_Stmt = 56,                      /* Stmt  */
  YYSYMBOL_OPERATION = 57,                 /* OPERATION  */
  YYSYMBOL_ParamDecl = 58,                 /* ParamDecl  */
  YYSYMBOL_ParamDeclEnd = 59,              /* ParamDeclEnd  */
  YYSYMBOL_Function = 60,                  /* Function  */
  YYSYMBOL_61_2 = 61,                      /* @2  */
  YYSYMBOL_62_3 = 62,                      /* @3  */
  YYSYMBOL_Expr = 63,                      /* Expr  */
  YYSYMBOL_CallParam = 64,                 /* CallParam  */
  YYSYMBOL_CallParamEnd = 65,              /* CallParamEnd  */
  YYSYMBOL_FuncCall = 66                   /* FuncCall  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   105,   111,   114,   115,   116,   117,   120,
     138,   172,   172,   192,   197,   199,   212,   268,   270,   316,
     318,   319,   320,   325,   328,   329,   330,   331,   332,   333,
     335,   342,   343,   351,   352,   353,   354,   355,   358,   359,
     375,   391,   407,   423,   439,   465,   488,   511,   534,   559,
     575,   585,   621,   622,   644,   647,   668,   669,   668,   701,
     751,   788,   825,   883,   929,   973,   979,  1012,  1020,  1021,
    1029,  1033,  1042
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TYPE", "ID",
  "SEMICOLON", "EQ", "PLUS_OP", "SUB_OP", "MULT_OP", "DIV_OP", "CAR_OP",
  "LeftPar", "RightPar", "LeftCurly", "RightCurly", "LeftBracket",
  "RightBracket", "COMMA", "EQ_COND", "GREATER", "LESS", "GREATER_EQ",
  "LESS_EQ", "NOT", "DOT", "CHAR", "QUOTE", "NUMBER", "FLOAT", "WRITE",
  "WRITELN", "READ", "RETURN", "IF", "ELSE", "WHILE", "BOOL", "TRUE",
  "FALSE", "$accept", "Program", "DeclList", "Decl", "VarDecl",
  "ArrayDecl", "IfStmt", "@1", "ElseStmt", "WhileStmt", "CONDITIONWHILE",
  "CONDITIONIF", "TestExpr", "TestOp", "Block", "StmtList", "Stmt",
  "OPERATION", "ParamDecl", "ParamDeclEnd", "Function", "@2", "@3", "Expr",
  "CallParam", "CallParamEnd", "FuncCall", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      26,     0,    65,   -30,     1,    -1,    -5,     4,    12,   -30,
      26,   -30,   -30,   -30,   -30,   -30,   -30,    29,   -30,     8,
     -30,     5,    46,    11,    -8,   -30,    95,    -1,    78,    -5,
      93,   -30,    26,   -30,     4,    -5,    93,   -30,   -30,   -30,
     -30,   -30,   -30,    -4,   111,    14,   -30,    78,   -30,   -30,
     -30,    22,    10,   -30,    31,    14,    14,    14,    14,    14,
      66,    36,    38,    14,    14,    14,    14,    14,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,    66,     7,    39,   -30,    66,
      50,    40,   117,    38,    11,   -30,    49,   -30,   -30,   -30,
     -30,   -30,    51,   -30,    59,   -30,   -30,   -30,   -30,   -30,
      32,   -30,   -30,   -30,   -30,    75,   -30,   -30,    77,   -30,
      72,   -30,    14,   -30,    62,    70,   -30,   -30,   -30,   -30,
     -30,    50,    -5,   -30,   -30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      14,     0,     0,    33,     0,     0,     0,     0,     0,     2,
       4,     5,     8,    35,    36,    37,     7,    14,     6,     0,
      67,     0,     0,    68,     0,    66,    20,     0,    21,     0,
       0,    23,    14,    13,     0,     0,     0,     1,     3,    32,
      34,     9,    56,     0,    51,     0,    60,    50,    61,    59,
      65,    71,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,    11,    24,
      25,    26,    27,    28,    29,     0,     0,     0,    15,     0,
      52,     0,    51,     0,    68,    72,     0,    44,    45,    46,
      47,    48,     0,    19,    38,    39,    40,    41,    42,    43,
      14,    18,    30,    17,    16,     0,    57,    54,     0,    69,
       0,    22,     0,    12,    55,     0,    10,    63,    64,    62,
      49,    52,     0,    53,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,     9,   -30,   -30,   -30,   -30,   -30,    -9,   -30,
      61,    69,    -6,    63,   -29,    80,   -30,   -20,   -14,   -30,
     -30,   -30,   -30,   -30,    24,   -30,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    13,   100,    14,    15,
      35,    29,    30,    75,    33,    16,    17,    31,   106,   107,
      18,    80,   115,    19,    52,    53,    20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      68,    36,    49,    26,    21,    25,    78,    62,    26,    32,
      41,    27,    37,    40,    62,    51,    34,    42,    82,    38,
      54,    43,   102,    85,    81,    83,    45,    28,    36,     1,
       2,     3,    28,     2,     3,    87,    88,    89,    90,    91,
      84,    76,    47,    95,    96,    97,    98,    99,    86,    93,
      44,    94,   103,   105,    92,   110,     4,   108,    45,     4,
       5,     6,     7,     5,     6,     7,   112,     6,   111,   101,
      26,    22,    46,   104,    47,    48,    82,    23,    45,   114,
     121,    24,   116,   122,    45,    63,    64,    65,    66,    67,
     119,   113,   120,   124,    28,    77,    61,    39,   117,    79,
      47,   118,    55,    56,    57,    58,    59,   123,   109,    50,
       0,    60,    69,    70,    71,    72,    73,    74,    55,    56,
      57,    58,    59,    23,    55,    56,    57,    58,    59
};

static const yytype_int8 yycheck[] =
{
      29,     7,    22,     4,     4,     4,    35,    27,     4,    14,
       5,    12,     0,     5,    34,     4,    12,    12,     4,    10,
      28,    16,    15,    13,    28,    45,    12,    28,    34,     3,
       4,     5,    28,     4,     5,    55,    56,    57,    58,    59,
      18,    32,    28,    63,    64,    65,    66,    67,    17,    13,
       4,    13,    13,     3,    60,     6,    30,    17,    12,    30,
      34,    35,    36,    34,    35,    36,     7,    35,    17,    75,
       4,     6,    26,    79,    28,    29,     4,    12,    12,     4,
      18,    16,     5,    13,    12,     7,     8,     9,    10,    11,
     110,   100,   112,   122,    28,    34,    27,    17,    26,    36,
      28,    29,     7,     8,     9,    10,    11,   121,    84,    22,
      -1,    16,    19,    20,    21,    22,    23,    24,     7,     8,
       9,    10,    11,    12,     7,     8,     9,    10,    11
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    30,    34,    35,    36,    41,    42,
      43,    44,    45,    46,    48,    49,    55,    56,    60,    63,
      66,     4,     6,    12,    16,     4,     4,    12,    28,    51,
      52,    57,    14,    54,    12,    50,    52,     0,    42,    55,
       5,     5,    12,    16,     4,    12,    26,    28,    29,    57,
      66,     4,    64,    65,    28,     7,     8,     9,    10,    11,
      16,    51,    57,     7,     8,     9,    10,    11,    54,    19,
      20,    21,    22,    23,    24,    53,    42,    50,    54,    53,
      61,    28,     4,    57,    18,    13,    17,    57,    57,    57,
      57,    57,    52,    13,    13,    57,    57,    57,    57,    57,
      47,    52,    15,    13,    52,     3,    58,    59,    17,    64,
       6,    17,     7,    48,     4,    62,     5,    26,    29,    57,
      57,    18,    13,    58,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    44,
      45,    47,    46,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    53,    53,    53,    53,    53,    53,
      54,    55,    55,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    58,    58,    59,    61,    62,    60,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      64,    65,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       6,     0,     5,     2,     0,     3,     3,     3,     3,     3,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     2,     1,     2,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       1,     1,     0,     4,     1,     2,     0,     0,     8,     3,
       3,     3,     6,     6,     6,     3,     2,     1,     0,     3,
       1,     1,     4
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_ID: /* ID  */
#line 81 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 863 "parser.tab.c"
        break;

    case YYSYMBOL_CHAR: /* CHAR  */
#line 83 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 869 "parser.tab.c"
        break;

    case YYSYMBOL_NUMBER: /* NUMBER  */
#line 82 "parser.y"
         { fprintf(yyoutput, "%d", ((*yyvaluep).number)); }
#line 875 "parser.tab.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 84 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 881 "parser.tab.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: DeclList  */
#line 97 "parser.y"
                   { 
					(yyval.ast) = (yyvsp[0].ast);
					 printf("\n--- Abstract Syntax Tree ---\n\n");
					 printAST((yyval.ast),0);

					}
#line 1276 "parser.tab.c"
    break;

  case 3: /* DeclList: Decl DeclList  */
#line 105 "parser.y"
                                { 
							  
							  (yyvsp[-1].ast)->left = (yyvsp[0].ast);
							  (yyval.ast) = (yyvsp[-1].ast);
							  
							}
#line 1287 "parser.tab.c"
    break;

  case 4: /* DeclList: Decl  */
#line 111 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 1293 "parser.tab.c"
    break;

  case 9: /* VarDecl: TYPE ID SEMICOLON  */
#line 120 "parser.y"
                                        { printf("\n RECOGNIZED RULE: Variable declaration %s\n", (yyvsp[-1].string));
									// Symbol Table
									symTabAccess();
									int inSymTab = found((yyvsp[-1].string), currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) 
										addItem((yyvsp[-1].string), "Var", (yyvsp[-2].string),0, currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[-1].string));
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    (yyval.ast) = AST_Type("Type",(yyvsp[-2].string),(yyvsp[-1].string));
									printf("-----------> %s\n", (yyval.ast)->LHS);
								}
#line 1314 "parser.tab.c"
    break;

  case 10: /* ArrayDecl: TYPE ID LeftBracket NUMBER RightBracket SEMICOLON  */
#line 138 "parser.y"
                                                                  {
								// Symbol Table

								
									int index=(yyvsp[-2].number);

									symTabAccess();
									int inSymTab = found((yyvsp[-4].string), currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) 
										addItem((yyvsp[-4].string), "Array", (yyvsp[-5].string),(yyvsp[-2].number), currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[-4].string));

									for(int i=0;i<index;i++){
										char id1[50];
										sprintf(id1, "%d", i);
										char id2[50];
										sprintf(id2, "%s", (yyvsp[-4].string));
										char new[50];
										sprintf(new, "%s[%s]", id2,id1);
										addItem(new, "Array", (yyvsp[-5].string),0, currentScope);

									}
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    (yyval.ast) = AST_Type("Array Type",(yyvsp[-5].string),(yyvsp[-4].string));
									printf("-----------> %s", (yyval.ast)->LHS);

}
#line 1351 "parser.tab.c"
    break;

  case 11: /* @1: %empty  */
#line 172 "parser.y"
                              {
	(yyval.ast) = AST_assignment("if", "", "");
	(yyval.ast)->left = (yyvsp[-1].ast);
	(yyval.ast)->left->left = (yyvsp[0].ast);
	emitGOTOContinue(); 
	emitMipsGOTOContinue(); 
	emitMipsNewLine(); 
	emitMipsIfElse(); 
	emitIfElseContinue();
	}
#line 1366 "parser.tab.c"
    break;

  case 12: /* IfStmt: IF CONDITIONIF Block @1 ElseStmt  */
#line 181 "parser.y"
                  {
	(yyval.ast) = appendNode((yyval.ast), (yyvsp[-1].ast));
	emitGOTOContinue();
	emitIfContinue();

	emitMipsGOTOContinue();
	emitMipsNewLine();
	emitMipsIfContinue();

}
#line 1381 "parser.tab.c"
    break;

  case 13: /* ElseStmt: ELSE Block  */
#line 192 "parser.y"
                     { 
	(yyval.ast) = AST_assignment("else", "", ""); 
	(yyval.ast)->left = (yyvsp[0].ast);
	
}
#line 1391 "parser.tab.c"
    break;

  case 14: /* ElseStmt: %empty  */
#line 197 "parser.y"
  {}
#line 1397 "parser.tab.c"
    break;

  case 15: /* WhileStmt: WHILE CONDITIONWHILE Block  */
#line 199 "parser.y"
                                     {
	//$$ = AST_assignment("WHILE", "", "");
	//$$->left = $2;
	//$$->left->left = $3;
	emitGoToWhile();
	emitWhileContinue();

	emitMipsGOTOWhile();
	emitMipsNewLine();
	emitMipsWhileContinue();

}
#line 1414 "parser.tab.c"
    break;

  case 16: /* CONDITIONWHILE: TestExpr TestOp TestExpr  */
#line 212 "parser.y"
                                         {
		printf("TEST OP: %s\n",(yyvsp[-1].ast));
		char id1[50];
		char id2[50];
		char id3[50];
		sprintf(id1, "%d", (yyvsp[-2].ast));
		sprintf(id2, "%s", (yyvsp[-1].ast));
		sprintf(id3, "%d", (yyvsp[0].ast));
		(yyval.ast) = AST_assignment((yyvsp[-1].ast), id1, id3);
		emitWhileCondition(id1,id2,id3);
		emitGoToWhileContinue();
		emitWhileTrue();

		if(strcmp(">",(yyvsp[-1].ast))==0){
			printf("TEST OP: %s\n",(yyvsp[-1].ast));
			emitMipsWhile();
			emitMipsWhileConditionGREAT(id1,id3);
			emitMipsGOTOWhileContinue();
			emitMipsNewLine();
			emitMipsWhileLoop();
		}
		if(strcmp("<",(yyvsp[-1].ast))==0){
			printf("TEST OP: %s\n",(yyvsp[-1].ast));
			emitMipsWhile();
			emitMipsWhileConditionLESS(id1,id3);
			emitMipsGOTOWhileContinue();
			emitMipsNewLine();
			emitMipsWhileLoop();
		}
		if(strcmp(">=",(yyvsp[-1].ast))==0){
			printf("TEST OP: %s\n",(yyvsp[-1].ast));
			emitMipsWhile();
			emitMipsWhileConditionGE(id1,id3);
			emitMipsGOTOWhileContinue();
			emitMipsNewLine();
			emitMipsWhileLoop();
		}
		if(strcmp("<=",(yyvsp[-1].ast))==0){
			printf("TEST OP: %s\n",(yyvsp[-1].ast));
			emitMipsWhile();
			emitMipsWhileConditionLE(id1,id3);
			emitMipsGOTOWhileContinue();
			emitMipsNewLine();
			emitMipsWhileLoop();
		}
		if(strcmp("==",(yyvsp[-1].ast))==0){
			printf("TEST OP: %s\n",(yyvsp[-1].ast));
			emitMipsWhile();
			emitMipsWhileConditionEQ(id1,id3);
			emitMipsGOTOWhileContinue();
			emitMipsNewLine();
			emitMipsWhileLoop();
		}


}
#line 1475 "parser.tab.c"
    break;

  case 17: /* CONDITIONWHILE: LeftPar CONDITIONWHILE RightPar  */
#line 268 "parser.y"
                                          {}
#line 1481 "parser.tab.c"
    break;

  case 18: /* CONDITIONIF: TestExpr TestOp TestExpr  */
#line 270 "parser.y"
                                      {
		printf("TEST OP: %s\n",(yyvsp[-1].ast));
		char id1[50];
		char id2[50];
		char id3[50];
		sprintf(id1, "%s", (yyvsp[-2].ast));
		sprintf(id2, "%s", (yyvsp[-1].ast));
		sprintf(id3, "%s", (yyvsp[0].ast));
		printf("HELP: %s\n", id2);
		emitIfCondition((yyvsp[-2].ast), id2, (yyvsp[0].ast));
		emitElseCondition();
		emitIfTrueCondition();
		if(strcmp(">",(yyvsp[-1].ast))==0){
			emitMipsIfConditionGREAT((yyvsp[-2].ast),(yyvsp[0].ast));
			emitMipsGOTOElse();
			emitMipsNewLine();
			emitMipsIfTrue();
		}
		if(strcmp("<",(yyvsp[-1].ast))==0){
			emitMipsIfConditionLESS((yyvsp[-2].ast),(yyvsp[0].ast));
			emitMipsGOTOElse();
			emitMipsNewLine();
			emitMipsIfTrue();
		}
		if(strcmp(">=",(yyvsp[-1].ast))==0){
			emitMipsIfConditionGE((yyvsp[-2].ast),(yyvsp[0].ast));
			emitMipsGOTOElse();
			emitMipsNewLine();
			emitMipsIfTrue();
		}
		if(strcmp("<=",(yyvsp[-1].ast))==0){
			emitMipsIfConditionLE((yyvsp[-2].ast),(yyvsp[0].ast));
			emitMipsGOTOElse();
			emitMipsNewLine();
			emitMipsIfTrue();
		}
		if(strcmp("==",(yyvsp[-1].ast))==0){
			emitMipsIfConditionGREAT((yyvsp[-2].ast),(yyvsp[0].ast));
			emitMipsGOTOElse();
			emitMipsNewLine();
			emitMipsIfTrue();
		}
		
		

}
#line 1532 "parser.tab.c"
    break;

  case 19: /* CONDITIONIF: LeftPar CONDITIONIF RightPar  */
#line 316 "parser.y"
                                       {(yyval.ast) = (yyvsp[-1].ast);}
#line 1538 "parser.tab.c"
    break;

  case 20: /* TestExpr: ID  */
#line 318 "parser.y"
             {(yyval.ast)=(yyvsp[0].string); }
#line 1544 "parser.tab.c"
    break;

  case 21: /* TestExpr: NUMBER  */
#line 319 "parser.y"
                 {char id2[50]; sprintf(id2, "%d", (yyvsp[0].number)); (yyval.ast)=id2; }
#line 1550 "parser.tab.c"
    break;

  case 22: /* TestExpr: ID LeftBracket TestExpr RightBracket  */
#line 320 "parser.y"
                                               {
		char id[50];
		sprintf(id, "%s[%d]", (yyvsp[-3].string),(yyvsp[-1].ast));
		(yyval.ast)=getValInt(id, currentScope);
	}
#line 1560 "parser.tab.c"
    break;

  case 23: /* TestExpr: OPERATION  */
#line 325 "parser.y"
                   {(yyval.ast)=(yyvsp[0].ast);}
#line 1566 "parser.tab.c"
    break;

  case 24: /* TestOp: EQ_COND  */
#line 328 "parser.y"
                {(yyval.ast)=(yyvsp[0].string);}
#line 1572 "parser.tab.c"
    break;

  case 25: /* TestOp: GREATER  */
#line 329 "parser.y"
                  {(yyval.ast)=(yyvsp[0].string);}
#line 1578 "parser.tab.c"
    break;

  case 26: /* TestOp: LESS  */
#line 330 "parser.y"
               {(yyval.ast)=(yyvsp[0].string);}
#line 1584 "parser.tab.c"
    break;

  case 27: /* TestOp: GREATER_EQ  */
#line 331 "parser.y"
                     {(yyval.ast)=(yyvsp[0].string);}
#line 1590 "parser.tab.c"
    break;

  case 28: /* TestOp: LESS_EQ  */
#line 332 "parser.y"
                  {(yyval.ast)=(yyvsp[0].string);}
#line 1596 "parser.tab.c"
    break;

  case 29: /* TestOp: NOT  */
#line 333 "parser.y"
              {(yyval.ast)=(yyvsp[0].string);}
#line 1602 "parser.tab.c"
    break;

  case 30: /* Block: LeftCurly DeclList RightCurly  */
#line 335 "parser.y"
                                       { 			
													(yyval.ast) = (yyvsp[-1].ast);
													printAST((yyvsp[-1].ast),0);
													
												}
#line 1612 "parser.tab.c"
    break;

  case 32: /* StmtList: Stmt StmtList  */
#line 343 "parser.y"
                        { 
							  if (strcmp((yyvsp[0].ast)->nodeType, "else") != 0 && strcmp((yyvsp[0].ast)->nodeType, ";") != 0) {(yyvsp[-1].ast)->left = (yyvsp[0].ast);}
							   (yyval.ast)=(yyvsp[-1].ast);
							  
							  
				}
#line 1623 "parser.tab.c"
    break;

  case 33: /* Stmt: SEMICOLON  */
#line 351 "parser.y"
                        {}
#line 1629 "parser.tab.c"
    break;

  case 34: /* Stmt: Expr SEMICOLON  */
#line 352 "parser.y"
                                {(yyval.ast) = (yyvsp[-1].ast); }
#line 1635 "parser.tab.c"
    break;

  case 38: /* OPERATION: LeftPar OPERATION RightPar  */
#line 358 "parser.y"
                                      {}
#line 1641 "parser.tab.c"
    break;

  case 39: /* OPERATION: NUMBER PLUS_OP OPERATION  */
#line 360 "parser.y"
        {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[-2].number));
		sprintf(id2, "%c", (char)43);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1661 "parser.tab.c"
    break;

  case 40: /* OPERATION: NUMBER SUB_OP OPERATION  */
#line 376 "parser.y"
        {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[-2].number));
		sprintf(id2, "%c", (char)45);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1681 "parser.tab.c"
    break;

  case 41: /* OPERATION: NUMBER MULT_OP OPERATION  */
#line 392 "parser.y"
        {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[-2].number));
		sprintf(id2, "%c", (char)42);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1701 "parser.tab.c"
    break;

  case 42: /* OPERATION: NUMBER DIV_OP OPERATION  */
#line 408 "parser.y"
        {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[-2].number));
		sprintf(id2, "%c", (char)47);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1721 "parser.tab.c"
    break;

  case 43: /* OPERATION: NUMBER CAR_OP OPERATION  */
#line 424 "parser.y"
        {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[-2].number));
		sprintf(id2, "%c", (char)94);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1741 "parser.tab.c"
    break;

  case 44: /* OPERATION: ID PLUS_OP OPERATION  */
#line 440 "parser.y"
        {	

		
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt((yyvsp[-2].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[-2].string), currentScope));
		}
		char id2[50];
		//char id3[50];
		
		sprintf(id2, "%c", (char)43);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1771 "parser.tab.c"
    break;

  case 45: /* OPERATION: ID SUB_OP OPERATION  */
#line 466 "parser.y"
        {	
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt((yyvsp[-2].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[-2].string), currentScope));
		}
		char id2[50];
		//char id3[50];
		sprintf(id2, "%c", (char)45);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1798 "parser.tab.c"
    break;

  case 46: /* OPERATION: ID MULT_OP OPERATION  */
#line 489 "parser.y"
        {	
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt((yyvsp[-2].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[-2].string), currentScope));
		}
		char id2[50];
		//char id3[50];
		sprintf(id2, "%c", (char)42);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1825 "parser.tab.c"
    break;

  case 47: /* OPERATION: ID DIV_OP OPERATION  */
#line 512 "parser.y"
        {	
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt((yyvsp[-2].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[-2].string), currentScope));
		}
		char id2[50];
		//char id3[50];
		sprintf(id2, "%c", (char)47);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1852 "parser.tab.c"
    break;

  case 48: /* OPERATION: ID CAR_OP OPERATION  */
#line 535 "parser.y"
        {	
		int idVal=getValInt(idVal, currentScope);
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt((yyvsp[-2].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[-2].string), currentScope));
		} 
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[-2].string));
		sprintf(id2, "%c", (char)94);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
#line 1881 "parser.tab.c"
    break;

  case 49: /* OPERATION: LeftPar OPERATION RightPar PLUS_OP OPERATION  */
#line 560 "parser.y"
        {	
		initialized();
		//char id1[50];
		char id2[50];
		//char id3[50];
		//sprintf(id1, "%d", $2);
		sprintf(id2, "%c", (char)43);
		//sprintf(id3, "%d", $3);
		//printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id2);
		//printf("OPERATION %s\n", id3);
		//insertValues(id2);
		insertValues(id2);
		//insertValues(id3);
	}
#line 1901 "parser.tab.c"
    break;

  case 50: /* OPERATION: NUMBER  */
#line 576 "parser.y"
        { 
		initialized();
		printf("\n%d\n", funcOp);
		char id[50];
		sprintf(id, "%d", (yyvsp[0].number));
		printf("OPERATION %s\n", id);
		insertValues(id);
		//$$=$1; 
	}
#line 1915 "parser.tab.c"
    break;

  case 51: /* OPERATION: ID  */
#line 586 "parser.y"
        {
		initialized();
		int z;
		char id[50];
		printf("\n%d\n", funcOp);
		if (funcOp == 0)  {
			z=getValInt((yyvsp[0].string), currentScope);
			
			sprintf(id, "%d", z);
		}
		else {
			sprintf(id, "%s", (yyvsp[0].string));
		}
		printf("OPERATION %s\n", id);
		insertValues(id);
	}
#line 1936 "parser.tab.c"
    break;

  case 52: /* ParamDecl: %empty  */
#line 621 "parser.y"
                { (yyval.ast) = AST_assignment("ParamList", "", "null");}
#line 1942 "parser.tab.c"
    break;

  case 53: /* ParamDecl: TYPE ID COMMA ParamDecl  */
#line 622 "parser.y"
                                          { printf("\n RECOGNIZED RULE: Param declaration %s\n", (yyvsp[-2].string));
									(yyval.ast) = AST_Type("Param",(yyvsp[-3].string), (yyvsp[-2].string));
									(yyval.ast)->left = (yyvsp[0].ast);
									// Symbol Table
									symTabAccess();
									int inSymTab = found((yyvsp[-2].string), "_function_param");
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) {
										addItem((yyvsp[-2].string), "Param", (yyvsp[-3].string),0, "_function_param");
										addRegVal((yyvsp[-2].string), "_function_param", parIdx);
										strcpy(funParType[parIdx], (yyvsp[-3].string));
										parIdx++;
									}
										
									else {
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[-2].string));
										semanticCheckPassed = 0;
									}
										
									
	}
#line 1969 "parser.tab.c"
    break;

  case 54: /* ParamDecl: ParamDeclEnd  */
#line 644 "parser.y"
                               {(yyval.ast)=(yyvsp[0].ast);}
#line 1975 "parser.tab.c"
    break;

  case 55: /* ParamDeclEnd: TYPE ID  */
#line 647 "parser.y"
                      { printf("\n RECOGNIZED RULE: Param declaration %s\n", (yyvsp[0].string));
									(yyval.ast) = AST_Type("Param",(yyvsp[-1].string), (yyvsp[0].string));
									// Symbol Table
									symTabAccess();
									int inSymTab = found((yyvsp[0].string), "_function_param");
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) {
										addItem((yyvsp[0].string), "Param", (yyvsp[-1].string),0, "_function_param");
										addRegVal((yyvsp[0].string), "_function_param", parIdx);
										strcpy(funParType[parIdx], (yyvsp[-1].string));
										parIdx++;
									}
										
									else {
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[0].string));
										semanticCheckPassed = 0;
									}
}
#line 1999 "parser.tab.c"
    break;

  case 56: /* @2: %empty  */
#line 668 "parser.y"
                                { emitFunction((yyvsp[-1].string)); 
								emitMIPSFunction((yyvsp[-1].string)); funcOp = 1; strcpy(currentScope, (yyvsp[-1].string));}
#line 2006 "parser.tab.c"
    break;

  case 57: /* @3: %empty  */
#line 669 "parser.y"
                                                                                                                                      { updateScopes((yyvsp[-3].string)); strcpy(funcType, (yyvsp[-4].string));}
#line 2012 "parser.tab.c"
    break;

  case 58: /* Function: TYPE ID LeftPar @2 ParamDecl @3 RightPar Block  */
#line 669 "parser.y"
                                                                                                                                                                                               {
							strcpy(currentScope, "global");
							
							
							symTabAccess();
							int inSymTab = found((yyvsp[-6].string), currentScope);
									
							if (inSymTab == 0) 
								addItem((yyvsp[-6].string), "Function", (yyvsp[-7].string),0, currentScope);
							else {
								printf("SEMANTIC ERROR: Function %s has already been defined. \n", (yyvsp[-6].string));
								semanticCheckPassed = 0;
							}
							if (semanticCheckPassed == 1) {
								printf("Function is semantically correct.");
								for(int i = 0; i < parIdx; i++) {
									addFunPar((yyvsp[-6].string), funParType[i], i);
								}
								parIdx=0;
								
							}
							strcpy(funcType, "");
							
							(yyval.ast)  = AST_Write("Function",(yyvsp[-7].string),(yyvsp[-6].string));
							(yyvsp[-4].ast)->left = (yyvsp[-2].ast);
							(yyval.ast)->left = (yyvsp[-4].ast);
							funcOp = 0;
			}
#line 2045 "parser.tab.c"
    break;

  case 59: /* Expr: ID EQ OPERATION  */
#line 701 "parser.y"
                        {
		printf("\n RECOGNIZED RULE: OPERATION\n");
		if(found((yyvsp[-2].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-2].string), currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

		printf("\nChecking types: \n");

		//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
		if(strcmp(getVariableType((yyvsp[-2].string), currentScope),"int") != 0) {
			printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", (yyvsp[-2].string), currentScope);
			semanticCheckPassed = 0;
		}
		reverseOpList();
		int operationTotal=calculateAll();
		deleteAll();
		char opTemp[50];
		sprintf(opTemp, "%d", operationTotal);
		(yyval.ast) = AST_assignment("=",(yyvsp[-2].string),opTemp);
		if (semanticCheckPassed == 1) {
							printf("\n\nOPERATION: Rule is semantically correct!\n\n");
							updateValueInt((yyvsp[-2].string), currentScope, operationTotal);
							char id2[50];
							sprintf(id2, "%d", operationTotal);
							showSymTable();
							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantIntAssignment((yyvsp[-2].string), id2);
							

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantIntAssignment((yyvsp[-2].string), id2);
							

						}

	}
#line 2100 "parser.tab.c"
    break;

  case 60: /* Expr: ID EQ CHAR  */
#line 751 "parser.y"
                     {
		printf("\n RECOGNIZED RULE: ID CHAR\n");
		if(found((yyvsp[-2].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-2].string), currentScope);
							semanticCheckPassed = 0;
						}
						if(strcmp(getVariableType((yyvsp[-2].string), currentScope),"char") != 0) {
							printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", (yyvsp[-2].string), currentScope);
							semanticCheckPassed = 0;
		}
		char id[50];
		sprintf(id, "%s", (yyvsp[0].string));
		char act=id[1];
		updateValueChar((yyvsp[-2].string),currentScope,act);
		showSymTable();
		printf("TEST CHAR %c\n",act);
		(yyval.ast) = AST_assignment("=",(yyvsp[-2].string),(yyvsp[0].string));
		// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantCharAssignment((yyvsp[-2].string), act);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantCharAssignment((yyvsp[-2].string), act);

						
	}
#line 2141 "parser.tab.c"
    break;

  case 61: /* Expr: ID EQ FLOAT  */
#line 788 "parser.y"
                      {
		printf("\n RECOGNIZED RULE: ID FLOAT\n");
		if(found((yyvsp[-2].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-2].string), currentScope);
							semanticCheckPassed = 0;
						}
						if(strcmp(getVariableType((yyvsp[-2].string), currentScope),"float") != 0) {
							printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", (yyvsp[-2].string), currentScope);
							semanticCheckPassed = 0;
		}
		char id[50];
		sprintf(id, "%s", (yyvsp[0].string));
		float convert=atof(id);
		updateValueFloat((yyvsp[-2].string),currentScope,convert);
		showSymTable();
		printf("TEST FLOAT %f\n",convert);
		(yyval.ast) = AST_assignment("=",(yyvsp[-2].string),(yyvsp[0].string));
		// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantFloatAssignment((yyvsp[-2].string), id);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantFloatAssignment((yyvsp[-2].string), id);

						
	}
#line 2182 "parser.tab.c"
    break;

  case 62: /* Expr: ID LeftBracket NUMBER RightBracket EQ OPERATION  */
#line 825 "parser.y"
                                                                { printf("\n RECOGNIZED RULE: ARRAY OPERATION\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ---- //
					char id1[50];
					char id2[50];
					sprintf(id1, "%s",(yyvsp[-5].string));
					sprintf(id2, "%d",(yyvsp[-3].number));
					char fullIndex[50];
					sprintf(fullIndex, "%s[%s]",id1,id2);
					if(found(fullIndex, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-5].string), currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

		printf("\nChecking types: \n");

		//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
		if(strcmp(getVariableType(fullIndex, currentScope),"int") != 0) {
			printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", (yyvsp[-5].string), currentScope);
			semanticCheckPassed = 0;
		}
		reverseOpList();
		int operationTotal=calculateAll();
		deleteAll();
		char opTemp[50];
		sprintf(opTemp, "%d", operationTotal);
		(yyval.ast) = AST_assignment("=",(yyvsp[-5].string),opTemp);
		if (semanticCheckPassed == 1) {
							printf("\n\nOPERATION: Rule is semantically correct!\n\n");
							char id3[50];
							sprintf(id3, "%d", operationTotal);
							updateValueInt(fullIndex,currentScope, id3);
							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantIntAssignment(fullIndex, id3);
							

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantIntAssignment(fullIndex, id3);
							


					}
					

				}
#line 2244 "parser.tab.c"
    break;

  case 63: /* Expr: ID LeftBracket NUMBER RightBracket EQ CHAR  */
#line 883 "parser.y"
                                                     {
		char id1[50];
		char id2[50];
		sprintf(id1, "%s",(yyvsp[-5].string));
		sprintf(id2, "%d",(yyvsp[-3].number));
		char fullIndex[50];
		char regIndex[50];
		sprintf(fullIndex, "%s[%s]",id1,id2);
		sprintf(regIndex, "%s%s",id2,id1);
		printf("FULL INDEX: %s\n",fullIndex);
		printf("\n RECOGNIZED RULE: ID CHAR\n");
		if(found(fullIndex, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-5].string), currentScope);
							semanticCheckPassed = 0;
						}
						if(strcmp(getVariableType(fullIndex, currentScope),"char") != 0) {
							printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", (yyvsp[-5].string), currentScope);
							semanticCheckPassed = 0;
		}
		char id[50];
		sprintf(id, "%s", (yyvsp[0].string));
		char act=id[1];
		updateValueChar(fullIndex,currentScope,act);
		showSymTable();
		printf("TEST CHAR %c\n",act);
		(yyval.ast) = AST_assignment("=",fullIndex,(yyvsp[0].string));
		// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantCharAssignment(fullIndex, act);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantCharAssignment(fullIndex, act);

						
	}
#line 2294 "parser.tab.c"
    break;

  case 64: /* Expr: ID LeftBracket NUMBER RightBracket EQ FLOAT  */
#line 929 "parser.y"
                                              {
		char id1[50];
		char id2[50];
		sprintf(id1, "%s",(yyvsp[-5].string));
		sprintf(id2, "%d",(yyvsp[-3].number));
		char fullIndex[50];
		sprintf(fullIndex, "%s[%s]",id1,id2);
		printf("\n RECOGNIZED RULE: ID FLOAT\n");
		if(found(fullIndex, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-5].string), currentScope);
							semanticCheckPassed = 0;
						}
						if(strcmp(getVariableType(fullIndex, currentScope),"float") != 0) {
							printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", (yyvsp[-5].string), currentScope);
							semanticCheckPassed = 0;
		}
		char id[50];
		sprintf(id, "%s", (yyvsp[0].string));
		float convert=atof(id);
		updateValueFloat(fullIndex,currentScope,convert);
		showSymTable();
		printf("TEST FLOAT %f\n",convert);
		(yyval.ast) = AST_assignment("=",fullIndex,(yyvsp[-3].number));
		// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantFloatAssignment(fullIndex, id);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantFloatAssignment(fullIndex, id);

						
	}
#line 2341 "parser.tab.c"
    break;

  case 65: /* Expr: ID EQ FuncCall  */
#line 973 "parser.y"
                         {
		(yyval.ast) = (yyvsp[0].ast);
		emitCallIDFunction((yyvsp[-2].string));
		emitMIPSCallIDFunction((yyvsp[-2].string));
	}
#line 2351 "parser.tab.c"
    break;

  case 66: /* Expr: WRITE ID  */
#line 979 "parser.y"
                        { printf("\n RECOGNIZED RULE: WRITE statement\n");
					char id[50];
					sprintf(id, "%s", (yyvsp[0].string));
					(yyval.ast) = AST_Write("write",id,"");
					
					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared
					    if(found((yyvsp[0].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[0].string), currentScope);
							semanticCheckPassed = 0;
						}

					if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");

							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							
							emitWriteId((yyvsp[0].string));

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers

							emitMIPSWriteId((yyvsp[0].string));
						}
				}
#line 2389 "parser.tab.c"
    break;

  case 67: /* Expr: FuncCall  */
#line 1012 "parser.y"
                                           {(yyval.ast)=(yyvsp[0].ast);}
#line 2395 "parser.tab.c"
    break;

  case 68: /* CallParam: %empty  */
#line 1020 "parser.y"
                { (yyval.ast) = AST_assignment("ParamList", "", "null");}
#line 2401 "parser.tab.c"
    break;

  case 69: /* CallParam: ID COMMA CallParam  */
#line 1021 "parser.y"
                                     { printf("\n RECOGNIZED RULE: Param call %s\n", (yyvsp[-2].string));
									(yyval.ast) = AST_Write("Param",(yyvsp[-2].string),""); 
									(yyval.ast)->left = (yyvsp[0].ast);
									strcpy(funcParams[paramIdx], (yyvsp[-2].string));
									paramIdx++;
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									}
#line 2414 "parser.tab.c"
    break;

  case 70: /* CallParam: CallParamEnd  */
#line 1029 "parser.y"
                               {
			(yyval.ast) = (yyvsp[0].ast);}
#line 2421 "parser.tab.c"
    break;

  case 71: /* CallParamEnd: ID  */
#line 1033 "parser.y"
                 { 
				(yyval.ast) = AST_Write("Param",(yyvsp[0].string),"");
				printf("\n RECOGNIZED RULE: Param Call %s\n", (yyvsp[0].string));
				strcpy(funcParams[paramIdx], (yyvsp[0].string));
				paramIdx++;
				
}
#line 2433 "parser.tab.c"
    break;

  case 72: /* FuncCall: ID LeftPar CallParam RightPar  */
#line 1042 "parser.y"
                                              {

				if(found((yyvsp[-3].string), currentScope) != 1) {
					printf("SEMANTIC ERROR: Function %s has NOT been declared in scope %s \n", (yyvsp[-3].string), currentScope);
					semanticCheckPassed = 0;
				}
				strcpy(funcType, (yyvsp[-3].string)); 
				
				for(int i = 0; i <paramIdx; i++) {
					if(found(funcParams[i], currentScope) != 1) {
						printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", funcParams[i], currentScope);
						semanticCheckPassed = 0;
					}
					/*
					if(strcmp(getVariableType(funcParams[i], currentScope), getFunPar(funcType, i)) != 0) {
						printf("SEMANTIC ERROR: Variable %s of type: %s must match the function param type: %s \n", funcParams[i], getVariableType(funcParams[i], currentScope), getFunPar(funcType, parIdx));
						semanticCheckPassed = 0;
					}
					*/
					if (semanticCheckPassed == 1)
						emitMipsParam(i, getValInt(funcParams[i], currentScope));
				}
				
				(yyval.ast) = AST_Write("FuncCall",(yyvsp[-3].string),""); 
				(yyval.ast)->left = (yyvsp[-1].ast); 
				if (semanticCheckPassed == 1) {
					for(int i = 0; i <paramIdx; i++) {
						emitParam(i, funcParams[i]);
					}
					emitCallFunction((yyvsp[-3].string));
					emitMIPSCallFunction((yyvsp[-3].string));
				}

			}
#line 2472 "parser.tab.c"
    break;


#line 2476 "parser.tab.c"

      default: break;
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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1080 "parser.y"


int main(int argc, char**argv)
{
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");
	int i;
	double total_time;
	clock_t start, end;
	start = clock();
	//time count starts 
	srand(time(NULL));
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}

	// Initialize IR and MIPS files
	initIRcodeFile();
	initAssemblyFile();

	// Start parser
	yyparse();

	// Add the closing part required for any MIPS file
	emitEndOfAssemblyCode();
	dataWrite();
	closeMIPS();

	cleanCode();

	end = clock();
	//time count stops 
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	//calulate total time
	printf("\nTime taken to compile is: %f\n", total_time);
	return 0;

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
