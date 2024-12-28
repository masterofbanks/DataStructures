#include <iostream> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List List;
    
    List.AddHead(0);
    List.AddTail(2);
    List.InsertAfter(1, 1);

    List.Print();
    std::cout << List.Size() << std::endl;

    List.Clear();
    
    List.Print();
    std::cout << List.Size() << std::endl;

    List.AddHead(0);
    
    List.Print();
    std::cout << List.Size() << std::endl;
    return 0;
}