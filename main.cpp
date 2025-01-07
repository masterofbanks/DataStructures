#include <iostream>
#include <string> 
#include <random>
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List<int> Int_List;
    int rand = 0;
    for(int i = 0; i < 20; i++){
        rand = std::rand() % 100 + 1;
        Int_List.AddTail(rand);
    }

    


    Int_List.Print();

    Int_List.Sort();

    Int_List.Print();
    


    

    
    
    

    
}