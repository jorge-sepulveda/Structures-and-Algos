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
        cout << dpq.size() << endl;
        //
        return 0;
    }
    catch (PQException& se) {
        se.what();
    }

}
