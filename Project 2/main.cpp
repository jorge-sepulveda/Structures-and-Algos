#include "Tree.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int main(){

    srand((unsigned)time(0));
    int random_integer;

    cout << "hi" << endl;//sdsddsd
    Tree<int> t1;
    t1.insert(50);
    for (int i = 0; i < 100; ++i)
    {
        random_integer = (rand()%10000)+1;
        t1.insert(random_integer);
        /* code */
    }
    cout << "Tree in order: ";
    t1.inOrder();
    cout << "\n";

    /*try{
        sd
        return 0;
    }
    catch (ArrayException& se) {
        se.what();
    }*/

}
