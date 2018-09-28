#ifndef _ABSTRACT_VECTOR_H
#define _ABSTRACT_VECTOR_H


//Inherit the below class in all your vector implementations
template <class T>
class AbstractVector {
    public:
    
    virtual T at(int i) = 0;
    
    virtual void set(int i, T o) = 0;
    
    virtual void insert(int i, T o) = 0;
    
    virtual void erase(int i) = 0;
    
    virtual int size() = 0;
    
    virtual bool empty() = 0;
    
};

#endif