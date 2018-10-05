#ifndef _SLLVECTOR_H
#define _SLLVECTOR_H

#include "AbstractVector.h"


#include <iostream>

template <class T>
class SLLVector : public AbstractVector<T>{
    private:
        struct Node{
            T data;
            Node *next;
        };
        Node* head;
        Node* tail;
        int count;
        int pos;
    public:
    
        SLLVector(void);
       
        ~SLLVector();
        
        T at(int i);
       
        void set(int i, T o) {}
        
        void insert(int i, T o);
            
        void erase(int i) {}
            
        int size();
            
        bool empty();
        
        void printElements();
        
        
        
       
    
       
};

#include "SLLVector.tpp"

#endif