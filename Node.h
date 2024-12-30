#ifndef NODE_H
#define NODE_H


#include <iostream>

struct Node{
    
    int data; //data that this node holds
    Node* next; //pointer to the next node

    Node(); // default constructor
    Node(int& d); //constructor to create a node with a certain data value d
    Node(int& d, Node* n); //constructor to create a node with a certain data value d and a certain next pointer n
};

#endif