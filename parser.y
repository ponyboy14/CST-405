%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"

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
int paramIdx = 0;
int parVal=0;
%}

%union {
	int number;
	char character;
	char* string;
	struct AST* ast;
}

%token <string> TYPE
%token <string> ID
%token <string> RETURN
%token <char> SEMICOLON
%token <char> EQ 
%token <char> OP
%token <char> LeftPar
%token <char> RightPar
%token <char> LeftCurly
%token <char> RightCurly
%token <char> LeftBracket
%token <char> RightBracket
%token <char> COMMA
%token <number> NUMBER
%token <string> WRITE

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;

%type <ast> Program DeclList Decl VarDecl Stmt StmtList Expr Function ParamDecl ParamDeclEnd Block CallParam CallParamEnd FuncCall
%type <string> ADDITION

%start Program

%%

Program: DeclList  { 
					$$ = $1;
					 printf("\n--- Abstract Syntax Tree ---\n\n");
					 printAST($$,0);

					}
;

DeclList:	Decl DeclList	{ $1->left = $2;
							  $$ = $1;
							}
	| Decl	{ $$ = $1; }
;

Decl:	VarDecl
	| Function
	| StmtList
;

VarDecl:	TYPE ID SEMICOLON	{ printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
									// Symbol Table
									symTabAccess();
									int inSymTab = found($2, currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) 
										addItem($2, "Var", $1,0, currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    $$ = AST_Type("Type",$1,$2);
									printf("-----------> %s\n", $$->LHS);
								}
			| TYPE ID LeftBracket NUMBER RightBracket SEMICOLON { printf("%d", (int) $4); 
												for (int i = 0; i < (int) $4; i++) {
													symTabAccess();
													int inSymTab = found($2, currentScope);
													//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
													
													if (inSymTab == 0) {
														char index[50];
														sprintf(index, "%s", $2);
														strcat(index, "[");
														char num[50]; 
														sprintf(num, "%d", i);
														strcat(index, num);
														strcat(index, "]");
														addItem(index, "Var", $1,0, currentScope);
													}
													else
														printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
													showSymTable();
												}
						}
;

StmtList:	
	| Stmt StmtList { $1->left = $2;
							  $$ = $1;
				}
;

Stmt:	SEMICOLON	{}
	| Expr SEMICOLON	{$$ = $1;}
;

// Fix addition patch
ADDITION:	ADDITION OP ADDITION { sprintf($$, "%s + %s",$1, $3); }
	| NUMBER { sprintf($$, "%d", $1); }
	| ID {if(strcmp(getVariableKind($1, currentScope), "Param") == 0)
				sprintf($$, "TPar%d", getParVal($1, currentScope));
		else
			$$=$1;
		}
;

Block:	 LeftCurly DeclList RETURN ID SEMICOLON RightCurly { emitReturn($4); $$ = $2; }
;


ParamDecl:	{ $$ = AST_assignment("ParamList", "", "null");}
		| TYPE ID COMMA ParamDecl { printf("\n RECOGNIZED RULE: Param declaration %s\n", $2);
									$$ = AST_Type("Param",$1, $2);
									$$->left = $4;
									// Symbol Table
									symTabAccess();
									int inSymTab = found($2, currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) 
										addItem($2, "Param", $1,0, currentScope);
										updateParVal($2, currentScope, parVal);
										parVal++;}  
		| ParamDeclEnd {$$=$1;}
;

ParamDeclEnd: TYPE ID { printf("\n RECOGNIZED RULE: Param declaration %s\n", $2);
									$$ = AST_Type("Param",$1, $2);
									// Symbol Table
									symTabAccess();
									int inSymTab = found($2, currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) 
										addItem($2, "Param", $1,0, currentScope);
										updateParVal($2, currentScope, parVal);
										parVal++;}
;

Function:	TYPE ID LeftPar ParamDecl {emitFunction($2);} RightPar Block{
							strcpy(currentScope, $2); 
							
							$<ast>$  = AST_Write("Function",$1,$2);
							$<ast>4->left = $<ast>6;
							$<ast>$->left = $<ast>4;
							strcpy(currentScope, "global");
							//semantic checks
							if (semanticCheckPassed == 1) {
								printf("Function is semantically correct.");

								
								

								emitMIPSFunction($2);
							} 
							parVal = 0;
			}
;
// TODO: Create array, functions, and function parameter rules

// TODO: Update to accept new operations and functions and arrays
Expr:	ID EQ ID 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ---- //
					  $$ = AST_assignment("=",$1,$3);

					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared

					    if(found($1, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
					    if(found($3, currentScope) != 1){
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}

					// Check types

						printf("\nChecking types: \n");
						int typeMatch = compareTypes ($1, $3, currentScope);
						if (typeMatch == 0){
							printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
							semanticCheckPassed = 0;
						}
						

					if (semanticCheckPassed == 1) {
						printf("\n\n>>> AssignStmt Rule is SEMANTICALLY correct and IR code is emitted! <<<\n\n");

						// ---- EMIT IR 3-ADDRESS CODE ---- //
						
						// The IR code is printed to a separate file

						// Temporary variables management will eventually go in here
						// and the paramaters of the function below will change
						// to using T0, ..., T9 variables

						emitAssignment($1, $3);

						// ----     EMIT MIPS CODE   ----  //

						// The MIPS code is printed to a separate file

						// MIPS registers management will eventually go in here
						// and the paramaters of the function below will change
						// to using $t0, ..., $t9 registers

						emitMIPSAssignment($1, $3);



					}
					

				}
	| ID EQ ADDITION {
		if(found($1, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

		printf("\nChecking types: \n");

		//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
		if(strcmp(getVariableType($1, currentScope),"int") != 0) {
			printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", $1, currentScope);
			semanticCheckPassed = 0;
		}	

		if (semanticCheckPassed == 1) {
							printf("\n\nADDITION: Rule is semantically correct!\n\n");
							updateValue($1,$3);
							char id2[50];
							sprintf(id2, "%s", $3);
							$$ = AST_assignment("=",$1, id2);
							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantIntAssignment($1, id2);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantIntAssignment($1, id2);
							

						}

	}

	| ID LeftBracket NUMBER RightBracket EQ ADDITION {
		char index[50];
		sprintf(index, "%s", $1);
		strcat(index, "[");
		char num[50]; 
		sprintf(num, "%d", $3);
		strcat(index, num);
		strcat(index, "]");
		if(found(index, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

		printf("\nChecking types: \n");

		//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
		if(strcmp(getVariableType(index, currentScope),"int") != 0) {
			printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", $1, currentScope);
			semanticCheckPassed = 0;
		}	

		if (semanticCheckPassed == 1) {
							printf("\n\nADDITION: Rule is semantically correct!\n\n");
							updateValue(index,$6);
							char id2[50];
							sprintf(id2, "%d", $6);
							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantIntAssignment(index, id2);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantIntAssignment(index, id2);

						}

	}
	| ID EQ FuncCall {
		$$ = $3;
		emitCallIDFunction($1);
	}

	| WRITE ID 	{ printf("\n RECOGNIZED RULE: WRITE statement\n");
					$$ = AST_Write("write",$2,"");
					
					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared
					    if(found($2, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, currentScope);
							semanticCheckPassed = 0;
						}

					if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");

							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							
							emitWriteId($2);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers

							emitMIPSWriteId($2);
						}
				}
				| FuncCall {$$=$1;}
	
	
;


CallParam:	{ $$ = AST_assignment("ParamList", "", "null");}
		| ID COMMA CallParam { printf("\n RECOGNIZED RULE: Param call %s\n", $1);
									strcpy(funcParams[paramIdx], $1);
									printf("Here");
									paramIdx++;
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									$$ = AST_Write("Param",$1,""); $$->left = $3;}
		| CallParamEnd {
			$$ = $1;}
;

CallParamEnd: ID { 
				printf("\n RECOGNIZED RULE: Param Call %s\n", $1);
				strcpy(funcParams[paramIdx], $1);
				paramIdx++;
				$$ = AST_Write("Param",$1,"");
}
;

FuncCall:	ID LeftPar CallParam {
				$<ast>$ = AST_Write("FuncCall",$1,""); 
				$<ast>$->left = $<ast>3; 
			} 
			RightPar {
				for(int i = 0; i <paramIdx; i++) {
					emitParam(i, funcParams[i]);
				}
				emitCallFunction($1);
				printf("here2");

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

	// Initialize IR and MIPS files
	initIRcodeFile();
	initAssemblyFile();

	// Start parser
	yyparse();

	// Add the closing part required for any MIPS file
	emitEndOfAssemblyCode();

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}