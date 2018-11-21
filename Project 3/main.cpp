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
#include <sstream> 

using namespace std;
//
int main(){

    try{

        srand((unsigned)time(0));
        int random_integer;
        string s1,s2,s3;

        ofstream logs;
        logs.open("results.csv");

        CStopWatch whole; //initializing stopwatch instance
        UnsortedPQ<int> upq;
        SortedPQ<int> spq;
        HeapPQ<int> hpq;



       /* 
        whole.Reset();
        logs << "UnsortedPQ,";
        for (int i=1;i<=50000;i++){
            random_integer = (rand()%100)+1;
            upq.insert(random_integer);
            if (i%50==0){
                s1 = to_string(whole.GetElapsedSeconds());
                logs << s1 << ",";
            }
        }
        logs << "\n";
        cout << to_string(whole.GetElapsedSeconds()) << "\n";

        whole.Reset();
        logs << "SortedPQ,";
        for (int i=1;i<=50000;i++){
            random_integer = (rand()%100)+1;
            spq.insert(random_integer);
            if (i%50==0){
                s2 = to_string(whole.GetElapsedSeconds());
                logs << s2 << ",";
            }
        }
        logs << "\n";
        cout << to_string(whole.GetElapsedSeconds()) << "\n";
        whole.Reset();

        logs << "HeapPQ,";
        for (int i=1;i<=50000;i++){
            random_integer = (rand()%100)+1;
            hpq.insert(random_integer);
            if (i%50==0){
                s3 = to_string(whole.GetElapsedSeconds());
                logs << s3 << ",";
            }
        }
        logs << "\n";
        cout << to_string(whole.GetElapsedSeconds()) << "\n";
        logs << "\n";

        ///////////////////////////////////////////////
        logs << "UnsortedPQ Removal,";
        whole.Reset();
        for (int i=1;i<=25000;i++){
            upq.removeMin();
            if (i%50==0){
                s1 = to_string(whole.GetElapsedSeconds());
                logs << s1 << ",";
            }
        }
        logs << "\n";
        cout << to_string(whole.GetElapsedSeconds()) << "\n";

        logs << "SortedPQ Removal,";
        whole.Reset();
        for (int i=1;i<=25000;i++){
            spq.removeMin();
            if (i%50==0){
                s2 = to_string(whole.GetElapsedSeconds());
                logs << s2 << ",";
            }
        }
        logs << "\n";
        cout << to_string(whole.GetElapsedSeconds()) << "\n";


        logs << "HeapPQ Removal,";
        whole.Reset();
        for (int i=1;i<=25000;i++){
            hpq.removeMin();
            if (i%50==0){
                s3 = to_string(whole.GetElapsedSeconds());
                logs << s3 << ",";
            }
        }
        logs << "\n";
        cout << to_string(whole.GetElapsedSeconds()) << "\n";

        logs.close();
        */



        //GET text file working!
        string line;
        int number;
        bool firstLine=true;
        bool secondLine=true;
        int typePQ;
        int sizePQ;
        UnsortedPQ<int> inputfilePQ0;
        SortedPQ<int> inputfilePQ1;
        HeapPQ<int> inputfilePQ2;
        ifstream myfile ("numbers.txt");
        if (myfile.is_open()){
            while ( myfile.good() ){
                getline (myfile,line);
                stringstream stringtoint(line); 
                
                if(firstLine){
                    stringtoint >> typePQ;
                    firstLine=false;
                    getline (myfile,line);
                }
                if(secondLine){
                    secondLine=false;
                    getline(myfile, line);
                    
                }
                stringtoint >> number;
                if(typePQ==0){
                    inputfilePQ0.insert(number);
                }
                else if(typePQ == 1){
                    inputfilePQ1.insert(number);
                }
                else if(typePQ == 1){
                    inputfilePQ2.insert(number);
                }
                //cout << number << endl;
            }
            myfile.close();
                if(typePQ==0){
                    cout << "unsortedPQ" << endl;
                    inputfilePQ0.printElements();
                }
                else if(typePQ == 1){
                     cout << "sortedPQ" << endl;
                    inputfilePQ1.printElements();
                }
                else if(typePQ == 2){
                    cout << "heapPQ" << endl;
                    //inputfilePQ2.printElements();
                }
        }
        else cout << "Unable to open file\n";
        
        






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
