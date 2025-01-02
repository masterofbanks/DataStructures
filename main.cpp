#include <iostream>
#include <string> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List<int> Int_List;
    
    // for(int i = 0; i < 10; i++){
    //     Int_List.AddTail(i);
    // }

    Int_List.AddHead(4);
    Int_List.AddTail(5);
    Int_List.AddTail(4);
    Int_List.AddTail(6);
    Int_List.AddTail(7);
    Int_List.AddTail(4);
    
    
    Int_List.AddTail(10);    
    Int_List.AddTail(19);  

    Int_List.AddTail(4);
    Int_List.AddTail(4);
    Int_List.AddTail(4);
    Int_List.AddTail(4);
    Int_List.AddTail(4);
    Int_List.AddTail(4);
    

    

    
    
    Int_List.Print();

    std::cout << Int_List.Remove(4) << std::endl;

    Int_List.Print();
}