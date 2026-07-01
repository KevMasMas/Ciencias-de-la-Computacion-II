#include <stdio.h>

int sequiencialSearch(int data[],int size, int target){
    for(int i=0; i<size; i++){
        if(data[i] == target)
            return i; //found it
    }

    return -1; //not found    
}

int main(){

    int data[] = {1,4,7,2,3,9,8};
    int size = 7;
    int target = 8;

    printf("El resultado es: %d", sequiencialSearch(data,size ,target));

    return 0;
}

