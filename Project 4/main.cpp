#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "Mergesort.tpp"
#include "Quicksort.tpp"

using namespace std;

int main(int argc, char const *argv[]) {

    srand((unsigned)time(0));
    int random_integer;
    double random_double;


    unsigned int size = 1000000;
    double* passArray = new double[1000000];

    for (int i=0;i<size;i++){
        random_double = ((double) rand() / (RAND_MAX));
        passArray[i] = random_double;
        //cout << "->" << passArray[i];
    }
    cout << "\n";
    mergesort(passArray, 0, size-1);
    cout << "sorted!" << endl;
    /*for (int i=0;i<size;i++){
        cout << "->" << passArray[i];
    }*/
    cout << "\n";

    delete[] passArray;
    return 0;
}
