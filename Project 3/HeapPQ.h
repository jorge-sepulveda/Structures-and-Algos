#ifndef _HEAP_PQ_H
#define _HEAP_PQ_H

#include <iostream>

#include "PriorityQueue.h"



template <class T>
class HeapPQ : public PriorityQueue<T>{
    private:
        T *items;
        int count;
        int capacity;
        void swap(T& x, T& y);
    public:

        HeapPQ( void );

        ~HeapPQ( void );

        bool empty(void);

        int size(void);

        void insert ( T e );

        T removeMin(void);

        T minValue(void);

        void heapify( int i );

        int parent(int i) { return (i-1)/2; }

        int left(int i) { return (2*i + 1); }

        int right(int i) { return (2*i + 2); }
};


#include "HeapPQ.tpp"

#endif
