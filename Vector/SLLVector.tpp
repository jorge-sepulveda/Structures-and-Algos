#include "SLLVector.h"


//Default Constructor
template <class T>
SLLVector<T>::SLLVector(void){
    front = NULL;
    rear = NULL;
    count = 0;
    //capacity = 0;
    std::cout << "made the linked list queue!" << std::endl;
}

/*//Enqueue function
template <class T>
void SLLVector<T>::enqueue(const T& e){
    Node * elem = new Node;
    elem->item = e;
    elem->next = NULL;
    count+=1;
    if (front==NULL){
        front = elem;
    }
    else{
        rear->next=elem;
    }
    rear = elem;
    //std::cout << "added the item into the LL" << std::endl;
}

//dequeue function
template <class T>
T SLLVector<T>::dequeue(){
    
    if( empty() ){
        throw VectorException ("VectorException: Empty Stack");
    }
    
    else{
        Node* tempPointer = front;
        T tempItem = tempPointer->item;
        //std::cout << "removed " << tempPointer->item << " from the queue" << std::endl;
        front = front->next;
        free(tempPointer);
        count-=1;
        return tempItem;
    }
}
    

//returns the item in front of the queue
template <class T>
T SLLVector<T>::frontelem(){
    return front->item;
}
    
//Checking to see if Queue is empty
template <class T>
bool SLLVector<T>::empty(){
    if (count == 0) {
        //std::cout << "empty!" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

template <class T>
int SLLVector<T>::size(){
    if (empty()){
        throw VectorException ("VectorException: Empty Stack");
    }
    return count;
}
*/


//destructor
template <class T>
SLLVector<T>::~SLLVector(){
    Node* current = front;
    Node* next;
    
    while (current != NULL){
    next = current->next; 
       free(current); 
       current = next; 
       
    }
    front = NULL;
    std::cout << "Linked List Vector Destroyed" << std::endl;
}