#include "DoublingPQ.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

int main(){

    try{
        cout << "hello world" << endl;
        DoublingPQ<int> dpq;

        dpq.insert(5);
        dpq.insert(6);
        dpq.insert(7);
        dpq.insert(3);
        cout << dpq.size() << endl;
        cout << "the min is " << dpq.minValue() << endl;//check
        //
        return 0;
    }
    catch (PQException& se) {
        se.what();
    }

}
