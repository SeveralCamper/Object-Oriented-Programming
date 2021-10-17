#include "tPoint.h"

void List::push(int value) {
        if (!head->next) {
            head->next = new Node(value);
            structSize++;
        } else {
            Node* tmp = head->next;
            while (tmp->next) tmp = tmp->next;
            tmp->next = new Node(value);
            structSize++;
    }
}

void List::clear() {
    try {
        if (!head->next) {
            throw "List is empty!";
        }
        Node* tmp, * tmpHead = head;
        tmp = head->next;
        while (tmp) {
            tmpHead = tmp;
            tmp = tmp->next;
            delete(tmpHead);
            structSize--;
            tmpHead = nullptr;
        }
        head->next = nullptr;
    }
    catch (const char* exception) {
        std::cerr << "ERROR:" << exception << std::endl;
    }
}

void Queue::clear() {
    try {
        if (!head->next) {
            throw "List is empty!";
        }
        Node* tmp, * tmpHead = head;
        tmp = head->next;
        while (tmp) {
            tmpHead = tmp;
            tmp = tmp->next;
            delete(tmpHead);
            structSize--;
            tmpHead = nullptr;
        }
        head->next = nullptr;
    }
    catch (const char* exception) {
        std::cerr << "ERROR:" << exception << std::endl;
    }
}

void List::print() {
    int curSize = 0;
    try {
        if (!head->next) {
            throw "List is empty!";
        }
        Node* tmp = head->next;
        while (tmp) {
            if (curSize + 1 == structSize) {
                std::cout << '[' << tmp->value << "]->NULL\n";
            } else {
                std::cout << '[' << tmp->value << "]->";
            }
            curSize++;
            tmp = tmp->next;
        }
    }
    catch (const char* exception) {
        std::cerr << "ERROR:" << exception << std::endl;
    }
}

int Queue::pop() {
    try {
        if (!head->next) {
            throw "List is empty!";
        }
        Node* tmp = head->next;
        head->next = tmp->next;
        int c = tmp->value;
        delete(tmp);
        tmp = nullptr;
        structSize--;
        return c;
    }
    catch (const char* exception) {
        std::cerr << "ERROR:" << exception << std::endl;
    }
    return 0;
}

int Stack::pop() {
    try {
        if (!head->next) {
            throw "List is empty!";
        }
        Node* tmp = head;
        while (tmp->next->next) tmp = tmp->next;
        int c = tmp->next->value;
        delete(tmp->next);
        tmp->next = nullptr;
        structSize--;
        return c;
    }
    catch (const char* exception) {
        std::cerr << "ERROR:" << exception << std::endl;
    }
    return 0;
}

void staticVarCheck() {
    List oneList;
    Stack twoStack;
    Queue twoQueue;
    List twoList;
    Stack thirdStack;
    std::cout << "Count of Lists:" << thirdStack.size << std::endl;
    return;
}
