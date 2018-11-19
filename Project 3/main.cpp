#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"
#include "stopwatch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;
//
int main(){

    try{
        
        srand((unsigned)time(0));
        int random_integer;
        
        CStopWatch whole; //initializing stopwatch instance
        UnsortedPQ<int> upq;
        SortedPQ<int> spq;
        HeapPQ<int> hpq;
        
        whole.Reset();
        for (int i=1;i<=10;i++){
            random_integer = (rand()%100)+1;
            upq.insert(random_integer);
        }
        cout << to_string(whole.GetElapsedSeconds()) << "\n";

        whole.Reset();
        
        for (int i=1;i<=10;i++){
            random_integer = (rand()%100)+1;
            spq.insert(random_integer);
        }
        cout << to_string(whole.GetElapsedSeconds()) << "\n";
        whole.Reset();
        
        for (int i=1;i<=10;i++){
            random_integer = (rand()%100)+1;
            hpq.insert(random_integer);
        }
        cout << to_string(whole.GetElapsedSeconds()) << "\n";


        //HeapPQ<int> hpq;

       /* string line;
        ifstream myfile ("numbers.txt");
        if (myfile.is_open()){
            while ( myfile.good() ){
                getline (myfile,line);
                cout << line << endl;
            }
            myfile.close();
        }
        else cout << "Unable to open file\n";*/
        
        





        //cout << "printing list again" << endl;
        //spq.printElements();
        //


        //cout << dpq.size() << endl;
        //cout << "the min is " << dpq.minValue() << endl;//check

        //dpq.printElements();
        //
        return 0;


    }
    catch (PQException& se) {
        se.what();
    }

}
