#ifndef GERNEIC_MERGE_SORT_H
#define GERNEIC_MERGE_SORT_H

#include <cstring>

template<typename T> static void merge(T *a, int first, int mid, int last, T *buffer);
template<typename T> static void do_merge_sort(T *a, int first, int last, T *buffer);

template<typename T> void merge_sort(T *a, int first, int last)
{
    // allocate a working buffer for our merges
    T *buffer = new T[last + 1 - first];
    
    do_merge_sort<T>(a, first, last, buffer);
    
    delete [] buffer;
}

template<typename T> static void do_merge_sort(T *a, int first, int last, T *buffer)
{
    // base case: the range [first, last] can no longer be subdivided.
    if (first < last) {
        
        int mid = (first + last) / 2; // index of mid point
        
        do_merge_sort<T>(a, first, mid, buffer);    // sort left half
        do_merge_sort<T>(a, mid + 1, last, buffer); // sort right half
        
        // merge the two halves
        merge<T>(a, first, mid, last, buffer);
    }
}

template<typename T> static void merge(T *a, int first, int mid, int last, T *buffer)
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
