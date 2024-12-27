#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include "Node.h"
class Singly_Linked_List{
private:
    Node* head;
    Node* tail;
    int size;
public:
    Singly_Linked_List(); //default constructor
    //Singly_Linked_List(const Singly_Linked_List& copy); //copy constructor
    //~Singly_Linked_List(); //destructor

    void AddHead(int d);
    void Print();
    Node* Head();
    Node* Tail();
    int Size();
};

#endif