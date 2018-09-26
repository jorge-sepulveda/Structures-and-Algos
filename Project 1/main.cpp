#include "IncrementalQueue.h"
#include "DoublingQueue.h"
#include "LinkedListQueue.h"
#include "stopwatch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

int main(){

    try{
        CStopWatch whole;
        whole.Reset();

        //opening a CSV file to output the times.
        std::ofstream logs;
        logs.open("results.csv");
        logs << "Input Size, Average Time(ArrayQueue), Average Time(DoublingQueue), Average Time(Linked List), , T1 for incarray , T1 for doubarray, T1 for linkedlist , , T2 for IA , T2 for DA, T2 for LL, , T3 for IA, T3 for DA, T3 for LL\n";
        CStopWatch stopwatch; //initializing stopwatch instance

        srand((unsigned)time(0));
        int random_integer;
        int input = 100000;
        std::string s1; //saves seconds for the ArrayQueue
        std::string s2; //saves seconds for the doublingarray
        std::string s3; //saves seconds for the linkedlist array
        std::string s;
        std::string seperator = ", , , ,";

		//initializing Queue objects
        IncrementalQueue<int> incqueue(10000);
        DoublingQueue<int> doubqueue(10000);
        LinkedListQueue<int> linkedqueue;

        /*This nested for loop is what runs the different processes and logs them into a CSV file.
        Every loop, the inner for loop will run the enqueue operations for each queue three times up until i reaches the end.
        Every loop, the objects will be deconstructed and reinitalized at the same initial size to start from scratch.
        //as i increases the input size will increase by 100,000 until i times.
        Test case variables used: i = 100, j = 3. */

        for (int i = 0; i<3;i++){
            logs << input;
            logs << seperator;

            for(int j=0;j<6;j++){

                stopwatch.Reset();
                for (int i=1;i<=input;i++){
                random_integer = (rand()%50)+1;
                incqueue.enqueue(random_integer);
                }
                s1 = std::to_string(stopwatch.GetElapsedSeconds());

                stopwatch.Reset();
                for (int i=1;i<=input;i++){
                    random_integer = (rand()%50)+1;
                    doubqueue.enqueue(random_integer);
                }
                s2 = std::to_string(stopwatch.GetElapsedSeconds());

                stopwatch.Reset();
                for (int i=1;i<=input;i++){
                    random_integer = (rand()%50)+1;
                    linkedqueue.enqueue(random_integer);
                }
                s3 = std::to_string(stopwatch.GetElapsedSeconds());

                incqueue.~IncrementalQueue();
                new(&incqueue) IncrementalQueue<int>(10000);
                doubqueue.~DoublingQueue();
                new(&doubqueue) DoublingQueue<int>(10000);
                linkedqueue.~LinkedListQueue();
                new(&linkedqueue) LinkedListQueue<int>();

                logs << ",  " << s1 << ", " << s2 << ", " << s3 << ", ";
            }
            logs << "\n";
            input+=100000;
        }//end for loop and adding some extra stuff
        //by this point, the items are already updated

        //doing basic operations for the different queues
        incqueue.enqueue(6);
        incqueue.enqueue(9);
        incqueue.enqueue(12);
        incqueue.enqueue(16);
        incqueue.enqueue(19);

        doubqueue.enqueue(7);
        doubqueue.enqueue(10);
        doubqueue.enqueue(13);
        doubqueue.enqueue(17);
        doubqueue.enqueue(20);

        linkedqueue.enqueue(5);
        linkedqueue.enqueue(8);
        linkedqueue.enqueue(11);
        linkedqueue.enqueue(15);
        linkedqueue.enqueue(18);

        std::cout << "front is " << incqueue.frontelem() << " from the IncrementalQueue\n";
        std::cout << "front is " << doubqueue.frontelem() << " from the DoublingQueue\n";
        std::cout << "front is " << linkedqueue.frontelem() << " from the LinkedListQueue\n";

        std::cout << "size is " << incqueue.size() << " from the IncrementalQueue\n";
        std::cout << "size is " << doubqueue.size() << " from the DoublingQueue\n";
        std::cout << "size is " << linkedqueue.size() << " from the LinkedListQueue\n";

        std::cout << "Dequeued " << incqueue.dequeue() << " from the IncrementalQueue\n";
        std::cout << "Dequeued " << doubqueue.dequeue() << " from the DoublingQueue\n";
        std::cout << "Dequeued " << linkedqueue.dequeue() << " from the LinkedListQueue\n";

        std::cout << "front is " << incqueue.frontelem() << " from the IncrementalQueue\n";
        std::cout << "front is " << doubqueue.frontelem() << " from the DoublingQueue\n";
        std::cout << "front is " << linkedqueue.frontelem() << " from the LinkedListQueue\n";

        std::cout << "is empty? " << incqueue.empty() << " from the IncrementalQueue\n";
        std::cout << "is empty? " << doubqueue.empty() << " from the DoublingQueue\n";
        std::cout << "is empty? " << linkedqueue.empty() << " from the LinkedListQueue\n";

        stopwatch.Reset();
        std::cout << std::to_string(whole.GetElapsedSeconds()) << "\n";
        //closing the CSV file
        //extra comments here
        //more comments here.
        
        logs.close();
        return 0;
    }
    catch (ArrayException& se) {
        se.what();
    }

}
