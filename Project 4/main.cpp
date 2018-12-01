#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "Mergesort.tpp"
#include "Quicksort.tpp"
#include "stopwatch.h"

using namespace std;

int main(int argc, char const *argv[]) {

    srand((unsigned)time(0));
    int random_integer;
    double random_double;

    CStopWatch timer;

    unsigned int size = 1000000;

    int* qIntArray = new int[1000000];
    int* mIntArray = new int[1000000];

    double* qDoubleArray = new double[1000000];
    double* mDoubleArray = new double[1000000];



    for (int i=0;i<size;i++){
        random_double = ((double) rand() / (RAND_MAX));
        qDoubleArray[i] = random_double;
        mDoubleArray[i] = random_double;
    }

    for (int i = 0; i<size;i++){
        random_integer = (rand()%10)+1;
        qIntArray[i] = random_integer;
        mIntArray[i] = random_integer;
    }

    timer.Reset();
    Qsort(qDoubleArray, 0, size-1);
    cout << "Double Quicksort time: ";
    cout << to_string(timer.GetElapsedSeconds()) << endl;

    timer.Reset();
    mergesort(mDoubleArray, 0, size-1);
    cout << "Double Mergesort time: ";
    cout << to_string(timer.GetElapsedSeconds()) << endl;

    timer.Reset();
    Qsort(qIntArray, 0, size-1);
    cout << "Int Quicksort time: ";
    cout << to_string(timer.GetElapsedSeconds()) << endl;

    timer.Reset();
    mergesort(mIntArray, 0, size-1);
    cout << "int Mergesort time: ";
    cout << to_string(timer.GetElapsedSeconds()) << endl;


    /*for (int i=0;i<intSize;i++){

        random_integer = (rand()%100)+1;
        intArray[i] = random_integer;
    }*/

    delete[] qIntArray;
    delete[] mIntArray;
    delete[] mDoubleArray;
    delete[] qDoubleArray;

    return 0;
}
