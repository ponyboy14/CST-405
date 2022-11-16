%option noyywrap

%{
#include <stdio.h>
#include <string.h>

#define YY_DECL int yylex()
#include "parser.tab.h"

int words = 0;
int chars = 0;
int lines = 0;

%}

NEWLINE [\n\r]
DELIM   [ \t]
WS      {DELIM}+
LETTER  [_a-zA-Z]
DIGIT   [0-9]
ID      {LETTER}({LETTER}|{DIGIT})*
NUMBER  {DIGIT}+
FLOAT [0-9]+["."][0-9]+
CHAR '([^\'']|\.)'
%%
"/*"    				{
							int c;
							while((c = input()) != 0) {
								if(c == '*') {
									if((c = input()) == '/')
										break;
									else
										unput(c);
								}
							}
						}
						
"int"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}
"float"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}
"char"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}
"void"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"write"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return WRITE;
		}
"if"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return IF;
		}
"else"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return ELSE;
		}
"bool"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return WRITE;
		}
"read"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return READ;
		}
"return"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return RETURN;
		}
"writeln"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return WRITELN;
		}
"false"	{words++; chars += strlen(yytext);
			printf("%s : BOOL_VAL\n", yytext);
			yylval.string = strdup(yytext); 
			return FALSE;
		}
"true"	{words++; chars += strlen(yytext);
			printf("%s : BOOL_VAL\n", yytext);
			yylval.string = strdup(yytext); 
			return TRUE;
		}



{ID}	{words++; chars += strlen(yytext);
			  printf("%s : IDENTIFIER\n",yytext);
			  yylval.string = strdup(yytext); 
			  return ID;
			}
			
{NUMBER}		{words++; chars += strlen(yytext);
			  printf("%s : NUMBER\n",yytext);
			  yylval.number = atoi(strdup(yytext)); 
			  return NUMBER;
			}

{CHAR}		{words++; chars += strlen(yytext);
			  printf("%s : CHAR\n",yytext);
			  yylval.string = strdup(yytext); 
			  return CHAR;
			}

{FLOAT}		{words++; chars += strlen(yytext);
			  printf("%s : FLOAT\n",yytext);
			  yylval.string = strdup(yytext); 
			  return FLOAT;
			}
			
";"		{chars++;
		  printf("%s : SEMICOLON\n", yytext);
		  yylval.string = strdup(yytext); 
		  return SEMICOLON;
		}
"'"		{chars++;
		  printf("%s : QUOTE\n", yytext);
		  yylval.string = strdup(yytext); 
		  return QUOTE;
		}
"=="		{chars++;
		  printf("%s : EQ_COND\n", yytext);
		  yylval.string = strdup(yytext); 
		  return EQ_COND;
		}
">"		{chars++;
		  printf("%s : GREATER\n", yytext);
		  yylval.string = strdup(yytext); 
		  return GREATER;
		}
"<"		{chars++;
		  printf("%s : LESS\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LESS;
		}
">="		{chars++;
		  printf("%s : GREATER_EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return GREATER_EQ;
		}
"<="		{chars++;
		  printf("%s : LESS_EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LESS_EQ;
		}
"!"		{chars++;
		  printf("%s : NOT\n", yytext);
		  yylval.string = strdup(yytext); 
		  return NOT;
		}
","		{chars++;
		  printf("%s : COMMA\n", yytext);
		  yylval.string = strdup(yytext); 
		  return COMMA;
		}
"."		{chars++;
		  printf("%s : DOT\n", yytext);
		  yylval.string = strdup(yytext); 
		  return DOT;
		}
		
"="		{chars++;
		  printf("%s : EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return EQ;
		}
"+"		{chars++;
		  printf("%s : PLUS_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return PLUS_OP;
		}
"-"		{chars++;
		  printf("%s : SUB_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return SUB_OP;
		}
"*"		{chars++;
		  printf("%s : MULT_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return MULT_OP;
		}
"/"		{chars++;
		  printf("%s : DIV_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return DIV_OP;
		}
"^"		{chars++;
		  printf("%s : CAR_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return CAR_OP;
		}
"{"		{chars++;
		  printf("%s : START_CURLY\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LeftCurly;
		}
"}"		{chars++;
		  printf("%s : END_CURLY\n", yytext);
		  yylval.string = strdup(yytext); 
		  return RightCurly;
		}
"["		{chars++;
		  printf("%s : START_BRAC\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LeftBracket;
		}
"]"		{chars++;
		  printf("%s : END_BRAC\n", yytext);
		  yylval.string = strdup(yytext); 
		  return RightBracket;
		}
"if"	{chars++;
		  printf("%s : IF\n", yytext);
		  yylval.string = strdup(yytext); 
		  return IF;
"("		{chars++;
		  printf("%s : START_PARENTHESES\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LeftPar;
		}
")"		{chars++;
		  printf("%s : END_PARENTHESES\n", yytext);
		  yylval.string = strdup(yytext); 
		  return RightPar;
		}
		
[\n]	{lines++; chars=0;}
[ \t]	{chars++;}
.		{chars++;
         printf("%s : Unrecognized symbol at line %d char %d\n", yytext,lines,chars);
		}
		

%%
