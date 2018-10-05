#include "SLLVector.h"

#include <iostream>

using namespace std;


//Default Constructor
template <class T>
SLLVector<T>::SLLVector(void){
    head = NULL;
    tail = NULL;
    count = 0;
    //capacity = 0;
    std::cout << "made the linked list queue!" << std::endl;
}

//at function
template <class T>
T SLLVector<T>::at(int i){
        Node* current = head;
        Node* next;
        T item;
        int counter = 0;
        
        while (current != NULL){
            if(counter == i){
                item = current->data;
                break;
            }
            else{
                next = current->next; 
                current = next; 
                counter++;
            }
            
        }
        return item;
}

template <class T>
void SLLVector<T>::insert(int i, T o){
    Node* elem = new Node;
    int counter = 0;
    
    elem->data = o;
    
    if (i>count){
        throw VectorException("SLLVectorException: Out of Bounds");
    }
    else if(head == NULL && i == 0){
        head = elem;
        elem->next = NULL;
        tail = elem;
        count++;
        cout << "inserted: " << o << endl;
    }
    else{
        Node* current = head;
        Node* nextOne;
        while (current != NULL){
            
            if (counter == i-1){
                elem->next = current->next;
                current->next = elem;
                count++;
                cout << "inserted: " << o << endl;
                break;
            }
            
            counter++;
            nextOne = current->next;
            current = nextOne;
        }
    }
}

template <class T>
int SLLVector<T>::size(){
    if (empty()){
        throw VectorException ("SLLVectorException: Empty Stack");
    }
    return count;
}

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
void SLLVector<T>::printElements(){
    Node* current = head;
    Node* nextOne;
    T o;
    while(current!=NULL){
        o = current->data;
        cout << o << endl;
        nextOne=current->next;
        current = nextOne;
    }
}




//destructor
template <class T>
SLLVector<T>::~SLLVector(){
    Node* current = head;
    Node* next;
    
    while (current != NULL){
    next = current->next; 
       free(current); 
       current = next; 
       
    }
    head = NULL;
    cout << "Linked List Vector Destroyed" << endl;
}