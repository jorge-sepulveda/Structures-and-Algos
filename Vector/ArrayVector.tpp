#include "ArrayVector.h"

//constructor with a parameters
template<class T>
ArrayVector<T>::ArrayVector(int s){
	items = new T[s];
	capacity = s;
	currentSize = 0;
	std::cout<< "ArrayVector created" << std::endl;
}

template<class T>
T ArrayVector<T>::at(int i){
	if (i < 0 || i > currentSize){
		throw VectorException("Vector Exception! Out of bounds");
	}
	return items[i];
}

template<class T>
void ArrayVector<T>::set(int i, T o){
	items[i] = o;
	currentSize++;
}

//insert
template<class T>
void ArrayVector<T>::insert(int i, T o){
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
void ArrayVector<T>::erase(int i){
	for (int j=i+1; j < currentSize;j++){
		items[j-1] = items[j];
	}
	currentSize-=1;
}

//size
template<class T>
int ArrayVector<T>::size(){
	return currentSize;
}

//empty
template<class T>
bool ArrayVector<T>::empty(){
	return (currentSize == 0);
}

//print elements
template<class T>
void ArrayVector<T>::printElements(){
	for (int i=0;i<currentSize;i++)
		std::cout<< items[i] << std::endl;
}


//destructor
template <class T>
ArrayVector<T>::~ArrayVector(){
	delete [] items;
	std::cout<< "ArrayVector destroyed" << std::endl;
}