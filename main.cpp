#include <iostream>
#include <vector>
#include <string> 
#include <random>
#include "Stack.h"

int main(){
    
    Singly_Linked_List<int> firstlist;

    for(int i = 0; i < 10; i++){
        firstlist.AddTail(i);
    }

    Singly_Linked_List<int> secondList;

    

    firstlist.Print();
    secondList.Print();

    firstlist.Swap(secondList);

    firstlist.Print();
    secondList.Print();


    
}