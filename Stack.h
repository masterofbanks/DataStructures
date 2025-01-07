#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Singly_Linked_List.h"


template <typename T>
class Stack{
public:
    /* Construction and Destruction */
    Stack();
    Stack(const Stack& stack);
    ~Stack();

    /*Operators*/
    Stack& operator=(const Stack& other);
    bool operator==(const )
    void Swap();

    /*Insertion*/
    void Push();

    /*Deletion*/
    void Pop();
    void Clear();

    /*Getters*/
    bool Empty();
    unsigned int Size();
    T& Top();


private:
    Singly_Linked_List<T>* secretList;


};


#include "Stack.cpp"


#endif