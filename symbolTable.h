//Symbol table header
#include <string.h>

struct Entry
{
	int itemID;
	char itemName[50];  //the name of the identifier
	char itemKind[8];  //is it a function or a variable?
	char itemType[8];  // Is it int, char, etc.?
	int arrayLength;
	char scope[50];     // global, or the name of the function
	int value;
	int parVal;
};

struct Entry symTabItems[100];
int symTabIndex = 0;
int SYMTAB_SIZE = 20;

void symTabAccess(void){
	printf("::::> Symbol table accessed.\n");
}

void addItem(char itemName[50], char itemKind[8], char itemType[8], int arrayLength, char scope[50]){
	

		// what about scope? should you add scope to this function?
		symTabItems[symTabIndex].itemID = symTabIndex;
		strcpy(symTabItems[symTabIndex].itemName, itemName);
		strcpy(symTabItems[symTabIndex].itemKind, itemKind);
		strcpy(symTabItems[symTabIndex].itemType, itemType);
		symTabItems[symTabIndex].arrayLength = arrayLength;
		strcpy(symTabItems[symTabIndex].scope, scope);
		symTabItems[symTabIndex].value = 0;
		symTabItems[symTabIndex].value = -1;
		symTabIndex++;
	
}

void showSymTable(){
	printf("itemID    itemName    itemKind    itemType     ArrayLength    itemSCope\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i=0; i<symTabIndex; i++){
		printf("%5d %15s  %7s  %7s %6d %15s \n",symTabItems[i].itemID, symTabItems[i].itemName, symTabItems[i].itemKind, symTabItems[i].itemType, symTabItems[i].arrayLength, symTabItems[i].scope);
	}
	

	printf("-----------------------------------------------------------------------\n");
}

int found(char itemName[50], char scope[50]){
	// Lookup an identifier in the symbol table
	// what about scope?
	// return TRUE or FALSE
	// Later on, you may want to return additional information

	// Dirty loop, becuase it counts SYMTAB_SIZE times, no matter the size of the symbol table
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return 1; // found the ID in the table
		}
	}
	return 0;
}

const char* getVariableType(char itemName[50], char scope[50]){
	//char *name = "int";
	//return name;

	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return symTabItems[i].itemType; // found the ID in the table
		}
	}
	return NULL;
}

const char* getVariableKind(char itemName[50], char scope[50]){
	//char *name = "int";
	//return name;

	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return symTabItems[i].itemKind; // found the ID in the table
		}
	}
	return NULL;
}

int compareTypes(char itemName1[50], char itemName2[50],char scope[50]){
	const char* idType1 = getVariableType(itemName1, scope);
	const char* idType2 = getVariableType(itemName2, scope);
	
	printf("%s = %s\n", idType1, idType2);
	
	int typeMatch = strcmp(idType1, idType2);
	if(typeMatch == 0){
		return 1; // types are matching
	}
	else return 0;
}

void updateValue(char * id, int val) {
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, id); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		if( str1 == 0 ){
			symTabItems[i].value = val; // found the ID in the table
			break;
		}
}
}

int getVal(char * id) {
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, id); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		if( str1 == 0){
			return symTabItems[i].value; // found the ID in the table
			break;
		}
}
}

void updateParVal(char * id, char scope[50], int val) {
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, id); 
		
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		if( str1 == 0 ){
			int str2 = strcmp(symTabItems[i].scope, scope);
			if (str2 == 0) {
				symTabItems[i].parVal = val; // found the ID in the table
				break;
			}
		}
}
}

int getParVal(char * id, char scope[50]) {
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, id); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		if( str1 == 0){
			int str2 = strcmp(symTabItems[i].scope, scope);
			if (str2 == 0) {
				return symTabItems[i].parVal; // found the ID in the table
				break;
			}
		}
}
}

void updateScopes(char scope[50]) {
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].scope, "_function_param"); 

		if(str1 == 0)
			strcpy(symTabItems[i].scope, scope)
	}
	
}