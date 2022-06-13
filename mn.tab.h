
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 92 "mn.y"

    struct data_type{
	    
		int integer;
		double floating;
		char name[1000];
        int hash_value;
		char str[1000];
		int type;
	};



/* Line 1676 of yacc.c  */
#line 54 "mn.tab.h"

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

/* Line 1676 of yacc.c  */
#line 105 "mn.y"

	struct data_type val;



/* Line 1676 of yacc.c  */
#line 130 "mn.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


