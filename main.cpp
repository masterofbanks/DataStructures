#include <iostream>
#include <string> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List<int> Int_List;
    
    for(int i = 0; i < 10; i++){
        Int_List.AddTail(i);
    }

    Int_List.AddTail(4);
    Int_List.AddTail(4);
    Int_List.AddTail(4);
    Int_List.AddTail(4);
    Int_List.AddTail(4);
    Int_List.AddTail(4);


    std::vector<Singly_Linked_List<int>::Node*> test;

    Int_List.FindAll(test, 4);

    std::cout << test.size() << std::endl;
    

    


    
    

    

    
    
    

    
}