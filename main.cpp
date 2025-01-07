#include <iostream>
#include <vector>
#include <string> 
#include <random>
#include "Stack.h"

int main(){
    
    Stack<int> test;
    test.Push(4);
    test.Push(45);
    test.Push(47);
    test.Push(48);
    test.Push(41);
    test.Push(42);

    test.Print();

    test.Pop();
    test.Pop();

    test.Print();
    
    test.Clear();

    test.Pop();

    test.Print();


    
}