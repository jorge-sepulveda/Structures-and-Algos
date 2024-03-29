#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <exception>

using namespace std;

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class Type>
class PriorityQueue
{
private:
	// data here

public:
   PriorityQueue(void) {}

   // Performs an insertion of "n" items from dataArray into the priority queue
   // BONUS: perform a bottomup heap construction for the heap.  Compare the time it takes to perform a
   // bottom up construction to inserting n items in your experimental section of your report.
   PriorityQueue ( Type *dataArray, int n ) {}

   ~PriorityQueue(void) {}

   bool empty(void) {}

   int size(void) {}

   // inserts a piece of data into the priority queue
   void insert ( Type data ) {}

   // removes and returns the minimum value in the queue
   // you must handle the error if the queue is empty
   Type removeMin ( void ) {}

   // return the minimum value in the queue without removing it
   // you must handle the error if the queue is empty
   Type minValue ( void ) {}
};

#endif