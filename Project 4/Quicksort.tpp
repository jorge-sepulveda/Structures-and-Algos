#include <iostream>

using namespace std;


template <class T>
void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
int partition(T* arr, int low, int high){

    srand((unsigned)time(0));

    int p = (rand()%(high-low + 1) + low);

    Swap(arr[p], arr[low]);
    T pivot = arr[low];
    int left = low;

    for (int i = (low+1); i <= high;i++){
        if (arr[i] < pivot){
            left +=1;
            Swap(arr[i], arr[left]);
        }
    }
    Swap(arr[low], arr[left]);
    return left;

}

template <class T>
void Qsort(T* arr, int first, int last){
    if (first < last){
        int pivot = partition(arr, first, last);
        Qsort(arr, first, pivot-1);
        Qsort(arr, pivot+1, last);
    }
}
