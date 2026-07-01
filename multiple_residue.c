

#include <stdio.h>

#define SLOTS 5
#define OPTION 2

int memory[SLOTS];

void init(){
    for(int i=0; i < SLOTS; i++){
        memory[i] = -1;
    }
}

void residue_store(int values[], int size){
    for(int i = 0; i < size; i++){
        int slot1 = values[i] % SLOTS;
        int slot2 = values[i] % OPTION;
        if( memory[slot1] == -1 )
            memory[slot1] = values[i];
        else if(memory[slot2] == -1)
            memory[slot2] = values[i];
        else
            printf("COLISION");
    }
}

void printMemory(){
    for (int i = 0; i < SLOTS; i++){
        printf("Slot: %d -> %d\t", i, memory[i]);
    }
    
}


int main(){
    int test[] = {12, 27, 42};
    int sizeExample = 3;
    init();
    residue_store(test, sizeExample);
    printMemory();
    return 0;
}