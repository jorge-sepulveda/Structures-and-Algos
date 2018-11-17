#include "HeapPQ.h"

using namespace std;

//Constructor for the Doubling Queue
template <class T>
HeapPQ<T>::HeapPQ(void){
    head = NULL;
    tail = NULL;
    count = 0;
    //capacity = 0;
    cout << "made the HeapPQ!" << endl;
}


//puts an item into the back of the queue and resizes if needed
template <class T>
void HeapPQ<T>::insert(T e){
    Node* elem = new Node;
    int counter = 0;
    elem->data = e;

    if(e <= 0){
        throw PQException("HeapPQ Exception :Cannot add negatives or 0");
    }

    if (head == NULL){
        head = elem;
        tail = elem;
        elem->next = NULL;
        count++;
    }
    else{
        if (elem->data <= head->data){
            elem->prev=NULL;
            elem->next = head;
            head->prev = elem;
            head = elem;
            count++;
        }
        else if(elem->data > tail->data){
            elem->next = NULL;
            tail->next = elem;
            elem->prev = tail;
            tail = elem;
            count++;
        }
        else{
            Node* current = head->next;
            while(current->data < elem->data){//1 after it.
                current = current->next;
                }
            elem->next=current;
            elem->prev=current->prev;
            current->prev->next=elem;
            current->prev=elem;

            count++;
        }
    }
}


template <class T>
T HeapPQ<T>::minValue(void){

    if(empty()){
        throw PQException("HeapPQ Exception: Empty Stack!");
    }

    return head->data;
}

template <class T>
T HeapPQ<T>::removeMin(void){

    if(empty()){
        throw PQException("HeapPQ Exception: Empty Stack!");
    }

    Node* target = head; 
    T removedMin = target->data; 
    head = head->next; 
    delete target; 
    count--;
    if (head == NULL){  
        tail = NULL; 
    }
    return removedMin;
}


template <class T>
void HeapPQ<T>::printElements(){
    Node* current = head;
    T o;

    if (empty()){
        throw PQException("HeapPQ Exception: Empty Stack!");
    }
    while(current!=NULL){
        o = current->data;
        cout << o << endl;
        current = current->next;
    }
}

//returns a bool if it's empty or not.
template <class T>
bool HeapPQ<T>::empty(){
    if (count == 0) {
        //std::cout << "empty!" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

//size
template <class T>
int HeapPQ<T>::size( void ){
    if (empty()){
        throw PQException("HeapPQ Exception: Empty Stack!");
    }
    return count;
}

//destructor
template <class T>
HeapPQ<T>::~HeapPQ(void) {
    Node* current = head;
    Node* target;

    while (current != NULL){
        target = current;
        current=current->next;
        delete target;

    }
    head = NULL;
    tail = NULL;
    cout << "HeapPQ destructor called" << endl;


}
