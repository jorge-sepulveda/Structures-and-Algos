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
    this->items = new Type[s];
    this->front = 0;
    this->back = -1;
    this->capacity = s;
    this->count = 0;
    //std::cout << "made the incremental queue!" << std::endl;
}

//prints all the elements in the queue
template <class Type>
void IncrementalQueue<Type>::printElements(){
    for (int i=this->front; i<=this->back;i++){
        std::cout << this->items[i] << std::endl;
    }
}

//returns the front item in the queue
template <class Type>
Type IncrementalQueue<Type>::frontelem(){
    if (empty()){
        throw StackException("Empty Stack! exiting the program");
    }
    else{
        return this->items[this->front];
    }
}


//puts an item into the back of the queue and resizes if needed
template <class Type>
void IncrementalQueue<Type>::enqueue(Type e){
    
    if (this->count == this->capacity){
        resize();
        this->back = (this->back + 1) % this->capacity;
        this->items[this->back] = e;
        this->count++;
        //std::cout << e << std::endl;
    } 
    else{
        this->back = (this->back + 1) % this->capacity;
        this->items[this->back] = e;
        this->count++;
        //std::cout << e << std::endl;
    }
    
}

//removes an item from front
template <class Type>
Type IncrementalQueue<Type>::dequeue(){

	
    
    if( empty() ){
        throw StackException ("StackException: Empty Stack");
    }

    Type itemDequeued = this->items[this->front];
    //std::cout << "removed " << this->items[this->front] << " from the queue" << std::endl;
    this->front = (this->front + 1) % this->capacity;
    this->count--;

    return itemDequeued;
}

//checks if the queue is empty
template <class Type>
bool IncrementalQueue<Type>::empty(){
    if (this->count == 0) {
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
    if (this->count == this->capacity){
        //std::cout << "full, gotta make a bigger  inc array" << std::endl;
        tempArray = new Type[this->capacity+10000];
        for (int i=0;i<this->capacity;i++){
            tempArray[i] = this->items[i];
        }
        this->capacity+=10000;
        //std::cout << "new size is: " << this->capacity << std::endl;
        delete[] this->items;
        this->items=tempArray;
    }
}

template <class Type>
int IncrementalQueue<Type>::size(){
    if (empty()){
        throw StackException ("StackException: Empty Stack");
    }
    return count;
}

//Destructor
template <class Type>
IncrementalQueue<Type>::~IncrementalQueue() {
    delete[] this->items;
    //std::cout << "inc queue destructor called" << std::endl;
}




    
#endif

