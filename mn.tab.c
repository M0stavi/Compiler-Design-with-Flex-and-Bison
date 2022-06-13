
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
#line 1 "mn.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	#include<string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	
	/*Useful Arrays*/

	char isVar[1000][1000];
	int available_index=0;
	
	int whatType[10010]={0};
	
	int isArr[10010]={0};
	
	int valInt[10010][100];
	
	double valDoub[10010][100];
	
	char valStr[10010][1000];
	
	
	int Cond = 0;
	
	int ara[100010];
	
	
	
	/*Useful functions*/
	
	int Check_var(char *str)
	{
		int check=1;
							
		for(int i=0;i<1000;i++)
		{
			if(strcmp(isVar[i],str)==0)
			{
				check=0;
				break;
			}
		}
		if(check) strcpy(isVar[available_index++], str);
		return check;
	}
	
	
	int hashVal(char *str)
	{
		int p=1;
		int val=0;
					
		int len = strlen(str);
					
		for(int i=0;i<len;i++)
		{   
		    int aa;
			char cc=str[i];
			if(cc >= 'A' && cc <= 'Z') aa=65+cc-'A';
            else if(cc >= 'a' && cc <= 'z') aa=97+cc-'a';
			else if(cc >= '0' && cc <= '9') aa=48+cc-'0';
			else if(cc == '_') aa=1;
			else aa=2;
			int x=aa*p;
			val+=x;
			p*=2;
		}
					
					
					
		int ret=val%10000;
		
		return ret;
					
	}
	
	int gcd(int a, int b)
	{
		if(a==0)  return b;
		if(b==0)  return a;
		if(a==b) return a;
		if (a > b) return gcd(a-b, b);
		return gcd(a, b-a);
		
	}



/* Line 189 of yacc.c  */
#line 164 "mn.tab.c"

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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 92 "mn.y"

    struct data_type{
	    
		int integer;
		double floating;
		char name[1000];
        int hash_value;
		char str[1000];
		int type;
	};



/* Line 209 of yacc.c  */
#line 202 "mn.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR_NAME = 258,
     INT = 259,
     DOUBLE = 260,
     STRING = 261,
     INTEGER_VALUE = 262,
     FLOATING_VALUE = 263,
     STRING_VALUE = 264,
     ARR = 265,
     PRINT = 266,
     OPS = 267,
     PS = 268,
     PE = 269,
     MAIN = 270,
     STOP = 271,
     COLON = 272,
     DASH = 273,
     COMMA = 274,
     DECLARE = 275,
     BAAM = 276,
     DAAN = 277,
     EQUALS = 278,
     FBO = 279,
     FBC = 280,
     PLUS = 281,
     DIV = 282,
     MUL = 283,
     POW = 284,
     LOG = 285,
     SIN = 286,
     COS = 287,
     TAN = 288,
     GTR = 289,
     LESS = 290,
     GEQ = 291,
     LEQ = 292,
     EQS = 293,
     LCM = 294,
     GCD = 295,
     MOD = 296,
     INPUT = 297,
     TAKE = 298,
     FOR = 299,
     WHILE = 300,
     DCRM = 301,
     DO = 302,
     IF = 303,
     ELSE = 304,
     SWITCH = 305,
     CASE = 306,
     DEFT = 307,
     CLASS = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 105 "mn.y"

	struct data_type val;



/* Line 214 of yacc.c  */
#line 278 "mn.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 290 "mn.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   977

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  323

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    12,    14,    15,    18,    34,    37,
      40,    46,    54,    66,    68,    70,    72,    94,   113,   140,
     167,   194,   221,   248,   269,   285,   286,   300,   301,   302,
     317,   326,   327,   340,   341,   342,   355,   363,   366,   377,
     381,   383,   388,   395,   404,   408,   410,   414,   421,   423,
     425,   427,   429,   431,   433,   435,   441,   445,   449,   453,
     457,   461,   466,   471,   476,   481,   485,   489,   493,   497,
     501,   505,   512
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    55,    15,    17,    18,    13,    56,
      14,    -1,    57,    -1,    -1,    56,    58,    -1,    53,     3,
      13,     3,    21,    73,    22,    19,     3,    21,    73,    22,
      16,    14,    16,    -1,    68,    16,    -1,    71,    16,    -1,
      11,    24,    74,    25,    16,    -1,    43,     3,    23,    42,
      24,    25,    16,    -1,    43,    10,     3,    13,    74,    14,
      23,    42,    24,    25,    16,    -1,    59,    -1,    60,    -1,
      64,    -1,    44,    24,    74,    19,    74,    19,    74,    25,
      13,    43,    10,     3,    13,    74,    14,    23,    42,    24,
      25,    16,    14,    -1,    44,    24,    74,    19,    74,    19,
      74,    25,    13,    11,    24,     3,    13,    74,    14,    25,
      16,    14,    -1,    45,    24,    74,    46,    25,    13,     3,
      23,    42,    24,    25,    16,     3,    23,    42,    24,    25,
      16,    11,    24,    74,    26,    74,    25,    16,    14,    -1,
      45,    24,    74,    46,    25,    13,     3,    23,    42,    24,
      25,    16,     3,    23,    42,    24,    25,    16,    11,    24,
      74,    18,    74,    25,    16,    14,    -1,    45,    24,    74,
      46,    25,    13,     3,    23,    42,    24,    25,    16,     3,
      23,    42,    24,    25,    16,    11,    24,    74,    28,    74,
      25,    16,    14,    -1,    45,    24,    74,    46,    25,    13,
       3,    23,    42,    24,    25,    16,     3,    23,    42,    24,
      25,    16,    11,    24,    74,    27,    74,    25,    16,    14,
      -1,    45,    24,    74,    46,    25,    13,     3,    23,    42,
      24,    25,    16,     3,    23,    42,    24,    25,    16,    11,
      24,    74,    41,    74,    25,    16,    14,    -1,    47,    13,
      74,    23,    42,    24,    25,    16,    11,    24,    74,    25,
      16,    14,    45,    24,    74,    46,    25,    16,    -1,    44,
      24,    74,    19,    74,    19,    74,    25,    13,    11,    24,
      74,    25,    16,    14,    -1,    -1,    48,    24,    74,    25,
      13,    11,    24,    74,    25,    16,    14,    61,    62,    -1,
      -1,    -1,    49,    48,    24,    74,    25,    13,    11,    24,
      74,    25,    16,    14,    63,    62,    -1,    49,    13,    11,
      24,    74,    25,    16,    14,    -1,    -1,    50,    24,    74,
      25,    17,    11,    24,    74,    25,    16,    65,    66,    -1,
      -1,    -1,    51,    24,    74,    25,    17,    11,    24,    74,
      25,    16,    67,    66,    -1,    52,    17,    11,    24,    74,
      25,    16,    -1,    20,    69,    -1,    53,    21,     3,    22,
       3,    24,    74,    19,    74,    25,    -1,    69,    19,    70,
      -1,    70,    -1,     3,    21,    73,    22,    -1,     3,    21,
      73,    22,    23,    74,    -1,    10,    21,    73,    22,     3,
      13,     7,    14,    -1,    71,    19,    72,    -1,    72,    -1,
      74,    23,    74,    -1,     3,    13,    74,    14,    23,    74,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,     3,    -1,    10,     3,    13,     7,    14,
      -1,    74,    26,    74,    -1,    74,    18,    74,    -1,    74,
      28,    74,    -1,    74,    27,    74,    -1,    74,    29,    74,
      -1,    30,    24,    74,    25,    -1,    31,    24,    74,    25,
      -1,    32,    24,    74,    25,    -1,    33,    24,    74,    25,
      -1,    74,    34,    74,    -1,    74,    35,    74,    -1,    74,
      36,    74,    -1,    74,    37,    74,    -1,    74,    38,    74,
      -1,    74,    41,    74,    -1,    40,    24,    74,    19,    74,
      25,    -1,    39,    24,    74,    19,    74,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   154,   154,   155,   156,   159,   160,   169,   189,   193,
     195,   246,   291,   324,   326,   328,   338,   379,   415,   438,
     462,   485,   508,   532,   548,   588,   588,   601,   602,   602,
     612,   639,   639,   656,   658,   658,   674,   705,   709,   742,
     743,   747,   768,   833,   865,   866,   869,   914,   961,   962,
     963,   970,   977,   982,   990,  1018,  1043,  1096,  1142,  1187,
    1233,  1266,  1288,  1311,  1334,  1357,  1388,  1417,  1445,  1475,
    1503,  1520,  1530
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR_NAME", "INT", "DOUBLE", "STRING",
  "INTEGER_VALUE", "FLOATING_VALUE", "STRING_VALUE", "ARR", "PRINT", "OPS",
  "PS", "PE", "MAIN", "STOP", "COLON", "DASH", "COMMA", "DECLARE", "BAAM",
  "DAAN", "EQUALS", "FBO", "FBC", "PLUS", "DIV", "MUL", "POW", "LOG",
  "SIN", "COS", "TAN", "GTR", "LESS", "GEQ", "LEQ", "EQS", "LCM", "GCD",
  "MOD", "INPUT", "TAKE", "FOR", "WHILE", "DCRM", "DO", "IF", "ELSE",
  "SWITCH", "CASE", "DEFT", "CLASS", "$accept", "program", "cline",
  "class", "statement", "loops", "condition", "$@1", "elses", "$@2",
  "switchase", "$@3", "cases", "$@4", "declaration", "variables",
  "variable", "assigns", "assign", "types", "expression", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    56,    56,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    61,    60,    62,    63,    62,
      62,    65,    64,    66,    67,    66,    66,    68,    68,    69,
      69,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     1,     0,     2,    15,     2,     2,
       5,     7,    11,     1,     1,     1,    21,    18,    26,    26,
      26,    26,    26,    20,    15,     0,    13,     0,     0,    14,
       8,     0,    12,     0,     0,    12,     7,     2,    10,     3,
       1,     4,     6,     8,     3,     1,     3,     6,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     3,     3,     3,     3,     3,
       3,     6,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     4,     0,     1,     0,     0,     0,     0,
       0,     0,     5,    48,    49,    50,     0,     0,     0,    54,
      51,    52,    53,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,    13,    14,    15,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,    37,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    57,    46,
      56,    59,    58,    60,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,     0,     0,    39,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    10,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,    72,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    38,    12,     0,
       0,     0,     0,    25,    33,    54,     0,     0,     0,     0,
      27,     0,     0,    32,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    30,     0,     0,    16,     0,     0,
      34,     0,     0,     0,     0,     0,     0,    33,    57,    56,
      59,    58,    70,     0,    35,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     0,     0,    27,    19,    18,    21,
      20,    22,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    17,     3,    40,    41,    42,   220,   230,   316,
      43,   214,   223,   297,    44,    54,    55,    45,    46,    16,
      47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
     -31,    67,     6,   -78,    66,   -78,    75,    91,    77,    78,
      87,   108,   -78,   -78,   -78,   -78,    82,    58,    88,    96,
     -78,   -78,   -78,   112,    93,   -78,    42,    94,    95,    98,
      99,   111,   116,    43,   118,   119,   131,   121,   128,   132,
     -78,   -78,   -78,   -78,   113,     4,   -78,    21,   151,   117,
     146,   117,   140,   145,   148,   -78,   117,   117,   117,   117,
     117,   117,   147,   165,   117,   117,   117,   117,   117,   166,
     -78,   -78,   155,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   150,   -78,   194,   167,   348,
     108,   108,    42,   369,   390,   411,   432,   453,   474,   130,
     160,   495,   231,   516,   537,   558,   154,   -78,   105,   915,
     105,    22,    22,   -78,   110,   110,   110,   110,   110,   149,
     108,   156,   169,   164,   159,   162,   -78,   -78,   -78,   -78,
     -78,   117,   117,   168,   117,   117,   171,   158,   176,   173,
     188,   175,   117,   -78,   -78,   170,   195,   579,   600,   177,
     277,   621,   190,   180,   196,   198,   186,   197,   915,   117,
     201,   -78,   -78,   203,   202,   117,   223,   209,   213,   226,
     117,   237,   915,   220,   -78,   210,   642,   230,   238,   117,
     117,   663,   239,   242,   240,   248,   221,   251,   684,   705,
     117,   -78,   -78,   246,    -6,   249,   250,   259,   260,   726,
     266,   261,   273,   267,   117,   270,   -78,   -78,   -78,   208,
     291,   280,   747,   -78,   -48,   284,   768,   286,   297,   285,
     253,   283,   292,   -78,   117,   294,   117,   296,   303,   -12,
     -78,   117,   310,   302,   308,   327,   281,   263,   313,   301,
     789,   309,   307,   -78,   304,   311,   318,   320,   117,   317,
     117,   330,   305,   323,   117,   117,   810,   315,   831,   335,
     326,   336,   252,   852,   338,   333,   342,   -78,   334,   349,
     344,   351,   359,   117,   -78,   355,   354,   356,   365,   357,
     873,   366,   117,   -78,   -78,   117,   372,   -78,   936,   894,
     -78,   117,   117,   117,   117,   117,   374,   -48,    13,    46,
      35,    55,    52,   377,   -78,   376,   383,   384,   385,   386,
     -78,   379,   395,   397,   398,   399,   253,   -78,   -78,   -78,
     -78,   -78,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   104,   -78,
     -78,   -78,   124,   -78,   -78,   -78,   322,   -78,   350,   -77,
     -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      87,   238,    89,   221,   222,   201,     5,    93,    94,    95,
      96,    97,    98,   124,   125,   101,   102,   103,   104,   105,
      71,     6,     1,    72,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   239,   202,   305,    73,
      76,    77,    78,   141,    74,    52,    62,    75,    76,    77,
      78,    78,    53,    63,    84,    79,    80,    81,    82,    83,
     307,    19,    84,    84,    78,    20,    21,    22,    23,    24,
       4,   306,    25,    76,    77,    78,    84,   309,    26,     7,
     308,    78,   147,   148,    78,   150,   151,    84,    27,    28,
      29,    30,     8,   158,     9,    10,    84,    31,    32,    11,
      12,    33,    34,    35,    18,    36,    37,    48,    38,    49,
     172,    39,    13,    14,    15,    50,   176,    51,    56,    57,
      86,   181,    58,    59,    20,    21,    22,    23,    73,    70,
     188,   189,    76,    77,    78,    60,    75,    76,    77,    78,
      61,   199,    64,    65,    66,    67,    84,    27,    28,    29,
      30,    84,    68,    69,    85,   212,    31,    32,    19,    88,
     216,    90,    20,    21,    22,    23,    91,    92,   100,   106,
      99,   120,   133,   134,   122,   233,   140,   235,    78,   142,
     144,   145,   240,   143,   146,    27,    28,    29,    30,   154,
     155,   156,   149,   159,    31,    32,   152,   157,   160,   256,
     153,   258,   163,   166,   167,   262,   263,   168,   121,   169,
     170,   215,    73,   171,   173,    20,    21,    22,    23,   174,
      75,    76,    77,    78,   280,   175,   177,   183,    79,    80,
      81,    82,    83,   288,   178,    84,   289,   179,    27,    28,
      29,    30,   298,   299,   300,   301,   302,    31,    32,    73,
     180,   182,   184,   186,   187,   191,   192,    75,    76,    77,
      78,   194,   196,   195,   193,    79,    80,    81,    82,    83,
      73,   200,    84,   203,   204,   205,   206,   136,    75,    76,
      77,    78,   208,   210,   213,   209,    79,    80,    81,    82,
      83,   164,   211,    84,   217,    73,   218,   224,   270,   226,
     227,   228,   229,    75,    76,    77,    78,   231,   246,   232,
     234,    79,    80,    81,    82,    83,   242,   237,    84,   236,
      73,   241,   243,   245,   247,   248,   265,   252,    75,    76,
      77,    78,   251,   250,   257,   253,    79,    80,    81,    82,
      83,   244,   254,    84,   255,    73,   259,   260,   261,   267,
     268,   272,   269,    75,    76,    77,    78,   273,   274,   275,
     276,    79,    80,    81,    82,    83,    73,   278,    84,   277,
     279,   281,   283,   123,    75,    76,    77,    78,   282,   284,
     287,   285,    79,    80,    81,    82,    83,    73,   290,    84,
     303,   310,   311,   317,   127,    75,    76,    77,    78,   312,
     313,   314,   315,    79,    80,    81,    82,    83,    73,   318,
      84,   319,   320,   321,   126,   128,    75,    76,    77,    78,
     322,   304,   107,     0,    79,    80,    81,    82,    83,    73,
       0,    84,     0,     0,     0,     0,   129,    75,    76,    77,
      78,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      73,     0,    84,     0,     0,     0,     0,   130,    75,    76,
      77,    78,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    73,   131,    84,     0,     0,     0,     0,     0,    75,
      76,    77,    78,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    73,   132,    84,     0,     0,     0,     0,     0,
      75,    76,    77,    78,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    73,   135,    84,     0,     0,     0,     0,
       0,    75,    76,    77,    78,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    73,     0,    84,     0,     0,   137,
       0,     0,    75,    76,    77,    78,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    73,     0,    84,     0,     0,
       0,     0,   138,    75,    76,    77,    78,     0,     0,     0,
       0,    79,    80,    81,    82,    83,    73,     0,    84,     0,
       0,     0,     0,   139,    75,    76,    77,    78,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    73,     0,    84,
       0,     0,     0,     0,   161,    75,    76,    77,    78,     0,
       0,     0,     0,    79,    80,    81,    82,    83,    73,     0,
      84,     0,     0,     0,     0,   162,    75,    76,    77,    78,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    73,
     165,    84,     0,     0,     0,     0,     0,    75,    76,    77,
      78,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      73,     0,    84,     0,     0,     0,     0,   185,    75,    76,
      77,    78,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    73,   190,    84,     0,     0,     0,     0,     0,    75,
      76,    77,    78,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    73,     0,    84,     0,     0,     0,     0,   197,
      75,    76,    77,    78,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    73,     0,    84,     0,     0,     0,     0,
     198,    75,    76,    77,    78,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    73,     0,    84,     0,     0,     0,
       0,   207,    75,    76,    77,    78,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    73,     0,    84,     0,     0,
       0,     0,   219,    75,    76,    77,    78,     0,     0,     0,
       0,    79,    80,    81,    82,    83,    73,     0,    84,     0,
       0,     0,     0,   225,    75,    76,    77,    78,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    73,     0,    84,
       0,     0,     0,     0,   249,    75,    76,    77,    78,     0,
       0,     0,     0,    79,    80,    81,    82,    83,    73,     0,
      84,     0,     0,     0,     0,   264,    75,    76,    77,    78,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    73,
       0,    84,     0,     0,     0,     0,   266,    75,    76,    77,
      78,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      73,     0,    84,     0,     0,     0,     0,   271,    75,    76,
      77,    78,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    73,     0,    84,     0,     0,     0,     0,   286,    75,
      76,    77,    78,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    73,     0,    84,     0,     0,     0,     0,   296,
      75,    76,    77,    78,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    73,     0,    84,     0,     0,     0,     0,
       0,    75,    76,    77,    78,     0,     0,     0,     0,    79,
      80,    81,    82,    83,   291,     0,    84,     0,     0,     0,
       0,     0,   292,   293,   294,    78,     0,     0,     0,     0,
      79,    80,    81,    82,    83,     0,     0,   295
};

static const yytype_int16 yycheck[] =
{
      49,    13,    51,    51,    52,    11,     0,    56,    57,    58,
      59,    60,    61,    90,    91,    64,    65,    66,    67,    68,
      16,    15,    53,    19,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    48,    43,    25,    18,
      27,    28,    29,   120,    23,     3,     3,    26,    27,    28,
      29,    29,    10,    10,    41,    34,    35,    36,    37,    38,
      25,     3,    41,    41,    29,     7,     8,     9,    10,    11,
       3,    25,    14,    27,    28,    29,    41,    25,    20,    13,
      25,    29,   131,   132,    29,   134,   135,    41,    30,    31,
      32,    33,    17,   142,     3,    18,    41,    39,    40,    21,
      13,    43,    44,    45,    22,    47,    48,    19,    50,    13,
     159,    53,     4,     5,     6,     3,   165,    24,    24,    24,
       3,   170,    24,    24,     7,     8,     9,    10,    18,    16,
     179,   180,    27,    28,    29,    24,    26,    27,    28,    29,
      24,   190,    24,    24,    13,    24,    41,    30,    31,    32,
      33,    41,    24,    21,     3,   204,    39,    40,     3,    13,
     209,    21,     7,     8,     9,    10,    21,    19,     3,     3,
      23,    21,    42,    13,     7,   224,    22,   226,    29,    23,
      16,    22,   231,    14,    22,    30,    31,    32,    33,    13,
      17,     3,    24,    23,    39,    40,    25,    22,     3,   248,
      42,   250,    25,    13,    24,   254,   255,    11,    14,    11,
      24,     3,    18,    16,    13,     7,     8,     9,    10,    16,
      26,    27,    28,    29,   273,    23,     3,     7,    34,    35,
      36,    37,    38,   282,    25,    41,   285,    24,    30,    31,
      32,    33,   291,   292,   293,   294,   295,    39,    40,    18,
      24,    14,    42,    23,    16,    16,    14,    26,    27,    28,
      29,    13,    11,    42,    24,    34,    35,    36,    37,    38,
      18,    25,    41,    24,    24,    16,    16,    46,    26,    27,
      28,    29,    16,    10,    14,    24,    34,    35,    36,    37,
      38,    14,    25,    41,     3,    18,    16,    13,    46,    13,
       3,    16,    49,    26,    27,    28,    29,    24,    45,    17,
      16,    34,    35,    36,    37,    38,    14,    14,    41,    23,
      18,    11,    14,    42,    11,    24,    11,    23,    26,    27,
      28,    29,    25,    24,    17,    24,    34,    35,    36,    37,
      38,    14,    24,    41,    24,    18,    16,    42,    25,    14,
      24,    13,    16,    26,    27,    28,    29,    24,    16,    25,
      11,    34,    35,    36,    37,    38,    18,    16,    41,    25,
      11,    16,    16,    25,    26,    27,    28,    29,    24,    14,
      14,    24,    34,    35,    36,    37,    38,    18,    16,    41,
      16,    14,    16,    14,    25,    26,    27,    28,    29,    16,
      16,    16,    16,    34,    35,    36,    37,    38,    18,    14,
      41,    14,    14,    14,    92,    25,    26,    27,    28,    29,
     316,   297,    72,    -1,    34,    35,    36,    37,    38,    18,
      -1,    41,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      18,    -1,    41,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    18,    19,    41,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    18,    19,    41,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    18,    19,    41,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    18,    -1,    41,    -1,    -1,    23,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    18,    -1,    41,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    18,    -1,    41,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    18,    -1,    41,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    18,    -1,
      41,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    18,
      19,    41,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      18,    -1,    41,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    18,    19,    41,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    18,    -1,    41,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    18,    -1,    41,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    18,    -1,    41,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    18,    -1,    41,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    18,    -1,    41,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    18,    -1,    41,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    18,    -1,
      41,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    18,
      -1,    41,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      18,    -1,    41,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    18,    -1,    41,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    18,    -1,    41,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    18,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    18,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    55,    57,     3,     0,    15,    13,    17,     3,
      18,    21,    13,     4,     5,     6,    73,    56,    22,     3,
       7,     8,     9,    10,    11,    14,    20,    30,    31,    32,
      33,    39,    40,    43,    44,    45,    47,    48,    50,    53,
      58,    59,    60,    64,    68,    71,    72,    74,    19,    13,
       3,    24,     3,    10,    69,    70,    24,    24,    24,    24,
      24,    24,     3,    10,    24,    24,    13,    24,    24,    21,
      16,    16,    19,    18,    23,    26,    27,    28,    29,    34,
      35,    36,    37,    38,    41,     3,     3,    74,    13,    74,
      21,    21,    19,    74,    74,    74,    74,    74,    74,    23,
       3,    74,    74,    74,    74,    74,     3,    72,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      21,    14,     7,    25,    73,    73,    70,    25,    25,    25,
      25,    19,    19,    42,    13,    19,    46,    23,    25,    25,
      22,    73,    23,    14,    16,    22,    22,    74,    74,    24,
      74,    74,    25,    42,    13,    17,     3,    22,    74,    23,
       3,    25,    25,    25,    14,    19,    13,    24,    11,    11,
      24,    16,    74,    13,    16,    23,    74,     3,    25,    24,
      24,    74,    14,     7,    42,    25,    23,    16,    74,    74,
      19,    16,    14,    24,    13,    42,    11,    25,    25,    74,
      25,    11,    43,    24,    24,    16,    16,    25,    16,    24,
      10,    25,    74,    14,    65,     3,    74,     3,    16,    25,
      61,    51,    52,    66,    13,    25,    13,     3,    16,    49,
      62,    24,    17,    74,    16,    74,    23,    14,    13,    48,
      74,    11,    14,    14,    14,    42,    45,    11,    24,    25,
      24,    25,    23,    24,    24,    24,    74,    17,    74,    16,
      42,    25,    74,    74,    25,    11,    25,    14,    24,    16,
      46,    25,    13,    24,    16,    25,    11,    25,    16,    11,
      74,    16,    24,    16,    14,    24,    25,    14,    74,    74,
      16,    18,    26,    27,    28,    41,    25,    67,    74,    74,
      74,    74,    74,    16,    66,    25,    25,    25,    25,    25,
      14,    16,    16,    16,    16,    16,    63,    14,    14,    14,
      14,    14,    62
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
#line 155 "mn.y"
    {fprintf(yyout,"Compilation Successful\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 169 "mn.y"
    {
	
				int hv = hashVal((yyvsp[(2) - (15)].val).name);
				if(whatType[hv] != 0)
				{
					printf("Variable named %s already declared\n", (yyvsp[(2) - (15)].val).name);
					fprintf(yyout, "Variable named %s already declared\n", (yyvsp[(2) - (15)].val).name);
				}
				else whatType[hv] = 8;

			
		;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 189 "mn.y"
    {fprintf(yyout,"Valid declaration statement\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 195 "mn.y"
    {
												fprintf(yyout,"Inside print operation\n");
												
												fprintf(yyout,"The value of  %s is: ", (yyvsp[(3) - (5)].val).name);
												
												printf("The value of  %s is: ", (yyvsp[(3) - (5)].val).name);
												
												int hv = (yyvsp[(3) - (5)].val).hash_value;
												
												int tp = (yyvsp[(3) - (5)].val).type;
												
												if(tp == 1)
												{
													fprintf(yyout,"%d\n", (yyvsp[(3) - (5)].val).integer);
													printf("%d\n", (yyvsp[(3) - (5)].val).integer);
													(yyval.val).integer = (yyvsp[(3) - (5)].val).integer;
												}
												
												else if(tp == 2)
												{
													fprintf(yyout,"%0.5lf\n", (yyvsp[(3) - (5)].val).floating);
													printf("%0.5lf\n", (yyvsp[(3) - (5)].val).floating);
													(yyvsp[(1) - (5)].val).floating = (yyvsp[(3) - (5)].val).floating;
													(yyval.val).floating = (yyvsp[(3) - (5)].val).floating;
												}
												
												else if(tp == 3)
												{
													fprintf(yyout,"%s\n", (yyvsp[(3) - (5)].val).str);
													printf("%s\n", (yyvsp[(3) - (5)].val).str);
													strcpy((yyval.val).str, (yyvsp[(3) - (5)].val).str);
												}
												else if(tp == 4)
												{
													if((yyvsp[(3) - (5)].val).integer == 1)
													{
														fprintf(yyout,"True\n");
														printf("True\n");
														strcpy((yyval.val).str, "True");
													}
													else if((yyvsp[(3) - (5)].val).integer == 0) 
													{
														fprintf(yyout,"False\n");
														printf("False\n");
														strcpy((yyval.val).str, "False");
													}
												}
											;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 246 "mn.y"
    {
															int hv = hashVal((yyvsp[(2) - (7)].val).name);
															fprintf(yyout,"Inside input operation\n");
															if(whatType[hv] == 0)
															{
																fprintf(yyout,"Variable %s not declared\n", (yyvsp[(2) - (7)].val).name);
																
															}
															else
															{   
																
																int t1 = whatType[hv];
																
																
																printf("Enter input for variable %s\n", (yyvsp[(2) - (7)].val).name);
																
																fprintf(yyout,"Input taken for variable %s is: ", (yyvsp[(2) - (7)].val).name);
																if(t1 == 1)
																{   
																	int x;
																	scanf("%d", &x);
																	valInt[hv][0] = x;
																	fprintf(yyout,"%d\n", valInt[hv][0]);
																}
																else if(t1 == 2)
																{	
																	double x;
																	scanf("%lf", &x);
																	valDoub[hv][0] = x;
																	fprintf(yyout,"%.5lf\n", valDoub[hv][0]);
																}
																else if(t1 == 3)
																{
																	char str[1000];
																	scanf("%s", str);
																	strcpy(valStr[hv], str);
																	fprintf(yyout,"%s\n", valStr[hv]);
																}
																
																
															}
														;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 291 "mn.y"
    {
																				int hv = hashVal((yyvsp[(3) - (11)].val).name);
																				if(whatType[hv] == 0)
																				{
																					printf("Variable not declared\n");
																				}
																				else
																				{   
																					
																					int t1 = whatType[hv];
																					//printf("TT %d\n",t1);
																					printf("Input value for array %s at index %d: ", (yyvsp[(3) - (11)].val).name, (yyvsp[(5) - (11)].val).integer);
																					if(t1==1)
																					{
																						int x;
																						scanf("%d", &x);
																						valInt[hv][(yyvsp[(5) - (11)].val).integer] = x;
																						fprintf(yyout, "Value assigned to array %s at index %d is: ", (yyvsp[(3) - (11)].val).name, (yyvsp[(5) - (11)].val).integer);
																						fprintf(yyout,"%d\n", valInt[hv][(yyvsp[(5) - (11)].val).integer]);
																					
																					}
																					else if(t1==2)
																					{
																						double x;
																						scanf("%lf", &x);
																						valDoub[hv][(yyvsp[(5) - (11)].val).integer] = x;
																						fprintf(yyout,"Value assigned to array %s at index %d is: ", (yyvsp[(3) - (11)].val).name, (yyvsp[(5) - (11)].val).integer);
																						fprintf(yyout,"%0.5lf\n", valDoub[hv][(yyvsp[(5) - (11)].val).integer]);
																					
																					}
																				}
																			;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 326 "mn.y"
    { Cond++; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 328 "mn.y"
    { Cond++; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 338 "mn.y"
    {
					
					int hv = hashVal((yyvsp[(12) - (21)].val).name);
					int t1 = whatType[hv];
					if(t1 == 0)
					{
						printf("Variable not declared\n");
					}
					else
					{
						char st[1000];
						strcpy(st, (yyvsp[(12) - (21)].val).name);
						
						int i = (yyvsp[(3) - (21)].val).integer, sz = (yyvsp[(5) - (21)].val).integer, inc = (yyvsp[(7) - (21)].val).integer;
						for( ; i < sz; i+=inc)
						{
							printf("Enter value for array %s at index %d: ", st, i);
							if(t1 == 1)
							{
								int x;
								scanf("%d", &x);
								valInt[hv][i] = x;
								fprintf(yyout,"Value assigned for array %s at index %d is: ", st, i);
								fprintf(yyout,"%d\n",valInt[hv][i]);
							}
							else if(t1 == 2)
							{
								double x;
								scanf("%lf", &x);
								valDoub[hv][i] = x;
								fprintf(yyout,"Value assigned for array %s at index %d is: ", st, i);
								fprintf(yyout,"%0.5lf\n",valDoub[hv][i]);
							}
						}
					}
					
		;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 379 "mn.y"
    {
	
				
				
				int hv = hashVal((yyvsp[(12) - (18)].val).name);
				int t1 = whatType[hv];
				if(t1 == 0)
				{
					printf("Variable not declared\n");
				}
				
				else
				{
					char st[1000];
					strcpy(st, (yyvsp[(12) - (18)].val).name);
						
					int i = (yyvsp[(3) - (18)].val).integer, sz = (yyvsp[(5) - (18)].val).integer, inc = (yyvsp[(7) - (18)].val).integer;
					for( ; i < sz; i+=inc)
					{
						printf("The value of array %s at index %d id: ", st,i);
						fprintf(yyout, "The value of array %s at index %d id: ", st,i);
						if(t1== 1)
						{
							printf("%d\n", valInt[hv][i]);
							fprintf(yyout,"%d\n", valInt[hv][i]);
						}
						else if(t1 == 2)
						{
							printf("%.5lf\n", valDoub[hv][i]);
							fprintf(yyout,"%.5lf\n", valDoub[hv][i]);
						}
					}
				}	
			;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 415 "mn.y"
    {
	
					int i = (yyvsp[(3) - (26)].val).integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal((yyvsp[(7) - (26)].val).name), hv2 = hashVal((yyvsp[(13) - (26)].val).name);
						int aa, bb;
						printf("Enter the value of variable %s: ", (yyvsp[(7) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", (yyvsp[(13) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb+=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 438 "mn.y"
    {
	
					int i = (yyvsp[(3) - (26)].val).integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal((yyvsp[(7) - (26)].val).name), hv2 = hashVal((yyvsp[(13) - (26)].val).name);
						int aa, bb;
						printf("Enter the value of variable %s: ", (yyvsp[(7) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", (yyvsp[(13) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb-=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 462 "mn.y"
    {
	
					int i = (yyvsp[(3) - (26)].val).integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal((yyvsp[(7) - (26)].val).name), hv2 = hashVal((yyvsp[(13) - (26)].val).name);
						int aa, bb;
						printf("Enter the value of variable %s: ", (yyvsp[(7) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", (yyvsp[(13) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb*=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 485 "mn.y"
    {
	
					int i = (yyvsp[(3) - (26)].val).integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal((yyvsp[(7) - (26)].val).name), hv2 = hashVal((yyvsp[(13) - (26)].val).name);
						int aa, bb;
						printf("Enter the value of variable %s: ", (yyvsp[(7) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", (yyvsp[(13) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb/=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 508 "mn.y"
    {
	
					int i = (yyvsp[(3) - (26)].val).integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal((yyvsp[(7) - (26)].val).name), hv2 = hashVal((yyvsp[(13) - (26)].val).name);
						int aa, bb;
						printf("Enter the value of variable %s: ", (yyvsp[(7) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", (yyvsp[(13) - (26)].val).name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb%=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 532 "mn.y"
    {
	
					int i = (yyvsp[(17) - (20)].val).integer+1;
					fprintf(yyout,"Do-While execution start\n");
					while(i--)
					{
						
						int hv = hashVal((yyvsp[(3) - (20)].val).name);
						printf("Enter the input for variable %s: ", (yyvsp[(3) - (20)].val).name);
						scanf("%d", &valInt[hv][0]);
						printf("The value of the expression is %d\n", valInt[hv][0]);
						fprintf(yyout,"The value of the expression is %d\n", valInt[hv][0]);
					}
		;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 548 "mn.y"
    {
			
			int i = (yyvsp[(3) - (15)].val).integer, sz = (yyvsp[(5) - (15)].val).integer, inc = (yyvsp[(7) - (15)].val).integer;
			for( ; i< sz; i++)
			{	
				printf("Value of the expression inside for loop: ");
				fprintf(yyout, "Value of the expression inside for loop: ");
				int t1 = (yyvsp[(12) - (15)].val).type;
				if(t1 == 1) 
				{
					printf("%d\n", (yyvsp[(12) - (15)].val).integer);
					fprintf(yyout, "%d\n", (yyvsp[(12) - (15)].val).integer);
				}
				else if(t1 == 2)
				{
					fprintf(yyout,"%.5lf\n", (yyvsp[(12) - (15)].val).floating);
					printf("%.5lf\n", (yyvsp[(12) - (15)].val).floating);
				}
				else if(t1 == 3)
				{
					printf("%s\n", (yyvsp[(12) - (15)].val).str);
					fprintf(yyout,"%s\n", (yyvsp[(12) - (15)].val).str);
				}
			}
			
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 588 "mn.y"
    {
			
				if((yyvsp[(3) - (11)].val).integer == 1) {
					fprintf(yyout,"Inside if block\n");
					fprintf(yyout, "%s\n", (yyvsp[(8) - (11)].val).str);
					printf("%s\n", (yyvsp[(8) - (11)].val).str);
					ara[Cond] = 1;
				}
			
		;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 597 "mn.y"
    { int qt=1; ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 601 "mn.y"
    {int qt=1;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 602 "mn.y"
    {
	
			
			if((yyvsp[(4) - (12)].val).integer == 1 && ara[Cond] == 0) {
					fprintf(yyout,"Inside else if block\n");
					fprintf(yyout, "%s\n", (yyvsp[(9) - (12)].val).str);
					printf("%s\n", (yyvsp[(9) - (12)].val).str);
					ara[Cond] = 1;
				}
		;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 611 "mn.y"
    {int qw;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 612 "mn.y"
    {
			
			if(ara[Cond] == 0)
			{	
				fprintf(yyout,"Inside else block\n");
				printf("%s\n", (yyvsp[(5) - (8)].val).str);
				fprintf(yyout,"%s\n", (yyvsp[(5) - (8)].val).str);
			}
			
		;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 639 "mn.y"
    {

		
			int x = (yyvsp[(3) - (10)].val).integer;
			if(x == 1)
			{
				ara[Cond] = 1;
				
				fprintf(yyout,"Inside switch block\n");
				printf("%s\n", (yyvsp[(8) - (10)].val).str);
				fprintf(yyout, "%s\n", (yyvsp[(8) - (10)].val).str);
				
			} 
		
		;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 653 "mn.y"
    {int pq;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 658 "mn.y"
    {

		
			int x = (yyvsp[(3) - (10)].val).integer;
			if(x == 1 && ara[Cond] == 0)
			{
				ara[Cond] = 1;
				
				fprintf(yyout,"Inside case block\n");
				printf("%s\n", (yyvsp[(8) - (10)].val).str);
				fprintf(yyout, "%s\n", (yyvsp[(8) - (10)].val).str);
				
			} 
		
		;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 672 "mn.y"
    {int a;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 674 "mn.y"
    {

		
			
			if(ara[Cond] == 0)
			{
				ara[Cond] = 1;
				
				fprintf(yyout,"Inside case block\n");
				printf("%s\n", (yyvsp[(5) - (7)].val).str);
				fprintf(yyout, "%s\n", (yyvsp[(5) - (7)].val).str);
				
			} 
		
		;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 705 "mn.y"
    {	
									fprintf(yyout,"All Declaraions Successful\n");
								;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 709 "mn.y"
    {
	
				int hv = hashVal((yyvsp[(3) - (10)].val).name);
				if(whatType[hv] != 8)
				{
					printf("No class named %s\n", (yyvsp[(3) - (10)].val).name);
					fprintf(yyout, "No class named %s\n", (yyvsp[(3) - (10)].val).name);
				}
				else
				{
					int a = (yyvsp[(7) - (10)].val).integer; double b = (yyvsp[(9) - (10)].val).floating;
					int hv2 = hashVal((yyvsp[(5) - (10)].val).name);
					int chk = Check_var((yyvsp[(5) - (10)].val).name);
					if(!chk)
					{
						printf("Variable %s already exists\n", (yyvsp[(5) - (10)].val).name);
						fprintf(yyout, "Variable %s already exists\n", (yyvsp[(5) - (10)].val).name);
					}
					else
					{
						strcpy(isVar[available_index++],(yyvsp[(5) - (10)].val).name);
						whatType[hv2] = 8;
						valInt[hv2][0] = a;
						valDoub[hv2][0] = b;
						printf("Values assigned to class %s variable %s are %d and %.5lf\n",(yyvsp[(3) - (10)].val).name, (yyvsp[(5) - (10)].val).name,valInt[hv2][0], valDoub[hv2][0] );
						fprintf(yyout,"Values assigned to class %s variable %s are %d and %.5lf\n",(yyvsp[(3) - (10)].val).name, (yyvsp[(5) - (10)].val).name,valInt[hv2][0], valDoub[hv2][0] );
					}
				}
	
		;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 747 "mn.y"
    {
										fprintf(yyout,"lower most declaration stage\n");
										fprintf(yyout,"Declaraion without assignment\n");
										int check = Check_var((yyvsp[(1) - (4)].val).name);
										if(check)
										{
											strcpy(isVar[available_index++],(yyvsp[(1) - (4)].val).name);
											fprintf(yyout,"newly declared variable: %s\n", (yyvsp[(1) - (4)].val).name);
											(yyvsp[(1) - (4)].val).type = (yyvsp[(3) - (4)].val).type;
											int hv = hashVal((yyvsp[(1) - (4)].val).name);
											fprintf(yyout,"Hash value of newly declared variable %s is %d\n", (yyvsp[(1) - (4)].val).name, hv);
											whatType[hv]=(yyvsp[(1) - (4)].val).type;
											fprintf(yyout,"The type of the variable is %d\n", whatType[hv]);
											
										}
										else
										{
											fprintf(yyout,"variable %s already declared\n", (yyvsp[(1) - (4)].val).name);
										}
									;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 768 "mn.y"
    {   
	
															fprintf(yyout,"lower most declaration stage\n");
															fprintf(yyout,"Declaraion with assignment\n");
															int check = Check_var((yyvsp[(1) - (6)].val).name);
															if(check)
															{
																fprintf(yyout,"Inside assignment operation when declared\n");
																(yyvsp[(1) - (6)].val).type = (yyvsp[(3) - (6)].val).type;
																fprintf(yyout,"type of newly declared variable: %s is %d\n", (yyvsp[(1) - (6)].val).name, (yyvsp[(1) - (6)].val).type);
																fprintf(yyout,"type of constant is %d\n", (yyvsp[(6) - (6)].val).type);
																fprintf(yyout,"value of constant is: ");
																if((yyvsp[(6) - (6)].val).type==1) fprintf(yyout,"%d\n", (yyvsp[(6) - (6)].val).integer);
																else if((yyvsp[(6) - (6)].val).type==2) fprintf(yyout,"%0.5lf\n", (yyvsp[(6) - (6)].val).floating);
																else if((yyvsp[(6) - (6)].val).type==3) fprintf(yyout,"%s\n", (yyvsp[(6) - (6)].val).str);
																if((yyvsp[(1) - (6)].val).type != (yyvsp[(6) - (6)].val).type)
																{
																	fprintf(yyout,"Invalid type!\n");
																}
																else
																{   
																	strcpy(isVar[available_index++],(yyvsp[(1) - (6)].val).name);
																	fprintf(yyout,"newly declared variable: %s\n", (yyvsp[(1) - (6)].val).name);
																	(yyvsp[(1) - (6)].val).type = (yyvsp[(3) - (6)].val).type;
																	int hv = hashVal((yyvsp[(1) - (6)].val).name);
																	fprintf(yyout,"Hash value of newly declared variable %s is %d\n", (yyvsp[(1) - (6)].val).name, hv);
																	whatType[hv]=(yyvsp[(1) - (6)].val).type;
																	if((yyvsp[(1) - (6)].val).type == 1)
																	{
																		valInt[hv][0] = (yyvsp[(6) - (6)].val).integer;
					
																	}
																	else if((yyvsp[(1) - (6)].val).type == 2)
																	{
																		valDoub[hv][0] = (yyvsp[(6) - (6)].val).floating;
																	}
																	else if((yyvsp[(1) - (6)].val).type == 3)
																	{
																		strcpy(valStr[hv], (yyvsp[(6) - (6)].val).str);
																	}
																	fprintf(yyout,"Assignment successfull\n");
																	fprintf(yyout,"Assigned value for variable %s: ", (yyvsp[(1) - (6)].val).name);
																	if((yyvsp[(1) - (6)].val).type == 1)
																	{
																		fprintf(yyout,"%d\n", valInt[hv][0]);
																	}
																    if((yyvsp[(1) - (6)].val).type == 2)
																	{
																		fprintf(yyout,"%0.5lf\n", valDoub[hv][0]);
																	}
																	else if((yyvsp[(1) - (6)].val).type == 3)
																	{
																		fprintf(yyout,"%s\n", valStr[hv]);
																	}
																
																}
															}
															else
															{
																fprintf(yyout,"Variable already declared\n");
															}
														;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 833 "mn.y"
    {
															fprintf(yyout,"lower most declaration stage\n");
															fprintf(yyout,"Declaraion of array\n");
															int check = Check_var((yyvsp[(5) - (8)].val).name);
															if(check)
															{
																strcpy(isVar[available_index++],(yyvsp[(5) - (8)].val).name);
																fprintf(yyout,"newly declared array: %s\n", (yyvsp[(5) - (8)].val).name);
																(yyvsp[(5) - (8)].val).type = (yyvsp[(3) - (8)].val).type;
																int hv = hashVal((yyvsp[(5) - (8)].val).name);
																isArr[hv] = 1;
																fprintf(yyout,"Hash value of newly declared variable %s is %d\n", (yyvsp[(5) - (8)].val).name, hv);
																whatType[hv]=(yyvsp[(3) - (8)].val).type;
																fprintf(yyout,"The type of the variable is %d\n", whatType[hv]);
																
															}
															else
															{
																fprintf(yyout,"variable %s already declared\n", (yyvsp[(5) - (8)].val).name);
															}
														;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 869 "mn.y"
    {
													fprintf(yyout,"Assignment without Declaraion\n");
													int hv = (yyvsp[(1) - (3)].val).hash_value;
													if(whatType[hv] == 0)
													{
														fprintf(yyout,"Variable not Declared yet! Assignment is not possible\n");
													}
													else
													{
														int t1 = whatType[hv];
														int t2 = (yyvsp[(3) - (3)].val).type;
														if(t1 != t2)
														{
															if(t1 == 2 && t2 == 1)
															{
																int hv = (yyvsp[(1) - (3)].val).hash_value;
																valDoub[hv][0] = (yyvsp[(3) - (3)].val).integer;
																fprintf(yyout,"Assignment Successful\n");
															}
															else
															{
																fprintf(yyout,"Invalid Assignment Operation\n");
															}
														}
														else
														{
															
															if(t1 == 1) 
															{   
																valInt[hv][0] = (yyvsp[(3) - (3)].val).integer;
																fprintf(yyout,"Assigned value for variable %s is %d\n", (yyvsp[(1) - (3)].val).name, valInt[hv][0]);
															}
															else if(t1 == 2) 
															{
																valDoub[hv][0] = (yyvsp[(3) - (3)].val).floating;
																fprintf(yyout,"Assigned value for variable %s is %0.5lf\n", (yyvsp[(1) - (3)].val).name, valDoub[hv][0]);
															}
															else if(t1 == 3) 
															{
																strcpy(valStr[hv], (yyvsp[(3) - (3)].val).str);
																fprintf(yyout,"Assigned value for variable %s is %s\n", (yyvsp[(1) - (3)].val).name, valStr[hv]);
															}
														}
													}
												;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 914 "mn.y"
    {	
																	fprintf(yyout,"Inside array assignment\n");
																	int hv = hashVal((yyvsp[(1) - (6)].val).name);
																	int index = (yyvsp[(3) - (6)].val).integer;
																	if(isArr[hv]==0)
																	{
																		fprintf(yyout,"Variable %s is not an array\n", (yyvsp[(1) - (6)].val).name);
																	}
																	else
																	{   
																	    fprintf(yyout,"Value assigned to array %s at index %d: ", (yyvsp[(1) - (6)].val).name, (yyvsp[(3) - (6)].val).integer);
																		int t1 = whatType[hv];
																		int t2 = (yyvsp[(6) - (6)].val).type;
																		if(t1!=t2)
																		{
																			if(t1 == 2 && t2==1)
																			{
																				valDoub[hv][index]=(yyvsp[(6) - (6)].val).integer;
																				fprintf(yyout,"%0.5lf\n", valDoub[hv][index]);
																			}
																			else fprintf(yyout,"Invalid assignment\n");

																		}
																		else
																		{
																			if(t1==1)
																			{
																				valInt[hv][index] = (yyvsp[(6) - (6)].val).integer;
																				fprintf(yyout,"%d\n", valDoub[hv][index]);
																			}
																			else if(t2==2)
																			{
																				valDoub[hv][index]=(yyvsp[(6) - (6)].val).floating;
																				fprintf(yyout,"%0.5lf\n", valDoub[hv][index]);
																			}
																		}
																		
																	}
																;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 961 "mn.y"
    { (yyval.val).type = (yyvsp[(1) - (1)].val).type; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 962 "mn.y"
    { (yyval.val).type = (yyvsp[(1) - (1)].val).type; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 963 "mn.y"
    { (yyval.val).type = (yyvsp[(1) - (1)].val).type; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 970 "mn.y"
    {
									
									(yyval.val).type = (yyvsp[(1) - (1)].val).type;
									(yyval.val).integer = (yyvsp[(1) - (1)].val).integer
	
								;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 977 "mn.y"
    {
									(yyval.val).type = (yyvsp[(1) - (1)].val).type;
									(yyval.val).floating = (yyvsp[(1) - (1)].val).floating;
								;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 982 "mn.y"
    {
									(yyval.val).type = (yyvsp[(1) - (1)].val).type;
									strcpy((yyval.val).str, (yyvsp[(1) - (1)].val).str);
									//fprintf(yyout,"eije: %s\n",$$.str);
	
							
								;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 990 "mn.y"
    {
								int hv = hashVal((yyvsp[(1) - (1)].val).name);
								if(whatType[hv]==0)
								{
									fprintf(yyout,"Variable not declared!\n");
								}
								else
								{
									int t1 = whatType[hv];
									(yyval.val).hash_value= hv;
									strcpy((yyval.val).name, (yyvsp[(1) - (1)].val).name);
									(yyval.val).type = t1;
									if(t1 == 1)
									{
										(yyval.val).integer = valInt[hv][0];
									}
									else if(t1 == 2)
									{
										(yyval.val).floating = valDoub[hv][0];
									}
									else if(t1 == 3)
									{
										strcpy((yyval.val).str, valStr[hv]);
									}
									
								}
							;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1018 "mn.y"
    {
												int hv = hashVal((yyvsp[(2) - (5)].val).name);
												if(whatType[hv] == 0)
												{
													fprintf(yyout,"Array %s not declared yet\n", (yyvsp[(2) - (5)].val).name);
												}
												else
												{
													(yyval.val).type = whatType[hv];
													strcpy((yyval.val).name, (yyvsp[(2) - (5)].val).name);
													int t1 = (yyval.val).type;
													int idx = (yyvsp[(4) - (5)].val).integer;
													if(t1 == 1)
													{
														(yyval.val).integer = valInt[hv][idx];
														
													}
													else if(t1 == 2)
													{
														(yyval.val).floating = valDoub[hv][idx];
													}
												}
											;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1043 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												strcpy((yyval.val).name, "addition expression");
												if(t1 != t2)
												{
													if(t1 == 3 || t2 == 3)
													{
														fprintf(yyout,"This operation is not possible\n");
													}
													
													else
													{
														(yyval.val).type = 2;
														double a, b;
														if(t1 == 2) a = (yyvsp[(1) - (3)].val).floating;
														else if(t1==1) a = (yyvsp[(1) - (3)].val).integer;
														if(t2 == 1) b = (yyvsp[(3) - (3)].val).integer;
														else if(t2 == 2) b = (yyvsp[(3) - (3)].val).floating;
														(yyval.val).floating = a+b;
													}
												}
												
												else
												{
													if(t1 == 1)
													{
														(yyval.val).type = 1;
														int a, b;
														a = (yyvsp[(1) - (3)].val).integer, b = (yyvsp[(3) - (3)].val).integer;
														(yyval.val).integer = a+b;
													}
													
													else if(t1 ==2)
													{
														(yyval.val).type = 2;
														double a, b;
														a = (yyvsp[(1) - (3)].val).floating, b = (yyvsp[(3) - (3)].val).floating;
														(yyval.val).floating = a+b;
													}
													
													else if(t1 == 3)
													{
														(yyval.val).type = 3;
														char a[1000], b[1000];
														strcpy(a, (yyvsp[(1) - (3)].val).str);
														strcat(a, (yyvsp[(3) - (3)].val).str);
														strcpy((yyval.val).str, a);
													}
												}
												
											;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1096 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												strcpy((yyval.val).name, "subtraction expression");
												if(t1 != t2)
												{
													if(t1 == 3 || t2 == 3)
													{
														fprintf(yyout,"This operation is not possible\n");
													}
													
													else
													{
														(yyval.val).type = 2;
														double a, b;
														if(t1 == 2) a = (yyvsp[(1) - (3)].val).floating;
														else if(t1==1) a = (yyvsp[(1) - (3)].val).integer;
														if(t2 == 1) b = (yyvsp[(3) - (3)].val).integer;
														else if(t2 == 2) b = (yyvsp[(3) - (3)].val).floating;
														(yyval.val).floating = a-b;
													}
												}
												
												else
												{
													if(t1 == 1)
													{
														(yyval.val).type = 1;
														int a, b;
														a = (yyvsp[(1) - (3)].val).integer, b = (yyvsp[(3) - (3)].val).integer;
														(yyval.val).integer = a-b;
													}
													
													else if(t1 ==2)
													{
														(yyval.val).type = 2;
														double a, b;
														a = (yyvsp[(1) - (3)].val).floating, b = (yyvsp[(3) - (3)].val).floating;
														(yyval.val).floating = a-b;
													}
													
												}
												
											;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1142 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												strcpy((yyval.val).name, "multiplication expression");
												if(t1 != t2)
												{
													if(t1 == 3 || t2 == 3)
													{
														fprintf(yyout,"This operation is not possible\n");
													}
													
													else
													{
														(yyval.val).type = 2;
														double a, b;
														if(t1 == 2) a = (yyvsp[(1) - (3)].val).floating;
														else if(t1==1) a = (yyvsp[(1) - (3)].val).integer;
														if(t2 == 1) b = (yyvsp[(3) - (3)].val).integer;
														else if(t2 == 2) b = (yyvsp[(3) - (3)].val).floating;
														(yyval.val).floating = (double)(a*b);
													}
												}
												
												else
												{
													if(t1 == 1)
													{
														(yyval.val).type = 1;
														int a, b;
														a = (yyvsp[(1) - (3)].val).integer, b = (yyvsp[(3) - (3)].val).integer;
														(yyval.val).integer = a*b;
													}
													
													else if(t1 ==2)
													{
														(yyval.val).type = 2;
														double a, b;
														a = (yyvsp[(1) - (3)].val).floating, b = (yyvsp[(3) - (3)].val).floating;
														(yyval.val).floating = a*b;
													}
													
												}
												
											;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1187 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												strcpy((yyval.val).name, "division expression");
												if(t1 != t2)
												{
													if(t1 == 3 || t2 == 3)
													{
														fprintf(yyout,"This operation is not possible\n");
													}
													
													else
													{
														(yyval.val).type = 2;
														double a, b;
														if(t1 == 2) a = (yyvsp[(1) - (3)].val).floating;
														else if(t1==1) a = (yyvsp[(1) - (3)].val).integer;
														if(t2 == 1) b = (yyvsp[(3) - (3)].val).integer;
														else if(t2 == 2) b = (yyvsp[(3) - (3)].val).floating;
														(yyval.val).floating = (double)(a/b);
													}
												}
												
												else
												{
													if(t1 == 1)
													{
														(yyval.val).type = 1;
														int a, b;
														a = (yyvsp[(1) - (3)].val).integer, b = (yyvsp[(3) - (3)].val).integer;
														(yyval.val).integer = a/b;
													}
													
													else if(t1 ==2)
													{
														(yyval.val).type = 2;
														double a, b;
														a = (yyvsp[(1) - (3)].val).floating, b = (yyvsp[(3) - (3)].val).floating;
														(yyval.val).floating = a/b;
													}
													
												}
												
											;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1233 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												if(t1 == 3 || t2 != 1)
												{
													fprintf(yyout,"Invalid power operation\n");
												}
												else
												{    
												    strcpy((yyval.val).name, "power expression");
													if(t1 == 2) (yyval.val).type = 2;
													else if(t1==1) (yyval.val).type = 1;
													int p= (yyvsp[(3) - (3)].val).integer;
													//fprintf(yyout,"PVAL: %d\n", p);
													int a;
													double aa;
													if(t1 == 1) a= (yyvsp[(1) - (3)].val).integer;
													else if(t1 == 2) aa = (yyvsp[(1) - (3)].val).floating;
													double ret1 = 1.0;
													int ret2 = 1;
													for(int i=0;i<p;i++) 
													{
														if(t1 == 1) ret2*=a;
														else if(t1 == 2) ret1*=aa;
														
														
													}
													if(t1 == 1) (yyval.val).integer = ret2;
													else if(t1 == 2) (yyval.val).floating = ret1;
												}
												
											;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1266 "mn.y"
    {   
	
												if((yyvsp[(3) - (4)].val).type == 3) 
												{
													fprintf(yyout,"Invalid log operation\n");
					
													(yyval.val).type = 2;
									
												}
												else
												{
													strcpy((yyval.val).name, "log operation expression");
													(yyval.val).type = 2;
													double aa;
													if((yyvsp[(3) - (4)].val).type == 1) aa= (yyvsp[(3) - (4)].val).integer;
													else if((yyvsp[(3) - (4)].val).type == 2) aa = (yyvsp[(3) - (4)].val).floating;
													(yyval.val).floating=log(aa);
													
												}
												
											;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1288 "mn.y"
    {   
	
												if((yyvsp[(3) - (4)].val).type == 3) 
												{
													fprintf(yyout,"Invalid sin operation\n");
					
													(yyval.val).type = 2;
									
												}
												else
												{
													strcpy((yyval.val).name, "sin operation expression");
													(yyval.val).type = 2;
													double aa;
													if((yyvsp[(3) - (4)].val).type == 1) aa= (yyvsp[(3) - (4)].val).integer;
													else if((yyvsp[(3) - (4)].val).type == 2) aa = (yyvsp[(3) - (4)].val).floating;
													(yyval.val).floating=sin(aa);
													
												}
												
											;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1311 "mn.y"
    {   
	
												if((yyvsp[(3) - (4)].val).type == 3) 
												{
													fprintf(yyout,"Invalid cos operation\n");
					
													(yyval.val).type = 2;
									
												}
												else
												{
													strcpy((yyval.val).name, "cos operation expression");
													(yyval.val).type = 2;
													double aa;
													if((yyvsp[(3) - (4)].val).type == 1) aa= (yyvsp[(3) - (4)].val).integer;
													else if((yyvsp[(3) - (4)].val).type == 2) aa = (yyvsp[(3) - (4)].val).floating;
													(yyval.val).floating=cos(aa);
													
												}
												
											;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1334 "mn.y"
    {   
	
												if((yyvsp[(3) - (4)].val).type == 3) 
												{
													fprintf(yyout,"Invalid tan operation\n");
					
													(yyval.val).type = 2;
									
												}
												else
												{
													strcpy((yyval.val).name, "tan operation expression");
													(yyval.val).type = 2;
													double aa;
													if((yyvsp[(3) - (4)].val).type == 1) aa= (yyvsp[(3) - (4)].val).integer;
													else if((yyvsp[(3) - (4)].val).type == 2) aa = (yyvsp[(3) - (4)].val).floating;
													(yyval.val).floating=tan(aa);
													
												}
												
											;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1357 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													(yyval.val).type = 4;
													strcpy((yyval.val).name, "Greater than expression");
													if(t1 == 1)
													{
														if((yyvsp[(1) - (3)].val).integer > (yyvsp[(3) - (3)].val).integer) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													if(t1==2)
													{
														if((yyvsp[(1) - (3)].val).floating > (yyvsp[(3) - (3)].val).floating) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp((yyvsp[(1) - (3)].val).str,(yyvsp[(3) - (3)].val).str) > 0) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
												}
											;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1388 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													(yyval.val).type = 4;
													strcpy((yyval.val).name, "Less than expression");
													if(t1 == 1)
													{
														if((yyvsp[(1) - (3)].val).integer < (yyvsp[(3) - (3)].val).integer) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													if(t1==2)
													{
														if((yyvsp[(1) - (3)].val).floating < (yyvsp[(3) - (3)].val).floating) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp((yyvsp[(1) - (3)].val).str,(yyvsp[(3) - (3)].val).str) < 0) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
												}
											;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1417 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													(yyval.val).type = 4;
													strcpy((yyval.val).name, "Greater equals than expression");
													if(t1 == 1)
													{
														if((yyvsp[(1) - (3)].val).integer >= (yyvsp[(3) - (3)].val).integer) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													if(t1==2)
													{
														if((yyvsp[(1) - (3)].val).floating >= (yyvsp[(3) - (3)].val).floating) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp((yyvsp[(1) - (3)].val).str,(yyvsp[(3) - (3)].val).str) >= 0) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
												}
											;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1445 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													(yyval.val).type = 4;
													strcpy((yyval.val).name, "Less equals than expression");
													if(t1 == 1)
													{
														if((yyvsp[(1) - (3)].val).integer <= (yyvsp[(3) - (3)].val).integer) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													if(t1==2)
													{
														if((yyvsp[(1) - (3)].val).floating <= (yyvsp[(3) - (3)].val).floating) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp((yyvsp[(1) - (3)].val).str,(yyvsp[(3) - (3)].val).str) <= 0) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
												}
											;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1475 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													(yyval.val).type = 4;
													strcpy((yyval.val).name, "Equals expression");
													if(t1 == 1)
													{
														if((yyvsp[(1) - (3)].val).integer == (yyvsp[(3) - (3)].val).integer) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													if(t1==2)
													{
														if((yyvsp[(1) - (3)].val).floating == (yyvsp[(3) - (3)].val).floating) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp((yyvsp[(1) - (3)].val).str,(yyvsp[(3) - (3)].val).str) == 0) (yyval.val).integer = 1;
														else (yyval.val).integer = 0;
													}
												}
											;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1503 "mn.y"
    {
												int t1 = (yyvsp[(1) - (3)].val).type, t2 = (yyvsp[(3) - (3)].val).type;
												if(t1 == 1 && t2 == 1)
												{
													(yyval.val).type = 1;
													strcpy((yyval.val).name, "MOD operation");
													(yyval.val).integer = (yyvsp[(1) - (3)].val).integer % (yyvsp[(3) - (3)].val).integer;
												}
												else
												{
													fprintf(yyout,"Invalid mod operation\n");
												}
											;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1520 "mn.y"
    {
														(yyval.val).type = 1;
													    strcpy((yyval.val).name, "GCD operation");
														int t1 = (yyvsp[(3) - (6)].val).type, t2 = (yyvsp[(5) - (6)].val).type;
														if(t1 == 1 && t2 == 1)
														{
															(yyval.val).integer = gcd((yyvsp[(3) - (6)].val).integer, (yyvsp[(5) - (6)].val).integer);
														}
													;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1530 "mn.y"
    {
														(yyval.val).type = 1;
													    strcpy((yyval.val).name, "LCM operation");
														int t1 = (yyvsp[(3) - (6)].val).type, t2 = (yyvsp[(5) - (6)].val).type;
														if(t1 == 1 && t2 == 1)
														{
															int x = gcd((yyvsp[(3) - (6)].val).integer, (yyvsp[(5) - (6)].val).integer);
															int y = (yyvsp[(3) - (6)].val).integer*(yyvsp[(5) - (6)].val).integer;
															(yyval.val).integer = y/x;
														}
													;}
    break;



/* Line 1455 of yacc.c  */
#line 3415 "mn.tab.c"
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
#line 1548 "mn.y"



void  yyerror(char *s){
	fprintf(yyout, "%s\n", s);
}

int yywrap()
{
	return 1;
}

int main()
{
	yyin = fopen("INPUT.txt","r");
	yyout = fopen("OUTPUT.txt","w");
	yyparse();
    
	return 0;
}
