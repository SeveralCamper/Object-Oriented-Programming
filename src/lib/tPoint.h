#ifndef T_POINT_H_
#define T_POINT_H_

#include <iomanip>
#include <iostream>
#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>

template <typename T>
class List {

public:
    template <typename T>
    List() : head(NULL) {};

    template<typename T>
    ~List() {
    while(head) {
        remove();
        }
    };

    bool equals(const List& other, Node* node) const;
    bool notEquals(const List& other, Node* node) const;

    void removeNode();
    void printNodeValue();
    void moveToNextNode(Node* node);
    void appendNode(const T& nodeValueAdress);

    List end() const;
    List begin() const;

    size_t getSize() const;

    T getHead() const;
    T getValueNode(Node* node) const;

protected:
    
    struct Node {
        Node() : next(NULL) {}
        Node(const T& nodeValueAdress) : nodeValue(nodeValueAdress), next(NULL) {}

        T nodeValue;

        Node* next;
    };
    Node* head;
};

template <typename T>
class Steck : public List {
    
};

template <typename T>
class Que : public List {

};


#endif //  T_POINT_H_