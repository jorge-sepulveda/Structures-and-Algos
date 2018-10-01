#ifndef _SLLVECTOR_H
#define _SLLVECTOR_H

#include "AbstractVector.h"


#include <iostream>

template <class T>
class SLLVector : public AbstractVector<T>{
    private:
        struct Node{
            T item;
            Node *next;
        };
        Node* front;
        Node* rear;
        int count;
    public:
    
        SLLVector(void);
       
        ~SLLVector();
        
        T at(int i) {}
       
        void set(int i, T o) {}
        
        void insert(int i, T o) {}
            
        void erase(int i) {}
            
        int size() {}
            
        bool empty() {}
        
        
        
       
    
       
};

#include "SLLVector.tpp"

#endif