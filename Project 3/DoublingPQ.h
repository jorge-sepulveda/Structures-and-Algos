#ifndef _DOUBLING_PQ_H
#define _DOUBLING_PQ_H

#include <iostream>

#include "exception.h"
#include "PriorityQueue.h"



template <class T>
class DoublingPQ : public PriorityQueue<T>{   
    private:
        T *tempArray;
        T *items;
        int front;
        int back;
        int capacity;
        int count;
        int min;
    
    public:
    
        DoublingPQ( void );
           
        ~DoublingPQ( void );
           
        bool empty(void);
        
        int size(void);
        
        void insert ( T e );
        
        T removeMin(void);
        
        T minValue(void);
           
        void resize();
           
        //void printElements();
};


#include "DoublingPQ.tpp"
    
#endif

