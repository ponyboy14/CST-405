
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


/* Line 189 of yacc.c  */
#line 106 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TYPE = 258,
     ID = 259,
     SEMICOLON = 260,
     EQ = 261,
     PLUS_OP = 262,
     SUB_OP = 263,
     MULT_OP = 264,
     DIV_OP = 265,
     CAR_OP = 266,
     LeftPar = 267,
     RightPar = 268,
     LeftCurly = 269,
     RightCurly = 270,
     LeftBracket = 271,
     RightBracket = 272,
     COMMA = 273,
     DOT = 274,
     CHAR = 275,
     QUOTE = 276,
     NUMBER = 277,
     FLOAT = 278,
     WRITE = 279,
     WRITELN = 280,
     READ = 281,
     RETURN = 282
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 33 "parser.y"

	int number;
	char character;
	char* string;
	struct AST* ast;



/* Line 214 of yacc.c  */
#line 178 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 190 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   81

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNRULES -- Number of states.  */
#define YYNSTATES  87

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      22,    29,    30,    33,    35,    38,    42,    46,    50,    54,
      58,    62,    66,    70,    74,    78,    82,    88,    90,    92,
      99,   100,   105,   107,   110,   111,   112,   121,   125,   129,
     136,   140,   143,   145,   146,   150,   152,   154
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      29,     0,    -1,    30,    -1,    31,    30,    -1,    31,    -1,
      32,    -1,    40,    -1,    34,    -1,    33,    -1,     3,     4,
       5,    -1,     3,     4,    16,    22,    17,     5,    -1,    -1,
      35,    34,    -1,     5,    -1,    43,     5,    -1,    12,    36,
      13,    -1,    22,     7,    36,    -1,    22,     8,    36,    -1,
      22,     9,    36,    -1,    22,    10,    36,    -1,    22,    11,
      36,    -1,     4,     7,    36,    -1,     4,     8,    36,    -1,
       4,     9,    36,    -1,     4,    10,    36,    -1,     4,    11,
      36,    -1,    12,    36,    13,     7,    36,    -1,    22,    -1,
       4,    -1,    14,    30,    27,     4,     5,    15,    -1,    -1,
       3,     4,    18,    38,    -1,    39,    -1,     3,     4,    -1,
      -1,    -1,     3,     4,    12,    41,    38,    42,    13,    37,
      -1,     4,     6,    36,    -1,     4,     6,    20,    -1,     4,
      16,    22,    17,     6,    36,    -1,     4,     6,    46,    -1,
      24,     4,    -1,    46,    -1,    -1,     4,    18,    44,    -1,
      45,    -1,     4,    -1,     4,    12,    44,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    85,    88,    91,    92,    93,    94,    97,
     115,   148,   149,   154,   155,   158,   159,   175,   191,   207,
     223,   239,   265,   288,   311,   334,   359,   375,   385,   404,
     421,   422,   444,   447,   468,   469,   468,   501,   557,   575,
     639,   645,   676,   682,   683,   691,   695,   704
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "ID", "SEMICOLON", "EQ",
  "PLUS_OP", "SUB_OP", "MULT_OP", "DIV_OP", "CAR_OP", "LeftPar",
  "RightPar", "LeftCurly", "RightCurly", "LeftBracket", "RightBracket",
  "COMMA", "DOT", "CHAR", "QUOTE", "NUMBER", "FLOAT", "WRITE", "WRITELN",
  "READ", "RETURN", "$accept", "Program", "DeclList", "Decl", "VarDecl",
  "ArrayDecl", "StmtList", "Stmt", "OPERATION", "Block", "ParamDecl",
  "ParamDeclEnd", "Function", "@1", "@2", "Expr", "CallParam",
  "CallParamEnd", "FuncCall", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    31,    31,    31,    32,
      33,    34,    34,    35,    35,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    37,
      38,    38,    38,    39,    41,    42,    40,    43,    43,    43,
      43,    43,    43,    44,    44,    44,    45,    46
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       6,     0,     2,     1,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     1,     1,     6,
       0,     4,     1,     2,     0,     0,     8,     3,     3,     6,
       3,     2,     1,     0,     3,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     0,    13,     0,     0,     2,     4,     5,     8,
       7,    11,     6,     0,    42,     0,     0,    43,     0,    41,
       1,     3,    12,    14,     9,    34,     0,    28,     0,    38,
      27,    37,    40,    46,     0,    45,     0,    30,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,    43,    47,     0,     0,    35,    32,     0,    21,    22,
      23,    24,    25,    15,    16,    17,    18,    19,    20,    44,
       0,    33,     0,    10,     0,    39,    30,     0,    26,    31,
      11,    36,     0,     0,     0,     0,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    11,    31,    81,
      55,    56,    12,    37,    72,    13,    34,    35,    14
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -28
static const yytype_int8 yypact[] =
{
       0,    -2,    25,   -28,     4,    11,   -28,     0,   -28,   -28,
     -28,     2,   -28,    27,   -28,    24,     5,    26,    12,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,    13,    41,     6,   -28,
      47,   -28,   -28,    15,    29,   -28,    21,    36,    28,     6,
       6,     6,     6,     6,    52,    31,     6,     6,     6,     6,
       6,    26,   -28,    40,    60,   -28,   -28,    61,   -28,   -28,
     -28,   -28,   -28,    58,   -28,   -28,   -28,   -28,   -28,   -28,
       6,    49,    55,   -28,     6,   -28,    36,    56,   -28,   -28,
       0,   -28,    42,    67,    69,    57,   -28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,    -7,   -28,   -28,   -28,    64,   -28,   -27,   -28,
       1,   -28,   -28,   -28,   -28,   -28,    30,   -28,    62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      21,    45,    15,     1,     2,     3,     2,     3,    19,    27,
      44,    20,    58,    59,    60,    61,    62,    28,    28,    64,
      65,    66,    67,    68,     4,    29,     4,    30,    30,    24,
      33,    16,    23,    51,    36,    38,    25,    17,    53,    54,
      26,    18,    52,    75,    63,    57,    70,    78,    39,    40,
      41,    42,    43,    17,    46,    47,    48,    49,    50,    39,
      40,    41,    42,    43,    71,    74,    73,    76,    77,    83,
      80,    84,    86,    82,    85,    22,     0,    79,    32,     0,
       0,    69
};

static const yytype_int8 yycheck[] =
{
       7,    28,     4,     3,     4,     5,     4,     5,     4,     4,
       4,     0,    39,    40,    41,    42,    43,    12,    12,    46,
      47,    48,    49,    50,    24,    20,    24,    22,    22,     5,
       4,     6,     5,    18,    22,    22,    12,    12,    17,     3,
      16,    16,    13,    70,    13,    17,     6,    74,     7,     8,
       9,    10,    11,    12,     7,     8,     9,    10,    11,     7,
       8,     9,    10,    11,     4,     7,     5,    18,    13,    27,
      14,     4,    15,    80,     5,    11,    -1,    76,    16,    -1,
      -1,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    24,    29,    30,    31,    32,    33,
      34,    35,    40,    43,    46,     4,     6,    12,    16,     4,
       0,    30,    34,     5,     5,    12,    16,     4,    12,    20,
      22,    36,    46,     4,    44,    45,    22,    41,    22,     7,
       8,     9,    10,    11,     4,    36,     7,     8,     9,    10,
      11,    18,    13,    17,     3,    38,    39,    17,    36,    36,
      36,    36,    36,    13,    36,    36,    36,    36,    36,    44,
       6,     4,    42,     5,     7,    36,    18,    13,    36,    38,
      14,    37,    30,    27,     4,     5,    15
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      case 4: /* "ID" */

/* Line 715 of yacc.c  */
#line 66 "parser.y"
	{ fprintf(yyoutput, "%s", (yyvaluep->string)); };

/* Line 715 of yacc.c  */
#line 790 "parser.tab.c"
	break;
      case 22: /* "NUMBER" */

/* Line 715 of yacc.c  */
#line 67 "parser.y"
	{ fprintf(yyoutput, "%d", (yyvaluep->number)); };

/* Line 715 of yacc.c  */
#line 799 "parser.tab.c"
	break;
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    { 
					(yyval.ast) = (yyvsp[(1) - (1)].ast);
					 //printf("\n--- Abstract Syntax Tree ---\n\n");
					 //printAST($$,0);

					;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { (yyvsp[(1) - (2)].ast)->left = (yyvsp[(2) - (2)].ast);
							  (yyval.ast) = (yyvsp[(1) - (2)].ast);
							;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    { printf("\n RECOGNIZED RULE: Variable declaration %s\n", (yyvsp[(2) - (3)].string));
									// Symbol Table
									symTabAccess();
									int inSymTab = found((yyvsp[(2) - (3)].string), currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) 
										addItem((yyvsp[(2) - (3)].string), "Var", (yyvsp[(1) - (3)].string),0, currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (3)].string));
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    (yyval.ast) = AST_Type("Type",(yyvsp[(1) - (3)].string),(yyvsp[(2) - (3)].string));
									printf("-----------> %s\n", (yyval.ast)->LHS);
								;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {
								// Symbol Table

								
									int index=(yyvsp[(4) - (6)].number);

									symTabAccess();
									int inSymTab = found((yyvsp[(2) - (6)].string), currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) 
										addItem((yyvsp[(2) - (6)].string), "Array", (yyvsp[(1) - (6)].string),(yyvsp[(4) - (6)].number), currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (6)].string));

									for(int i=0;i<index;i++){
										char id1[50];
										sprintf(id1, "%d", i);
										char id2[50];
										sprintf(id2, "%s", (yyvsp[(2) - (6)].string));
										char new[50];
										sprintf(new, "%s[%s]", id2,id1);
										addItem(new, "Array", (yyvsp[(1) - (6)].string),0, currentScope);

									}
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    (yyval.ast) = AST_Type("Array Type",(yyvsp[(1) - (6)].string),(yyvsp[(2) - (6)].string));
									printf("-----------> %s", (yyval.ast)->LHS);

;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    { (yyvsp[(1) - (2)].ast)->left = (yyvsp[(2) - (2)].ast);
							  (yyval.ast) = (yyvsp[(1) - (2)].ast);
				;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {(yyval.ast) = (yyvsp[(1) - (2)].ast);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[(1) - (3)].number));
		sprintf(id2, "%c", (char)43);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[(1) - (3)].number));
		sprintf(id2, "%c", (char)45);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[(1) - (3)].number));
		sprintf(id2, "%c", (char)42);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[(1) - (3)].number));
		sprintf(id2, "%c", (char)47);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[(1) - (3)].number));
		sprintf(id2, "%c", (char)94);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    {	

		
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getVal((yyvsp[(1) - (3)].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[(1) - (3)].string), currentScope));
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
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {	
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getVal((yyvsp[(1) - (3)].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[(1) - (3)].string), currentScope));
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
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 289 "parser.y"
    {	
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getVal((yyvsp[(1) - (3)].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[(1) - (3)].string), currentScope));
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
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 312 "parser.y"
    {	
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getVal((yyvsp[(1) - (3)].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[(1) - (3)].string), currentScope));
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
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    {	
		int idVal=getVal(idVal, currentScope);
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getVal((yyvsp[(1) - (3)].string), currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal((yyvsp[(1) - (3)].string), currentScope));
		} 
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", (yyvsp[(1) - (3)].string));
		sprintf(id2, "%c", (char)94);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 360 "parser.y"
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
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 376 "parser.y"
    { 
		initialized();
		printf("\n%d\n", funcOp);
		char id[50];
		sprintf(id, "%d", (yyvsp[(1) - (1)].number));
		printf("OPERATION %s\n", id);
		insertValues(id);
		//$$=$1; 
	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 386 "parser.y"
    {
		initialized();
		int z;
		char id[50];
		printf("\n%d\n", funcOp);
		if (funcOp == 0)  {
			z=getVal((yyvsp[(1) - (1)].string), currentScope);
			
			sprintf(id, "%d", z);
		}
		else {
			sprintf(id, "%s", (yyvsp[(1) - (1)].string));
		}
		printf("OPERATION %s\n", id);
		insertValues(id);
	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 404 "parser.y"
    { 
													(yyval.ast) = (yyvsp[(2) - (6)].ast);

													if(strcmp(getVariableType((yyvsp[(4) - (6)].string),currentScope), funcType) != 0) {
														printf("SEMANTIC ERROR: Return type must be the same as Function stype. \n", (yyvsp[(2) - (6)].ast));
														semanticCheckPassed = 0;
													}
													
													if (semanticCheckPassed == 1)  {
														emitReturn((yyvsp[(4) - (6)].string)); 
														emitMIPSReturn((yyvsp[(4) - (6)].string));
													}
													
												;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 421 "parser.y"
    { (yyval.ast) = AST_assignment("ParamList", "", "null");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 422 "parser.y"
    { printf("\n RECOGNIZED RULE: Param declaration %s\n", (yyvsp[(2) - (4)].string));
									(yyval.ast) = AST_Type("Param",(yyvsp[(1) - (4)].string), (yyvsp[(2) - (4)].string));
									(yyval.ast)->left = (yyvsp[(4) - (4)].ast);
									// Symbol Table
									symTabAccess();
									int inSymTab = found((yyvsp[(2) - (4)].string), "_function_param");
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) {
										addItem((yyvsp[(2) - (4)].string), "Param", (yyvsp[(1) - (4)].string),0, "_function_param");
										addRegVal((yyvsp[(2) - (4)].string), "_function_param", parIdx);
										strcpy(funParType[parIdx], (yyvsp[(1) - (4)].string));
										parIdx++;
									}
										
									else {
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (4)].string));
										semanticCheckPassed = 0;
									}
										
									
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 444 "parser.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 447 "parser.y"
    { printf("\n RECOGNIZED RULE: Param declaration %s\n", (yyvsp[(2) - (2)].string));
									(yyval.ast) = AST_Type("Param",(yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
									// Symbol Table
									symTabAccess();
									int inSymTab = found((yyvsp[(2) - (2)].string), "_function_param");
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) {
										addItem((yyvsp[(2) - (2)].string), "Param", (yyvsp[(1) - (2)].string),0, "_function_param");
										addRegVal((yyvsp[(2) - (2)].string), "_function_param", parIdx);
										strcpy(funParType[parIdx], (yyvsp[(1) - (2)].string));
										parIdx++;
									}
										
									else {
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (2)].string));
										semanticCheckPassed = 0;
									}
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 468 "parser.y"
    { emitFunction((yyvsp[(2) - (3)].string)); 
								emitMIPSFunction((yyvsp[(2) - (3)].string)); funcOp = 1; strcpy(currentScope, (yyvsp[(2) - (3)].string));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 469 "parser.y"
    { updateScopes((yyvsp[(2) - (5)].string)); strcpy(funcType, (yyvsp[(1) - (5)].string));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 469 "parser.y"
    {
							strcpy(currentScope, "global");
							
							
							symTabAccess();
							int inSymTab = found((yyvsp[(2) - (8)].string), currentScope);
									
							if (inSymTab == 0) 
								addItem((yyvsp[(2) - (8)].string), "Function", (yyvsp[(1) - (8)].string),0, currentScope);
							else {
								printf("SEMANTIC ERROR: Function %s has already been defined. \n", (yyvsp[(2) - (8)].string));
								semanticCheckPassed = 0;
							}
							if (semanticCheckPassed == 1) {
								printf("Function is semantically correct.");
								for(int i = 0; i < parIdx; i++) {
									addFunPar((yyvsp[(2) - (8)].string), funParType[i], i);
								}
								parIdx=0;
								
							}
							strcpy(funcType, "");
							
							(yyval.ast)  = AST_Write("Function",(yyvsp[(1) - (8)].string),(yyvsp[(2) - (8)].string));
							(yyvsp[(4) - (8)].ast)->left = (yyvsp[(6) - (8)].ast);
							(yyval.ast)->left = (yyvsp[(4) - (8)].ast);
							funcOp = 0;
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 501 "parser.y"
    {
		printf("\n RECOGNIZED RULE: OPERATION\n");
		if(found((yyvsp[(1) - (3)].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[(1) - (3)].string), currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

		printf("\nChecking types: \n");

		//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
		if(strcmp(getVariableType((yyvsp[(1) - (3)].string), currentScope),"int") != 0) {
			printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", (yyvsp[(1) - (3)].string), currentScope);
			semanticCheckPassed = 0;
		}
		
		if(funcOp == 0) {
			reverseOpList();
			int operationTotal=calculateAll();
			deleteAll();
			char opTemp[50];
			sprintf(opTemp, "%d", operationTotal);
			(yyval.ast) = AST_assignment("=",(yyvsp[(1) - (3)].string),opTemp);
			if (semanticCheckPassed == 1) {
								printf("\n\nOPERATION: Rule is semantically correct!\n\n");
								updateValue((yyvsp[(1) - (3)].string), currentScope, operationTotal);
								char id2[50];
								sprintf(id2, "%d", operationTotal);
								// ---- EMIT IR 3-ADDRESS CODE ---- //
								
								// The IR code is printed to a separate file
								//$$ = $3
								//printf("Reading additon: %s\n", $$);
								emitConstantIntAssignment((yyvsp[(1) - (3)].string), id2);
								

								// ----     EMIT MIPS CODE   ----  //

								// The MIPS code is printed to a separate file

								// MIPS registers management will eventually go in here
								// and the paramaters of the function below will change
								// to using $t0, ..., $t9 registers
								
								emitMIPSConstantIntAssignment((yyvsp[(1) - (3)].string), id2);
								

							}
		}
		else {
			print_op();
			mips_func((yyvsp[(1) - (3)].string));
		}

	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 557 "parser.y"
    {
		printf("\n RECOGNIZED RULE: ID CHAR\n");
		if(found((yyvsp[(1) - (3)].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[(1) - (3)].string), currentScope);
							semanticCheckPassed = 0;
						}
						if(strcmp(getVariableType((yyvsp[(1) - (3)].string), currentScope),"char") != 0) {
							printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", (yyvsp[(1) - (3)].string), currentScope);
							semanticCheckPassed = 0;
		}
		char id[50];
		//sprintf(id, "%c", $3);
		//updateValue($1,$3);
		//$$ = AST_assignment("=",$1,$3);

						
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 575 "parser.y"
    { printf("\n RECOGNIZED RULE: ARRAY OPERATION\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ---- //
					char id1[50];
					char id2[50];
					sprintf(id1, "%s",(yyvsp[(1) - (6)].string));
					sprintf(id2, "%d",(yyvsp[(3) - (6)].number));
					char fullIndex[50];
					sprintf(fullIndex, "%s[%s]",id1,id2);
					if(found(fullIndex, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[(1) - (6)].string), currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

		printf("\nChecking types: \n");

		//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
		if(strcmp(getVariableType(fullIndex, currentScope),"int") != 0) {
			printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", (yyvsp[(1) - (6)].string), currentScope);
			semanticCheckPassed = 0;
		}
		reverseOpList();
		if (funcOp == 0) {
			int operationTotal=calculateAll();
			deleteAll();
			char opTemp[50];
			sprintf(opTemp, "%d", operationTotal);
			(yyval.ast) = AST_assignment("=",(yyvsp[(1) - (6)].string),opTemp);
			if (semanticCheckPassed == 1) {
								printf("\n\nOPERATION: Rule is semantically correct!\n\n");
								char id3[50];
								sprintf(id3, "%d", operationTotal);
								updateValue(fullIndex,currentScope, id3);
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
		else {
			
			print_op();
			mips_func((yyvsp[(1) - (6)].string));
		}
					

	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 639 "parser.y"
    {
		(yyval.ast) = (yyvsp[(3) - (3)].ast);
		emitCallIDFunction((yyvsp[(1) - (3)].string));
		emitMIPSCallIDFunction((yyvsp[(1) - (3)].string));
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 645 "parser.y"
    { printf("\n RECOGNIZED RULE: WRITE statement\n");
					(yyval.ast) = AST_Write("write",(yyvsp[(2) - (2)].string),"");
					
					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared
					    if(found((yyvsp[(2) - (2)].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[(2) - (2)].string), currentScope);
							semanticCheckPassed = 0;
						}

					if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");

							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							
							emitWriteId((yyvsp[(2) - (2)].string));

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers

							emitMIPSWriteId((yyvsp[(2) - (2)].string));
						}
				;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 676 "parser.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 682 "parser.y"
    { (yyval.ast) = AST_assignment("ParamList", "", "null");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 683 "parser.y"
    { printf("\n RECOGNIZED RULE: Param call %s\n", (yyvsp[(1) - (3)].string));
									(yyval.ast) = AST_Write("Param",(yyvsp[(1) - (3)].string),""); 
									(yyval.ast)->left = (yyvsp[(3) - (3)].ast);
									strcpy(funcParams[paramIdx], (yyvsp[(1) - (3)].string));
									paramIdx++;
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 691 "parser.y"
    {
			(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 695 "parser.y"
    { 
				(yyval.ast) = AST_Write("Param",(yyvsp[(1) - (1)].string),"");
				printf("\n RECOGNIZED RULE: Param Call %s\n", (yyvsp[(1) - (1)].string));
				strcpy(funcParams[paramIdx], (yyvsp[(1) - (1)].string));
				paramIdx++;
				
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 704 "parser.y"
    {

				if(found((yyvsp[(1) - (4)].string), currentScope) != 1) {
					printf("SEMANTIC ERROR: Function %s has NOT been declared in scope %s \n", (yyvsp[(1) - (4)].string), currentScope);
					semanticCheckPassed = 0;
				}
				strcpy(funcType, (yyvsp[(1) - (4)].string)); 
				
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
					printf("here");
					if (semanticCheckPassed == 1)
						emitMipsParam(i, getVal(funcParams[i], currentScope));
					printf("here");
				}
				
				(yyval.ast) = AST_Write("FuncCall",(yyvsp[(1) - (4)].string),""); 
				(yyval.ast)->left = (yyvsp[(3) - (4)].ast); 
				if (semanticCheckPassed == 1) {
					for(int i = 0; i <paramIdx; i++) {
						emitParam(i, funcParams[i]);
					}
					emitCallFunction((yyvsp[(1) - (4)].string));
					emitMIPSCallFunction((yyvsp[(1) - (4)].string));
				}

			;}
    break;



/* Line 1455 of yacc.c  */
#line 2325 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 744 "parser.y"


int main(int argc, char**argv)
{
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");
	
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

	cleanCode();

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
