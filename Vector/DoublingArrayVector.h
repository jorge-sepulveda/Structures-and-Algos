#ifndef _DOUBLINGARRAYVECTOR_H
#define _DOUBLINGARRAYVECTOR_H

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

};

#include "DoublingArrayVector.tpp"

#endif