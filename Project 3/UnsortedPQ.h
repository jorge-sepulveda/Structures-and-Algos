#ifndef _UNSORTED_PQ_H
#define _UNSORTED_PQ_H

#include <iostream>

#include "exception.h"
#include "PriorityQueue.h"



template <class T>
class UnsortedPQ : public PriorityQueue<T>{
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
        T min;

    public:

        UnsortedPQ( void );

        ~UnsortedPQ( void );

        bool empty(void);

        int size(void);

        void insert ( T e );

        T removeMin(void);

        T minValue(void);

        void printElements();
};


#include "UnsortedPQ.tpp"

#endif
