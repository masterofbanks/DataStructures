#include <iostream>
#include <vector>
#include <string> 
#include <random>
#include "Singly_Linked_List.h"

int main(){
    Singly_Linked_List<float> FloatList;
    std::vector<float> vector_floats;
    vector_floats.push_back(24.1f);
    vector_floats.push_back(25.1f);
    vector_floats.push_back(26.1f);
    vector_floats.push_back(27.1f);
    vector_floats.push_back(28.1f);


    FloatList.AddNodesHead(vector_floats);
    FloatList.AddNodesTail(vector_floats);

    FloatList.Print();

    
    
    

    
}