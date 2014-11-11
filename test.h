#ifndef TEST_H
#define TEST_H

#include <iostream>

//--template<typename T> void merge_sort(T *a, int first, int last)
template<typename Container> void test(Container &c)
{
    auto  first = c.begin();
    auto  end = c.end();
    auto  last = end - 1;
    
    decltype(Container::value_type) x;

    // allocate a working buffer for our merges
    //--T *buffer = new T[last + 1 - first]; // T is Iter::value_type
    
    //x *buffer = new x[last + 1 - first]; // T is Iter::value_type
    /*
        
    delete [] buffer;
     */ 
}
#endif