// ---- Functions to handle IR code emissions ---- //
FILE *IRcode;
FILE *read;
char* regs[8] = {"","","","","","","",""};
int cont = 0;
iftrue = 0;
elsetrue = 0;
char params[][50];

int getOpenRegister(char id[50]) {
    for(int i = 0; i < 8; i++) {
        if(strcmp("", regs[i]) == 0) {
            regs[i] = id;
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


void freeRegister(int reg) {
    regs[reg] = "";
}

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

void emitIf(char cond[50]) {
    fprintf (IRcode, "IF NOT %s GOTO ELSE%d\n", cond, iftrue);
    fprintf (IRcode, "IFTRUE%d:\n", iftrue);
    iftrue++;
}

void emitElse() {
    fprintf (IRcode, "ELSE%d:\n", elsetrue);
    elsetrue++;
}

void emitContinue() {
    fprintf (IRcode, "CONTNUE%d:\n", cont);
    cont++;
}
void emitGotoContinue() {
    fprintf (IRcode, "GOTO CONTNUE%d\n", cont);
}