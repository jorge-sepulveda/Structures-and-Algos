#include "ArrayVector.h"

#include <iostream>

using namespace std;


int main(){
	try{
		ArrayVector<int> testVector(10);

		for(int i=0;i<10;i++){
			testVector.insert(i,i);
		}

		cout << "index: " <<testVector.at(3) << endl;
		cout << testVector.size() << endl;
		cout << testVector.empty() << endl;

		testVector.printElements();
		testVector.erase(5);
		cout << "printing elements again" << endl;
		testVector.printElements();
		cout << testVector.at(10) << endl;

	}
	catch (VectorException& se) {
        se.what();
    }
}