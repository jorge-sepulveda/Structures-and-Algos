#include "SortedPQ.h"

using namespace std;

//Constructor for the Doubling Queue
template <class T>
SortedPQ<T>::SortedPQ(void){
    head = NULL;
    tail = NULL;
    count = 0;
    //capacity = 0;
    //cout << "made the SortedPQ!" << endl;
}


//puts an item into the back of the queue and resizes if needed
template <class T>
void SortedPQ<T>::insert(T e){
    Node* elem = new Node;
    int counter = 0;
    elem->data = e;

    if(e <= 0){
        throw PQException("SortedPQ Exception :Cannot add negatives or 0");
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
T SortedPQ<T>::minValue(void){

    if(empty()){
        throw PQException("SortedPQ Exception: Empty Stack!");
    }

    return head->data;
}

template <class T>
T SortedPQ<T>::removeMin(void){

    if(empty()){
        throw PQException("SortedPQ Exception: Empty Stack!");
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


//returns a bool if it's empty or not.
template <class T>
bool SortedPQ<T>::empty(){
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
int SortedPQ<T>::size( void ){
    if (empty()){
        throw PQException("SortedPQ Exception: Empty Stack!");
    }
    return count;
}

//destructor
template <class T>
SortedPQ<T>::~SortedPQ(void) {
    Node* current = head;
    Node* target;

    while (current != NULL){
        target = current;
        current=current->next;
        delete target;

    }
    head = NULL;
    tail = NULL;
    //cout << "SortedPQ destructor called" << endl;


}
