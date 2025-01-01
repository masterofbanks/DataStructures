#include <iostream>
#include <string> 
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List<int> Int_List;
    
    for(int i = 0; i < 10; i++){
        Int_List.AddTail(i);
    }
    
    Int_List.Print();

    int test[] = {0,1,2,3,4};

    Int_List.AddNodesTail(test, 5);

    Int_List.Print();


    
}