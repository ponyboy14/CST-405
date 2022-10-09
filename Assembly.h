// Set of functions to emit MIPS code
FILE * MIPScode;
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

void  initAssemblyFile(){
    // Creates a MIPS file with a generic header that needs to be in every file

    MIPScode = fopen("MIPScode.asm", "w");
    
    fprintf(MIPScode, ".text\n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "# -----------------------\n");

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
    fprintf(MIPScode, "li $t%d", getOpenReg(id1));
    fprintf(MIPScode, ",%s\n", id2);
}

void emitMIPSWriteId(char * id){
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(MIPScode, "li $a0,%s\n", id);
    fprintf(MIPScode, "li $v0, 1\n");
    fprintf(MIPScode, "move $a0,$t%d\n", getReg(id));
    fprintf(MIPScode, "syscall\n");
    
    
    
}

void emitEndOfAssemblyCode(){
    fprintf(MIPScode, "# -----------------\n");
    fprintf(MIPScode, "#  Done, terminate program.\n\n");
    fprintf(MIPScode, "li $v0,10   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, ".end main\n");
}

