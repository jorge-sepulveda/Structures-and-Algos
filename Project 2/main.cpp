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

    cout << "making happy little trees" << endl;
    Tree<int> t1;
    Tree<double> t2;

    ofstream logs;
    logs.open("results.csv");
    logs << "Number of nodes, Int Tree height, Double Tree Height\n";
        
    for (int i = 1; i <= 1000; ++i)
    {
        random_integer = rand() % 10;
        random_double = ((double) rand() / (RAND_MAX));
        t1.insert(random_integer);
        t2.insert(random_double);
        //every i intervals, get the height and log it.
        if (i%10==0){
            logs << i << ", " << t1.maxDepth()-1 << ", " << t2.maxDepth()-1 << "\n";
        }  
    }
    logs.close();

    //t1.levelOrder();
    //t1.inOrder();

    

}
