#include "UnsortedPQ.h"

using namespace std;

//Constructor for the Doubling Queue
template <class T>
UnsortedPQ<T>::UnsortedPQ(void){
    head = NULL;
    tail = NULL;
    count = 0;
    //capacity = 0;
    //cout << "made the UnsortedPQ!" << endl;
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

    else if(head == NULL && count==0 && tail == NULL){
        head = elem;
        elem->prev=NULL;
        tail = elem;
        count++;
        //cout << "started and inserted: " << e << endl;
        return;
    }
    //check if there is only one element
    else if(count==1){
        //cout << "in the first checker" << endl;
        head->next=elem;
        elem->prev=head;
        tail=elem;
        count++;
        //cout << "inserted: " << e << endl;
        return;
    }
    //adding to the tail
    else{
        //cout << "added to the tail" << endl;
        tail->next=elem;
        elem->prev=tail;
        elem->next=NULL;
        tail = elem;
        count++;
        //cout << "inserted to the tail: " << e << endl;
        return;
    }
}


template <class T>
T UnsortedPQ<T>::minValue(void){
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
T UnsortedPQ<T>::removeMin(){
    Node* current = head;
    Node* target;
    T min = minValue();
    T removedMin;

    if(empty()){
        throw PQException("UnsortedPQ Exception: Empty Stack!");
    }

    else if(count==1){
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
                //cout << "removed the head: " << removedMin << endl;
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
                //cout << "removed the tail: " << removedMin << endl;
                return removedMin;

            }
            else{
                target = current;
                removedMin = target->data;
                current->prev->next = current->next;
                current->next->prev=current->prev;


                delete target;
                //cout << "removed: " << removedMin << endl;
                count--;
                return removedMin;
            }

        }
        current=current->next;

    }
    return removedMin;
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
        throw PQException("UnsortedPQ Exception: Empty Stack!");
    }
    return count;
}

//destructor
template <class T>
UnsortedPQ<T>::~UnsortedPQ(void) {
    Node* current = head;
    Node* target;

    while (current != NULL){
        target = current;
        current=current->next;
        delete target;

    }
    head = NULL;
    tail = NULL;
    //cout << "UnsortedPQ destructor called" << endl;


}
