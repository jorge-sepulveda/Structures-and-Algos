#include "HeapPQ.h"

using namespace std;

//Constructor for the Doubling Queue
template <class T>
HeapPQ<T>::HeapPQ(void){
    items = new T[100000];
    count = 0;
    capacity = 100000;
    //capacity = 0;
    //cout << "made the HeapPQ!" << endl;
}


//puts an item into the back of the queue and resizes if needed
template <class T>
void HeapPQ<T>::insert(T e){

    if (count == capacity)
    {
        throw PQException("HeapPQ Exception: FULL STACK!");
    }

    // First insert the new key at the end
    count++;
    int i = count - 1;
    items[i] = e;

    // Fix the min heap property if it is violated
    while (i != 0 && items[parent(i)] > items[i])
    {
       swap(items[i], items[parent(i)]);
       i = parent(i);
    }

}



template <class T>
T HeapPQ<T>::minValue(void){

    if(empty()){
        throw PQException("HeapPQ Exception: Empty Stack!");
    }

    return items[0];
}

template <class T>
T HeapPQ<T>::removeMin(void){

    if (count <= 0){
        throw PQException("HeapPQ Exception: Empty Stack!");
    }
    if (count == 1)
    {
        count--;
        return items[0];
    }

    // Store the minimum value, and remove it from heap
    T root = items[0];
    items[0] = items[count-1];
    count--;
    heapify(0);

    return root;
}


//swap elements in the array to help with heapifying
template <class T>
void HeapPQ<T>::swap(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
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


template <class T>
void HeapPQ<T>::heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < count && items[l] <= items[i]){
        smallest = l;
    }
    if (r < count && items[r] < items[smallest]){
        smallest = r;
    }
    if (smallest != i){
        swap(items[i], items[smallest]);
        heapify(smallest);
    }
}

//destructor
template <class T>
HeapPQ<T>::~HeapPQ(void) {
    delete[] items;
    //cout << "HeapPQ destructor called" << endl;


}
