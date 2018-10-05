#ifndef _DLLVECTOR_H
#define _DLLVECTOR_H

#include "AbstractVector.h"


#include <iostream>

template <class T>
class DLLVector : public AbstractVector<T>{
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
    
        DLLVector(void);
       
        ~DLLVector();
        
        T at(int i);
       
        void set(int i, T o);
        
        void insert(int i, T o);
            
        void erase(int i);
            
        int size();
            
        bool empty();
        
        void printElements();
        
        
        
       
    
       
};

#include "DLLVector.tpp"

#endif