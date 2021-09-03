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

int** genRandMatrix(int size, int maxValue, int cols)
{
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % maxValue;
        }
    }
    return matrix;
}

void printMatrix(int** matrix, int size, int cols)
{
    std::cout << size << ": ";
    for (int i = 0; i < size; i++) {
        std::cout << "\n";
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(5) << matrix[i][j];
        }
    }
}
