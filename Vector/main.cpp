#include "ArrayVector.h"
#include "DoublingArrayVector.h"
#include "IncrementalArrayVector.h"
#include "SLLVector.h"
#include "DLLVector.h"

#include <iostream>

using namespace std;


int main(){
	try{
		ArrayVector<double> testVector(10);
		DoublingArrayVector<int> testVector2(10);
		IncrementalArrayVector<int> testVector3(10);
		SLLVector<int> testVector4;
		DLLVector<int> testVector5;

		for(int i=0;i<100;i++){
			//testVector.insert(i,i);
			//testVector2.insert(i,i);
			//testVector3.insert(i,i);
			testVector5.insert(i,i);
		}
		/*
		cout << "index: " <<testVector.at(3) << endl;
		cout << testVector.size() << endl;
		cout << testVector.empty() << endl;

		cout << "Array Vector list" << endl;
		testVector.printElements();
		cout << "Doubling Vector list" << endl;
		testVector2.printElements();
		cout << "inc Vector list" << endl;
		cout << testVector3.size() << endl;
		cout <<	testVector4.size() << endl;
		testVector4.insert(5,45);
		
		for (int i = 0; i<testVector4.size();i++){
			cout << testVector4.at(i) << endl;
		}
		for (int i = 0; i<testVector4.size();i++){
			cout << testVector4.at(i) << endl;
		}
		testVector4.set(5,63);
		testVector4.erase(5);
		testVector4.erase(2);
		testVector4.erase(5);

		
		k\as
		cout << testVector4.printElements() << endl
		testVector4.insert(0,45);

		cout << "printing elements again" << endl;
		testVector.printElements();
		cout << testVector3.at(50) << endl;
		testVector2.resize();
		testVector3.resize(50);*/
		
	}
	catch (VectorException& se) {
        se.what();
    }
}