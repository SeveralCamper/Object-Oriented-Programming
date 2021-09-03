#include <iostream>
#include <DInamicArrTransformations.h>

int main ()
{   	
    int size = rand()%10;
    int maxValue = 100;
    int *arr = genRandArray(size, maxValue);
    printArray(arr, size);
    delete [] arr; 
}
