#include <iostream> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List List;
    
    for(int i = 0; i < 10; i++){
        List.AddTail(i);
    }
    
    List.Print();

    

    List.RemoveHead();
    List.Print();
}