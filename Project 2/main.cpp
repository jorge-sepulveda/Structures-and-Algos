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

    cout << "hi" << endl;//sdsddsdsdf
    Tree<int> t1;
    t1.insert(20);
    t1.insert(8);
    t1.insert(22);
    t1.insert(4);
    t1.insert(12);
    t1.insert(21);
    t1.insert(23);
    t1.insert(2);
    t1.insert(5);
    t1.insert(9);
    t1.insert(15);

    /*for (int i = 0; i < 100; ++i)
    {
        //random_integer = (rand()%10000)+1;
        t1.insert(i);
    }*/
    //cout << "Tree in order: ";
    //t1.inOrder();
     cout << "level order: \n";
    t1.levelOrder();
    cout << "\n";

    /*try{
        sd
        return 0;
    }
    catch (ArrayException& se) {
        se.what();
    }*/

}
