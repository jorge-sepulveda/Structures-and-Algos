#include "DoublingArrayVector.h"

#include <iostream>

//constructor with a parameters
template<class T>
DoublingArrayVector<T>::DoublingArrayVector(int s){
	items = new T[s];
	capacity = s;
	currentSize = 0;
	std::cout<< "DoublingDoublingArrayVector created" << std::endl;
}

template<class T>
T DoublingArrayVector<T>::at(int i){
	if (i < 0 || i > currentSize){
		throw VectorException("Vector Exception! Out of bounds");
	}
	return items[i];
}

template<class T>
void DoublingArrayVector<T>::set(int i, T o){
	items[i] = o;
	currentSize++;
}

//insert
template<class T>
void DoublingArrayVector<T>::insert(int i, T o){
	if (currentSize >= capacity){
		throw VectorException("Vector Exception! Vector is full");
	}
	for(int j = currentSize - 1; j >= i; j--){
		items[j+1] = items[j];
	}
	items[i] = o;
	currentSize+=1;
}


//erase
template<class T>
void DoublingArrayVector<T>::erase(int i){
	for (int j=i+1; j < currentSize;j++){
		items[j-1] = items[j];
	}
	currentSize-=1;
}

//size
template<class T>
int DoublingArrayVector<T>::size(){
	return currentSize;
}

//empty
template<class T>
bool DoublingArrayVector<T>::empty(){
	return (currentSize == 0);
}

//print elements
template<class T>
void DoublingArrayVector<T>::printElements(){
	for (int i=0;i<currentSize;i++)
		std::cout<< items[i] << std::endl;
}


//destructor
template <class T>
DoublingArrayVector<T>::~DoublingArrayVector(){
	delete [] items;
	std::cout<< "DoublingArrayVector destroyed" << std::endl;
}