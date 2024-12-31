#include <iostream>
#include <string> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List<int> Int_List;
    
    for(int i = 0; i < 10; i++){
        Int_List.AddTail(i);
    }
    
    Int_List.Print();

    Singly_Linked_List<std::string> String_List;

    String_List.AddTail("Hello");
    String_List.AddTail("World");

    String_List.Print();

    String_List.InsertAfter("Third Element", 1);
    String_List.Print();
}