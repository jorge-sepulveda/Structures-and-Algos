#include "DoublingPQ.h"

using namespace std;

//Constructor for the Doubling Queue
template <class T>
DoublingPQ<T>::DoublingPQ(void){
    items = new T[100];
    front = 0;
    back = -1;
    capacity = 100;
    count = 0;
    min = 100;
    cout << "made the doubling queue!" << endl;
}


//puts an item into the back of the queue and resizes if needed
template <class T>
void DoublingPQ<T>::insert(T e){
    
    if (count == capacity){
        resize();
        back = (back + 1) % capacity;
        items[back] = e;
        count++;
        cout << "added the item!" << endl;
    } 
    else{
        back = (back + 1) % capacity;
        items[back] = e;
        count++;
        cout << "added the item!" << endl;
    }
    
}

/*//dequeue function
template <class T>
T DoublingPQ<T>::dequeue(){

    
    
    if( empty() ){
        throw PQException ("PQException: Empty Stack");
    }
    //std::cout << "removed " << items[front] << " from the queue" << std::endl;
    T itemDequeued = items[front];

    front = (front + 1) % capacity;
    count--;
    
    return itemDequeued;
}*/

//returns a bool if it's empty or not. 
template <class T>
bool DoublingPQ<T>::empty(){
    if (count == 0) {
        //std::cout << "empty!" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

//resize function creates a new array that is twice the size of the current array and replaces the current array after copying the old array to the new one. 
template <class T>
void DoublingPQ<T>::resize(){
    if (count == capacity){
        //std::cout << "full, gotta make a bigger doubling array" << std::endl;
        tempArray = new T[capacity*2];
        for (int i=0;i<capacity;i++){
            tempArray[i] = items[i];
        }
        capacity*=2;
        //std::cout << "new size is: " << capacity << std::endl;
        delete[] items;
        items=tempArray;
        
    }
}

/*//prints all the elements in the queue. 
template <class T>
void DoublingPQ<T>::printElements(){
    for (int i=front; i<=back;i++){
        std::cout << items[i] << std::endl;
    }
}*/

template <class T>
int DoublingPQ<T>::size( void ){
    if (empty()){
        throw PQException ("DoublingPQ: Empty Stack");
    }
    return count;
}

//destructor
template <class T>
DoublingPQ<T>::~DoublingPQ(void) {
    delete[] items;
    cout << "doubling queue destructor called" << endl;
    
    
}