#ifndef GEN_RAND_ARRAY_H_
#define GEN_RAND_ARRAY_H_

#include <iomanip>
#include <iostream>

int* genRandArray(int size, int maxValue);

void printArray(int* arr, int size);

int** genRandMatrix(int size, int maxValue);

void printMatrix(int** matrix, int size);

#endif //  GEN_RAND_ARRAY_H_
