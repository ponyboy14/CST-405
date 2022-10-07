	| NUM OP {
		printf("\n RECOGNIZED RULE:");

		char str[50];

		sprintf(str, "%d", $1); // convert $1 from int to string
		
						AddExpr($1, $2);
					   $$ = AST_assignment("+",str);

						// ---- SEMANTIC ANALYSIS ACTIONS ---- //  
						
						// Check types
						
						printf("%s + ", "number");  // This temporary for now, until the line above is debugged and uncommented
	
					}
	

	| ID OP 	{ printf("\n RECOGNIZED RULE: Constant Assignment statement\n"); 
					   // ---- SEMANTIC ACTIONS by PARSER ----
					   
						AddExpr($1, $2);

					   $$ = AST_assignment("+",$1);

						// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

						// Check if identifiers have been declared

					    if(found($1, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

						printf("\nChecking types: \n");

						//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
						
						printf("%s +\n", "int");  // This temporary for now, until the line above is debugged and uncommented

						

	| NUM {printf("\n RECOGNIZED RULE:")
			printf("\n RECOGNIZED RULE:");

			char str[50];

			sprintf(str, "%d", $1); // convert $1 from int to string

			AddExpr($1,"e");

			$$ = AST_assignment("+",str);
	}