#ifndef _DOUBLING_ARRAY_VECTOR_H
#define _DOUBLING_ARRAY_VECTOR_H

#include <iostream>

#include "AbstractVector.h"

template <class T>
class DoublingArrayVector : public AbstractVector<T>{
	private:
		T* items;
		int capacity;
		int currentSize;
		T* tempArray;

	public:

	DoublingArrayVector(int s);

	~DoublingArrayVector();

	T at(int i);
    
   	void set(int i, T o);
    
    void insert(int i, T o);
    
    void erase(int i);
    
    int size();
    
    bool empty();

    void printElements();
    
    void resize();

};

#include "DoublingArrayVector.tpp"

#endif