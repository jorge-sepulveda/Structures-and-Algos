#ifndef _LINKEDLISTQUEUE_H
#define _LINKEDLISTQUEUE_H

#include "Queue.h"


#include <iostream>

template <class Type>
class LinkedListQueue : public AbstractQueue<Type>{
    private:
        struct Node{
            Type item;
            Node *next;
        };
        Node* front;
        Node* rear;
        int count;
    public:
    
       LinkedListQueue(void);
       
       ~LinkedListQueue();
       
       bool empty();
    
       int size();
    
       Type frontelem(); //throw(exception) {}
    
       Type dequeue(); //throw(exception) {}
       
       void enqueue ( const Type& e );
       
};

//Default Constructor
template <class Type>
LinkedListQueue<Type>::LinkedListQueue(void){
    front = NULL;
    rear = NULL;
    count = 0;
    //capacity = 0;
    //std::cout << "made the linked list queue!" << std::endl;
}

//Enqueue function
template <class Type>
void LinkedListQueue<Type>::enqueue(const Type& e){
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
template <class Type>
Type LinkedListQueue<Type>::dequeue(){
    
    if( empty() ){
        throw StackException ("StackException: Empty Stack");
    }
    
    else{
        Node* tempPointer = front;
        Type tempItem = tempPointer->item;
        //std::cout << "removed " << tempPointer->item << " from the queue" << std::endl;
        front = front->next;
        free(tempPointer);
        count-=1;
        return tempItem;
    }
}
    

//returns the item in front of the queue
template <class Type>
Type LinkedListQueue<Type>::frontelem(){
    return front->item;
}
    
//Checking to see if Queue is empty
template <class Type>
bool LinkedListQueue<Type>::empty(){
    if (count == 0) {
        //std::cout << "empty!" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

template <class Type>
int LinkedListQueue<Type>::size(){
    if (empty()){
        throw StackException ("StackException: Empty Stack");
    }
    return count;
}



//destructor
template <class Type>
LinkedListQueue<Type>::~LinkedListQueue(){
    Node* current = front;
    Node* next;
    
    while (current != NULL){
    next = current->next; 
       free(current); 
       current = next; 
       
    }
    front = NULL;
    //std::cout << "deleted the linked list" << std::endl;
}



#endif