#include "UnsortedPQ.h"
#include "SortedPQ.h"
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

        string line;
        ifstream myfile ("numbers.txt");
        if (myfile.is_open()){
            while ( myfile.good() ){
                getline (myfile,line);
                cout << line << endl;
            }
            myfile.close();
        }
        else cout << "Unable to open file\n";

        dpq.insert(5);
        dpq.insert(6);
        dpq.insert(7);
        dpq.insert(3);
        dpq.insert(10);
        cout << dpq.removeMin() << endl;
        cout << dpq.removeMin() << endl;
        cout << dpq.removeMin() << endl;
        cout << dpq.removeMin() << endl;
        dpq.insert(8);
        dpq.insert(67);
        dpq.insert(23);
        dpq.insert(2);
        dpq.insert(14);
        dpq.printElements();


        //cout << dpq.removeMin() << endl;
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
