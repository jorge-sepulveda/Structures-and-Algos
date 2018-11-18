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


        //HeapPQ<int> hpq;

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

        hpq.insert(1);
        hpq.insert(5);
        hpq.insert(4);
        hpq.insert(3);
        hpq.insert(2);
        hpq.insert(1);
        hpq.insert(3);
        hpq.insert(5);



        cout << "removed: " <<  hpq.removeMin() << endl;
        cout << "removed: " <<  hpq.removeMin() << endl;
        cout << "removed: " <<  hpq.removeMin() << endl;
        cout << "removed: " <<  hpq.removeMin() << endl;
        cout << "removed: " <<  hpq.removeMin() << endl;
        cout << "removed: " <<  hpq.removeMin() << endl;
        //hpq.removeMin();//yee

        hpq.printElements();
        cout << "removing some mins" << endl;





        //cout << "printing list again" << endl;
        //spq.printElements();
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
