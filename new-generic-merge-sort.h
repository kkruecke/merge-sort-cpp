#ifndef GERNEIC_MERGE_SORContainer_H
#define GERNEIC_MERGE_SORContainer_H

#include <cstring>

template<typename Iter> static void merge(Iter start, int first, int mid, int last, Iter buffer_start);
template<typename Iter> static void do_merge_sort(Iter start, int first, int last, Iter buffer_start);


/*
 * Main merge sort algorithm. The other methods--do_merge_sort() and merge()--are ancillary
 */ 
template<typename Container> void merge_sort(Container& a, int first, int last)
{
    // allocate a working buffer for our merges
    //--Container *buffer = new Container[last + 1 - first]; 
    
    std::array<Container::value_type, int> buffer(last + 1 - first); // replaced heap allocation with std:array<>
    
    // TODO: use auto? 
    do_merge_sort<Container>(a.begin(), first, last, buffer);
    
//--delete [] buffer;
}

template<typename Iter> static void do_merge_sort(Iter start, int first, int last, Iter buffer_start)
{
    // base case: the range [first, last] can no longer be subdivided.
    if (first < last) {
        
        int mid = (first + last) / 2; // index of mid point
        
        do_merge_sort<Container>(a, first, mid, buffer);    // sort left half
        do_merge_sort<Container>(a, mid + 1, last, buffer); // sort right half
        
        // merge the two halves
        merge<Container>(a, first, mid, last, buffer);
    }
}

//--template<typename Container> static void merge(Container *a, int first, int mid, int last, Container *buffer)
template<typename Iter> static void merge(Container *a, int first, int mid, int last, Container *buffer)
{
    int first1 = first;  
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    
    int index = 0;
    /* 
     * While both subarrays are not empty, copy the smaller item into the 
     * temporary array.
     */
    for (; first1 <= last1 && first2 <= last2; ++index) {  
        
        if (a[first1] < a[first2]) {
            
            buffer[index] = a[first1];
            first1++;
        } else {
            
            buffer[index] = a[first2];
            first2++;
        }
    }
    
    // finish off the first subarray, if necessary
    for (;first1 <= last1; first1++, index++) {
        
        buffer[index] = a[first1];
    }
    
    // finish off the second subarray, if necessary
    for (;first2 <= last2; first2++, index++) {
        
        buffer[index] = a[first2];
    }
         
    // copy the temp array to the original array
    int start = first;
    int length = last + 1 - first;
    
    for (index = 0; index < length; ++index, ++start) {
        
        a[start] = buffer[index];
    }
}
#endif
