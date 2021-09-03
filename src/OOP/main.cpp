#include <DInamicArrTransformations.h>
#include <iostream>

int main()
{
    std::cout << "First ex. - Dinamic Array\n";
    int size = rand() % 10;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    printArray(arr, size);
    delete[] arr;
    std::cout << "\n";

    std::cout << "Second ex. - Dinamic Matrix\n";
    size = rand() % 10 + 1;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix, size);
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
}
