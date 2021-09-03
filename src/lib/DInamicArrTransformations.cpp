#include "DInamicArrTransformations.h"

int* genRandArray(int size, int maxValue)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % maxValue;
    }
    return arr;
}

void printArray(int* arr, int size)
{
    std::cout << size << ": ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int** genRandMatrix(int size, int maxValue)
{
    int** matrix = new int*[size + 1];
    for (int i = 0; i < size + 1; i++) {
        int los = rand() % 10 + 1;
        matrix[i] = new int[los];
        matrix[i][0] = los - 1;
        for (int j = 1; j < los; j++)
            matrix[i][j] = rand() % maxValue;
    }
    return matrix;
}

void printMatrix(int** matrix, int size)
{
    std::cout << size << ": ";
    for (int i = 0; i < size + 1; i++) {
        std::cout << "\n";
        for (int j = 0; j < matrix[i][0]+1; j++) {
            std::cout << std::setw(5) << matrix[i][j];
        }
    }
}
