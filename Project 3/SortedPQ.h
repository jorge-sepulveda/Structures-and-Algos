#ifndef _SORTED_PQ_H
#define _SORTED_PQ_H

#include <iostream>

#include "PriorityQueue.h"



template <class T>
class SortedPQ : public PriorityQueue<T>{
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

        SortedPQ( void );

        ~SortedPQ( void );

        bool empty(void);

        int size(void);

        void insert ( T e );

        T removeMin(void);

        T minValue(void);

        //void resize()
};


#include "SortedPQ.tpp"

#endif
