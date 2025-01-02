#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <vector>

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

    /* Construction and Destruction */
    Singly_Linked_List(); //default constructor
    Singly_Linked_List(const Singly_Linked_List& copy); //copy constructor
    ~Singly_Linked_List(); //destructor

    /*Operators*/
    Singly_Linked_List& operator=(const Singly_Linked_List& fuck);
    T& operator[](unsigned int index);
    bool operator==(const Singly_Linked_List<T>& rhs) const;
    //void Sort();

    /*Insertion */
    void AddHead(T d);
    void AddTail(T d);
    void InsertAfter(T d, unsigned int index);
    void AddNodesHead(const T* data, unsigned int count);
    void AddNodesTail(const T* data, unsigned int count);
    void InsertAt(T d, unsigned int index);


    /* Deletion*/


    void RemoveHead();
    void RemoveTail();
    void Clear();
    int Remove(T d);
    //bool RemoveAt(unsigned int index);

    /*Getters*/
    Node* Find(T d);
    void FindAll(std::vector<Node*>& outData, T d);  
    Node* GetNode(unsigned int index);
    void Print();
    Node* Head();
    Node* Tail();
    int Size();


private:
    Node* head;
    Node* tail;
    int size;
};

#include "Singly_Linked_List.cpp"


#endif