#ifndef _INCREMENTALQUEUE_H
#define _INCREMENTALQUEUE_H

#include "Queue.h"
#include "exception.h"

#include <iostream>

template <class Type>
class IncrementalQueue : public AbstractQueue<Type>{   
    private:
        Type *tempArray;
        Type *items;
        int front;
        int back;
        int capacity;
        int count;
    
    public:
    
        IncrementalQueue(int s);
           
        ~IncrementalQueue();
           
        bool empty();
        
        int size();
        
        Type frontelem();
        
        Type dequeue(); 
           
        void enqueue ( Type e );
           
        void resize();
           
        void printElements();
};


//constructor for the queue
template <class Type>
IncrementalQueue<Type>::IncrementalQueue(int s){
    items = new Type[s];
    front = 0;
    back = -1;
    capacity = s;
    count = 0;
    //std::cout << "made the incremental queue!" << std::endl;
}

//prints all the elements in the queue
template <class Type>
void IncrementalQueue<Type>::printElements(){
    for (int i=front; i<=back;i++){
        std::cout << items[i] << std::endl;
    }
}

//returns the front item in the queue
template <class Type>
Type IncrementalQueue<Type>::frontelem(){
    if (empty()){
        throw ArrayException("Empty Stack! exiting the program");
    }
    else{
        return items[front];
    }
}


//puts an item into the back of the queue and resizes if needed
template <class Type>
void IncrementalQueue<Type>::enqueue(Type e){
    
    if (count == capacity){
        resize();
        back = (back + 1) % capacity;
        items[back] = e;
        count++;
        //std::cout << e << std::endl;
    } 
    else{
        back = (back + 1) % capacity;
        items[back] = e;
        count++;
        //std::cout << e << std::endl;
    }
    
}

//removes an item from front
template <class Type>
Type IncrementalQueue<Type>::dequeue(){

	
    
    if( empty() ){
        throw ArrayException ("ArrayException: Empty Stack");
    }

    Type itemDequeued = items[front];
    //std::cout << "removed " << items[front] << " from the queue" << std::endl;
    front = (front + 1) % capacity;
    count--;

    return itemDequeued;
}

//checks if the queue is empty
template <class Type>
bool IncrementalQueue<Type>::empty(){
    if (count == 0) {
        //std::cout << "empty!" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

//creates a new array to replace the smaller array. 
template <class Type>
void IncrementalQueue<Type>::resize(){
    if (count == capacity){
        //std::cout << "full, gotta make a bigger  inc array" << std::endl;
        tempArray = new Type[capacity+10000];
        for (int i=0;i<capacity;i++){
            tempArray[i] = items[i];
        }
        capacity+=10000;
        //std::cout << "new size is: " << capacity << std::endl;
        delete[] items;
        items=tempArray;
    }
}

template <class Type>
int IncrementalQueue<Type>::size(){
    if (empty()){
        throw ArrayException ("ArrayException: Empty Stack");
    }
    return count;
}

//Destructor
template <class Type>
IncrementalQueue<Type>::~IncrementalQueue() {
    delete[] items;
    //std::cout << "inc queue destructor called" << std::endl;
}




    
#endif

