#ifndef _INCREMENTAL_ARRAY_VECTOR_H
#define _INCREMENTAL_ARRAY_VECTOR_H

#include <iostream>

#include "AbstractVector.h"

template <class T>
class IncrementalArrayVector : public AbstractVector<T>{
	private:
		T* items;
		int capacity;
		int currentSize;
		T* tempArray;

	public:

	IncrementalArrayVector(int s);

	~IncrementalArrayVector();

	T at(int i);
    
   	void set(int i, T o);
    
    void insert(int i, T o);
    
    void erase(int i);
    
    int size();
    
    bool empty();

    void printElements();
    
    void resize(int n);

};

#include "IncrementalArrayVector.tpp"

#endif