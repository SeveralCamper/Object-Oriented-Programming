#ifndef T_POINT_H_
#define T_POINT_H_

#include <iomanip>
#include <iostream>
#include <climits>
#include <SFML/Graphics.hpp>

#define MAX_LIST_SIZE 10

class List {

public:
    int structSize = 0;
    inline static int size = 0;

    List() : head(new Node(INT_MAX)) {
        size++;
    }

    List(int value) : head(new Node(INT_MAX)) {
        head->next = new Node(value);
        size++;
    }

    ~List() {
        if (head->next) clear();
        delete head;
        --size;
    }

    void push(int value);

    virtual void clear();

    void print();

protected:
    struct Node {
        Node(int value, Node* next) : value(value), next(next) {}
        Node(int value) : value(value), next(nullptr) {}

        int value;

        Node* next;
    }; Node* head;
};

class Queue : public List {
public:
    int pop();
    void clear() override;
};

class Stack : public List {
public:
    int pop();
};

void staticVarCheck();

#endif //  T_POINT_H_