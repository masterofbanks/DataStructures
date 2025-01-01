#include <iostream>
#include <string> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List<int> Int_List;
    
    for(int i = 0; i < 10; i++){
        Int_List.AddTail(i);
    }
    
    Int_List.Print();

    
    Singly_Linked_List<int> copy;

    copy = Singly_Linked_List<int>(Int_List);

    copy.Print();
}