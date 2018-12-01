#include <iostream>

using namespace std;

template <class T>
int partition(T* arr, int low, int high){

    srand((unsigned)time(0));

    int l = low;
    int h = high;
    
    T temp;

    T pivot = arr[(rand()%(high-low + 1) + low)];




}
