#include <string.h>

int counter;
int arrayAdd[50];

void reverseArray(char array[], int counter){
    int temp[counter];
    for(int i=0; i<counter;i++){
        temp[counter-i-1]=array[i];
    }
    for(int i=0; i<counter;i++){
        array[i]=temp[i];
    }
}

int stringToInt(int array[]){
    return atoi(array[]);
}

void addArray(char array[]){
    int input=stringToInt(array[]);
    arrayAdd[counter]=input;
    counter++;
}

int calculate(){
    int total = 0;
    reverseArray(arrayAdd,counter)
    for(int i=0; i<counter;i++){
        total=arrayAdd[i];
    }
    return total;
}

void clearAll(){
    for(int i=0; i<counter; i++){
        arrayAdd[i]=0;
    }
    counter=0;
}