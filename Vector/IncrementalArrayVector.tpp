#include "IncrementalArrayVector.h"

#include <iostream>

//constructor with a parameters


//add a RESIZE TO THIS!
template<class T>
IncrementalArrayVector<T>::IncrementalArrayVector(int s){
	items = new T[s];
	capacity = s;
	currentSize = 0;
	std::cout<< "IncrementalArrayVector created" << std::endl;
}

template<class T>
T IncrementalArrayVector<T>::at(int i){
	if (i < 0 || i > currentSize){
		throw VectorException("Vector Exception! Out of bounds");
	}
	return items[i];
}

template<class T>
void IncrementalArrayVector<T>::set(int i, T o){
	items[i] = o;
	currentSize++;
}

//insert
template<class T>
void IncrementalArrayVector<T>::insert(int i, T o){
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
void IncrementalArrayVector<T>::erase(int i){
	for (int j=i+1; j < currentSize;j++){
		items[j-1] = items[j];
	}
	currentSize-=1;
}

//size
template<class T>
int IncrementalArrayVector<T>::size(){
	return currentSize;
}

//empty
template<class T>
bool IncrementalArrayVector<T>::empty(){
	return (currentSize == 0);
}

//print elements
template<class T>
void IncrementalArrayVector<T>::printElements(){
	for (int i=0;i<currentSize;i++)
		std::cout<< items[i] << std::endl;
}

//print elements
template<class T>
void IncrementalArrayVector<T>::resize(int n){
	tempArray = new T[capacity+n];
	for (int i=0;i<currentSize;i++){
		tempArray[i] = items[i];
	}
	capacity+=n;
	delete[] items;
	items = tempArray;
	std::cout << "resized!" << std::endl;
	std::cout << capacity << std::endl;
	
}

template <class T>
IncrementalArrayVector<T>::~IncrementalArrayVector(){
	delete [] items;
	std::cout<< "IncrementalArrayVector destroyed" << std::endl;

}