%{
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

%}


%code requires {
    struct data_type{
	    
		int integer;
		double floating;
		char name[1000];
        int hash_value;
		char str[1000];
		int type;
	};
}


%union{
	struct data_type val;
}




/* bison declarations */

/*Terminals*/

%token<val> VAR_NAME
%token<val> INT
%token<val> DOUBLE
%token<val> STRING
%token<val> INTEGER_VALUE
%token<val> FLOATING_VALUE
%token<val> STRING_VALUE
%token<val> ARR
%token<val> PRINT
%token<val> OPS

%token PS PE MAIN STOP COLON DASH COMMA DECLARE BAAM DAAN EQUALS FBO FBC PLUS DIV MUL POW LOG SIN COS TAN GTR LESS GEQ LEQ EQS LCM GCD MOD INPUT TAKE FOR WHILE DCRM DO IF ELSE SWITCH CASE DEFT CLASS


/*Non Terminals*/

%type<val> types
%type<val> expression
%type<val> assigns
%type<val> assign
%type<val> statement
%type<val> loops
%type<val> elses
%type<val> condition


%left GTR LESS GEQ LEQ EQS
%left PLUS DASH
%left MUL DIV
%left MOD
%left POW



/* Grammar rules  */

%%

program:
	| program MAIN COLON DASH PS cline PE {fprintf(yyout,"Compilation Successful\n");}
	| class 
	;

cline:
    |cline statement
    ;



/*Class*/

class:
	
	CLASS VAR_NAME PS VAR_NAME BAAM types DAAN COMMA VAR_NAME BAAM types DAAN STOP PE STOP {
	
				int hv = hashVal($2.name);
				if(whatType[hv] != 0)
				{
					printf("Variable named %s already declared\n", $2.name);
					fprintf(yyout, "Variable named %s already declared\n", $2.name);
				}
				else whatType[hv] = 8;

			
		}
	
	;
	

/*Class*/


statement: 
	  declaration STOP 						{fprintf(yyout,"Valid declaration statement\n");}
	  
	
	
	| assigns STOP
	
	| PRINT FBO expression FBC STOP			{
												fprintf(yyout,"Inside print operation\n");
												
												fprintf(yyout,"The value of  %s is: ", $3.name);
												
												printf("The value of  %s is: ", $3.name);
												
												int hv = $3.hash_value;
												
												int tp = $3.type;
												
												if(tp == 1)
												{
													fprintf(yyout,"%d\n", $3.integer);
													printf("%d\n", $3.integer);
													$$.integer = $3.integer;
												}
												
												else if(tp == 2)
												{
													fprintf(yyout,"%0.5lf\n", $3.floating);
													printf("%0.5lf\n", $3.floating);
													$1.floating = $3.floating;
													$$.floating = $3.floating;
												}
												
												else if(tp == 3)
												{
													fprintf(yyout,"%s\n", $3.str);
													printf("%s\n", $3.str);
													strcpy($$.str, $3.str);
												}
												else if(tp == 4)
												{
													if($3.integer == 1)
													{
														fprintf(yyout,"True\n");
														printf("True\n");
														strcpy($$.str, "True");
													}
													else if($3.integer == 0) 
													{
														fprintf(yyout,"False\n");
														printf("False\n");
														strcpy($$.str, "False");
													}
												}
											}



    | TAKE VAR_NAME EQUALS INPUT FBO  FBC STOP		   {
															int hv = hashVal($2.name);
															fprintf(yyout,"Inside input operation\n");
															if(whatType[hv] == 0)
															{
																fprintf(yyout,"Variable %s not declared\n", $2.name);
																
															}
															else
															{   
																
																int t1 = whatType[hv];
																
																
																printf("Enter input for variable %s\n", $2.name);
																
																fprintf(yyout,"Input taken for variable %s is: ", $2.name);
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
														} 
	
	
	
	| TAKE ARR VAR_NAME PS expression PE EQUALS INPUT FBO FBC STOP		{
																				int hv = hashVal($3.name);
																				if(whatType[hv] == 0)
																				{
																					printf("Variable not declared\n");
																				}
																				else
																				{   
																					
																					int t1 = whatType[hv];
																					//printf("TT %d\n",t1);
																					printf("Input value for array %s at index %d: ", $3.name, $5.integer);
																					if(t1==1)
																					{
																						int x;
																						scanf("%d", &x);
																						valInt[hv][$5.integer] = x;
																						fprintf(yyout, "Value assigned to array %s at index %d is: ", $3.name, $5.integer);
																						fprintf(yyout,"%d\n", valInt[hv][$5.integer]);
																					
																					}
																					else if(t1==2)
																					{
																						double x;
																						scanf("%lf", &x);
																						valDoub[hv][$5.integer] = x;
																						fprintf(yyout,"Value assigned to array %s at index %d is: ", $3.name, $5.integer);
																						fprintf(yyout,"%0.5lf\n", valDoub[hv][$5.integer]);
																					
																					}
																				}
																			}
	
	| loops
	
	| condition { Cond++; }
	
	| switchase { Cond++; }
	
	;
	

	
/* Loop */



loops: FOR FBO expression COMMA expression COMMA expression FBC PS TAKE ARR VAR_NAME PS expression PE EQUALS INPUT FBO FBC STOP PE {
					
					int hv = hashVal($12.name);
					int t1 = whatType[hv];
					if(t1 == 0)
					{
						printf("Variable not declared\n");
					}
					else
					{
						char st[1000];
						strcpy(st, $12.name);
						
						int i = $3.integer, sz = $5.integer, inc = $7.integer;
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
					
		}
	
	
	

	| FOR FBO expression COMMA expression COMMA expression FBC PS PRINT FBO VAR_NAME PS expression PE FBC STOP PE{
	
				
				
				int hv = hashVal($12.name);
				int t1 = whatType[hv];
				if(t1 == 0)
				{
					printf("Variable not declared\n");
				}
				
				else
				{
					char st[1000];
					strcpy(st, $12.name);
						
					int i = $3.integer, sz = $5.integer, inc = $7.integer;
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
			}
	
	
	| WHILE FBO expression DCRM FBC PS VAR_NAME EQUALS INPUT FBO FBC STOP VAR_NAME EQUALS INPUT FBO FBC STOP PRINT FBO expression PLUS expression FBC STOP PE{
	
					int i = $3.integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal($7.name), hv2 = hashVal($13.name);
						int aa, bb;
						printf("Enter the value of variable %s: ", $7.name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", $13.name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb+=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			}
	| WHILE FBO expression DCRM FBC PS VAR_NAME EQUALS INPUT FBO FBC STOP VAR_NAME EQUALS INPUT FBO FBC STOP PRINT FBO expression DASH expression FBC STOP PE{
	
					int i = $3.integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal($7.name), hv2 = hashVal($13.name);
						int aa, bb;
						printf("Enter the value of variable %s: ", $7.name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", $13.name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb-=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			}
			
	| WHILE FBO expression DCRM FBC PS VAR_NAME EQUALS INPUT FBO FBC STOP VAR_NAME EQUALS INPUT FBO FBC STOP PRINT FBO expression MUL expression FBC STOP PE{
	
					int i = $3.integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal($7.name), hv2 = hashVal($13.name);
						int aa, bb;
						printf("Enter the value of variable %s: ", $7.name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", $13.name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb*=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			}		
	| WHILE FBO expression DCRM FBC PS VAR_NAME EQUALS INPUT FBO FBC STOP VAR_NAME EQUALS INPUT FBO FBC STOP PRINT FBO expression DIV expression FBC STOP PE{
	
					int i = $3.integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal($7.name), hv2 = hashVal($13.name);
						int aa, bb;
						printf("Enter the value of variable %s: ", $7.name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", $13.name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb/=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			}
	| WHILE FBO expression DCRM FBC PS VAR_NAME EQUALS INPUT FBO FBC STOP VAR_NAME EQUALS INPUT FBO FBC STOP PRINT FBO expression MOD expression FBC STOP PE{
	
					int i = $3.integer;
					fprintf(yyout,"Inside while\n");
					while(i--)
					{
						int hv1 = hashVal($7.name), hv2 = hashVal($13.name);
						int aa, bb;
						printf("Enter the value of variable %s: ", $7.name);
						scanf("%d", &aa);
						valInt[hv1][0] = aa;
						bb=aa;
						printf("Enter the value of variable %s: ", $13.name);
						scanf("%d", &aa);
						valInt[hv2][0] = aa;
						bb%=aa;
						printf("The value of the expression is: %d\n", bb);
						fprintf(yyout,"The value of the expression is: %d\n", bb);
					}
					fprintf(yyout,"While execution end\n");
	
	
			}
			
	|DO PS expression EQUALS INPUT FBO FBC STOP PRINT FBO expression FBC STOP PE WHILE FBO expression DCRM FBC STOP{
	
					int i = $17.integer+1;
					fprintf(yyout,"Do-While execution start\n");
					while(i--)
					{
						
						int hv = hashVal($3.name);
						printf("Enter the input for variable %s: ", $3.name);
						scanf("%d", &valInt[hv][0]);
						printf("The value of the expression is %d\n", valInt[hv][0]);
						fprintf(yyout,"The value of the expression is %d\n", valInt[hv][0]);
					}
		}
	
	
	|	FOR FBO expression COMMA expression COMMA expression FBC PS PRINT FBO expression FBC STOP PE {
			
			int i = $3.integer, sz = $5.integer, inc = $7.integer;
			for( ; i< sz; i++)
			{	
				printf("Value of the expression inside for loop: ");
				fprintf(yyout, "Value of the expression inside for loop: ");
				int t1 = $12.type;
				if(t1 == 1) 
				{
					printf("%d\n", $12.integer);
					fprintf(yyout, "%d\n", $12.integer);
				}
				else if(t1 == 2)
				{
					fprintf(yyout,"%.5lf\n", $12.floating);
					printf("%.5lf\n", $12.floating);
				}
				else if(t1 == 3)
				{
					printf("%s\n", $12.str);
					fprintf(yyout,"%s\n", $12.str);
				}
			}
			
	}
	
	
	;


/* Loop */



/* Conditional Part */


	
	
condition: IF FBO expression FBC PS PRINT FBO expression FBC STOP PE{
			
				if($3.integer == 1) {
					fprintf(yyout,"Inside if block\n");
					fprintf(yyout, "%s\n", $8.str);
					printf("%s\n", $8.str);
					ara[Cond] = 1;
				}
			
		} elses { int qt=1; }

	;
	
elses: {int qt=1}
	| ELSE IF FBO expression FBC PS PRINT FBO expression FBC STOP PE{
	
			
			if($4.integer == 1 && ara[Cond] == 0) {
					fprintf(yyout,"Inside else if block\n");
					fprintf(yyout, "%s\n", $9.str);
					printf("%s\n", $9.str);
					ara[Cond] = 1;
				}
		} elses {int qw;}
	| ELSE PS PRINT FBO expression FBC STOP PE {
			
			if(ara[Cond] == 0)
			{	
				fprintf(yyout,"Inside else block\n");
				printf("%s\n", $5.str);
				fprintf(yyout,"%s\n", $5.str);
			}
			
		}
	;
	







/* Conditional Part */



/* Switch Case Part */



switchase: SWITCH  FBO expression FBC COLON PRINT FBO expression FBC STOP{

		
			int x = $3.integer;
			if(x == 1)
			{
				ara[Cond] = 1;
				
				fprintf(yyout,"Inside switch block\n");
				printf("%s\n", $8.str);
				fprintf(yyout, "%s\n", $8.str);
				
			} 
		
		} cases {int pq;}
	;
	
cases:

	|CASE FBO expression FBC COLON PRINT FBO expression FBC STOP{

		
			int x = $3.integer;
			if(x == 1 && ara[Cond] == 0)
			{
				ara[Cond] = 1;
				
				fprintf(yyout,"Inside case block\n");
				printf("%s\n", $8.str);
				fprintf(yyout, "%s\n", $8.str);
				
			} 
		
		} cases {int a;}
		
	| DEFT COLON PRINT FBO expression FBC STOP{

		
			
			if(ara[Cond] == 0)
			{
				ara[Cond] = 1;
				
				fprintf(yyout,"Inside case block\n");
				printf("%s\n", $5.str);
				fprintf(yyout, "%s\n", $5.str);
				
			} 
		
		} 
		
	;


	
	



/* Switch Case Part */

	
	
/* Declaraion Part */
	
	
declaration:DECLARE variables	    {	
									fprintf(yyout,"All Declaraions Successful\n");
								}  
								
	| CLASS BAAM VAR_NAME DAAN VAR_NAME FBO expression COMMA expression FBC {
	
				int hv = hashVal($3.name);
				if(whatType[hv] != 8)
				{
					printf("No class named %s\n", $3.name);
					fprintf(yyout, "No class named %s\n", $3.name);
				}
				else
				{
					int a = $7.integer; double b = $9.floating;
					int hv2 = hashVal($5.name);
					int chk = Check_var($5.name);
					if(!chk)
					{
						printf("Variable %s already exists\n", $5.name);
						fprintf(yyout, "Variable %s already exists\n", $5.name);
					}
					else
					{
						strcpy(isVar[available_index++],$5.name);
						whatType[hv2] = 8;
						valInt[hv2][0] = a;
						valDoub[hv2][0] = b;
						printf("Values assigned to class %s variable %s are %d and %.5lf\n",$3.name, $5.name,valInt[hv2][0], valDoub[hv2][0] );
						fprintf(yyout,"Values assigned to class %s variable %s are %d and %.5lf\n",$3.name, $5.name,valInt[hv2][0], valDoub[hv2][0] );
					}
				}
	
		}
	
    ;

variables: variables COMMA variable
	| variable
	;
	
	
variable: VAR_NAME BAAM types DAAN	{
										fprintf(yyout,"lower most declaration stage\n");
										fprintf(yyout,"Declaraion without assignment\n");
										int check = Check_var($1.name);
										if(check)
										{
											strcpy(isVar[available_index++],$1.name);
											fprintf(yyout,"newly declared variable: %s\n", $1.name);
											$1.type = $3.type;
											int hv = hashVal($1.name);
											fprintf(yyout,"Hash value of newly declared variable %s is %d\n", $1.name, hv);
											whatType[hv]=$1.type;
											fprintf(yyout,"The type of the variable is %d\n", whatType[hv]);
											
										}
										else
										{
											fprintf(yyout,"variable %s already declared\n", $1.name);
										}
									}	
	
	| VAR_NAME BAAM types DAAN EQUALS expression		{   
	
															fprintf(yyout,"lower most declaration stage\n");
															fprintf(yyout,"Declaraion with assignment\n");
															int check = Check_var($1.name);
															if(check)
															{
																fprintf(yyout,"Inside assignment operation when declared\n");
																$1.type = $3.type;
																fprintf(yyout,"type of newly declared variable: %s is %d\n", $1.name, $1.type);
																fprintf(yyout,"type of constant is %d\n", $6.type);
																fprintf(yyout,"value of constant is: ");
																if($6.type==1) fprintf(yyout,"%d\n", $6.integer);
																else if($6.type==2) fprintf(yyout,"%0.5lf\n", $6.floating);
																else if($6.type==3) fprintf(yyout,"%s\n", $6.str);
																if($1.type != $6.type)
																{
																	fprintf(yyout,"Invalid type!\n");
																}
																else
																{   
																	strcpy(isVar[available_index++],$1.name);
																	fprintf(yyout,"newly declared variable: %s\n", $1.name);
																	$1.type = $3.type;
																	int hv = hashVal($1.name);
																	fprintf(yyout,"Hash value of newly declared variable %s is %d\n", $1.name, hv);
																	whatType[hv]=$1.type;
																	if($1.type == 1)
																	{
																		valInt[hv][0] = $6.integer;
					
																	}
																	else if($1.type == 2)
																	{
																		valDoub[hv][0] = $6.floating;
																	}
																	else if($1.type == 3)
																	{
																		strcpy(valStr[hv], $6.str);
																	}
																	fprintf(yyout,"Assignment successfull\n");
																	fprintf(yyout,"Assigned value for variable %s: ", $1.name);
																	if($1.type == 1)
																	{
																		fprintf(yyout,"%d\n", valInt[hv][0]);
																	}
																    if($1.type == 2)
																	{
																		fprintf(yyout,"%0.5lf\n", valDoub[hv][0]);
																	}
																	else if($1.type == 3)
																	{
																		fprintf(yyout,"%s\n", valStr[hv]);
																	}
																
																}
															}
															else
															{
																fprintf(yyout,"Variable already declared\n");
															}
														}
	
	
	
	|ARR BAAM types DAAN VAR_NAME PS INTEGER_VALUE PE	{
															fprintf(yyout,"lower most declaration stage\n");
															fprintf(yyout,"Declaraion of array\n");
															int check = Check_var($5.name);
															if(check)
															{
																strcpy(isVar[available_index++],$5.name);
																fprintf(yyout,"newly declared array: %s\n", $5.name);
																$5.type = $3.type;
																int hv = hashVal($5.name);
																isArr[hv] = 1;
																fprintf(yyout,"Hash value of newly declared variable %s is %d\n", $5.name, hv);
																whatType[hv]=$3.type;
																fprintf(yyout,"The type of the variable is %d\n", whatType[hv]);
																
															}
															else
															{
																fprintf(yyout,"variable %s already declared\n", $5.name);
															}
														}
	
	

	
	;
/* Declaraion Part */


/* Assignment Part */


assigns: assigns COMMA assign
	| assign
	;

assign:  expression EQUALS expression			{
													fprintf(yyout,"Assignment without Declaraion\n");
													int hv = $1.hash_value;
													if(whatType[hv] == 0)
													{
														fprintf(yyout,"Variable not Declared yet! Assignment is not possible\n");
													}
													else
													{
														int t1 = whatType[hv];
														int t2 = $3.type;
														if(t1 != t2)
														{
															if(t1 == 2 && t2 == 1)
															{
																int hv = $1.hash_value;
																valDoub[hv][0] = $3.integer;
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
																valInt[hv][0] = $3.integer;
																fprintf(yyout,"Assigned value for variable %s is %d\n", $1.name, valInt[hv][0]);
															}
															else if(t1 == 2) 
															{
																valDoub[hv][0] = $3.floating;
																fprintf(yyout,"Assigned value for variable %s is %0.5lf\n", $1.name, valDoub[hv][0]);
															}
															else if(t1 == 3) 
															{
																strcpy(valStr[hv], $3.str);
																fprintf(yyout,"Assigned value for variable %s is %s\n", $1.name, valStr[hv]);
															}
														}
													}
												}
	| VAR_NAME PS expression PE EQUALS expression       		{	
																	fprintf(yyout,"Inside array assignment\n");
																	int hv = hashVal($1.name);
																	int index = $3.integer;
																	if(isArr[hv]==0)
																	{
																		fprintf(yyout,"Variable %s is not an array\n", $1.name);
																	}
																	else
																	{   
																	    fprintf(yyout,"Value assigned to array %s at index %d: ", $1.name, $3.integer);
																		int t1 = whatType[hv];
																		int t2 = $6.type;
																		if(t1!=t2)
																		{
																			if(t1 == 2 && t2==1)
																			{
																				valDoub[hv][index]=$6.integer;
																				fprintf(yyout,"%0.5lf\n", valDoub[hv][index]);
																			}
																			else fprintf(yyout,"Invalid assignment\n");

																		}
																		else
																		{
																			if(t1==1)
																			{
																				valInt[hv][index] = $6.integer;
																				fprintf(yyout,"%d\n", valDoub[hv][index]);
																			}
																			else if(t2==2)
																			{
																				valDoub[hv][index]=$6.floating;
																				fprintf(yyout,"%0.5lf\n", valDoub[hv][index]);
																			}
																		}
																		
																	}
																}											
	;



 /* Assignment Part */	


	
types:INT			{ $$.type = $1.type; }
	| DOUBLE		{ $$.type = $1.type; }
	| STRING		{ $$.type = $1.type; }
	;


	
/* Expressions */	

expression: INTEGER_VALUE		{
									
									$$.type = $1.type;
									$$.integer = $1.integer
	
								}
							
	| FLOATING_VALUE			{
									$$.type = $1.type;
									$$.floating = $1.floating;
								}

	| STRING_VALUE				{
									$$.type = $1.type;
									strcpy($$.str, $1.str);
									//fprintf(yyout,"eije: %s\n",$$.str);
	
							
								}
							
	|	VAR_NAME			{
								int hv = hashVal($1.name);
								if(whatType[hv]==0)
								{
									fprintf(yyout,"Variable not declared!\n");
								}
								else
								{
									int t1 = whatType[hv];
									$$.hash_value= hv;
									strcpy($$.name, $1.name);
									$$.type = t1;
									if(t1 == 1)
									{
										$$.integer = valInt[hv][0];
									}
									else if(t1 == 2)
									{
										$$.floating = valDoub[hv][0];
									}
									else if(t1 == 3)
									{
										strcpy($$.str, valStr[hv]);
									}
									
								}
							}
	
	| ARR VAR_NAME PS INTEGER_VALUE PE		{
												int hv = hashVal($2.name);
												if(whatType[hv] == 0)
												{
													fprintf(yyout,"Array %s not declared yet\n", $2.name);
												}
												else
												{
													$$.type = whatType[hv];
													strcpy($$.name, $2.name);
													int t1 = $$.type;
													int idx = $4.integer;
													if(t1 == 1)
													{
														$$.integer = valInt[hv][idx];
														
													}
													else if(t1 == 2)
													{
														$$.floating = valDoub[hv][idx];
													}
												}
											}
	
	
	| expression PLUS expression			{
												int t1 = $1.type, t2 = $3.type;
												strcpy($$.name, "addition expression");
												if(t1 != t2)
												{
													if(t1 == 3 || t2 == 3)
													{
														fprintf(yyout,"This operation is not possible\n");
													}
													
													else
													{
														$$.type = 2;
														double a, b;
														if(t1 == 2) a = $1.floating;
														else if(t1==1) a = $1.integer;
														if(t2 == 1) b = $3.integer;
														else if(t2 == 2) b = $3.floating;
														$$.floating = a+b;
													}
												}
												
												else
												{
													if(t1 == 1)
													{
														$$.type = 1;
														int a, b;
														a = $1.integer, b = $3.integer;
														$$.integer = a+b;
													}
													
													else if(t1 ==2)
													{
														$$.type = 2;
														double a, b;
														a = $1.floating, b = $3.floating;
														$$.floating = a+b;
													}
													
													else if(t1 == 3)
													{
														$$.type = 3;
														char a[1000], b[1000];
														strcpy(a, $1.str);
														strcat(a, $3.str);
														strcpy($$.str, a);
													}
												}
												
											} 
	

    | expression DASH expression			{
												int t1 = $1.type, t2 = $3.type;
												strcpy($$.name, "subtraction expression");
												if(t1 != t2)
												{
													if(t1 == 3 || t2 == 3)
													{
														fprintf(yyout,"This operation is not possible\n");
													}
													
													else
													{
														$$.type = 2;
														double a, b;
														if(t1 == 2) a = $1.floating;
														else if(t1==1) a = $1.integer;
														if(t2 == 1) b = $3.integer;
														else if(t2 == 2) b = $3.floating;
														$$.floating = a-b;
													}
												}
												
												else
												{
													if(t1 == 1)
													{
														$$.type = 1;
														int a, b;
														a = $1.integer, b = $3.integer;
														$$.integer = a-b;
													}
													
													else if(t1 ==2)
													{
														$$.type = 2;
														double a, b;
														a = $1.floating, b = $3.floating;
														$$.floating = a-b;
													}
													
												}
												
											}	

    
	
	| expression MUL expression			{
												int t1 = $1.type, t2 = $3.type;
												strcpy($$.name, "multiplication expression");
												if(t1 != t2)
												{
													if(t1 == 3 || t2 == 3)
													{
														fprintf(yyout,"This operation is not possible\n");
													}
													
													else
													{
														$$.type = 2;
														double a, b;
														if(t1 == 2) a = $1.floating;
														else if(t1==1) a = $1.integer;
														if(t2 == 1) b = $3.integer;
														else if(t2 == 2) b = $3.floating;
														$$.floating = (double)(a*b);
													}
												}
												
												else
												{
													if(t1 == 1)
													{
														$$.type = 1;
														int a, b;
														a = $1.integer, b = $3.integer;
														$$.integer = a*b;
													}
													
													else if(t1 ==2)
													{
														$$.type = 2;
														double a, b;
														a = $1.floating, b = $3.floating;
														$$.floating = a*b;
													}
													
												}
												
											}
	
	
	| expression DIV expression			{
												int t1 = $1.type, t2 = $3.type;
												strcpy($$.name, "division expression");
												if(t1 != t2)
												{
													if(t1 == 3 || t2 == 3)
													{
														fprintf(yyout,"This operation is not possible\n");
													}
													
													else
													{
														$$.type = 2;
														double a, b;
														if(t1 == 2) a = $1.floating;
														else if(t1==1) a = $1.integer;
														if(t2 == 1) b = $3.integer;
														else if(t2 == 2) b = $3.floating;
														$$.floating = (double)(a/b);
													}
												}
												
												else
												{
													if(t1 == 1)
													{
														$$.type = 1;
														int a, b;
														a = $1.integer, b = $3.integer;
														$$.integer = a/b;
													}
													
													else if(t1 ==2)
													{
														$$.type = 2;
														double a, b;
														a = $1.floating, b = $3.floating;
														$$.floating = a/b;
													}
													
												}
												
											}
											
											
											
	| expression POW expression    			{
												int t1 = $1.type, t2 = $3.type;
												if(t1 == 3 || t2 != 1)
												{
													fprintf(yyout,"Invalid power operation\n");
												}
												else
												{    
												    strcpy($$.name, "power expression");
													if(t1 == 2) $$.type = 2;
													else if(t1==1) $$.type = 1;
													int p= $3.integer;
													//fprintf(yyout,"PVAL: %d\n", p);
													int a;
													double aa;
													if(t1 == 1) a= $1.integer;
													else if(t1 == 2) aa = $1.floating;
													double ret1 = 1.0;
													int ret2 = 1;
													for(int i=0;i<p;i++) 
													{
														if(t1 == 1) ret2*=a;
														else if(t1 == 2) ret1*=aa;
														
														
													}
													if(t1 == 1) $$.integer = ret2;
													else if(t1 == 2) $$.floating = ret1;
												}
												
											}


	| LOG FBO expression FBC				{   
	
												if($3.type == 3) 
												{
													fprintf(yyout,"Invalid log operation\n");
					
													$$.type = 2;
									
												}
												else
												{
													strcpy($$.name, "log operation expression");
													$$.type = 2;
													double aa;
													if($3.type == 1) aa= $3.integer;
													else if($3.type == 2) aa = $3.floating;
													$$.floating=log(aa);
													
												}
												
											}
    
	| SIN FBO expression FBC				{   
	
												if($3.type == 3) 
												{
													fprintf(yyout,"Invalid sin operation\n");
					
													$$.type = 2;
									
												}
												else
												{
													strcpy($$.name, "sin operation expression");
													$$.type = 2;
													double aa;
													if($3.type == 1) aa= $3.integer;
													else if($3.type == 2) aa = $3.floating;
													$$.floating=sin(aa);
													
												}
												
											}
	
	
	| COS FBO expression FBC				{   
	
												if($3.type == 3) 
												{
													fprintf(yyout,"Invalid cos operation\n");
					
													$$.type = 2;
									
												}
												else
												{
													strcpy($$.name, "cos operation expression");
													$$.type = 2;
													double aa;
													if($3.type == 1) aa= $3.integer;
													else if($3.type == 2) aa = $3.floating;
													$$.floating=cos(aa);
													
												}
												
											}
											
											
	| TAN FBO expression FBC				{   
	
												if($3.type == 3) 
												{
													fprintf(yyout,"Invalid tan operation\n");
					
													$$.type = 2;
									
												}
												else
												{
													strcpy($$.name, "tan operation expression");
													$$.type = 2;
													double aa;
													if($3.type == 1) aa= $3.integer;
													else if($3.type == 2) aa = $3.floating;
													$$.floating=tan(aa);
													
												}
												
											}										
	
	
	| expression GTR expression				{
												int t1 = $1.type, t2 = $3.type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													$$.type = 4;
													strcpy($$.name, "Greater than expression");
													if(t1 == 1)
													{
														if($1.integer > $3.integer) $$.integer = 1;
														else $$.integer = 0;
													}
													if(t1==2)
													{
														if($1.floating > $3.floating) $$.integer = 1;
														else $$.integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp($1.str,$3.str) > 0) $$.integer = 1;
														else $$.integer = 0;
													}
												}
											}
											
	

	
	| expression LESS expression				{
												int t1 = $1.type, t2 = $3.type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													$$.type = 4;
													strcpy($$.name, "Less than expression");
													if(t1 == 1)
													{
														if($1.integer < $3.integer) $$.integer = 1;
														else $$.integer = 0;
													}
													if(t1==2)
													{
														if($1.floating < $3.floating) $$.integer = 1;
														else $$.integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp($1.str,$3.str) < 0) $$.integer = 1;
														else $$.integer = 0;
													}
												}
											}
	
	
	| expression GEQ expression				{
												int t1 = $1.type, t2 = $3.type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													$$.type = 4;
													strcpy($$.name, "Greater equals than expression");
													if(t1 == 1)
													{
														if($1.integer >= $3.integer) $$.integer = 1;
														else $$.integer = 0;
													}
													if(t1==2)
													{
														if($1.floating >= $3.floating) $$.integer = 1;
														else $$.integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp($1.str,$3.str) >= 0) $$.integer = 1;
														else $$.integer = 0;
													}
												}
											}
	
	| expression LEQ expression				{
												int t1 = $1.type, t2 = $3.type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													$$.type = 4;
													strcpy($$.name, "Less equals than expression");
													if(t1 == 1)
													{
														if($1.integer <= $3.integer) $$.integer = 1;
														else $$.integer = 0;
													}
													if(t1==2)
													{
														if($1.floating <= $3.floating) $$.integer = 1;
														else $$.integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp($1.str,$3.str) <= 0) $$.integer = 1;
														else $$.integer = 0;
													}
												}
											}
											
											
											
	| expression EQS expression				{
												int t1 = $1.type, t2 = $3.type;
												if(t1 != t2)
												{
													fprintf(yyout,"Invalid! type must be same\n");
												}
												else
												{
													$$.type = 4;
													strcpy($$.name, "Equals expression");
													if(t1 == 1)
													{
														if($1.integer == $3.integer) $$.integer = 1;
														else $$.integer = 0;
													}
													if(t1==2)
													{
														if($1.floating == $3.floating) $$.integer = 1;
														else $$.integer = 0;
													}
													else if(t1 == 3)
													{
														if(strcmp($1.str,$3.str) == 0) $$.integer = 1;
														else $$.integer = 0;
													}
												}
											}										
	
	|expression MOD expression				{
												int t1 = $1.type, t2 = $3.type;
												if(t1 == 1 && t2 == 1)
												{
													$$.type = 1;
													strcpy($$.name, "MOD operation");
													$$.integer = $1.integer % $3.integer;
												}
												else
												{
													fprintf(yyout,"Invalid mod operation\n");
												}
											}
	
	
	
	
	| GCD FBO expression COMMA expression FBC		{
														$$.type = 1;
													    strcpy($$.name, "GCD operation");
														int t1 = $3.type, t2 = $5.type;
														if(t1 == 1 && t2 == 1)
														{
															$$.integer = gcd($3.integer, $5.integer);
														}
													}
	
	| LCM FBO expression COMMA expression FBC		{
														$$.type = 1;
													    strcpy($$.name, "LCM operation");
														int t1 = $3.type, t2 = $5.type;
														if(t1 == 1 && t2 == 1)
														{
															int x = gcd($3.integer, $5.integer);
															int y = $3.integer*$5.integer;
															$$.integer = y/x;
														}
													}
	
	
	;

/* Expressions */


%%


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