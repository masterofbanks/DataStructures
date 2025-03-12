#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Singly_Linked_List.h"


template <typename T>
class Stack{
public:
    
    Stack(){
        secretList = new Singly_Linked_List<T>();
    }
    
    ~Stack(){
        delete(secretList);
    }

    

    void Print(){
        typename Singly_Linked_List<T>::Node* temp = secretList->Head();
        std::cout << "\n--------------" << std::endl;
        while(temp != nullptr){
            if(temp == secretList->Head()){
                std::cout << temp->data << "  <- top " << std::endl;
            }
            else{
                std::cout << temp->data << std::endl;
    
            }
            temp = temp->next;
        }
        std::cout << "--------------" << std::endl;
        std::cout << "Size: " << Size() << "\n" << std::endl;  
    }

    
    void Push(T d){
        secretList->AddHead(d);
    }

    
    void Pop(){
        if(!Empty()){
            secretList->RemoveHead();
    
        }
    
        else{
            std::cout << "Stack is Empty!" << std::endl;
        }
    }
    void Clear(){
        if(!Empty()){
            secretList->Clear();
    
        }
    }

    
    bool Empty(){
        return secretList->Size() == 0;
    }
    unsigned int Size(){
        return secretList->Size();
    }
    T& Top(){
        return secretList->Head()->data;
    }


private:
    Singly_Linked_List<T>* secretList;


};




#endif