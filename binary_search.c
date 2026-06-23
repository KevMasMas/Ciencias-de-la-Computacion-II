#include <stdio.h>

int binarySearch(int sortedData[], int size, int target){
    int lower = 0;
    int upper = size - 1;

    while(lower <= upper){
        int middle = (int)((lower + upper) / 2);
        if(sortedData[middle] == target)
            return middle; //found it

        if(target < sortedData[middle]) // discart higher half
            upper = middle - 1;
        else
            lower = middle + 1;
    }
    return -1; //not found
}

int main(){

    int data[] = {1,2,10,22,54,102};
    int size = 7;
    int target = 54;

    printf("El resultado es: %d", binarySearch(data,size ,target));

    return 0;
}



