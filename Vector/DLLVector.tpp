#include "DLLVector.h"

#include <iostream>

using namespace std;


//Default Constructor
template <class T>
DLLVector<T>::DLLVector(void){
    head = NULL;
    tail = NULL;
    count = 0;
    //capacity = 0;
    std::cout << "made the doubly linked list queue!" << std::endl;
}

//at function
template <class T>
T DLLVector<T>::at(int i){
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
void DLLVector<T>::insert(int i, T o){
    Node* elem = new Node;
    int counter = 0;
    
    elem->data = o;
    
    if (i>count){
        throw VectorException("DLLVectorException: Out of Bounds");
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
void DLLVector<T>::set(int i, T o){
    if (i>count){
        throw VectorException("DLLVectorException: Out of Bounds");
    }
    else{
        int counter = 0;
        Node* current = head;
        Node* nextOne;
        T temp;
        while (current != NULL){
            
            if (counter == i){
                temp = current->data;
                current->data=o;
                cout << "replaced " << temp << " for " << o <<  endl;
                break;
            }
            counter++;
            nextOne = current->next;
            current = nextOne;
        }
    }
}

template <class T>
void DLLVector<T>::erase(int i){
    if (i>count){
        throw VectorException("DLLVectorException: Out of Bounds");
    }
    else{
        int counter = 0;
        Node* current = head;
        Node* nextOne;
        Node* target;
        T temp;
        while (current != NULL){
            
            if (counter == i-1){
                target = current->next;
                temp = target->data;
                current->next = current->next->next;
                free(target);
                cout << "removed: " << temp << endl;
                count--;
                break;
            }
            
            counter++;
            nextOne = current->next;
            current = nextOne;
        }
    }
}

template <class T>
int DLLVector<T>::size(){
    if (empty()){
        throw VectorException ("DLLVectorException: Empty Stack");
    }
    return count;
}

template <class T>
bool DLLVector<T>::empty(){
    if (count == 0) {
        //std::cout << "empty!" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

template <class T>
void DLLVector<T>::printElements(){
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


//

//destructor
template <class T>
DLLVector<T>::~DLLVector(){
    Node* current = head;
    Node* next;
    
    while (current != NULL){
    next = current->next; 
       free(current); 
       current = next; 
       
    }
    head = NULL;
    cout << "DLLVector Destroyed" << endl;
}