#include <math.h>
#include <stdio.h>
#include <string.h>

char OperationList[50];

void reverseOpList()
{
  int indexE=0;
  while(OperationList[indexE]!=(char)69){
    indexE++;
  }
  int loopE=indexE;
  for(int i=0;i<loopE/2;i++){
    indexE--;
    char temp=OperationList[i];
    OperationList[i]=OperationList[indexE];
    OperationList[indexE]=temp;
  }
   
} 

void initialized(){
    int testEnd=0;
    for(int i=0; i<50; i++){
        if(OperationList[i]==(char)69){
            testEnd=1;
        }
    }
    if(testEnd==0){
        int test=69;
        char end=(char)test;
        OperationList[0]=end;
        if(end==(char)69){
        }
    }
}

void insertValues(char id1[]){
    for(int i=0; i<50; i++){

        if(OperationList[i]==(char)69){
            for(int j=0;j<strlen(id1);j++){
                OperationList[i+j]=id1[j];
                OperationList[i+j+1]=(char)69;
                int test=strlen(id1);
              //break;
            }
            break;
            
        }
    }
}

void deleteAll(){
    char str[50];
    str[0]=(char)69;
    strcpy(OperationList, str);
}

int getNumber(){
    char outputNumber[50];
    //printf("GET NUMBER TEST 1: %s\n",OperationList);
    strcpy(outputNumber, "");
  for(int i=0;i<50;i++){ 
    char b=OperationList[i];
    int a=(int)b;
    //printf("GET NUMBER TEST 2: %c %d\n",OperationList[i],i);
    if(a==42||a==43||a==45||a==47||a==94||a==69){
      int j=0;
      while(OperationList[j]!=(char)42&&OperationList[j]!=(char)43&&OperationList[j]!=(char)45&&OperationList[j]!=(char)47&&OperationList[j]!=(char)94&&OperationList[j]!=(char)69){
        strncat(outputNumber, &OperationList[j], 1);
        j++;
        }
        //printf("J'S CHAR: %c\n",OperationList[j]);
      for(int ii=0;ii<j;ii++){
        int k=0;
        while(OperationList[k]!=(char)69){
        //printf("GET NUMBER LOOP 1 %d: %s\n",ii, OperationList);
        OperationList[k]=OperationList[k+1];
        if(OperationList[k]==(char)69&&OperationList[k+1]==(char)69){
          OperationList[k+1]=(char)32;
          break;
        }
        //printf("GET NUMBER LOOP 2: %s\n",OperationList);
        k++;
      }
      }
      int k=0;
      break;
    }
  }
  int output=strtof(outputNumber,0);
  strcpy(outputNumber, "");
  return output;
}

char getOp(){
  char temp=OperationList[0];
  int i=0;
  while(OperationList[i]!=(char)69){
    //printf("GET OP %s\n",OperationList);
    OperationList[i]=OperationList[i+1];
    if(OperationList[i]==(char)69&&OperationList[i+1]==(char)69){
      OperationList[i+1]=(char)32;
      break;
    }
    //printf("GET OP2 %s\n",OperationList);
    i++;
  }
  return temp;
}

void revOpList(){
  char placeholder[50];
  sprintf(placeholder, "");
  while(OperationList[0]!=(char)69){
    int tempNum=getNumber();
    char new[50];
    sprintf(new, "%d", tempNum);
    sprintf(placeholder, "%d%s",tempNum ,placeholder);
    char tempOp=getOp();
    if(tempOp==(char)69){

    }
    else{
      sprintf(placeholder, "%c%s", tempOp,placeholder);
    }
  }
  strcpy(OperationList,placeholder);
  strcpy(placeholder,"");
}


int calculateAll(){
  int OperationDone=1;
  while(OperationDone==1){
    int total=0.0;
    int z =getNumber();
    char op=getOp();
    if(op==(char)69){
      return z;
    }
    int zz=getNumber();
    printf("First Number: %d\n",z); 
    printf("Operation: %c\n",op);
    printf("Second Number: %d\n",zz);
    int testOp=(int)op;
    if(testOp==94){
        total=z;
        for(int i=1;i<zz;i++){
            total=total*z;
        }
        printf("Total: %d\n",total);
      
  }
    if(testOp==42){
      total=total+(z*zz);
      printf("Total: %d\n",total);
  }
    if(testOp==43){
      total=total+(z+zz);
      printf("Total: %d\n",total);
  }
    if(testOp==45){
      total=total+(z-zz);
      printf("Total: %d\n",total);
  }
    if(testOp==47){
      if(zz==0){
        printf("CANNOT DIVIDE NUMBER BY 0\n");
        total=0.0;
      }
      else{
        total=(z/zz);
      }
      printf("Total: %d\n",total);
  }
    if(testOp==94){
      total=z;
      if(zz==0){
        total=1.0;
      }
      for(int pow=1;pow<zz;pow++){
        total=total*z;
      }
      printf("Total: %d\n",total);
  }
    if(OperationList[0]==(char)69){
      printf("The Total Calculated is  %d\n",total);
      OperationDone=0;
      return total;
    }
    char new[60];
    sprintf(new, "%d%s", total,OperationList);
  
    strcpy(OperationList, new);
  }
}

void print_op() {
  
  printf("%s\n", OperationList);
}

void mips_func(char target[50]) {
  int f = 1;
  char lastOp;
  char first[50];
  char id[50];
  int i = 0;
  int start = 0;
  
  while(i < 50) {
    
    // || strcmp(OperationList[i], "-") == 0 || strcmp(OperationList[i], "*") == 0 || strcmp(OperationList[i], "/") == 0
    if (OperationList[i] == '+' || OperationList[i] == 'E') {
      switch ( lastOp ) {
        case '+':
            sprintf(id, "%.*s", i - start, OperationList + start);    
            if (f==1) {
              if (first[0] != '$')
                emitMipsAddi(target, id, first);
              else if ( id[0] != '$') 
                emitMipsAddi(target, first, id);
              else 
                emitMipsAdd(target, first, id);
              f = 0;
            }
            else {
              if ( id[0] != '$') 
                emitMipsSoloAddi(target,id);
              else 
                emitMipsSoloAdd(target, id);
            }
            break;
        case '-':          
            sprintf(id, "%.*s", i - 1 - start, OperationList + start); 
            break;
        case '*':         
            sprintf(id, "%.*s", i - 1 - start, OperationList + start); 
            break;
        case '/':        
            sprintf(id, "%.*s", i - 1 - start, OperationList + start); 
            break;
        default:          
            sprintf(first, "%.*s", i - start, OperationList + start);
            break;
      }
      lastOp = OperationList[i];
      start = i + 1;
      
    }
    if (OperationList[i] == 'E')
      break;
    i++;
  }
}