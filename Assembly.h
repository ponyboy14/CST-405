// Set of functions to emit MIPS code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE * MIPScode;
FILE * MIPS;
FILE * MIPSout;
int contin = 0;
char* registers[9] = {"","","","","","","","",""};
char* floatNameTrack[50][50];
float floatValTrack[50];
int ifC=0;
int elseC=0;
int ifcontinueC=0;
int whileC=0;

// Add function to handle 
int getOpenReg(char id[50]) {
    for(int i = 0; i < 9; i++) {
        if(strcmp("", registers[i]) == 0) {
            registers[i] = id;
            printf("Test this NEW: %s\n",registers[i]);
            return i;
        }

    }
}

int getReg(char id[50]) {
    for(int i = 0; i < 9; i++) {
        printf("Test this: %s\n",registers[i]);
        if(strcmp(id, registers[i]) == 0){
            return i;
        }
    }
    return getOpenReg(id);
}


void freeReg(int reg) {
    registers[reg] = "";
}

void  initAssemblyFile(){
    // Creates a MIPS file with a generic header that needs to be in every file

    MIPScode = fopen("MIPStmp.asm", "w");
    
    fprintf(MIPScode, ".text\n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "# -----------------------\n");
    //fprintf(MIPScode, "j begin\n");

}

void emitMIPSAssignment(char * id1, char * id2){
  // This is the temporary approach, until register management is implemented
  fprintf(MIPScode, "li $t%d,%s\n", getReg(id1), id1);
  fprintf(MIPScode, "li $t%d,%s\n", getReg(id2), id2);
  fprintf(MIPScode, "li $t%d,$t%d\n", getReg(id1), getReg(id2));
}

void emitMIPSConstantIntAssignment(char id1[50], char id2[50]){
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocate Register(id1);  // This is conceptual to inform what needs to be done later
    fprintf(MIPScode, "li $t%d", getReg(id1));
    fprintf(MIPScode, ",%s\n", id2);
}

void emitMIPSConstantCharAssignment(char id1[50], char id2){
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocate Register(id1);  // This is conceptual to inform what needs to be done later
    
    fprintf(MIPScode, "li $t%d", getReg(id1));
    fprintf(MIPScode, ",'%c'\n", id2);
}

void addFloatInfo(char id1[50], char id2[50]){
    for(int i=0; i<50; i++){
        if(floatNameTrack[0][i]==""){
            for(int j=0; j<50; j++){
                floatNameTrack[j][i]=id1[j];
            }
            float temp=atof(id2);
            floatValTrack[i]=temp;
            break;
        }
    }
}

void emitMIPSConstantFloatAssignment(char id1[50], char id2[50]){
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocate Register(id1);  // This is conceptual to inform what needs to be done later
    fprintf(MIPScode, "lwc1 $f%d", getReg(id1));
    fprintf(MIPScode, ",%s\n", id1);
    addFloatInfo(id1, id2);
}


void clearFloat(){
    for(int i=0; i<50; i++){
        for(int j=0; j<50;j++){
            floatNameTrack[i][j]="";
        }
    }
}

void dataWrite(){
    fprintf(MIPScode, ".data\n");
    char strTemp[50];
    sprintf(strTemp,"");
    for(int i=0; i<50;i++){
        if(floatNameTrack[0][i]==""){
            break;
        }
        for(int j=0;j<50;j++){
            if(floatNameTrack[j][i]==NULL){
                break;
            }
            sprintf(strTemp, "%s%c", strTemp, floatNameTrack[j][i]);
        }
        float temp=floatValTrack[i];
        fprintf(MIPScode, "%s: .float %f\n", strTemp, temp);
        sprintf(strTemp,"");
    }
}

void emitMIPSWriteId(char * id[]){
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(MIPScode, "li $a0,%s\n", id);
    if(strcmp(getVariableType(id, "global"),"int") == 0 && strcmp(getVariableKind(id, "global"),"Var") == 0) {
    fprintf(MIPScode, "li $v0, 1\n");
    fprintf(MIPScode, "move $a0,$t%d\n", getReg(id));
    fprintf(MIPScode, "syscall\n");}
    if(strcmp(getVariableType(id, "global"),"char") == 0 && strcmp(getVariableKind(id, "global"),"Var") == 0) {
    fprintf(MIPScode, "li $v0, 11\n");
    fprintf(MIPScode, "move $a0,$t%d\n", getReg(id));
    fprintf(MIPScode, "syscall\n");}
    if(strcmp(getVariableType(id, "global"),"float") == 0 && strcmp(getVariableKind(id, "global"),"Var") == 0) {
    fprintf(MIPScode, "li $v0, 2\n");
    fprintf(MIPScode, "mov.s $f12,$f%d\n", getReg(id));
    fprintf(MIPScode, "syscall\n");}
    if(strcmp(getVariableType(id, "global"),"int") == 0 && strcmp(getVariableKind(id, "global"),"Array") == 0) {
    for(int i=0;i<getArrayLength(id,"global");i++){
    char tempArray[50];
    sprintf(tempArray,"%s[%d]",id,i);
    fprintf(MIPScode, "li $v0, 1\n");
    fprintf(MIPScode, "li $v0, 1\n");
    fprintf(MIPScode, "move $a0,$t%d\n", getReg(tempArray));
    fprintf(MIPScode, "syscall\n");
    sprintf(tempArray,"");}}
    if(strcmp(getVariableType(id, "global"),"char") == 0 && strcmp(getVariableKind(id, "global"),"Array") == 0) {
    for(int i=0;i<getArrayLength(id,"global");i++){
    char tempArray[50];
    sprintf(tempArray,"%s[%d]",id,i);
    fprintf(MIPScode, "li $v0, 11\n");
    fprintf(MIPScode, "move $a0,$t%d\n", getReg(tempArray));
    fprintf(MIPScode, "syscall\n");
    sprintf(tempArray,"");}}
    if(strcmp(getVariableType(id, "global"),"float") == 0 && strcmp(getVariableKind(id, "global"),"Array") == 0) {
    for(int i=0;i<getArrayLength(id,"global");i++){
    char tempArray[50];
    sprintf(tempArray,"%s[%d]",id,i);
    fprintf(MIPScode, "li $v0, 2\n");
    fprintf(MIPScode, "mov.s $f12,$f%d\n", getReg(tempArray));
    fprintf(MIPScode, "syscall\n");
    sprintf(tempArray,"");}}
    
    
    
}

void emitEndOfAssemblyCode(){
    fprintf(MIPScode, "# -----------------\n");
    fprintf(MIPScode, "#  Done, terminate program.\n\n");
    fprintf(MIPScode, "li $v0,10   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, ".end main\n");
}

void closeMIPS(){
    fclose(MIPScode);
}

void emitMIPSFunction(char id[50]) {
    fprintf(MIPScode, "%s: \n", id);
}

void emitMIPSCallFunction(char id[50]) {
    
    fprintf (MIPScode, "jal %s\n", id);
    fprintf (MIPScode, "continue%d:\n", contin);
    contin++;
}

void emitMIPSCallIDFunction(char id[50]) {
    fprintf (MIPScode, "move $t%d, $t9\n", getReg(id));
}

void emitMIPSReturn(char id[50]) {
    fprintf (MIPScode, "move $t9, $t%d\n", getReg(id));
    fprintf (MIPScode, "jr $ra\n");
    fprintf (MIPScode, "begin:\n");
}

void cleanCode(){
    MIPS = fopen("MIPStmp.asm", "r");
    MIPSout = fopen("MIPScode.asm", "w");
    int count = 1;
    char line[256];
    int last;

    while (fgets(line, sizeof(line), MIPS)) {
        if (strcmp(line, "begin:\n") == 0) {
            last = count;
        }
        count++;
    }
    count = 1;
    fseek(MIPS, 0, SEEK_SET);
    while (fgets(line, sizeof(line), MIPS)) {
        if (strcmp(line, "begin:\n") != 0 || count == last) {
            fprintf(MIPSout, line);
            
        }
        count++;
    }
    fclose(MIPS);
    fclose(MIPSout);
    remove("MIPStmp.asm");

}

void emitMipsAddi(char target[50], char left[50], char right[50]) {
    fprintf(MIPScode, "addi $t%d, %s, %s\n", getReg(target), left, right);
}
void emitMipsAdd(char target[50], char left[50], char right[50]) {
    fprintf(MIPScode, "add $t%d, %s, %s\n", getReg(target), left, right);
}

void emitMipsSoloAddi(char target[50], char right[50]) {
    fprintf(MIPScode, "addi $t%d, $t%d, %s\n", getReg(target), getReg(target), right);
}
void emitMipsSoloAdd(char target[50], char right[50]) {
    fprintf(MIPScode, "add $t%d, $t%d, %s\n", getReg(target), getReg(target), right);
}

void emitMipsParam(int reg, int val[50]) {
     fprintf(MIPScode, "li $s%d, %d\n", reg, val);
}

void emitMipsIfConditionEQ(char id1[50],char id2[50]){
    ifC++;
    fprintf(MIPScode, "beq $t%d, $t%d, IFTRUE%d\n", getReg(id1),getReg(id2), ifC);
}

void emitMipsIfConditionLESS(char id1[50],char id2[50]){
    ifC++;
    fprintf(MIPScode, "blt $t%d, $t%d, IFTRUE%d\n", getReg(id1),getReg(id2), ifC);
}

void emitMipsIfConditionGREAT(char id1[50],char id2[50]){
    ifC++;
    fprintf(MIPScode, "bgt $t%d, $t%d, IFTRUE%d\n", getReg(id1),getReg(id2), ifC);
}

void emitMipsIfConditionLE(char id1[50],char id2[50]){
    ifC++;
    fprintf(MIPScode, "ble $t%d, $t%d, IFTRUE%d\n", getReg(id1),getReg(id2), ifC);
}

void emitMipsIfConditionGE(char id1[50],char id2[50]){
    ifC++;
    fprintf(MIPScode, "bge $t%d, $t%d, IFTRUE%d\n", getReg(id1),getReg(id2), ifC);
}

void emitMipsIfConditionELSE(char id1[50],char id2[50]){
    fprintf(MIPScode, "beq $t%d, $t%d, IFTRUE%d\n", getReg(id1),getReg(id2), ifC);
}

void emitMipsIfTrue(){
    fprintf(MIPScode, "IFTRUE%d: \n", ifC);
}

void emitMipsGOTOElse(){
    elseC=ifC;
    fprintf(MIPScode, "j ELSE%d\n", elseC);
}

void emitMipsGOTOContinue(){
    fprintf(MIPScode, "j CONTINUEIF%d\n", elseC);
}

void emitMipsNewLine(){
    fprintf(MIPScode, "\n");
}

void emitMipsIfElse(){
    fprintf(MIPScode, "ELSE%d: \n", elseC);
}

void emitMipsIfContinue(){
    fprintf(MIPScode, "CONTINUEIF%d: \n", elseC);
    elseC--;
}


//while

void emitMipsWhileConditionEQ(char id1[50],char id2[50]){
    whileC++;
    fprintf(MIPScode, "beq $t%d, $t%d, WHILELOOP%d\n", getReg(id1),getReg(id2), whileC);
}

void emitMipsWhileConditionLESS(char id1[50],char id2[50]){
    whileC++;
    fprintf(MIPScode, "blt $t%d, $t%d, WHILELOOP%d\n", getReg(id1),getReg(id2), whileC);
}

void emitMipsWhileConditionGREAT(char id1[50],char id2[50]){
    whileC++;
    fprintf(MIPScode, "bgt $t%d, $t%d, WHILELOOP%d\n", getReg(id1),getReg(id2), whileC);
}

void emitMipsWhileConditionLE(char id1[50],char id2[50]){
    whileC++;
    fprintf(MIPScode, "ble $t%d, $t%d, WHILELOOP%d\n", getReg(id1),getReg(id2), whileC);
}

void emitMipsWhileConditionGE(char id1[50],char id2[50]){
    whileC++;
    fprintf(MIPScode, "bge $t%d, $t%d, WHILELOOP%d\n", getReg(id1),getReg(id2), whileC);
}

void emitMipsGOTOWhileContinue(){
    fprintf(MIPScode, "j CONTINUEWHILE%d\n", whileC);
}

void emitMipsGOTOWhile(){
    fprintf(MIPScode, "j WHILE%d\n", whileC);
}

void emitMipsWhileContinue(){
    fprintf(MIPScode, "CONTINUEWHILE%d: \n", whileC);
}

void emitMipsWhile(){
    fprintf(MIPScode, "WHILE%d: \n", whileC);
}

void emitMipsWhileLoop(){
    fprintf(MIPScode, "WHILELOOP%d: \n", whileC);
}

void emitMipsCUOP(){
    fprintf(MIPScode, "li $t9, 1 \n");
}

void emitMipsOPEQ(char id1[50]){
    fprintf(MIPScode, "move $t%d, $t9 \n", getReg(id1));
    fprintf(MIPScode, "li $t9, 0 \n");
}

void emitMipsAddOP(char id1[50]){
    fprintf(MIPScode, "add $t9, $t9, %s\n", id1);
}

void emitMipsSubOP(char id1[50]){
    fprintf(MIPScode, "sub $t9, $t9, %s\n", id1);
}

void emitMipsMulOP(char id1[50]){
    fprintf(MIPScode, "mul $t9, $t9, %s\n", id1);
}

void emitMipsDivOP(char id1[50]){
    fprintf(MIPScode, "li $t8, %s \n",id1);
    fprintf(MIPScode, "div $t8, $t9\n");
    fprintf(MIPScode, "mflo $t9\n");
    fprintf(MIPScode, "li $t8, 0 \n");
}

void emitMipsCarOP(char id1[50]){
    fprintf(MIPScode, "mul $t9, $t9, %s\n", id1);
}
