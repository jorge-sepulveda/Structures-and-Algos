# Programming Assignment 3

## Priority Queues

There are three different implentations of the Priority Queue. An unsorted linked list,
a sorted linked list and an array based heap.

### initialization

```c++
UnsortedPQ<T> upq;
SortedPQ<T> spq;
HeapPQ<T> hpq;
```

### Priority Queue Functions:
  - insert(T e) : inserts e into the Queue
  - removeMin() : removes the minimum
  - printElements() : prints all the elements in the structures
  - empty() : returns a boolean if there is anything in the Queues
  - size() : returns the current size of the queue



### how to run it

I've included a makefile so we can easily compile it by typing make.

```sh
$ make
$ ./main
```

You can also compile it running g++
```sh
g++ -std=c++11 main.cpp -o main
./main
```
