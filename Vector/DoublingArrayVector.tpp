#include "DoublingArrayVector.h"

#include <iostream>

//constructor with a parameters


//add a RESIZE TO THIS!
template<class T>
DoublingArrayVector<T>::DoublingArrayVector(int s){
	items = new T[s];
	capacity = s;
	currentSize = 0;
	std::cout<< "DoublingArrayVector created" << std::endl;
}

template<class T>
T DoublingArrayVector<T>::at(int i){
	if (i < 0 || i > currentSize){
		throw VectorException("doub Vector Exception! Out of bounds");
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
		//throw VectorException("Vector Exception! Vector is full");
		resize();
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

//print elements
template<class T>
void DoublingArrayVector<T>::resize(){
	tempArray = new T[capacity*2];
	for (int i=0;i<currentSize;i++){
		tempArray[i] = items[i];
	}
	capacity*=2;
	delete[] items;
	items = tempArray;
	std::cout << "resized!" << std::endl;
	std::cout << capacity << std::endl;
	
}

template <class T>
DoublingArrayVector<T>::~DoublingArrayVector(){
	delete [] items;
	std::cout<< "DoublingArrayVector destroyed" << std::endl;

}