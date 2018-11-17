#include "SortedPQ.h"

using namespace std;

//Constructor for the Doubling Queue
template <class T>
SortedPQ<T>::SortedPQ(void){
    head = NULL;
    tail = NULL;
    count = 0;
    //capacity = 0;
    cout << "made the SortedPQ!" << endl;
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

    else if(head == NULL && count==0 && tail == NULL){
        head = elem;
        tail = elem;
        count++;
        cout << "started and inserted: " << e << endl;
        return;
    }
    //check if there is only one element
    else if(count==1){
        //cout << "in the first checker" << endl;
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
        tail->next=elem;
        elem->prev=tail;
        tail = elem;
        count++;
        cout << "inserted to the tail: " << e << endl;
        return;
    }
}


template <class T>
T SortedPQ<T>::minValue(void){
  Node* current = head;
  int counter = 0;
  T min;
  while (current != NULL){
      if (counter == 0){
          min = current->data;
      }
      if (current->data < min){
          min = current->data;
      }
      counter++;
      current = current->next;
  }
    return min;
}

template <class T>
T SortedPQ<T>::removeMin(){
    Node* current = head;
    Node* target;
    T min = minValue();
    T removedMin;

    if(empty()){
        throw PQException("SortedPQ Exception: Empty Stack!");
    }

    else if(size()==1){
        target = head;
        removedMin = target->data;
        head = NULL;
        tail = NULL;
        delete target;
        count--;
    }

    while (current != NULL){
        if (current->data == min){
            if(current->prev == NULL){
                target=current;
                removedMin = target->data;
                head->next->prev = NULL;
                head=head->next;

                delete target;
                //cout << "removed the head: " << mintemp << endl;
                count--;
                return removedMin;
            }
            else if(current->next==NULL){
                target = current;
                removedMin = target->data;
                tail->prev->next = NULL;
                tail=tail->prev;
                delete target;
                count--;
                //cout << "removed the tail: " << mintemp << endl;
                return removedMin;

            }
            else{
                target = current;
                removedMin = target->data;
                current->prev->next = current->next;
                current->next->prev=current->prev;
                //current->next = current->next->next;
                delete target;
                //cout << "removed: " << mintemp << endl;
                count--;
                return removedMin;
            }

        }
        current=current->next;

    }
    return removedMin;
}


template <class T>
void SortedPQ<T>::printElements(){
    Node* current = head;
    T o;

    if (empty()){
        throw PQException("SortedPQ Exception: Empty Stack!");
    }
    while(current!=NULL){
        o = current->data;
        cout << o << endl;
        current = current->next;
    }
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
    cout << "SortedPQ destructor called" << endl;


}
