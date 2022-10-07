// ---- Functions to handle IR code emissions ---- //
int registers[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


void  initIRcodeFile(){
    IRcode = fopen("IRcode.ir", "a");
    fprintf(IRcode, "\n\n#### IR Code ####\n\n");
}

void emitBinaryOperation(char op[1], const char* id1, const char* id2){
    fprintf(IRcode, "T1 = %s %s %s", id1, op, id2);
}

void emitAssignment(char * id1, char * id2){
  // This is the temporary approach, until temporary variables management is implemented
  reg1 = getReg(id1)
  reg2 = getReg(id2)
  fprintf(IRcode, "T%d = %s\n", reg1, id1);
  fprintf(IRcode, "T%d = %s\n", reg2, id2);
  fprintf(IRcode, "T%d = T%d\n", reg2, reg1);
}

void emitIntAssign(char * id, int num) {
    fprintf(IRcode, "T%d = %d\n", reg1 = getReg(id), num);
}

void emitIdAssign(char * id1, char * id2) {
    fprintf(IRcode, "T%d = %d\n", reg1 = getReg(id1), getReg(id2));
}

void emitConstantIntAssignment (char id1[50], char id2[50]){
    fprintf(IRcode, "%s = %s\n", id1, id2);
}

void emitWriteId(char * id){
    //fprintf (IRcode, "output %s\n", id); // This is the intent... :)

    // This is what needs to be printed, but must manage temporary variables
    // We hardcode T2 for now, but you must implement a mechanism to tell you which one...
    fprintf (IRcode, "output T%d\n", getReg(id));
}


int getReg(char * id) {
    for(int i = 0; i < 8; i++) {
        if registers[i] == id 
            return i;
    getOpenReg()
}
int getOpenReg() {
    for(int i = 0; i < 8; i++) {
        if registers[i] == NULL {
            registers[i] = 1;
            return i;
        }

    }
}

void freeReg(int reg) {
    registers[reg] == 0;
}