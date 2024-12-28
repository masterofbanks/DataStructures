#include <iostream> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List List;
    
    for(unsigned int i = 0; i < 10; i++){
        List.AddTail(i);
        List.AddHead(i);
    }
    List.Print();
    std::cout << List.Size() << std::endl;
    return 0;
}