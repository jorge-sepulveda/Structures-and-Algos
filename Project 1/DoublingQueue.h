#ifndef _DOUBLINGQUEUE_H
#define _DOUBLINGQUEUE_H

#include "Queue.h"

//#define SIZE = 10

#include <iostream>

template <class Type>
class DoublingQueue : public AbstractQueue<Type>{
    private:
        Type *tempArray;
        Type *items;
        int front;
        int back;
        int capacity;
        int count;
    
    public:
       
       DoublingQueue(int s);
       
       ~DoublingQueue();
    
       bool empty();
    
       int size();
    
       Type frontelem(); //throw(exception) {}
    
       Type dequeue(); //throw(exception) {}
       
       void enqueue ( Type e );
       
       void resize();
       
       void printElements();
    
    
};

//Constructor for the Doubling Queue
template <class Type>
DoublingQueue<Type>::DoublingQueue(int s){
    items = new Type[s];
    front = 0;
    back = -1;
    capacity = s;
    count = 0;
    //std::cout << "made the doubling queue!" << std::endl;
}

//returns the front element in the queue
template <class Type>
Type DoublingQueue<Type>::frontelem(){
    if (empty()){
        throw ArrayException("Empty Stack! exiting the program");
    }
    else{
        return items[front];
    }
}

//puts an item into the back of the queue and resizes if needed
template <class Type>
void DoublingQueue<Type>::enqueue(Type e){
    
    if (count == capacity){
        resize();
        back = (back + 1) % capacity;
        items[back] = e;
        count++;
        //std::cout << "added the item!" << std::endl;
    } 
    else{
        back = (back + 1) % capacity;
        items[back] = e;
        count++;
        //std::cout << "added the item!" << std::endl;
    }
    
}

//dequeue function
template <class Type>
Type DoublingQueue<Type>::dequeue(){

    
    
    if( empty() ){
        throw ArrayException ("ArrayException: Empty Stack");
    }
    //std::cout << "removed " << items[front] << " from the queue" << std::endl;
    Type itemDequeued = items[front];

    front = (front + 1) % capacity;
    count--;
    
    return itemDequeued;
}

//returns a bool if it's empty or not. 
template <class Type>
bool DoublingQueue<Type>::empty(){
    if (count == 0) {
        //std::cout << "empty!" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

//resize function creates a new array that is twice the size of the current array and replaces the current array after copying the old array to the new one. 
template <class Type>
void DoublingQueue<Type>::resize(){
    if (count == capacity){
        //std::cout << "full, gotta make a bigger doubling array" << std::endl;
        tempArray = new Type[capacity*2];
        for (int i=0;i<capacity;i++){
            tempArray[i] = items[i];
        }
        capacity*=2;
        //std::cout << "new size is: " << capacity << std::endl;
        delete[] items;
        items=tempArray;
        
    }
}

//prints all the elements in the queue. 
template <class Type>
void DoublingQueue<Type>::printElements(){
    for (int i=front; i<=back;i++){
        std::cout << items[i] << std::endl;
    }
}

template <class Type>
int DoublingQueue<Type>::size(){
    if (empty()){
        throw ArrayException ("ArrayException: Empty Stack");
    }
    return count;
}

//destructor
template <class Type>
DoublingQueue<Type>::~DoublingQueue() {
    delete[] items;
    //std::cout << "doubling queue destructor called" << std::endl;
}

#endif