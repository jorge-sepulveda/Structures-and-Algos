#include "ArrayVector.h"
#include "DoublingArrayVector.h"
#include "IncrementalArrayVector.h"
#include "SLLVector.h"
#include "DLLVector.h"

#include <iostream>

using namespace std;

/*
 * Author: Jorge Sepulveda
 * Class: CSCE 221
 * Instructor: Eduardo Nakamura
 * Assignment: Vector implementation
 * Date: October 8 2018
 * 
 * This main file runs the vector functions that Harish posted on Piazza and applying the same functions to each Vector implementation.
 */

int main(){
	try{
		ArrayVector<double> testVector(50);
		IncrementalArrayVector<int> testVector2(1);
		DoublingArrayVector<int> testVector3(1);
		SLLVector<int> testVector4;
		DLLVector<int> testVector5;
		
		cout << "\nFixed array" << endl;

		for(int i=0;i<10;i++)
		testVector.insert(i,i);
		for(int i=0;i<10;i++)
			cout<<"Output must be "<<i<<". Output: "<<testVector.at(i)<<endl;
		testVector.erase(0);
		for(int i=0;i<9;i++)
			cout<<"Output must be "<<i+1<<". Output: "<<testVector.at(i)<<endl;
		testVector.set(2,3);
		cout<<"Output must be "<<3<<". Output: "<<testVector.at(2)<<endl;
		testVector.insert(5,25);
		cout<<"Output must be "<<6<<". Output: "<<testVector.at(6)<<endl;
		cout<<"Output must be "<<25<<". Output: "<<testVector.at(5)<<endl;
		cout<<"Output must be "<<5<<". Output: "<<testVector.at(4)<<endl;

		cout << "\nincremental array" << endl;

		for(int i=0;i<10;i++)
		testVector2.insert(i,i);
		for(int i=0;i<10;i++)
			cout<<"Output must be "<<i<<". Output: "<<testVector2.at(i)<<endl;
		testVector2.erase(0);
		for(int i=0;i<9;i++)
			cout<<"Output must be "<<i+1<<". Output: "<<testVector2.at(i)<<endl;
		testVector2.set(2,3);
		cout<<"Output must be "<<3<<". Output: "<<testVector2.at(2)<<endl;
		testVector2.insert(5,25);
		cout<<"Output must be "<<6<<". Output: "<<testVector2.at(6)<<endl;
		cout<<"Output must be "<<25<<". Output: "<<testVector2.at(5)<<endl;
		cout<<"Output must be "<<5<<". Output: "<<testVector2.at(4)<<endl;

		cout << "\ndoubling array" << endl;

		for(int i=0;i<10;i++)
		testVector3.insert(i,i);
		for(int i=0;i<10;i++)
			cout<<"Output must be "<<i<<". Output: "<<testVector3.at(i)<<endl;
		testVector3.erase(0);
		for(int i=0;i<9;i++)
			cout<<"Output must be "<<i+1<<". Output: "<<testVector3.at(i)<<endl;
		testVector3.set(2,3);
		cout<<"Output must be "<<3<<". Output: "<<testVector3.at(2)<<endl;
		testVector3.insert(5,25);
		cout<<"Output must be "<<6<<". Output: "<<testVector3.at(6)<<endl;
		cout<<"Output must be "<<25<<". Output: "<<testVector3.at(5)<<endl;
		cout<<"Output must be "<<5<<". Output: "<<testVector3.at(4)<<endl;
		
		cout << "\nSingly linked list" << endl;

		for(int i=0;i<10;i++)
		testVector4.insert(i,i);
		for(int i=0;i<10;i++)
			cout<<"Output must be "<<i<<". Output: "<<testVector4.at(i)<<endl;
		testVector4.erase(0);
		for(int i=0;i<9;i++)
			cout<<"Output must be "<<i+1<<". Output: "<<testVector4.at(i)<<endl;
		testVector4.set(2,3);
		cout<<"Output must be "<<3<<". Output: "<<testVector4.at(2)<<endl;
		testVector4.insert(5,25);
		cout<<"Output must be "<<6<<". Output: "<<testVector4.at(6)<<endl;
		cout<<"Output must be "<<25<<". Output: "<<testVector4.at(5)<<endl;
		cout<<"Output must be "<<5<<". Output: "<<testVector4.at(4)<<endl;

		
		
		cout << "\ndoubly linked list" << endl;

		for(int i=0;i<10;i++)
		testVector5.insert(i,i);
		for(int i=0;i<10;i++)
			cout<<"Output must be "<<i<<". Output: "<<testVector5.at(i)<<endl;
		testVector5.erase(0);
		for(int i=0;i<9;i++)
			cout<<"Output must be "<<i+1<<". Output: "<<testVector5.at(i)<<endl;
		testVector5.set(2,3);
		cout<<"Output must be "<<3<<". Output: "<<testVector5.at(2)<<endl;
		testVector5.insert(5,25);
		cout<<"Output must be "<<6<<". Output: "<<testVector5.at(6)<<endl;
		cout<<"Output must be "<<25<<". Output: "<<testVector5.at(5)<<endl;
		cout<<"Output must be "<<5<<". Output: "<<testVector5.at(4)<<endl;
		
	}
	catch (VectorException& se) {
        se.what();
    }
}