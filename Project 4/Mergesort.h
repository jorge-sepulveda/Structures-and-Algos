#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>

using namespace std;

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class T>
class Mergesort
{
private:
	// data here



public:

    T* items;

    int size;

    Mergesort(T* data, int s );

    void merge(T arr[], int l, int m, int r);

    void mergesort(T arr[], int l, int r);

    void printArray();
};

template <class T>
Mergesort<T>::Mergesort(T* data, int s){
    cout << "Constructor called" << endl;
    items = data;
    size = s;
}

template <class T>
void Mergesort<T>::merge(T* arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    T L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}

template <class T>
void Mergesort<T>::printArray(){
    for(int i=0;i<size;i++){
        cout << items[i] << endl;
    }
}

template <class T>
void Mergesort<T>::mergesort(T* arr, int l, int r){
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

#endif
