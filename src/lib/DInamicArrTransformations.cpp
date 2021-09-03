#include "DInamicArrTransformations.h"

int *genRandArray(int size, int maxValue){
    int *arr = new int[size];
    for (int i = 0; i < size; i++){
        arr[i] =rand()%maxValue;
    }
    return arr;
}

void printArray(int *arr, int size){
    std::cout << size << ": ";
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

