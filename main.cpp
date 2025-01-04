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


    Int_List.Print();
    
    Int_List.RemoveAt(0);

    Int_List.Print();

    Int_List.RemoveAt(14);

    Int_List.Print();

    Int_List.RemoveAt(7);


    Int_List.Print();

    Int_List.RemoveAt(30);
    

    Int_List.Print();
    
    

    

    
    
    

    
}