#include "ArrayVector.h"
#include "DoublingArrayVector.h"
#include "IncrementalArrayVector.h"
#include "SLLVector.h"

#include <iostream>

using namespace std;


int main(){
	try{
		ArrayVector<double> testVector(10);
		DoublingArrayVector<int> testVector2(10);
		IncrementalArrayVector<int> testVector3(10);
		SLLVector<int> testVector4;

		for(int i=0;i<1000;i++){
			//testVector.insert(i,i);
			testVector2.insert(i,i);
			testVector3.insert(i,i);
			//testVector4.enqueue(i);
		}

		//cout << "index: " <<testVector.at(3) << endl;
		cout << testVector.size() << endl;
		cout << testVector.empty() << endl;

		//cout << "Array Vector list" << endl;
		//testVector.printElements();
		cout << "Doubling Vector list" << endl;
		testVector2.printElements();
		cout << "inc Vector list" << endl;
		testVector3.printElements();
		//testVector.insert(9,45);
		//testVector.erase(5);
		//cout << "printing elements again" << endl;
		//testVector.printElements();
		//cout << testVector3.at(50) << endl;
		//testVector2.resize();
		//testVector3.resize(50);
		//dfdsf
		
	}
	catch (VectorException& se) {
        se.what();
    }
}