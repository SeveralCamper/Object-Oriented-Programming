
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "../lib/tPoint.h"

int main() {
    Stack stack;
    for (int  i = 0; i < MAX_LIST_SIZE; i++) {
        stack.push(i);
    }
    std::cout << "Stack:" << std::endl;
    stack.print();
    std::cout << "Stack size: " << stack.structSize << std::endl;

    std::cout << std::endl;
    std::cout << "Stack:" << std::endl;
    for (int i = 0; i < stack.structSize; i++) {
        stack.pop();
    }
    stack.print();
    std::cout << "Stack size: " << stack.structSize << std::endl;

    std::cout << std::endl;
    std::cout << "List's count:" << stack.size << std::endl;
    std::cout << std::endl;

    std::cout << "Clear stack:"<< std::endl;
    stack.clear();
    std::cout << "Stack size: "<< stack.structSize << std::endl;
    std::cout << std::endl;

    Queue queue;
    for (int  i = MAX_LIST_SIZE; i > 0; i--) {
        queue.push(i);
    }
    std::cout << "Queue:" << std::endl;
    queue.print();
    std::cout << "Queue size: " << queue.structSize << std::endl;

    std::cout << std::endl;
    std::cout << "Queue:" << std::endl;
    for (int i = 0; i < queue.structSize; i++) {
        queue.pop();
    }
    queue.print();
    std::cout << "Queue size: " << queue.structSize << std::endl;

    std::cout << std::endl;
    std::cout << "List's count:" << stack.size << std::endl;
    std::cout << std::endl;

    std::cout << "Clear queue:"<< std::endl;
    queue.clear();
    std::cout << "Queue size: "<< queue.structSize << std::endl;
    std::cout << std::endl;

    staticVarCheck();
    std::cout << "Count of Lists:" << queue.size << std::endl;
    return 0;
}
