#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

//
int main(){

    try{
        UnsortedPQ<int> dpq;
        SortedPQ<int> spq;
        HeapPQ<int> hpq;

       /* string line;
        ifstream myfile ("numbers.txt");
        if (myfile.is_open()){
            while ( myfile.good() ){
                getline (myfile,line);
                cout << line << endl;
            }
            myfile.close();
        }
        else cout << "Unable to open file\n";*/

        spq.insert(5);
        spq.insert(4);
        spq.insert(4);
        spq.insert(5);
        spq.insert(6);
        spq.insert(7);
        spq.insert(3);
        spq.insert(10);
        spq.insert(9);
        spq.insert(8);
        spq.insert(15);
        spq.insert(16);
        spq.insert(12);
        spq.insert(11);
        spq.insert(20);
        spq.insert(25);
        spq.insert(1);
        spq.insert(2);
        //yoooo
        spq.printElements();
        cout << "removing some mins" << endl;


        cout << spq.removeMin() << endl;
        cout << spq.removeMin() << endl;
        cout << spq.removeMin() << endl;
        cout << spq.removeMin() << endl;
        cout << spq.removeMin() << endl;
        cout << spq.removeMin() << endl; 

        spq.insert(11);
        spq.insert(20);
        spq.insert(25);
        spq.insert(1);
        spq.insert(2);

        cout << "printing list again" << endl;
        spq.printElements();
        //
        //cout << dpq.size() << endl;
        //cout << "the min is " << dpq.minValue() << endl;//check

        //dpq.printElements();
        //
        return 0;
    }
    catch (PQException& se) {
        se.what();
    }

}
