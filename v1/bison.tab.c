
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
#line 3 "bison.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>

	int yylex ();
	int yyerror();

	int switchdone = 0;
	int switchvar;

	int ifval[1000];
	int ifptr = -1;
	int ifdone[1000];

    int ptr = 0;
    int value[1000];
    char varlist[1000][1000];

    ///if already declared  return 1 else return 0
    int isdeclared(char str[]){
        int i;
        for(i = 0; i < ptr; i++){
            if(strcmp(varlist[i],str) == 0) return 1;
        }
        return 0;
    }
    /// if already declared return 0 or add new value and return 1;
    int addnewval(char str[],int val){
        if(isdeclared(str) == 1) return 0;
        strcpy(varlist[ptr],str);
        value[ptr] = val;
        ptr++;
        return 1;
    }

    ///get the value of corresponding string
    int getval(char str[]){
        int indx = -1;
        int i;
        for(i = 0; i < ptr; i++){
            if(strcmp(varlist[i],str) == 0) {
                indx = i;
                break;
            }
        }
		if(indx==-1)
		{
			return 0;
		}
        return value[indx];
    }
    int setval(char str[], int val){
    	int indx = -1;
        int i;
        for(i = 0; i < ptr; i++){
            if(strcmp(varlist[i],str) == 0) {
                indx = i;
                break;
            }
        }
		if(indx!=-1)
        value[indx] = val;

	

    }




/* Line 189 of yacc.c  */
#line 145 "bison.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     ID = 258,
     NUM = 259,
     STR = 260,
     GE = 261,
     LE = 262,
     GT = 263,
     LT = 264,
     MINUS = 265,
     PLUS = 266,
     DIV = 267,
     MULT = 268,
     SCAN = 269,
     LESS = 270,
     GREAT = 271,
     WHILE = 272,
     INT = 273,
     DOUBLE = 274,
     CHAR = 275,
     MAIN = 276,
     PB = 277,
     PE = 278,
     BB = 279,
     BE = 280,
     DOT = 281,
     CM = 282,
     ASGN = 283,
     PRINTVAR = 284,
     PRINTSTR = 285,
     PRINTLN = 286,
     IF = 287,
     ELSE = 288,
     ELSEIF = 289,
     FOR = 290,
     INC = 291,
     TO = 292,
     SWITCH = 293,
     DEFAULT = 294,
     COL = 295,
     FUNCTION = 296,
     IFX = 297,
     SH = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 74 "bison.y"

  char text[10000];
  int val;



/* Line 214 of yacc.c  */
#line 231 "bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 243 "bison.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    15,    16,    19,    22,    25,    28,
      31,    34,    37,    40,    44,    46,    48,    50,    54,    56,
      58,    62,    67,    73,    79,    85,    90,    92,    94,    98,
     102,   106,   110,   114,   118,   122,   126,   130,   139,   141,
     142,   151,   157,   167,   177,   189,   190,   193,   199,   205,
     210,   218,   220,   221,   228,   235,   236,   239,   248,   249,
     253,   254
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    65,    46,    65,    -1,    18,    21,    22,
      23,    24,    47,    25,    -1,    -1,    47,    48,    -1,    47,
      53,    -1,    47,    54,    -1,    47,    55,    -1,    47,    52,
      -1,    47,    59,    -1,    47,    62,    -1,    47,    58,    -1,
      49,    50,    26,    -1,    18,    -1,    19,    -1,    20,    -1,
      51,    27,    50,    -1,    51,    -1,     3,    -1,     3,    28,
      54,    -1,     3,    28,    54,    26,    -1,    14,    22,     3,
      23,    26,    -1,    29,    22,     3,    23,    26,    -1,    30,
      22,     5,    23,    26,    -1,    31,    22,    23,    26,    -1,
       4,    -1,     3,    -1,    54,    11,    54,    -1,    54,    10,
      54,    -1,    54,    13,    54,    -1,    54,    12,    54,    -1,
      54,     9,    54,    -1,    54,     8,    54,    -1,    54,     7,
      54,    -1,    54,     6,    54,    -1,    22,    54,    23,    -1,
      32,    22,    56,    23,    24,    60,    25,    57,    -1,    54,
      -1,    -1,    57,    34,    22,    54,    23,    24,    60,    25,
      -1,    57,    33,    24,    60,    25,    -1,    17,    22,     3,
      15,     4,    23,    24,    60,    25,    -1,    17,    22,     3,
      16,     4,    23,    24,    60,    25,    -1,    35,    22,    54,
      37,    54,    36,    54,    23,    24,    60,    25,    -1,    -1,
      60,    61,    -1,    29,    22,     3,    23,    26,    -1,    30,
      22,     5,    23,    26,    -1,    31,    22,    23,    26,    -1,
      38,    22,    63,    23,    24,    64,    25,    -1,    54,    -1,
      -1,    64,    54,    40,    24,    47,    25,    -1,    64,    39,
      40,    24,    47,    25,    -1,    -1,    65,    66,    -1,    49,
      41,    22,    67,    23,    24,    47,    25,    -1,    -1,    49,
       3,    68,    -1,    -1,    68,    27,    49,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   108,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   127,   129,   129,   129,   131,   132,   134,
     144,   160,   170,   189,   200,   207,   223,   224,   234,   236,
     238,   240,   251,   253,   255,   257,   259,   269,   277,   288,
     289,   297,   314,   328,   352,   370,   371,   376,   405,   429,
     444,   447,   455,   456,   463,   477,   478,   481,   486,   487,
     489,   490
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "STR", "GE", "LE", "GT",
  "LT", "MINUS", "PLUS", "DIV", "MULT", "SCAN", "LESS", "GREAT", "WHILE",
  "INT", "DOUBLE", "CHAR", "MAIN", "PB", "PE", "BB", "BE", "DOT", "CM",
  "ASGN", "PRINTVAR", "PRINTSTR", "PRINTLN", "IF", "ELSE", "ELSEIF", "FOR",
  "INC", "TO", "SWITCH", "DEFAULT", "COL", "FUNCTION", "IFX", "SH",
  "$accept", "starthere", "program", "statement", "declaration", "type",
  "variables", "variable", "assign", "print", "expression", "ifelse",
  "ifexp", "elseif", "whileloop", "forloop", "LoopStatement", "Lprint",
  "switch", "expswitch", "switchinside", "function", "func", "fparameter",
  "fsparameter", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    48,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    57,
      57,    57,    58,    58,    59,    60,    60,    61,    61,    61,
      62,    63,    64,    64,    64,    65,    65,    66,    67,    67,
      68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     7,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     1,     1,     1,     3,     1,     1,
       3,     4,     5,     5,     5,     4,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     8,     1,     0,
       8,     5,     9,     9,    11,     0,     2,     5,     5,     4,
       7,     1,     0,     6,     6,     0,     2,     8,     0,     3,
       0,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      55,     0,     0,     1,    14,    15,    16,    55,     0,    56,
       0,     2,     0,     0,    14,    58,     0,     0,     0,     4,
      60,     0,     0,    59,     4,    27,    26,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     5,     0,     9,
       6,     7,     8,    12,    10,    11,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,    19,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,    36,     0,     0,     0,    38,
       0,     0,    51,     0,     0,    13,     0,    35,    34,    33,
      32,    29,    28,    31,    30,    61,    21,     0,     0,     0,
       0,     0,    25,     0,     0,     0,    20,    17,    22,     0,
       0,    23,    24,    45,     0,    52,     0,     0,     0,     0,
       0,    45,    45,    39,     0,     0,     0,    46,     0,    50,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,    42,    43,     0,     0,     0,     0,     0,    45,     4,
       4,    45,     0,     0,     0,    49,     0,     0,     0,     0,
       0,    47,    48,    44,    54,    53,    41,     0,    45,     0,
      40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     7,    22,    37,    38,    60,    61,    39,    40,
      41,    42,    80,   134,    43,    44,   118,   127,    45,    83,
     120,     2,     9,    18,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -107
static const yytype_int16 yypact[] =
{
    -107,    12,   -12,  -107,    23,  -107,  -107,  -107,   -27,  -107,
      25,    13,    27,    28,  -107,    13,    26,    51,    32,  -107,
    -107,    33,    49,    31,  -107,    36,  -107,    37,    39,    -1,
    -107,    43,    48,    50,    53,    55,    63,  -107,    70,  -107,
    -107,   252,  -107,  -107,  -107,  -107,    13,    79,    -1,    83,
      85,  -107,   218,    86,    89,    67,    -1,    -1,    -1,    72,
      69,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,  -107,   195,    82,     3,  -107,    84,    90,    80,   252,
      92,   179,   252,   104,    -1,  -107,    70,   207,   207,   207,
     207,    10,    10,  -107,  -107,  -107,  -107,    97,   108,   124,
     105,   110,  -107,   106,    -1,   114,   252,  -107,  -107,   116,
     120,  -107,  -107,  -107,   187,  -107,   125,   127,   -20,    -1,
      21,  -107,  -107,  -107,   126,   132,   137,  -107,   226,  -107,
     121,   171,    91,   184,    -7,   159,   160,   141,   142,   147,
     148,  -107,  -107,   150,   153,   189,   199,   216,  -107,  -107,
    -107,  -107,    -1,   217,   221,  -107,   215,   115,   138,   241,
     244,  -107,  -107,  -107,  -107,  -107,  -107,   186,  -107,   248,
    -107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,   -24,  -107,     2,   162,  -107,  -107,  -107,
     -28,  -107,  -107,  -107,  -107,  -107,  -106,  -107,  -107,  -107,
    -107,   261,  -107,  -107,  -107
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      47,    52,    51,    26,     8,   123,     4,     5,     6,   124,
     125,   126,     3,     8,    12,   132,   133,    17,    98,    99,
      72,    29,    68,    69,    51,    26,   143,   144,    79,    81,
      82,    14,     5,     6,    87,    88,    89,    90,    91,    92,
      93,    94,   156,    29,    10,   159,   129,    13,    70,    15,
      19,    16,    25,    26,    20,    21,   106,    24,    46,    49,
     130,    50,   169,    27,    48,    53,    28,    14,     5,     6,
      54,    29,    55,    59,    30,    56,   114,    57,    31,    32,
      33,    34,    25,    26,    35,    58,    73,    36,    74,    76,
      78,   128,   131,    27,    77,    85,    28,    14,     5,     6,
      84,    29,    86,    95,    71,    97,   102,   100,    31,    32,
      33,    34,   109,   101,    35,   103,   141,    36,    25,    26,
     124,   125,   126,   108,   160,   157,   158,   105,   110,    27,
     113,   111,    28,    14,     5,     6,   112,    29,   115,   116,
     164,    25,    26,   117,    31,    32,    33,    34,   135,   121,
      35,   122,    27,    36,   136,    28,    14,     5,     6,   137,
      29,   139,   145,   165,   147,   146,   148,    31,    32,    33,
      34,   149,   150,    35,   151,   152,    36,    62,    63,    64,
      65,    66,    67,    68,    69,    62,    63,    64,    65,    66,
      67,    68,    69,    62,    63,    64,    65,    66,    67,    68,
      69,    62,    63,    64,    65,    66,    67,    68,    69,   142,
     168,   140,   153,   124,   125,   126,   104,    66,    67,    68,
      69,    96,   154,   119,    62,    63,    64,    65,    66,    67,
      68,    69,    62,    63,    64,    65,    66,    67,    68,    69,
     163,    75,   155,   161,   124,   125,   126,   162,   107,   138,
      62,    63,    64,    65,    66,    67,    68,    69,    62,    63,
      64,    65,    66,    67,    68,    69,   166,   167,    11,     0,
     124,   125,   126,   170,     0,     0,     0,   124,   125,   126
};

static const yytype_int16 yycheck[] =
{
      24,    29,     3,     4,     2,    25,    18,    19,    20,    29,
      30,    31,     0,    11,    41,   121,   122,    15,    15,    16,
      48,    22,    12,    13,     3,     4,    33,    34,    56,    57,
      58,    18,    19,    20,    62,    63,    64,    65,    66,    67,
      68,    69,   148,    22,    21,   151,    25,    22,    46,    22,
      24,    23,     3,     4,     3,    23,    84,    24,    27,    22,
      39,    22,   168,    14,    28,    22,    17,    18,    19,    20,
      22,    22,    22,     3,    25,    22,   104,    22,    29,    30,
      31,    32,     3,     4,    35,    22,     3,    38,     3,     3,
      23,   119,   120,    14,     5,    26,    17,    18,    19,    20,
      28,    22,    27,     3,    25,    23,    26,    23,    29,    30,
      31,    32,     4,    23,    35,    23,    25,    38,     3,     4,
      29,    30,    31,    26,   152,   149,   150,    23,     4,    14,
      24,    26,    17,    18,    19,    20,    26,    22,    24,    23,
      25,     3,     4,    23,    29,    30,    31,    32,    22,    24,
      35,    24,    14,    38,    22,    17,    18,    19,    20,    22,
      22,    40,     3,    25,    23,     5,    24,    29,    30,    31,
      32,    24,    24,    35,    24,    22,    38,     6,     7,     8,
       9,    10,    11,    12,    13,     6,     7,     8,     9,    10,
      11,    12,    13,     6,     7,     8,     9,    10,    11,    12,
      13,     6,     7,     8,     9,    10,    11,    12,    13,    25,
      24,    40,    23,    29,    30,    31,    37,    10,    11,    12,
      13,    26,    23,    36,     6,     7,     8,     9,    10,    11,
      12,    13,     6,     7,     8,     9,    10,    11,    12,    13,
      25,    23,    26,    26,    29,    30,    31,    26,    86,    23,
       6,     7,     8,     9,    10,    11,    12,    13,     6,     7,
       8,     9,    10,    11,    12,    13,    25,    23,     7,    -1,
      29,    30,    31,    25,    -1,    -1,    -1,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    65,     0,    18,    19,    20,    46,    49,    66,
      21,    65,    41,    22,    18,    22,    23,    49,    67,    24,
       3,    23,    47,    68,    24,     3,     4,    14,    17,    22,
      25,    29,    30,    31,    32,    35,    38,    48,    49,    52,
      53,    54,    55,    58,    59,    62,    27,    47,    28,    22,
      22,     3,    54,    22,    22,    22,    22,    22,    22,     3,
      50,    51,     6,     7,     8,     9,    10,    11,    12,    13,
      49,    25,    54,     3,     3,    23,     3,     5,    23,    54,
      56,    54,    54,    63,    28,    26,    27,    54,    54,    54,
      54,    54,    54,    54,    54,     3,    26,    23,    15,    16,
      23,    23,    26,    23,    37,    23,    54,    50,    26,     4,
       4,    26,    26,    24,    54,    24,    23,    23,    60,    36,
      64,    24,    24,    25,    29,    30,    31,    61,    54,    25,
      39,    54,    60,    60,    57,    22,    22,    22,    23,    40,
      40,    25,    25,    33,    34,     3,     5,    23,    24,    24,
      24,    24,    22,    23,    23,    26,    60,    47,    47,    60,
      54,    26,    26,    25,    25,    25,    25,    23,    24,    60,
      25
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
        case 3:

/* Line 1455 of yacc.c  */
#line 108 "bison.y"
    { printf("\nCompilation Successful\n"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 127 "bison.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 129 "bison.y"
    {;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 131 "bison.y"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 132 "bison.y"
    {;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 135 "bison.y"
    {
						//printf("%s\n",$1);
						int x = addnewval((yyvsp[(1) - (1)].text),0);
						if(!x) {
							printf("Compilation Error:Variable %s is already declared\n",(yyvsp[(1) - (1)].text));
							exit(-1);
						}

					;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 145 "bison.y"
    {
						//printf("%s %d\n",$1,$3);
						int x = addnewval((yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].val));
						if(!x) {
							printf("Compilation Error: Variable %s is already declared\n",(yyvsp[(1) - (3)].text));
							exit(-1);
							}
					;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 161 "bison.y"
    {
						if(!isdeclared((yyvsp[(1) - (4)].text))) {
							printf("Compilation Error: Variable %s is not declared\n",(yyvsp[(1) - (4)].text));
							exit(-1);
						}
						else{
							setval((yyvsp[(1) - (4)].text),(yyvsp[(3) - (4)].val));
						}
				    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 171 "bison.y"
    {
			int tmp;
			tmp = 7;
			//printf("scan korte chai\n");
			scanf("%d", &tmp);
			//printf("%d - %s \n", tmp, $3);
			
			setval((yyvsp[(3) - (5)].text), tmp);
		;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 190 "bison.y"
    {
						if(!isdeclared((yyvsp[(3) - (5)].text))){
							printf("Compilation Error: Variable %s is not declared\n",(yyvsp[(3) - (5)].text));
							exit(-1);
						}
						else{
							int v = getval((yyvsp[(3) - (5)].text));
							printf("%d",v);
						}
					;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 202 "bison.y"
    {
						int l = strlen((yyvsp[(3) - (5)].text));
						int i;
						for(i = 1;  i < l-1; i++) printf("%c",(yyvsp[(3) - (5)].text)[i]);
					;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 209 "bison.y"
    {
						printf("\n");
					;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 223 "bison.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 225 "bison.y"
    {
						if(!isdeclared((yyvsp[(1) - (1)].text))) {
							printf("Compilation Error: Variable %s is not declared\n",(yyvsp[(1) - (1)].text));
							exit(-1);
						}
						else{
							(yyval.val) = getval((yyvsp[(1) - (1)].text));
						}
				 	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 235 "bison.y"
    {(yyval.val) = (yyvsp[(1) - (3)].val) + (yyvsp[(3) - (3)].val);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 237 "bison.y"
    {(yyval.val) = (yyvsp[(1) - (3)].val) - (yyvsp[(3) - (3)].val);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 239 "bison.y"
    {(yyval.val) = (yyvsp[(1) - (3)].val) * (yyvsp[(3) - (3)].val);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 241 "bison.y"
    {
						if((yyvsp[(3) - (3)].val)) {
 							(yyval.val) = (yyvsp[(1) - (3)].val) / (yyvsp[(3) - (3)].val);
							}
				  		else {
							(yyval.val) = 0;
							printf("\nRuntime Error: division by zero\t");
							exit(-1);
				  		} 
					;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 252 "bison.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) < (yyvsp[(3) - (3)].val); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 254 "bison.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) > (yyvsp[(3) - (3)].val); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 256 "bison.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) <= (yyvsp[(3) - (3)].val); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 258 "bison.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) >= (yyvsp[(3) - (3)].val); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 260 "bison.y"
    {(yyval.val) = (yyvsp[(2) - (3)].val);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 270 "bison.y"
    {
						if((yyvsp[(3) - (8)].val))
						printf("%s", (yyvsp[(6) - (8)].text));
						ifdone[ifptr] = 0;
						ifptr--;
					;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 278 "bison.y"
    {
						ifptr++;
						ifdone[ifptr] = 0;
						if((yyvsp[(1) - (1)].val)){
							printf("\nIf executed\n");
							ifdone[ifptr] = 1;
						}
						(yyval.val) = (yyvsp[(1) - (1)].val);
					;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 290 "bison.y"
    {
						if((yyvsp[(4) - (8)].val) && ifdone[ifptr] == 0){
							printf("%s", (yyvsp[(7) - (8)].text));
							printf("\nElse if block expressin %d executed\n",(yyvsp[(4) - (8)].val));
							ifdone[ifptr] = 1;
						}
					;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 298 "bison.y"
    {
						if(ifdone[ifptr] == 0){
							printf("%s", (yyvsp[(4) - (5)].text));
							printf("\nElse block executed\n");
							ifdone[ifptr] = 1;
						}
					;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 315 "bison.y"
    {
			int tmp = getval((yyvsp[(3) - (9)].text));
			while(tmp<(yyvsp[(5) - (9)].val))
			{
				printf("%d ", tmp);
				printf("%s",(yyvsp[(8) - (9)].text));
				
				
				tmp = tmp+1;
			}
			setval((yyvsp[(3) - (9)].text), tmp);

		;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 329 "bison.y"
    {
			int tmp = getval((yyvsp[(3) - (9)].text));
			while(tmp>(yyvsp[(5) - (9)].val))
			{
				printf("%d ", tmp);
				
				printf("%s",(yyvsp[(8) - (9)].text));
				
				tmp = tmp-1;
			}
			setval((yyvsp[(3) - (9)].text), tmp);

		;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 353 "bison.y"
    {
						int st = (yyvsp[(3) - (11)].val);
						int ed = (yyvsp[(5) - (11)].val);
						int dif = (yyvsp[(7) - (11)].val);
						int cnt = 0;
						int k = 0;
						//printf(" hhel : \n%s\n", $10);
						for(k = st; k <= ed; k += dif){
							cnt++;
							int r ;
							if(strlen((yyvsp[(10) - (11)].text))!=0)
							printf("%s\n", (yyvsp[(10) - (11)].text));
						}	
						printf("Loop executes %d times\n",cnt+2);
					;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 370 "bison.y"
    { strcpy((yyval.text),"");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 371 "bison.y"
    {
				 strcat((yyval.text), (yyvsp[(2) - (2)].text));
				;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 377 "bison.y"
    {
						char val[1000];
						strcpy(val, "");
						if(!isdeclared((yyvsp[(3) - (5)].text))){
							strcat(val, "Compilation Error: Variable ");

							char tmp[20];
							sprintf(tmp, "%s ", (yyvsp[(3) - (5)].text));
							strcat(val, tmp);
							strcat( val,"is not declared\n");
							printf("%s", val);
							exit(-1);
							strcpy((yyval.text), val);
						}
						else{
							char val[1000];
							strcpy(val, "");
							int v = getval((yyvsp[(3) - (5)].text));
							char tmp[18];
							sprintf(tmp, "%d", v);
							//strcpy(tmp,atoi(v));
							//printf(" v er value : %d - %s\n ", v, tmp);
							strcat(val, tmp);
							strcpy((yyval.text), val);

							//printf("%d",v);
						}
					;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 407 "bison.y"
    {
						char val[10000];
						strcpy(val, "");
						int l = strlen((yyvsp[(3) - (5)].text));
						int i;
						for(i = 1;  i < l-1; i++) 
						{
							char tmp[20];
							sprintf(tmp, "%c", (yyvsp[(3) - (5)].text)[i]);
							//printf(" str er tmp:  %s\n",tmp);
							strcat(val, tmp);
							
							
							//printf("%c",$3[i]);
						}
						//strcat(val, "");
						
						//printf("  %s ", $$);
						
						strcpy((yyval.text), val);
						//printf("::: --- val: %s - %s\n",val, $$);
					;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 431 "bison.y"
    {
						strcpy((yyval.text), "\n");
					;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 448 "bison.y"
    {
						switchdone = 0;
						switchvar = (yyvsp[(1) - (1)].val);
					;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 457 "bison.y"
    {
						if((yyvsp[(2) - (6)].val) == switchvar){
							printf("Executed %d\n",(yyvsp[(2) - (6)].val));
							switchdone = 1;
						}					
					;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 464 "bison.y"
    {
						if(switchdone == 0){
							switchdone = 1;
							printf("Default Block executed\n");
						}
					;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 482 "bison.y"
    {
						printf("Function Declared\n");
					;}
    break;



/* Line 1455 of yacc.c  */
#line 2060 "bison.tab.c"
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
#line 495 "bison.y"



int yyerror(char *s){
	printf( "%s\n", s);
}
