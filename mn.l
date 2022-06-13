%{
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<math.h>
	#include<string.h>
	#include "mn.tab.h"
%}

/*Definitions*/

Identifier [#-&][a-zA-Z][0-9A-Za-z]*

Int			"int"

Double		"double"

String		"string"

Digit		[0-9]+



String_value	[a-zA-Z0-9@$%^&*(){}_+-,.:\|?><]

Float	[0-9]*"."[0-9]+

Ops "++" | "--" | "**" | "//"


%%

"[" 		   {return PS;  }

"]"  		   {return PE;	}

"("				{ return FBO; }

")"				{ return FBC; }

"Start"	       {return MAIN; }

"."				{return STOP;}

":"				{return COLON;}

"-"				{return DASH;}

","				{ return COMMA; }

"<"				{ return BAAM; }

">"				{ return DAAN; }

"=="			{ return EQUALS; }

"+"              { return PLUS; }

"/"              { return DIV; }

"*"              { return MUL; }

"^^"              { return POW; }

"%%"			  { return MOD; }

"log"              { return LOG; }

"sin"              { return SIN; }

"cos"              { return COS; }

"tan"              { return TAN; }

">>"              { return GTR; }

"<<"              { return LESS; }

">="              { return GEQ; }

"<="              { return LEQ; }

"="              { return EQS; }

"lcm"			{ return LCM;  }

"gcd"              { return GCD; }

"print"			{ return PRINT; }

"input"			{ return INPUT; }

"take"			{ return TAKE; }

"for"			{ return FOR; }

"while"			{ return WHILE; }

"---"			{ return DCRM; }

"do"			{
					return DO;
				}
   
"array"			{   
					
					return ARR; 
				}

"if"			{ return IF; }

"else"			{ return ELSE; }

"switch"		{ return SWITCH; }

"case"			{ return CASE; }

"default" 		{ return DEFT; }

"class"			{ return CLASS; }



{Digit}+		{
					yylval.val.integer = atoi(yytext);
					yylval.val.type=1;
					return INTEGER_VALUE;
				}
				
				

{Float}			{
					yylval.val.floating = atof(yytext);
					yylval.val.type=2;
					return FLOATING_VALUE;
				}
				

"'"{String_value}*"'"  		{
								yylval.val.type=3;
								char str[10000];
								int len = strlen(yytext);
								int idx=0;
								for(int i=1;i<len-1;i++) str[idx++] = yytext[i];
								str[idx]='\0';
								strcpy(yylval.val.str, str);
								return STRING_VALUE;
							}
				

"Declaring"     { return DECLARE; }



{Int}           {
					yylval.val.type=1;
					return INT;

				} 

{Double}        {
					yylval.val.type=2;
					return DOUBLE;

				} 

{String}        {
					yylval.val.type=3;
					return STRING;

				} 				

{Identifier}  		{   
					
						
						strcpy(yylval.val.name,yytext);
					
						return VAR_NAME;
					}
				
"!!"[a-zA-Z0-9@$%^&*(){}_+-,.:\|?>< ]*					{ fprintf(yyout, "This is single line comment\n"); }

[!][a-zA-Z0-9@$*(){}_+-,.:\|?><\n\t ]*[!]				{ fprintf(yyout, "This is multiple line comment\n"); } 
				

[ ]*	    			{}
[\n]*					{}
[\t]*					{}
.						{printf("Syntax Error: %s\n",yytext);}

%%
