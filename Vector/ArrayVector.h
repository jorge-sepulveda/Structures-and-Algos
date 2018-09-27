#ifndef _ARRAYVECTOR_H
#define _ARRAYVECTOR_H

#include <iostream>

#include "AbstractVector.h"
#include "exception.h"

template <class T>
class ArrayVector : public AbstractVector<T>{
	private:
		T* items;
		int capacity;
		int currentSize;

	public:

	ArrayVector(int s);

	~ArrayVector();

	T at(int i);
    
   	void set(int i, T o);
    
    void insert(int i, T o);
    
    void erase(int i);
    
    int size();
    
    bool empty();

    void printElements();

};

#include "ArrayVector.tpp"

#endif