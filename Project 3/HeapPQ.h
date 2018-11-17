#ifndef _HEAP_PQ_H
#define _HEAP_PQ_H

#include <iostream>

#include "PriorityQueue.h"



template <class T>
class HeapPQ : public PriorityQueue<T>{
    private:
        struct Node{
            T data;
            Node *next;
            Node *prev;
        };
        Node* head;
        Node* tail;
        int count;
        int pos;

    public:

        HeapPQ( void );

        ~HeapPQ( void );

        bool empty(void);

        int size(void);

        void insert ( T e );

        T removeMin(void);

        T minValue(void);

        //void resize()

        void printElements();
};


#include "HeapPQ.tpp"

#endif
