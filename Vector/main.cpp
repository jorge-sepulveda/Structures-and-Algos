#include "ArrayVector.h"
#include "DoublingArrayVector.h"

#include <iostream>

using namespace std;


int main(){
	try{
		ArrayVector<double> testVector(10);
		DoublingArrayVector<int> testVector2(10);

		for(int i=0;i<10;i++){
			testVector.insert(i,i);
			testVector2.insert(i,5);
		}

		cout << "index: " <<testVector.at(3) << endl;
		cout << testVector.size() << endl;
		cout << testVector.empty() << endl;

		cout << "Array Vector list" << endl;
		testVector.printElements();
		cout << "Doubling Vector list" << endl;
		testVector2.printElements();
		//testVector.insert(9,45);
		testVector.erase(5);
		cout << "printing elements again" << endl;
		testVector.printElements();
		cout << testVector.at(10) << endl;

	}
	catch (VectorException& se) {
        se.what();
    }
}