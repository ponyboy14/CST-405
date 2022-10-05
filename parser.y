%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
char currentScope[50]; // global or the name of the function
%}

%union {
	int number;
	char character;
	char* string;
	struct AST* ast;
}

%token <string> TYPE
%token <string> ID
%token <char> SEMICOLON
%token <char> EQ
%token <number> NUMBER
%token WRITE

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;

%type <ast> Program DeclList Decl VarDecl Stmt StmtList Expr

%start Program

%%

Program: DeclList  { $$ = $1;}
;

DeclList:	Decl DeclList	{ $1->left = $2;
							  $$ = $1;
							}
	| Decl	{ $$ = $1; }
;

Decl:	VarDecl
	| StmtList
;

VarDecl:	TYPE ID SEMICOLON	{ printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
									// Symbol Table
									symTabAccess();
									int inSymTab = found($2, currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == -1) 
										addItem($2, "Var", $1,0, currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								  //  code goes here...

								}
;

StmtList:	
	| Stmt StmtList
;

Stmt:	SEMICOLON	{}
	| Expr SEMICOLON	{$$ = $1;}
;

Expr:	ID { printf("\n RECOGNIZED RULE: Simplest expression\n"); }
	| ID EQ ID 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ----
					if found($1) == -1 
					  	printf("ID: %s is undeclared", $1);
					if found($3) == -1 
					  	printf("ID: %s is undeclared", $3);
					if found($3) != -1 && found($1) != -1 {
						if checkItemType(found($3), found($1)) 
							$$ = AST_assignment("=",$1, $3);
						else
							printf("ID: %s and ID: %s are not the same type.", $1, $3);
					}
				}
	| ID EQ NUMBER 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					   // ---- SEMANTIC ACTIONS by PARSER ----
					   char str[50];
					   sprintf(str, "%d", $3); 
					   	if found($1) == -1 
					  		printf("ID: %s is undeclared", $1);
						if found($3) != -1 && found($1) != -1 {
							if checkItemType(found($3), found($1)) 
								$$ = AST_assignment("=",$1, $3);
						else
							printf("ID: %s and ID: %s are not the same type.", $1, $3);
					}
					}
	| WRITE ID 	{ printf("\n RECOGNIZED RULE: WRITE statement\n");
					$$ = AST_Write("write",$2,"");
				}
;


%%

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
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}