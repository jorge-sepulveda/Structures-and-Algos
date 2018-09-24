#ifndef ABSTRACT_QUEUE_H
#define ABSTRACT_QUEUE_H

#include <iostream>

template <class Type>
class AbstractQueue
{
private:
    // data goes here

public:
    //AbstractQueue(int s);
        
    AbstractQueue() {}
        
    ~AbstractQueue(void) {}
        
    bool empty();
        
    int size();
        
    Type frontele(); //throw(exception) {}
        
    Type dequeue(); //throw(exception) {}
           
    void enqueue ( Type e );
};


#endif