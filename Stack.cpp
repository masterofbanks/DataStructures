#include <iostream>
#include "Stack.h"

//default constructor
template <typename T>
Stack<T>::Stack(){
    secretList = new Singly_Linked_List<T>();
}

template <typename T>
Stack<T>::~Stack(){
    delete(secretList);
}

template <typename T>
void Stack<T>::Print(){
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

//pushes a new value to the top of the stack
template <typename T>
void Stack<T>::Push(T d){
    secretList->AddHead(d);
}

//remove the value at the top of the stack
template <typename T>
void Stack<T>::Pop(){
    if(!Empty()){
        secretList->RemoveHead();

    }

    else{
        std::cout << "Stack is Empty!" << std::endl;
    }
}

//remove every value in the stack
template <typename T>
void Stack<T>::Clear(){
    if(!Empty()){
        secretList->Clear();

    }
}


template <typename T>
bool Stack<T>::Empty(){
    return secretList->Size() == 0;
}

template <typename T>
unsigned int Stack<T>::Size(){
    return secretList->Size();
}


template <typename T>
T& Stack<T>::Top(){
    return secretList->Head()->data;
}







