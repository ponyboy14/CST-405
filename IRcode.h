// ---- Functions to handle IR code emissions ---- //
FILE *IRcode;
FILE *read;
char* regs[8] = {"","","","","","","",""};
int cont = 0;
char params[][50];
int ifCount=0;
int elseCount=0;
int ifcontinueCount=0;
int whileCount=0;

int getOpenRegister(char id[50]) {
    for(int i = 0; i < 8; i++) {
        if(strcmp("", regs[i]) == 0) {
            regs[i] = id;
            //sprintf(regs[i],"%s",id);
            return i;
        }

    }
}

int getRegister(char id[50]) {
    for(int i = 0; i < 8; i++) {
        if(strcmp(id, regs[i]) == 0){
            return i;
        }
    }
    
    return getOpenRegister(id);
}


/*void freeRegister(int reg) {
    regs[reg] = "";
}*/

void  initIRcodeFile(){
    IRcode = fopen("IRcode.ir", "w");
    fprintf(IRcode, "#### IR Code ####\n\n");
    fprintf(IRcode, "goto main\n\n");
}

void emitBinaryOperation(char op[1], const char* id1, const char* id2){
    fprintf(IRcode, "T1 = %s %s %s", id1, op, id2);
}

void emitAssignment(char * id1, char * id2){
  // This is the temporary approach, until temporary variables management is implemented

  fprintf(IRcode, "T%d = %s\n", getRegister(id1), id1);
  fprintf(IRcode, "T%d = %s\n", getRegister(id2), id2);
  fprintf(IRcode, "T%d = T%d\n", getRegister(id1), getRegister(id2));
}

void emitConstantIntAssignment (char id1[50], char id2[50]){
    fprintf(IRcode, "T%d = %s\n", getRegister(id1), id2);
}

void emitConstantCharAssignment (char id1[50], char id2){
    fprintf(IRcode, "T%d = '%c'\n", getRegister(id1), id2);
}

void emitConstantFloatAssignment (char id1[50], char id2[50]){
    fprintf(IRcode, "T%d = %s\n", getRegister(id1), id2);
}

void emitWriteId(char * id){
    //fprintf (IRcode, "output %s\n", id); // This is the intent... :)

    // This is what needs to be printed, but must manage temporary variables
    // We hardcode T2 for now, but you must implement a mechanism to tell you which one...
    fprintf (IRcode, "output T%d\n", getRegister(id));
}

void emitFunction(char id[50]) {
    fprintf (IRcode, "%s: \n", id);
}

void emitParam(int idx, char id[50]) {
    fprintf (IRcode, "TPar%d = T%d\n", idx, getRegister(id));
}

void emitCallFunction(char id[50]) {
    
    fprintf (IRcode, "TPos = \"continue%d\"\n", cont);
    fprintf (IRcode, "call %s\n", id);
    fprintf (IRcode, "continue%d:\n", cont);
    cont++;
}

void emitCallIDFunction(char id[50]) {
    fprintf (IRcode, "T%d = T8\n", getRegister(id));
}

void emitReturn(char id[50]) {
    fprintf (IRcode, "T8 = T%d\n", getRegister(id));
    fprintf (IRcode, "goto TPos\n");
    fprintf (IRcode, "main:"); 
}

void emitIfCondition (char id1[50], char id2[50], char id3[50]){
    for(int i=0; i<ifCount; i++){fprintf(IRcode, "    ");}
    ifCount++;
    fprintf(IRcode, "IF     T%d %s %s   GOTO IFTRUE%d\n", getRegister(id1), id2, id3, ifCount);
}

void emitElseCondition (){
    for(int i=0; i<ifCount+1; i++){fprintf(IRcode, "    ");}
    elseCount=ifCount;
    fprintf(IRcode, "GOTO ELSE%d\n",elseCount);
}

void emitIfTrueCondition (){
    for(int i=0; i<ifCount+1; i++){fprintf(IRcode, "    ");}
    fprintf(IRcode, "IFTRUE%d: ",ifCount);
}

void emitIfElseContinue (){
    for(int i=0; i<ifCount+1; i++){fprintf(IRcode, "    ");}
    fprintf(IRcode, "ELSE%d: ",elseCount);
    
    
}

void emitGOTOContinue (){
    for(int i=0; i<ifCount+1; i++){fprintf(IRcode, "    ");}
    fprintf(IRcode, "GOTO IFCONTINUE%d: \n",elseCount);
}

void emitIfContinue (){
    for(int i=0; i<ifCount+1; i++){fprintf(IRcode, "    ");}
    fprintf(IRcode, "IFCONTINUE%d: \n",elseCount);
    elseCount--;
}

void emitWhileCondition (char id1[50], char id2[50], char id3[50]){
    for(int i=0; i<whileCount; i++){fprintf(IRcode, "    ");}
    whileCount++;
    fprintf(IRcode, "WHILE%d     T%d %s %s GOTO WHILETRUE%d\n",whileCount, getRegister(id1), id2, id3, whileCount);
}

void emitWhileTrue (){
    for(int i=0; i<whileCount; i++){fprintf(IRcode, "    ");}
    fprintf(IRcode, "WHILETRUE%d: ",whileCount);
}

void emitGoToWhile (){
    for(int i=0; i<whileCount; i++){fprintf(IRcode, "    ");}
    fprintf(IRcode, "GOTO WHILE%d     \n",whileCount);
}

void emitWhileContinue (){
    for(int i=0; i<whileCount; i++){fprintf(IRcode, "    ");}
    fprintf(IRcode, "WHILECONTINUE%d:  ",whileCount);
}

void emitGoToWhileContinue (){
    for(int i=0; i<whileCount; i++){fprintf(IRcode, "    ");}
    fprintf(IRcode, "GOTO WHILECONTINUE%d     \n",whileCount);
}

void emitAddOp (int id1, int id2){
    fprintf(IRcode, "%d + %d\n", id1, id2);
}

void emitSubOp (int id1, int id2){
    fprintf(IRcode, "%d - %d\n", id1, id2);
}

void emitMulOp (int id1, int id2){
    fprintf(IRcode, "%d * %d\n", id1, id2);
}

void emitDivOp (int id1, int id2){
    fprintf(IRcode, "%d / %d\n", id1, id2);
}

void emitCarOp (int id1, int id2){
    fprintf(IRcode, "%d ^ %d\n", id1, id2);
}
