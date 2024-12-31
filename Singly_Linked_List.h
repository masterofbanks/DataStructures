#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

template <typename T>
class Singly_Linked_List{

public:
    struct Node{
    
        T data; //data that this node holds
        Node* next; //pointer to the next node

        Node(); // default constructor
        Node(T& d); //constructor to create a node with a certain data value d
        Node(T& d, Node* n); //constructor to create a node with a certain data value d and a certain next pointer n
    };

    Singly_Linked_List(); //default constructor
    //Singly_Linked_List(const Singly_Linked_List& copy); //copy constructor
    ~Singly_Linked_List(); //destructor
    //Singly_Linked_List& operator=(const Singly_Linked_List& copy);
    void AddHead(T d);
    void AddTail(T d);
    void InsertAfter(T d, unsigned int index);

    void RemoveHead();

    Node* GetNode(unsigned int index);
    void Print();
    Node* Head();
    Node* Tail();

    int Size();

    void Clear();

private:
    Node* head;
    Node* tail;
    int size;
};

#include "Singly_Linked_List.cpp"


#endif