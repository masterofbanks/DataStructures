#include <iostream>
#include "Singly_Linked_List.h"

//default constructor
//set both thte head and tail to null
//set size to 0
Singly_Linked_List::Singly_Linked_List(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Singly_Linked_List::Singly_Linked_List(const Singly_Linked_List& copy){

// }

//Destructor method that frees all the memory allocated for a Linked List
Singly_Linked_List::~Singly_Linked_List()
{
    Clear();

}

// Singly_Linked_List &Singly_Linked_List::operator=(const Singly_Linked_List &copy)
// {
    

// }

//get the size of the linked list
int Singly_Linked_List::Size(){
    return size;
}



// add a new node to the linked list
// make this node the new head
void Singly_Linked_List::AddHead(int d){
    //if the list is empty, make the head and tail the new node
    if(size == 0){
        head = new Node(d);
        tail = head;
        tail->next = nullptr;
    }
    //if the list has one element, make the old head the tail and the new head the head
    else if(size == 1){
        Node* old = head;
        head = new Node(d);
        head->next = old;
    }

    
    // else make a new node with d as its value 
    else{
        Node* construct = new Node(d);
        //save the old head in a temporary Node
        Node* old = head;
        //make the head pointer point to the new node
        head = construct;
        //make the head's next pointer point to the old head
        head->next = old;
    }

    //incrament size by one
    size++;
        
}

//add a new node to the tail of the linked list
void Singly_Linked_List::AddTail(int d){
    //if the list is empty make a new node the head and tail
    if(size == 0){
        tail = new Node(d);
        head = tail;
    }
    //if the list has one element, make the new node the tail and keep the old head as the head
    // also make the head's next pointer the new tail and the new tail's next pointer nullptr
    else if(size == 1){
        tail = new Node(d);
        head->next = tail;
    }
    //else just make a new node the tail and the old tail's next pointer the new node
    else{
        Node* temp = tail;
        tail = new Node(d);
        temp->next = tail;
    }

    //incrament size by 1
    size++;
}

//inserts a node with a data value d after the node at index d
void Singly_Linked_List::InsertAfter(int d, unsigned int index){
    //if the index is greater than the size of the SLL, seg faults will occur
    // throw an exception in this case
    try{
        if(index < size){
            
            //if the index == size -1, just call AddTail
            if(index == size-1){
                AddTail(d);
            }
            
            //else, go to the node at the index,
            else{
                Node* indexedNode = GetNode(index);
                //create a new Node with data value d
                Node* newNode = new Node(d);
                //save the indexed node's next pointer in a temp variable
                Node* temp = indexedNode->next;
                //set the indexed node's next pointer to the new Node
                indexedNode->next = newNode;
                //set the new Node's next pointer to the temp variable
                newNode->next = temp;
                //incrament the size of the List by 1
                size++;
            }
                
        }


        else{
            throw(index);
        }
    }

    catch (int number){
        std::cout << "Index is out of the range of the Linked List" << std::endl;
    }
}

//gets a node at an index of a Linked list
Node* Singly_Linked_List::GetNode(unsigned int index){
    try{
        if(index < size){
            int currentIndex = 0;
            Node* indexedNode = head;
            while(currentIndex != index){
                indexedNode = indexedNode->next;
                currentIndex++;
            }

            return indexedNode;

        }

        else{
            throw(index);
        }
        
    }

    catch(int number){
        std::cout << "Index is out of the range of the Linked List" << std::endl;
        
    }
     
    return nullptr;
    
}

//prints the list via a while loop 
// in the form {1, 2, 3, ...}
void Singly_Linked_List::Print(){
    if(size == 0){
        std::cout << "{}" << std::endl;
    }

    else if(size == 1){
        std::cout << "{" << head->data << "}" << std::endl;
    }

    else{
        //print start bracket
        std::cout << "{";
        //start at the head usinbg a temp Node
        Node* temp = head;
        //print out the value at each node and contrinue to the next node
        //until you reach the tail
        while(temp!=tail){
            std::cout << temp->data << ", ";
            temp = temp->next;
        } 

        //print the tail data plus end bracket
        std::cout << tail->data << "}" << std::endl;
    }
    


}
Node* Singly_Linked_List::Head(){
    return head;
}
Node* Singly_Linked_List::Tail(){
    return tail;
}

void Singly_Linked_List::Clear(){
    //create an indexed Node at the head and a garbage node set to nullptr
    Node* indexedNode = head;
    Node* temp = nullptr;
    //while the indexed Node isnt nullptr
    while(indexedNode != nullptr){
        //set garb to the indexed pointer
        temp = indexedNode->next;
        //incrament the indexed Node
        //delete garb
        delete(indexedNode);
        indexedNode = temp;

    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}


