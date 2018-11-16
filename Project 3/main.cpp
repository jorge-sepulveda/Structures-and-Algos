#include "UnsortedPQ.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

int main(){

    try{
        cout << "hello world" << endl;
        UnsortedPQ<int> dpq;

        dpq.insert(5);
        dpq.insert(6);
        dpq.insert(7);
        dpq.insert(3);
        dpq.insert(10);
        cout << dpq.removeMin() << endl;
        cout << dpq.removeMin() << endl;
        cout << dpq.removeMin() << endl;
        cout << dpq.removeMin() << endl;
        //cout << dpq.size() << endl;/
        //cout << "the min is " << dpq.minValue() << endl;//check

        //dpq.printElements();
        //
        return 0;
    }
    catch (PQException& se) {
        se.what();
    }

}
