#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <vector>

template <typename T>
class Singly_Linked_List{

public:
    struct Node{
    
        T data;  
        Node* next;  

        Node(){
            data = 0;
            next = nullptr;

        } 
            
            
        

        Node(T& d){
            data = d;
            next = nullptr;
        }  
        Node(T& d, Node* n){
            data = d;
            next = n; 
        }  
    
    };
    
    Singly_Linked_List(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }  
    Singly_Linked_List(const Singly_Linked_List& other)  {
        if(other.size == 0){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
    
        else if(other.size == 1){
            head = new Node(other.head->data);
            tail = head;
            size = 1;
        }
    
        else{
            head = new Node(other.head->data);
            Node* currentDummy = head;
    
            Node* otherTemp = other.head->next;
    
            while(otherTemp != nullptr){
                
                currentDummy->next = new Node(otherTemp->data);
                currentDummy = currentDummy->next;
                otherTemp = otherTemp->next;
            }
    
            currentDummy->next = nullptr;
            tail = currentDummy;
            size = other.size;
        }
    }
    ~Singly_Linked_List()  {
        Clear();
    }

    /*Operators*/
    Singly_Linked_List& operator=(const Singly_Linked_List<T>& other) {
        Clear();
        if(other.size == 0){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        else if(other.size == 1){
            head = new Node(other.head->data);
            tail = head;
            size = 1;
        }

        else{
            head = new Node(other.head->data);
            Node* currentDummy = head;

            Node* otherTemp = other.head->next;

            while(otherTemp != nullptr){
                
                currentDummy->next = new Node(otherTemp->data);
                currentDummy = currentDummy->next;
                otherTemp = otherTemp->next;
            }

            currentDummy->next = nullptr;
            tail = currentDummy;
            size = other.size;
        }

        return *this; 
    }
    T& operator[](unsigned int index){
        Node* nthNode = GetNode(index);
        return nthNode->data;
    }
    bool operator==(const Singly_Linked_List<T>& rhs) const {
        //if the two sizes are different->return false
        if(rhs.size != size){
            return false;
        }
    
        //if both linked_lists are empty, return true
        if(rhs.head == nullptr && head == nullptr){
            return true;
        }
    
        Node* temp = head;
        Node* rhsTemp = rhs.head;
    
        while(temp != nullptr){
            if(temp->data != rhsTemp->data){
                return false;
            }
    
            temp = temp->next;
            rhsTemp = rhsTemp->next;
        }
    
        return true;
    }
    void Sort() {
        MergeSort(0, Size() - 1);
    }
    void Swap(Singly_Linked_List<T>& other) {
        Node* tempHead = head;
        Node* tempTail = tail;
        int tempSize = size;
        head = other.head;
        tail = other.tail;
        size = other.size;
        other.head = tempHead;
        other.tail = tempTail;
        other.size = tempSize;
    }
    // << operator for linkedlist of linkedlists printing

    /*Insertion */
    void AddHead(T d) {
        //if the list is empty, make the head and tail the new node
        if(size == 0){
            head = new Node(d);
            tail = head;
            tail->next = nullptr;
        }
        //if the list has one element, make the old head the tail and the new head the head
        else if(size == 1){
            Node* old = head;
            head = new Node(d);
            head->next = old;
        }
    
        
        // else make a new node with d as its value 
        else{
            Node* construct = new Node(d);
            //save the old head in a temporary Node
            Node* old = head;
            //make the head pointer point to the new node
            head = construct;
            //make the head's next pointer point to the old head
            head->next = old;
        }
    
        //incrament size by one
        size++;    
    }
    void AddTail(T d) {
        //if the list is empty make a new node the head and tail
        if(size == 0){
            tail = new Node(d);
            head = tail;
        }
        //if the list has one element, make the new node the tail and keep the old head as the head
        // also make the head's next pointer the new tail and the new tail's next pointer nullptr
        else if(size == 1){
            tail = new Node(d);
            head->next = tail;
        }
        //else just make a new node the tail and the old tail's next pointer the new node
        else{
            Node* temp = tail;
            tail = new Node(d);
            temp->next = tail;
        }
    
        //incrament size by 1
        size++;
    }
    void InsertAfter(T d, unsigned int index) {
        try{
            //if the index == size -1, just call AddTail
            if(index == size-1){
                AddTail(d);
            }
            
            //else, go to the node at the index,
            else{
                Node* indexedNode = GetNode(index);
                //create a new Node with data value d
                Node* newNode = new Node(d);
                //save the indexed node's next pointer in a temp variable
                Node* temp = indexedNode->next;
                //set the indexed node's next pointer to the new Node
                indexedNode->next = newNode;
                //set the new Node's next pointer to the temp variable
                newNode->next = temp;
                //incrament the size of the List by 1
                size++;
            }
        }
    
        catch(const std::out_of_range& e){
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    void AddNodesHead(const T* data, unsigned int count) {
        for(int i = count-1; i >=0; i--){
            AddHead(*(data+i));
    
        }
    }
    void AddNodesHead(std::vector<T>& input) {
        for(int i = 0; i < input.size(); i++){
            if(i == 0){
                AddHead(input[i]);
            }
    
            else{
                InsertAt(input[i], i);
            }
        }
    }
    void AddNodesTail(const T* data, unsigned int count) {
        for(int i = 0; i < count; i++){
            AddTail(*(data+i));
    
        }
    }
    void AddNodesTail(std::vector<T>& input) {
        for(int i = 0; i < input.size(); i++){
            AddTail(input[i]);
        }
    }
    void InsertAt(T d, unsigned int index) {
        try{
            if(index == size){
                AddTail(d);
            }
    
            else if(index == 0){
                AddHead(d);
            }
    
            else if(index > size){
                throw std::out_of_range("index is out of the range of the size of the list");
    
            }
    
            else{
                InsertAfter(d, index-1);
            }
        }
    
        catch(const std::out_of_range& e){
            std::cerr << "Error: " << e.what() << std::endl;
        }   
    }


    /* Deletion*/
    void RemoveHead() {
        //if size is 0 -> print List is empty
        if(size == 0){
            std::cout << "List is Empty! Can't Remove Anything" << std::endl;
        }
        //if the size is 1 -> make head and tail nullptr and decrement size by 1
        else if(size == 1){
            head = nullptr;
            tail = nullptr;
            size--;
        }
        //else 
        else{
            //save the head in a temporary pointer called garb
            Node* garb = head;
            //set head to head->next
            head = head->next;
            //delete garb
            delete(garb);
            //decrement size by 1
            size--;
        }   
    }
    void RemoveTail() {
        //if size is 0 -> print List is empty
        if(size == 0){
            std::cout << "List is Empty! Can't Remove Anything" << std::endl;
        }
        //if the size is 1 -> make head and tail nullptr and decrement size by 1
        else if(size == 1){
            head = nullptr;
            tail = nullptr;
            size--;
        }
    
        else{
            //create a temp node that points to the head
            Node* temp = head;
            //iterate that temp node until the node just before the tail 
            while(temp != nullptr)
            {
                if(temp->next->next == nullptr){
                    break;
                }
    
                temp = temp->next;
            }
    
            //save the old tail in another Node
            Node* oldTail = tail;
            //make tail point to temp
            tail = temp;
            //make tail->next nullptr
            tail->next = nullptr;
            //delete old tail
            delete oldTail;
            //decrement size
            size--;
        }
    }
    void Clear() {
        //create an indexed Node at the head and a garbage node set to nullptr
        Node* indexedNode = head;
        Node* temp = nullptr;
        //while the indexed Node isnt nullptr
        while(indexedNode != nullptr){
            //set garb to the indexed pointer
            temp = indexedNode->next;
            //incrament the indexed Node
            //delete garb
            delete(indexedNode);
            indexedNode = temp;
    
        }
    
        head = nullptr;
        tail = nullptr;
        size = 0;   
    }
    int Remove(T d) {
        if(head == nullptr){
            return 0;
        }
        int numNodesDeleted = 0;
        Node* current = head;
        Node* prev = nullptr;
    
        
        while(current->data == d){
            
            RemoveHead();
    
            current = head;
            if(current == nullptr){
                return numNodesDeleted+1;
            }
            numNodesDeleted++;
        }
    
    
        current = head->next;
        prev = head;
        int index = 0;
        Node* garb = nullptr;
        while(current != nullptr){
            index++;
    
            if(current->data == d){
                if(tail->data == d && index==size-1){
                    garb = tail;
                    tail = prev;
                    tail->next = nullptr;
                    delete(garb);
                    numNodesDeleted++;
                    size--;
                    break;
                }
                prev->next = current->next;
                garb = current;
                current = current->next;
                
                delete(garb);
                numNodesDeleted++;
                size--;
                index--;
                
            }
    
            else{
                prev = current;
                current = current->next;
            }
    
    
        }
    
    
        return numNodesDeleted;   
    }
    bool RemoveAt(unsigned int index) {
        if(head == nullptr){
            return false;
        }
    
        if(index == 0){
            RemoveHead();
            return true;
        }
    
        try{
            if(index >= size){
                throw std::out_of_range("index out of range of the size of the list");
            }
    
            else if(index == size - 1){
                RemoveTail();
                return true;
            }
    
            else{
                int i = 0;
                Node* current = head;
                Node* prev = nullptr;
                while(i != index){
                    prev = current;
                    current = current->next;
                    i++;
                }
    
                Node* garb = current;
                prev->next = current->next;
                delete(garb);
                size--;
                return true;
            }
        }
    
        catch(const std::out_of_range& e){
            std::cerr << "Error: " << e.what() << std::endl;
        }
    
        return false;
    }

    /*Getters*/
    Node* Find(T d) {
        if(head == nullptr){
            return nullptr;
        }
        
        Node* current = head;
    
        while(current != nullptr){
            if(current->data == d){
                return current;
            }
    
            current = current->next;
        }
    
        return nullptr;
    }
    void FindAll(std::vector<Node*>& outData, T d)  {
        if(head == nullptr){
            return;
        }
    
        Node* current = head;
        while(current != nullptr){
            if(current->data == d){
                outData.push_back(current);
            }
    
            current = current->next;
        }
    } 
    Node* GetNode(unsigned int index) {
        
    
        if(index < size){
            int currentIndex = 0;
            Node* indexedNode = head;
            while(currentIndex != index){
                indexedNode = indexedNode->next;
                currentIndex++;
            }
    
            return indexedNode;
    
        }
    
        else{
            throw std::out_of_range(std::to_string(index) +  " is out of range of the Linked List with size " + std::to_string(size));;
        }
    
        
         
        return nullptr;
    }
    void Print() {
        if(size == 0){
            std::cout << "{}" << std::endl;
        }
    
        else if(size == 1){
            std::cout << "{" << head->data << "}" << std::endl;
        }
    
        else{
            //print start bracket
            std::cout << "{";
            //start at the head usinbg a temp Node
            Node* temp = head;
            //print out the value at each node and contrinue to the next node
            //until you reach the tail
            while(temp!=tail){
                std::cout << temp->data << ", ";
                temp = temp->next;
            } 
    
            //print the tail data plus end bracket
            std::cout << tail->data << "}" << std::endl;
        }
    
        std::cout << "Size: " << size << std::endl;
        
    }
    Node* Head() {
        return head;

    }
    
    Node* Tail() {
        return tail;
    }
    int Size(){
        return size;
    } 
    

private:
    Node* head;
    Node* tail;
    int size;

    void Merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        Singly_Linked_List<T> L;
        Singly_Linked_List<T> R;
        for(int i = 0; i < n1; i++){
            L.AddTail(GetNode(left + i)->data);
        }

        for(int j = 0; j < n2; j++){
            R.AddTail(GetNode(mid + 1 + j)->data);
        }

        int i = 0, j = 0;
        int k = left;

        
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                GetNode(k)->data = L[i];
                i++;
            }

            else{
                GetNode(k)->data = R[j];
                j++;
            }

            k++;
        }

        while(i < n1){
            GetNode(k)->data = L[i];
            i++;
            k++;
        }

        while(j < n2){
            GetNode(k)->data = R[j];
            j++;
            k++;
        }
    }
    void MergeSort(int left, int right) {
        if(left >= right){
            return;
        }
    
        int mid = left + (right - left) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }

    

};



#endif