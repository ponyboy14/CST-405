%{




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
%}

%union {
	int number;
	char character;
	char* string;
	struct AST* ast;
}

%token <string> TYPE
%token <string> ID
%token <character> SEMICOLON
%token <string> EQ 
%token <string> PLUS_OP
%token <string> SUB_OP
%token <string> MULT_OP
%token <string> DIV_OP
%token <string> CAR_OP
%token <string> LeftPar
%token <character> RightPar
%token <string> LeftCurly
%token <string> RightCurly
%token <string> LeftBracket
%token <string> RightBracket
%token <string> COMMA
%token <string> EQ_COND
%token <string> GREATER
%token <string> LESS
%token <string> GREATER_EQ
%token <string> LESS_EQ
%token <string> NOT
%token <string> DOT
%token <string> CHAR
%token <string> QUOTE
%token <number> NUMBER
%token <string> FLOAT
%token <string> WRITE
%token <string> WRITELN
%token <string> READ
%token <string> RETURN
%token <string> IF
%token <string> ELSE
%token <string> WHILE
%token <string> BOOL
%token <string> TRUE
%token <string> FALSE

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;
%printer { fprintf(yyoutput, "%s", $$); } CHAR;
%printer { fprintf(yyoutput, "%s", $$); } FLOAT;

%type <ast> Program DeclList Decl VarDecl Stmt StmtList Expr Function ParamDecl ParamDeclEnd Block CallParam CallParamEnd FuncCall FuncBlock
%type <ast> OPERATION
%type <ast> ArrayDecl
%type <ast> IfStmt ElseStmt CONDITIONIF TestOp TestExpr 
%type <ast> WhileStmt CONDITIONWHILE
%type <ast> CarOp MultDivOp AddSubOp Obj1 Obj2 Obj3


%start Program

%%

Program: DeclList  { 
					$$ = $1;
					 //printf("\n--- Abstract Syntax Tree ---\n\n");
					 //printAST($$,0);

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
    | ArrayDecl
	| IfStmt
	| ElseStmt
	| WhileStmt
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
;

ArrayDecl: 	TYPE ID LeftBracket NUMBER RightBracket SEMICOLON {
								// Symbol Table

								
									int index=$4;

									symTabAccess();
									int inSymTab = found($2, currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) 
										addItem($2, "Array", $1,$4, currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);

									for(int i=0;i<index;i++){
										char id1[50];
										sprintf(id1, "%d", i);
										char id2[50];
										sprintf(id2, "%s", $2);
										char new[50];
										sprintf(new, "%s[%s]", id2,id1);
										addItem(new, "Array", $1,0, currentScope);

									}
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    $$ = AST_Type("Array Type",$1,$2);
									printf("-----------> %s", $$->LHS);

};


IfStmt: IF  CONDITIONIF Block {
	if (semanticCheckPassed) {
		$<ast>$ = AST_assignment("if", "", "");
		$<ast>$->left = $<ast>2;
		$<ast>$->left->left = $<ast>3;
		emitGOTOContinue(); 
		emitMipsGOTOContinue(); 
		emitMipsNewLine(); 
		emitMipsIfElse(); 
		emitIfElseContinue();
	}
	} ElseStmt{
	if (semanticCheckPassed) {
		$<ast>$ = appendNode($<ast>$, $<ast>4);
		emitGOTOContinue();
		emitIfContinue();

		emitMipsGOTOContinue();
		emitMipsNewLine();
		emitMipsIfContinue();
	}

};

ElseStmt: ELSE Block { 
	if (semanticCheckPassed) {
		$$ = AST_assignment("else", "", ""); 
		$$->left = $2;
	}
	
}
| {};

WhileStmt: WHILE CONDITIONWHILE Block{
	if (semanticCheckPassed) {
		$$ = AST_assignment("WHILE", "", "");
		$$->left = $2;
		$$->left->left = $3;
		emitGoToWhile();
		emitWhileContinue();

		emitMipsGOTOWhile();
		emitMipsNewLine();
		emitMipsWhileContinue();
	}

};

CONDITIONWHILE: TestExpr TestOp TestExpr {
		printf("TEST OP: %s\n",$3);
		char id1[50];
		char id2[50];
		char id3[50];
		sprintf(id1, "%d", $1);
		sprintf(id2, "%s", $2);
		sprintf(id3, "%d", $3);

		if ((strcmp(">",$2)==0 || strcmp("<",$2)==0) && strcmp(id1,id2) == 0) {
			printf("SEMANTIC ERROR: Left Val %d is equal to Right Val %d", $1, $3);
			semanticCheckPassed = 0;
		}

		if (semanticCheckPassed) {
			$$ = AST_assignment($2, id1, id3);
			emitWhileCondition(id1,id2,id3);
			emitGoToWhileContinue();
			emitWhileTrue();

			if(strcmp(">",$2)==0){
				printf("TEST OP: %s\n",$2);
				emitMipsWhile();
				emitMipsWhileConditionGREAT(id1,id3);
				emitMipsGOTOWhileContinue();
				emitMipsNewLine();
				emitMipsWhileLoop();
			}
			if(strcmp("<",$2)==0){
				printf("TEST OP: %s\n",$2);
				emitMipsWhile();
				emitMipsWhileConditionLESS(id1,id3);
				emitMipsGOTOWhileContinue();
				emitMipsNewLine();
				emitMipsWhileLoop();
			}
			if(strcmp(">=",$2)==0){
				printf("TEST OP: %s\n",$2);
				emitMipsWhile();
				emitMipsWhileConditionGE(id1,id3);
				emitMipsGOTOWhileContinue();
				emitMipsNewLine();
				emitMipsWhileLoop();
			}
			if(strcmp("<=",$2)==0){
				printf("TEST OP: %s\n",$2);
				emitMipsWhile();
				emitMipsWhileConditionLE(id1,id3);
				emitMipsGOTOWhileContinue();
				emitMipsNewLine();
				emitMipsWhileLoop();
				}
		}


}
	| LeftPar CONDITIONWHILE RightPar {};
//should we emit MIPS after testop? commands in MIPS are dependent on what testop it is (beq, blt, bne, etc.)
CONDITIONIF: TestExpr TestOp TestExpr {
		char id1[50];
		char id2[50];
		char id3[50];
		sprintf(id1, "%s", $1);
		sprintf(id2, "%s", $2);
		sprintf(id3, "%s", $3);
		printf("HELP: %s\n", id2);
		if ((strcmp(">",$2)==0 || strcmp("<",$2)==0) && strcmp(id1,id2) == 0) {
			printf("SEMANTIC ERROR: Left Val %d is equal to Right Val %d", $1, $3);
			semanticCheckPassed = 0;
		}

		if (semanticCheckPassed) {
			emitIfCondition($1, id2, $3);
			emitElseCondition();
			emitIfTrueCondition();
			if(strcmp(">",$2)==0){
				emitMipsIfConditionGREAT($1,$3);
				emitMipsGOTOElse();
				emitMipsNewLine();
				emitMipsIfTrue();
			}
			if(strcmp("<",$2)==0){
				emitMipsIfConditionLESS($1,$3);
				emitMipsGOTOElse();
				emitMipsNewLine();
				emitMipsIfTrue();
			}
			if(strcmp(">=",$2)==0){
				emitMipsIfConditionGE($1,$3);
				emitMipsGOTOElse();
				emitMipsNewLine();
				emitMipsIfTrue();
			}
			if(strcmp("<=",$2)==0){
				emitMipsIfConditionLE($1,$3);
				emitMipsGOTOElse();
				emitMipsNewLine();
				emitMipsIfTrue();
			}
			if(strcmp("==",$2)==0){
				emitMipsIfConditionGREAT($1,$3);
				emitMipsGOTOElse();
				emitMipsNewLine();
				emitMipsIfTrue();
			}
		}	
		

}
	| LeftPar CONDITIONIF RightPar {};

TestExpr: ID {$$=$1; }
	| NUMBER {char id2[50]; sprintf(id2, "%d", $1); printf("TEST1: %s\n",id2); $$=id2; };
	| ID LeftBracket TestExpr RightBracket {
		char id[50];
		sprintf(id, "%s[%d]", $1,$3);
		if(found(id, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
		if (semanticCheckPassed)
			$$=getValInt(id, currentScope);
	}
	| OPERATION{$$=$1;}


TestOp: EQ_COND {$$=$1;}
	| GREATER {$$=$1;}
	| LESS {$$=$1;}
	| GREATER_EQ {$$=$1;}
	| LESS_EQ {$$=$1;}
	| NOT {$$=$1;};

Block:	 LeftCurly DeclList RightCurly { 
													$$ = $2;

													
													
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

OPERATION: LeftPar OPERATION RightPar {}
	| NUMBER PLUS_OP OPERATION
	{	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", $1);
		sprintf(id2, "%c", (char)43);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
	|	NUMBER SUB_OP OPERATION
	{	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", $1);
		sprintf(id2, "%c", (char)45);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
	|	NUMBER MULT_OP OPERATION
	{	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", $1);
		sprintf(id2, "%c", (char)42);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
	|	NUMBER DIV_OP OPERATION
	{	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", $1);
		sprintf(id2, "%c", (char)47);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
	|	NUMBER CAR_OP OPERATION
	{	
		initialized();
		char id1[50];
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", $1);
		sprintf(id2, "%c", (char)94);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
	| ID PLUS_OP OPERATION
	{	

		
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt($1, currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal($1, currentScope));
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
	|	ID SUB_OP OPERATION
	{	
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt($1, currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal($1, currentScope));
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
	|	ID MULT_OP OPERATION
	{	
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt($1, currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal($1, currentScope));
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
	|	ID DIV_OP OPERATION
	{	
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt($1, currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal($1, currentScope));
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
	|	ID CAR_OP OPERATION
	{	
		int idVal=getValInt(idVal, currentScope);
		initialized();
		char id1[50];
		if(funcOp == 0) {
			int idVal=getValInt($1, currentScope);
			
			sprintf(id1, "%d", idVal);
		}
		else {
			sprintf(id1, "$s%d", getRegVal($1, currentScope));
		} 
		char id2[50];
		//char id3[50];
		sprintf(id1, "%d", $1);
		sprintf(id2, "%c", (char)94);
		//sprintf(id3, "%d", $3);
		printf("OPERATION %s\n", id2);
		printf("OPERATION %s\n", id1);
		//printf("OPERATION %s\n", id3);
		insertValues(id2);
		insertValues(id1);
		//insertValues(id3);
	}
	| LeftPar OPERATION RightPar PLUS_OP OPERATION
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
	| NUMBER 
	{ 
		initialized();
		printf("\n%d\n", funcOp);
		char id[50];
		sprintf(id, "%d", $1);
		printf("OPERATION %s\n", id);
		insertValues(id);
		//$$=$1; 
	}
	| ID 
	{
		initialized();
		if(found($1, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
		int z;
		char id[50];
		printf("\n%d\n", funcOp);
		if (funcOp == 0)  {
			z=getValInt($1, currentScope);
			
			sprintf(id, "%d", z);
		}
		else {
			sprintf(id, "%s", $1);
		}
		printf("OPERATION %s\n", id);
		insertValues(id);
	}
;


FuncBlock:	 LeftCurly DeclList RETURN ID SEMICOLON RightCurly { 
													$$ = $2;

													if(strcmp(getVariableType($4,currentScope), funcType) != 0) {
														printf("SEMANTIC ERROR: Return type must be the same as Function stype. \n", $2);
														semanticCheckPassed = 0;
													}
													
													if (semanticCheckPassed == 1)  {
														emitReturn($4); 
														emitMIPSReturn($4);
													}
													
												}
;


ParamDecl:	{ $$ = AST_assignment("ParamList", "", "null");}
		| TYPE ID COMMA ParamDecl { printf("\n RECOGNIZED RULE: Param declaration %s\n", $2);
									$$ = AST_Type("Param",$1, $2);
									$$->left = $4;
									// Symbol Table
									symTabAccess();
									int inSymTab = found($2, "_function_param");
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) {
										addItem($2, "Param", $1,0, "_function_param");
										addRegVal($2, "_function_param", parIdx);
										strcpy(funParType[parIdx], $1);
										parIdx++;
									}
										
									else {
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
										semanticCheckPassed = 0;
									}
										
									
	}  
		| ParamDeclEnd {$$=$1;}
;

ParamDeclEnd: TYPE ID { printf("\n RECOGNIZED RULE: Param declaration %s\n", $2);
									$$ = AST_Type("Param",$1, $2);
									// Symbol Table
									symTabAccess();
									int inSymTab = found($2, "_function_param");
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == 0) {
										addItem($2, "Param", $1,0, "_function_param");
										addRegVal($2, "_function_param", parIdx);
										strcpy(funParType[parIdx], $1);
										parIdx++;
									}
										
									else {
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
										semanticCheckPassed = 0;
									}
}
;

Function:	TYPE ID LeftPar { emitFunction($2); 
								emitMIPSFunction($2); funcOp = 1; strcpy(currentScope, $2);}ParamDecl { updateScopes($2); strcpy(funcType, $1);} RightPar Block{
							strcpy(currentScope, "global");
							
							
							symTabAccess();
							int inSymTab = found($2, currentScope);
									
							if (inSymTab == 0) 
								addItem($2, "Function", $1,0, currentScope);
							else {
								printf("SEMANTIC ERROR: Function %s has already been defined. \n", $2);
								semanticCheckPassed = 0;
							}
							if (semanticCheckPassed == 1) {
								printf("Function is semantically correct.");
								for(int i = 0; i < parIdx; i++) {
									addFunPar($2, funParType[i], i);
								}
								parIdx=0;
								
							}
							strcpy(funcType, "");
							
							$<ast>$  = AST_Write("Function",$1,$2);
							$<ast>4->left = $<ast>6;
							$<ast>$->left = $<ast>4;
							funcOp = 0;
			}
;
// TODO: Create array, functions, and function parameter rules

// TODO: Update to accept new operations and functions and arrays
Expr:	ID EQ OPERATION {
		printf("\n RECOGNIZED RULE: OPERATION\n");
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

		//$$ = AST_assignment("=",$1,$3);
		if (semanticCheckPassed == 1) {
							printf("\n\nOPERATION: Rule is semantically correct!\n\n");
							//updateValueInt($1, currentScope, operationTotal);
							char id2[50];
							sprintf(id2, "%d", $3);
							showSymTable();
							// ---- EMIT IR 3-ADDRESS CODE ---- //
							updateValueInt($1,currentScope, $3);
							$$ = AST_assignment("=",$1,id2);
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);


							emitConstantIntAssignment($1, id2); 
							

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMipsOPEQ($1);
							emitMIPSConstantIntAssignment($1, id2);
							

						}

	}
	| ID EQ NUMBER 	{ printf("\n RECOGNIZED RULE: Constant Assignment statement\n"); 
					   // ---- SEMANTIC ACTIONS by PARSER ----
					   char str[50];
					   
					   sprintf(str, "%d", $3); // convert $3 from int to string
					   $$ = AST_assignment("=",$1, str);

						// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

						// Check if identifiers have been declared

					    if(found($1, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

						printf("\nChecking types: \n");

						//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
						
						printf("%s = %s\n", "int", "number");  // This temporary for now, until the line above is debugged and uncommented
						
						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");

							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file

							// Temporary variables management will eventually go in here
							// and the paramaters of the function below will change
							// to using T0, ..., T9 variables
							
							updateValueInt($1,currentScope, $3);

							char id1[50], id2[50];
							sprintf(id1, "%s", $1);
							sprintf(id2, "%d", $3);

							// Temporary variables management will eventually go in here
							// and the paramaters of the function below will change
							// to using T0, ..., T9 variables

							emitConstantIntAssignment(id1, id2);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers

							emitMIPSConstantIntAssignment(id1, id2);

						}
					}
	| ID EQ CHAR {
		printf("\n RECOGNIZED RULE: ID CHAR\n");
		if(found($1, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						if(strcmp(getVariableType($1, currentScope),"char") != 0) {
							printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
		}
		char id[50];
		sprintf(id, "%s", $3);
		char act=id[1];
		updateValueChar($1,currentScope,act);
		showSymTable();
		printf("TEST CHAR %c\n",act);
		$$ = AST_assignment("=",$1,$3);
		// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantCharAssignment($1, act);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantCharAssignment($1, act);

						
	}

	| ID EQ FLOAT {
		printf("\n RECOGNIZED RULE: ID FLOAT\n");
		if(found($1, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						if(strcmp(getVariableType($1, currentScope),"float") != 0) {
							printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
		}
		char id[50];
		sprintf(id, "%s", $3);
		float convert=atof(id);
		updateValueFloat($1,currentScope,convert);
		showSymTable();
		printf("TEST FLOAT %f\n",convert);
		$$ = AST_assignment("=",$1,$3);
		// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							//$$ = $3
							//printf("Reading additon: %s\n", $$);
							emitConstantFloatAssignment($1, id);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers
							
							emitMIPSConstantFloatAssignment($1, id);

						
	}

	| ID LeftBracket NUMBER RightBracket EQ OPERATION 	{ printf("\n RECOGNIZED RULE: ARRAY OPERATION\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ---- //
					char id1[50];
					char id2[50];
					sprintf(id1, "%s",$1);
					sprintf(id2, "%d",$3);
					char fullIndex[50];
					sprintf(fullIndex, "%s[%s]",id1,id2);
					if(found(fullIndex, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

		printf("\nChecking types: \n");

		//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
		if(strcmp(getVariableType(fullIndex, currentScope),"int") != 0) {
			printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", $1, currentScope);
			semanticCheckPassed = 0;
		}
		reverseOpList();
		int operationTotal=calculateAll();
		deleteAll();
		char opTemp[50];
		sprintf(opTemp, "%d", operationTotal);
		$$ = AST_assignment("=",$1,opTemp);
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

	| ID LeftBracket NUMBER RightBracket EQ CHAR {
		char id1[50];
		char id2[50];
		sprintf(id1, "%s",$1);
		sprintf(id2, "%d",$3);
		char fullIndex[50];
		char regIndex[50];
		sprintf(fullIndex, "%s[%s]",id1,id2);
		sprintf(regIndex, "%s%s",id2,id1);
		printf("FULL INDEX: %s\n",fullIndex);
		printf("\n RECOGNIZED RULE: ID CHAR\n");
		if(found(fullIndex, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						if(strcmp(getVariableType(fullIndex, currentScope),"char") != 0) {
							printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
		}
		char id[50];
		sprintf(id, "%s", $6);
		char act=id[1];
		updateValueChar(fullIndex,currentScope,act);
		showSymTable();
		printf("TEST CHAR %c\n",act);
		$$ = AST_assignment("=",fullIndex,$6);
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

| ID LeftBracket NUMBER RightBracket EQ FLOAT {
		char id1[50];
		char id2[50];
		sprintf(id1, "%s",$1);
		sprintf(id2, "%d",$3);
		char fullIndex[50];
		sprintf(fullIndex, "%s[%s]",id1,id2);
		printf("\n RECOGNIZED RULE: ID FLOAT\n");
		if(found(fullIndex, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						if(strcmp(getVariableType(fullIndex, currentScope),"float") != 0) {
							printf("SEMANTIC ERROR: Variable %s is not an int in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
		}
		char id[50];
		sprintf(id, "%s", $6);
		float convert=atof(id);
		updateValueFloat(fullIndex,currentScope,convert);
		showSymTable();
		printf("TEST FLOAT %f\n",convert);
		$$ = AST_assignment("=",fullIndex,$3);
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


	| ID EQ FuncCall {
		$$ = $3;
		emitCallIDFunction($1);
		emitMIPSCallIDFunction($1);
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
									$$ = AST_Write("Param",$1,""); 
									$$->left = $3;
									strcpy(funcParams[paramIdx], $1);
									paramIdx++;
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									}
		| CallParamEnd {
			$$ = $1;}
;

CallParamEnd: ID { 
				$$ = AST_Write("Param",$1,"");
				printf("\n RECOGNIZED RULE: Param Call %s\n", $1);
				strcpy(funcParams[paramIdx], $1);
				paramIdx++;
				
}
;

FuncCall:	ID LeftPar CallParam RightPar {

				if(found($1, currentScope) != 1) {
					printf("SEMANTIC ERROR: Function %s has NOT been declared in scope %s \n", $1, currentScope);
					semanticCheckPassed = 0;
				}
				strcpy(funcType, $1); 
				
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
						emitMipsParam(i, getValInt(funcParams[i], currentScope));
					printf("here");
				}
				
				$<ast>$ = AST_Write("FuncCall",$1,""); 
				$<ast>$->left = $<ast>3; 
				if (semanticCheckPassed == 1) {
					for(int i = 0; i <paramIdx; i++) {
						emitParam(i, funcParams[i]);
					}
					emitCallFunction($1);
					emitMIPSCallFunction($1);
				}

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
	int i;
	double total_time;
	clock_t start, end;
	start = clock();
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
	//dataWrite();
	closeMIPS();

	cleanCode();

	end = clock();
	//time count stops 
	#ifdef WINDOWS
		total_time = ((double) (end - start)) / CLK_TCK;
		
	#else
		total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
		char execute_time[10];
		char line[256];
		FILE * time_file;
		time_file = fopen("time.txt", "r");
		while (fgets(line, sizeof(line), time_file)) {
			if (line[0] == 'r') {
				int i = 5;
				while(line[i] != '\n') {
					execute_time[i-5] = line[i];
					i++;
				}
			}
		}
		fclose(time_file);
		remove("time.txt");
	#endif
	
	
	//calulate total time
	printf("\nTime to Compile: \n\n%s Seconds\n\n\nTime to Execute:\n\n%f seconds\n", execute_time, total_time);
	return 0;

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
