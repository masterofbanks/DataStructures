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

    for(int i = 11; i < 21; i++){
        secondList.AddTail(i);
    }

    firstlist.Print();
    secondList.Print();

    firstlist.Swap(secondList);

    firstlist.Print();
    secondList.Print();


    
}