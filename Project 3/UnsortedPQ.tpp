#include "UnsortedPQ.h"

using namespace std;

//Constructor for the Doubling Queue
template <class T>
UnsortedPQ<T>::UnsortedPQ(void){
    head = NULL;
    tail = NULL;
    count = 0;
    //capacity = 0;
    cout << "made the doubly linked list queue!" << endl;
}


//puts an item into the back of the queue and resizes if needed
template <class T>
void UnsortedPQ<T>::insert(T e){
    Node* elem = new Node;
    int counter = 0;
    elem->data = e;

    if(e <= 0){
        throw PQException("UnsortedPQ Exception :Cannot add negatives or 0");
    }

    else if(head == NULL && count==0){
        head = elem;
        count++;
        min = e;
        cout << "started and inserted: " << e << endl;
        return;
    }
    //check if there is only one element
    else if(count==1){
        //cout << "in the first checker" << endl;
        if (e < min){
            min = e;
        }
        head->next=elem;
        elem->prev=head;
        tail=elem;
        count++;
        cout << "inserted: " << e << endl;
        return;
    }
    //adding to the tail
    else{
        //cout << "added to the tail" << endl;
        if (e < min){
            min = e;
        }
        tail->next=elem;
        elem->prev=tail;
        tail = elem;
        count++;
        cout << "inserted to the tail: " << e << endl;
        return;
    }
}


template <class T>
T UnsortedPQ<T>::minValue(void){
    return min;
}

template <class T>
T UnsortedPQ<T>::removeMin(){
    Node* current = head;
    Node* target;
    T mintemp;
    bool firstcheck;

    while (current != NULL){
        if (current->data == min){
            mintemp = current->data;
            //check if it's the head
            if(current->prev==NULL){
                target=head;
                mintemp = target->data;
                head=head->next;
                free(target);
                //cout << "removed the head: " << mintemp << endl;
                count--;
                break;
            }
            else if(current->next == NULL){
                target = tail;
                mintemp = target->data;
                tail->prev->next = NULL;
                tail=tail->prev;
                free(target);
                count--;
                //cout << "removed the tail: " << mintemp << endl;
                break;

            }
            else{
                target = current;
                mintemp = target->data;
                current->prev->next = current->next;
                current->next->prev=current->prev;
                //current->next = current->next->next;
                free(target);
                //cout << "removed: " << mintemp << endl;
                count--;
                break;
            }

        }
        current=current->next;

    }
    current=head;
    while (current != NULL){
        if(firstcheck){
            min = current->data;
            firstcheck=false;
        }
        if (current->data<min){
            min = current->data;
        }
        current=current->next;
    }
    return mintemp;
}
/*//dequeue function
template <class T>
T UnsortedPQ<T>::dequeue(){



    if( empty() ){
        throw PQException ("PQException: Empty Stack");
    }
    //std::cout << "removed " << items[front] << " from the queue" << std::endl;
    T itemDequeued = items[front];

    front = (front + 1) % capacity;
    count--;

    return itemDequeued;
}*/

template <class T>
void UnsortedPQ<T>::printElements(){
    Node* current = head;
    T o;
    while(current!=NULL){
        o = current->data;
        cout << o << endl;
        current = current->next;
    }
}

//returns a bool if it's empty or not.
template <class T>
bool UnsortedPQ<T>::empty(){
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
int UnsortedPQ<T>::size( void ){
    if (empty()){
        throw PQException("UnsortedPQ: Empty Stack");
    }
    return count;
}

//destructor
template <class T>
UnsortedPQ<T>::~UnsortedPQ(void) {
    Node* current = head;
    Node* next;

    while (current != NULL){
    next = current->next;
       free(current);
       current = next;

    }
    head = NULL;
    cout << "DLL PQ destructor called" << endl;


}
