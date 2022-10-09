// ---- Functions to handle IR code emissions ---- //
FILE *IRcode;
char* registers[8] = {"","","","","","","",""};

int getOpenReg(char id[50]) {
    for(int i = 0; i < 8; i++) {
        if(strcmp("", registers[i]) == 0) {
            registers[i] = id;
            return i;
        }

    }
}

int getReg(char id[50]) {
    for(int i = 0; i < 8; i++) {
        if(strcmp(id, registers[i]) == 0){
            return i;
        }
    }
    return getOpenReg(id);
}


void freeReg(int reg) {
    registers[reg] = "";
}

void  initIRcodeFile(){
    IRcode = fopen("IRcode.ir", "a");
    fprintf(IRcode, "\n\n#### IR Code ####\n\n");
}

void emitBinaryOperation(char op[1], const char* id1, const char* id2){
    fprintf(IRcode, "T1 = %s %s %s", id1, op, id2);
}

void emitAssignment(char * id1, char * id2){
  // This is the temporary approach, until temporary variables management is implemented

  fprintf(IRcode, "T%d = %s\n", getReg(id1), id1);
  fprintf(IRcode, "T%d = %s\n", getReg(id2), id2);
  fprintf(IRcode, "T%d = T%d\n", getReg(id1), getReg(id2));
}

void emitConstantIntAssignment (char id1[50], char id2[50]){
    fprintf(IRcode, "T%d = %s\n", getReg(id1), id2);
}

void emitWriteId(char * id){
    //fprintf (IRcode, "output %s\n", id); // This is the intent... :)

    // This is what needs to be printed, but must manage temporary variables
    // We hardcode T2 for now, but you must implement a mechanism to tell you which one...
    fprintf (IRcode, "output T%d\n", getReg(id));
}