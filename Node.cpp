#include "Node.h"


// default constructor
Node::Node(){
    data = 0;
    next = nullptr;
}

/*constructor to create a node 
with a certain data value d*/
Node::Node(int& d){
    data = d;
    next = nullptr;
}

/*constructor to create a node 
with a certain data value d 
and a certain next pointer*/
Node::Node(int &d, Node* n){
    data = d;
    next = n;
}
