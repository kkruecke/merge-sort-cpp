#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <algorithm>

namespace algolib {
/*
 * Two different iterator types might not actually needed. It may be that a random access iterator type is always required for both.
 */
template<typename Iterator, typename Comparator> static void merge(Iterator first, Iterator mid,
        Iterator last,
        Iterator buffer_start,
        Comparator C);

template<typename Iterator, typename Comparator> static void merge_sort(Iterator first, Iterator last,
                                                                  Iterator buffer, Comparator C);

template<typename T, typename Iterator, typename Comparator> void merge_sort(Iterator first, Iterator last, Comparator C)
{
   // allocate a working buffer for our merges
   T *temp_buffer = new T[last + 1 - first];
    
   merge_sort(first, last, temp_buffer, C);
    
   delete [] temp_buffer;
}

template<typename Iterator, typename Comparator> static void merge_sort(Iterator first, Iterator last,
                                                                  Iterator buffer, Comparator c) 
{
    // Base case: the range [first, last] can no longer be subdivided; it is of length one.
    if (first < last) {

        /*
         * 1. Divide data structure in a left, first half and second or right half.
         */ 

        int half_distance = (last - first) / 2; 
        
        Iterator mid = first + half_distance;

        /*
         * Recurse passing as input the left half.
         */
        algolib::merge_sort(first, mid, buffer, c);    

        /*
         * When left half recursion end, recurse passing as input on right half of [first, last], which is [mid + , last]. 
         * Note: Both descents--left and right--implictly save the indecies of [first, mid] and [mid+1, last] on the stack.
         */
        algolib::merge_sort(mid + 1, last, buffer, c);

        /*
         * 2. Conquer by merging the sub arrays [first, mid] and [first, last] into a sorted array in [first, last]
         */ 
        algolib::merge(first, mid, last, buffer, c); // merge/sort step
    }
}

/*
 * Merges subarrays  [first, mid] and [mid + 1, last] into a sorted array in working buffer, buffer_start. Then copies the working buffer 
 * over the original segement [first, last]
 */

template<typename Iterator, typename Comparator> static void merge(Iterator first, Iterator mid, Iterator last,
                                                                  Iterator buffer_start, Comparator compare)
{
    Iterator first1 = first;
    Iterator last1 = mid;
    
    Iterator first2 = mid + 1;
    Iterator last2 = last;
        
    int index = 0;
    
    /* 
     * While both sub-arrays are not empty, copy the smaller item into the 
     * temporary array buffer.
     */
    Iterator buffer_cursor = buffer_start;
    
    for (; first1 <= last1 && first2 <= last2; ++buffer_cursor) {
        
        if ( compare(*first1, *first2) ) {
            
            *buffer_cursor = *first1++;

        } else {
            
            *buffer_cursor = *first2++;
        }
    }
    
    // finish off the first sub-array, if necessary
    for (;first1 <= last1; ++first1, ++buffer_cursor) {
        
        *buffer_cursor = *first1;
    }
    
    // finish off the second sub-array, if necessary
    for (;first2 <= last2; ++first2, ++buffer_cursor) {
        
        *buffer_cursor = *first2;
    }
         
   // Copy the temp array to the original array
   int length = last + 1 - first;

   Iterator start = buffer_start;
   
    for (Iterator end = start + length; start != end;) {
        
        *first++ = *start++;
    }
    
}

} // end namespace algolib
#endif
