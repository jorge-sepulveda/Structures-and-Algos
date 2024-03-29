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
    
    if(i < 0 || i>=count){
            throw VectorException("DLLVectorException: Out of Bounds");
        }
    
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

/*
 * This insert function has been heavily modified so it can handle an a null head and tail. 
 * 
*/
template <class T>
void DLLVector<T>::insert(int i, T o){
    Node* elem = new Node;
    int counter = 0;    
    elem->data = o;

    if (i>count){
        throw VectorException("DLLVectorException: Out of Bounds");
    }
    //check if the DLL is empty
    else if(head == NULL && count==0){
        head = elem;
        count++;
        //cout << "inserted: " << o << endl;
        return;
    }
    //adding to the front of the DLL
    else if(i==0 && head != NULL){
        //cout << "adding to the front" << endl;
        elem->next = head;
        head->prev = elem; 
        head = elem;
        //cout << "inserted: " << o << endl;
        return;
    }
    //check if there is only one element
    else if(count==1){
        //cout << "in the first checker" << endl;
        head->next=elem;
        elem->prev=head;
        tail=elem;
        count++;
        //cout << "inserted: " << o << endl;
        return;
    }
    //adding to the tail
    else if(i == count){
        //cout << "added to the tail" << endl;
        tail->next=elem;
        elem->prev=tail;
        tail = elem;
        count++;
        //cout << "inserted: " << o << endl;
        return;
    }
    //element
    else{
        //cout << "got in the else" << endl;
        Node* current = head;
        while (current != NULL){
            
            if (counter == i){
                //cout << "made it to equal!" << endl;
                elem->next=current;
                elem->prev=current->prev;
                current->prev->next=elem;
                current->prev=elem;

                count++;
                //cout << "inserted: " << o << endl;
                return;
            }
            counter++;
            current=current->next;
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
        T temp;
        while (current != NULL){
            
            if (counter == i){
                temp = current->data;
                current->data=o;
                //cout << "replaced " << temp << " for " << o <<  endl;
                break;
            }
            counter++;
            current = current->next;
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
        
        if (i == 0){
            target = head; 
            temp=target->data;
            head=head->next;
            free(target);
            cout << "removed the head: " << temp << endl;
            count--;
            return;
        }
        else if(i == count-1){
            target = tail;
            temp = target->data;
            tail->prev->next = NULL;
            tail=tail->prev;
            free(target);
            count--;
            cout << "removed the tail: " << temp << endl;
            return;
        }
        
        else{
            
            while (current != NULL){
                
                
                if (counter == i-1){
                    target = current;
                    temp = target->data;
                    current->prev->next = current->next;
                    current->next->prev=current->prev;
                    //current->next = current->next->next;
                    free(target);
                    cout << "removed: " << temp << endl;
                    count--;
                    return;
                }
            
            counter++;
            current = current->next;
            }
        
        }
    }//end top else
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
    T o;
    while(current!=NULL){
        o = current->data;
        cout << o << endl;
        current = current->next;
    }
}

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