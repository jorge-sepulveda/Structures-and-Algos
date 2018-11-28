#include "Mergesort.h"
#include <iostream>


using namespace std;

int main(int argc, char const *argv[]) {
    int size = 19;
    double passArray[] = {5,4,3,2,1,1,3,4,2,5,3,6,7,8,4,3,5,6};

    Mergesort<double> m1(passArray, size);

    m1.mergesort(m1.items, 0, m1.size-1);

    m1.printArray();
    //cout << 0 << endl;
    return 0;
}
