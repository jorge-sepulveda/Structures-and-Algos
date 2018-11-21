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
         * Down here are all the insertions into the PQ's and it's removals
         * The times are being logged into csv file called results.csv
        */



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




        /**
         *Down here is where the text file is being read and PQ's are being initialized
         * depending on the T variable input. It will create the proper PQ and removes
         * all of it's elements using RemoveMin
        */


        UnsortedPQ<int> inputfilePQ0;
        SortedPQ<int> inputfilePQ1;
        HeapPQ<int> inputfilePQ2;

        int T, N;

        ifstream f;

        f.open("numbers.txt");
        f >> T >> N;

        int a [N];

        for (int i = 0; i < N; i++) {
        	f >> a[i];
        }

        f.close();

        for (int i = 0; i < N; i++) {
          if(T==0){
            inputfilePQ0.insert(a[i]);
          }
          else if(T==1){
            inputfilePQ1.insert(a[i]);
          }
          else if(T==2){
            inputfilePQ2.insert(a[i]);
          }
        	//cout << a[i] << endl;
        }

        if(T==0){
          cout << "UnsortedPQ " << endl;
        }
        else if(T==1){
          cout << "SortedPQ " << endl;
        }
        else if(T==2){
          cout << "HeapPQ" <<  endl;
        }


        for (int i = 0; i < N; i++) {
          if(T==0){
            cout << "removed: " <<  inputfilePQ0.removeMin() << endl;
          }
          else if(T==1){
            cout << "removed: " <<  inputfilePQ1.removeMin() << endl;
          }
          else if(T==2){
            cout << "removed: " <<  inputfilePQ2.removeMin() << endl;
          }
        	//cout << a[i] << endl;
        }


        return 0;


    }
    catch (PQException& se) {
        se.what();
    }

}
