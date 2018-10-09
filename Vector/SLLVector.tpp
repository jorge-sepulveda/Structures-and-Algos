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
        
        if(i < 0 || i>=count){
            throw VectorException("DLLVectorException: Out of Bounds");
        }
        
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
        head = elem;
        //cout << "inserted: " << o << endl;
        return;
    }
    //check if there is only one element
    else if(count==1){
        //cout << "in the first checker" << endl;
        head->next=elem;
        tail=elem;
        count++;
        //cout << "inserted: " << o << endl;
        return;
    }
    //adding to the tail
    else if(i == count){
        //cout << "added to the tail" << endl;
        tail->next=elem;
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
            
            if (counter == i-1){
                //cout << "made it to equal!" << endl;
                elem->next=current->next;
                current->next=elem;


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
void SLLVector<T>::set(int i, T o){
    if (i>count){
        throw VectorException("SLLVectorException: Out of Bounds");
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
                //cout << "replaced " << temp << " for " << o <<  endl;
                break;
            }
            counter++;
            nextOne = current->next;
            current = nextOne;
        }
    }
}

template <class T>
void SLLVector<T>::erase(int i){
    if (i>count){
        throw VectorException("SLLVectorException: Out of Bounds");
    }
    else{
        int counter = 0;
        Node* current = head;
        Node* nextOne;
        Node* target;
        T temp;
        
        if (i == 0){
            target = head;
            temp = target->data;
            head=head->next;
            free(target);
            cout << "removed the head: " << temp << endl;
            count--;
            return;
        }
        //made this else really long to avoid getting garbage and seg faults
        else{
            while (current != NULL){
                //cout<<"in the loop"<<endl;
                if (counter == i-1){
                    if(current->next==tail){
                        
                        tail=current;
                        target = current->next;
                        temp = target->data;
                        current->next = NULL;
                        free(target);
                        cout << "removed the tail: " << temp << endl;
                        count--;
                        cout << count <<endl;
                        return;
                    }
                    else{
                        target = current->next;
                        if(target==NULL){
                            throw VectorException("SLLVectorException: Out of bounds");
                        }
                        temp = target->data;
                        current->next = current->next->next;
                        free(target);
                        cout << "removed: " << temp << endl;
                        count--;
                        cout << count <<endl;
                        return;
                    }
                
                }
            counter++;
            current=current->next;
            }   
            
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
    T o;
    while(current!=NULL){
        o = current->data;
        cout << o << endl;
        current=current->next;
    }
}


//

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
    cout << "SLLVector Destroyed" << endl;
}