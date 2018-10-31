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
    for (int i = 0; i < 10000000; ++i)
    {
        //random_integer = rand() % 10;
        random_double = ((double) rand() / (RAND_MAX));
        //cout << random_double << endl;
        t2.insert(random_double);
        //cout << random_integer << endl;
    }
    //cout << "Tree in order: ";
    //t1.inOrder();
    //cout << "level order: \n";
    //t1.levelOrder();sdsd
    //cout << "height: " << t1.maxDepth() - 1 << endl;//s
    //cout << "nodes: "<< t1.getCount() << endl;
    cout << "height: " << t2.maxDepth() - 1 << endl;
    cout << "nodes: "<< t2.getCount() << endl;

    /*try{
        sd
        return 0;
    }
    catch (ArrayException& se) {
        se.what();
    }*/

}
