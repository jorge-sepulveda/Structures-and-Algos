#include "Tree.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

/*
 *Author: Jorge Sepulveda
 *Date: 10/29/2018
 *Class: CSCE 221
 *Programming assignment 2
 */

using namespace std;

int main(){

    srand((unsigned)time(0));
    int random_integer;
    double random_double;

    cout << "making happy little trees" << endl;//sdsddsdsdf
    Tree<int> t1;
    Tree<double> t2;

    ofstream logs;
    logs.open("results.csv");
    logs << "Number of nodes, Int Tree height, Double Tree Height\n";
        
    for (int i = 1; i <= 30000; ++i)
    {
        random_integer = rand() % 10;
        random_double = ((double) rand() / (RAND_MAX));
        //cout << random_double << endl;
        t1.insert(random_integer);
        t2.insert(random_double);
        //cout << random_integer << endl;
        //every i intervals, get the height and log it.
        if (i%50==0){
            logs << i << ", " << t1.maxDepth()-1 << ", " << t2.maxDepth()-1 << "\n";
            //cout << "t1 height: " << t1.maxDepth() - 1 << endl;
            //cout << "t2 height: " << t2.maxDepth() - 1 << endl;
        }  
    }
    logs.close();

    

}
