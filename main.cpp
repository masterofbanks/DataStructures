#include <iostream> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List List;
    List.AddHead(2);
    List.AddHead(1);
    List.AddHead(0);
    List.Print();

    return 0;
}