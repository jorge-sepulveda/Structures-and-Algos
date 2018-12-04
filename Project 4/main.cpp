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
    ofstream logs;
    logs.open("results.csv");

    CStopWatch timer;

    unsigned int size = 10000;

    logs << "Size, qsortdouble, msortdouble, qsortint, msortint\n";
    //1000000
    for(int i = 50000;i<=1000000;i+=50000){

        int* qIntArray = new int[i];
        int* mIntArray = new int[i];

        double* qDoubleArray = new double[i];
        double* mDoubleArray = new double[i];

        //inserting values into array size
        for (int j=0;j<i;j++){
            random_double = ((double) rand() / (RAND_MAX));
            qDoubleArray[j] = random_double;
            mDoubleArray[j] = random_double;
            random_integer = (rand()%10)+1;
            qIntArray[j] = random_integer;
            mIntArray[j] = random_integer;
        }

        cout << "size is: " << i << endl;
        logs << i << ", ";
        timer.Reset();
        Qsort(qDoubleArray, 0, i-1);
        //cout << "Double Quicksort time: ";
        logs << to_string(timer.GetElapsedSeconds()) << ",";

        timer.Reset();
        mergesort(mDoubleArray, 0, i-1);
        //cout << "Double Mergesort time: ";
        logs << to_string(timer.GetElapsedSeconds()) << ",";

        timer.Reset();
        Qsort(qIntArray, 0, i-1);
        //cout << "Int Quicksort time: ";
        logs << to_string(timer.GetElapsedSeconds()) << ",";

        timer.Reset();
        mergesort(mIntArray, 0, i-1);
        //cout << "int Mergesort time: ";
        logs << to_string(timer.GetElapsedSeconds()) << ",";
        logs << "\n";

        delete[] qIntArray;
        delete[] mIntArray;
        delete[] mDoubleArray;
        delete[] qDoubleArray;
    }

    //file reading
    int T, N;

    ifstream f;

    f.open("numbers.txt");
    f >> T >> N;

    int a[N];

    for (int i = 0; i < N; i++) {
        f >> a[i];
    }

    f.close();

    //unsorted Input
        cout << "Unsorted input:     ";
    for (int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
    if(T == 1){
        cout << "Mergesort selected: ";
        mergesort(a, 0, N-1);
    }
    else if(T==2){
        cout << "Quicksort selected: ";
        Qsort(a, 0, N-1);
    }
    //sorted
    for (int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}
