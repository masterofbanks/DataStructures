#include <iostream>
#include <string> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List<int> Int_List;
    
    for(int i = 0; i < 10; i++){
        Int_List.AddTail(i);
    }
    
    Int_List.Print();

    
    Int_List.RemoveTail();

    Int_List.Print();

    std::cout << Int_List[15] << std::endl;
    
}