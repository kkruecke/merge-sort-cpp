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

/*
 * Iterative version of Merge Sort 
 * ===============================
 *
 * Code below is a convert C++11 version of this java code:
 * http://www.sinbadsoft.com/blog/a-recursive-and-iterative-merge-sort-implementations/
*/
// Fwd ref.
template<typename T, typename Iterator, typename Comparator > static void iter_merge(Iterator first, int start, int middle, int end, Comparator comparer,
                              T *work_buffer); 

template<typename T, typename Iterator, typename Comparator> Iterator iter_merge_sort(Iterator first, Iterator last, Comparator comparer)
{
    auto length = last + 1 - first;

    T *work_buffer = new T[length]; 

    /*
     * Traverse array input from beginning to end, sorting adjacent subarrays from the bottom up. Subarrays are always a power of 2 in size, starting 
     * with size one (2 to the zero), then 2 (2 to the first), 4 (2 to the second) and so on. The number of iterations is:
     * 
     *   log base 2(length) rounded up. 
     */
    for (int width = 1; width <= length / 2 + 1; width *= 2) {
        
        /*
         * merge adjacent subarrays of size width
         */  

        for (int start = width; start < length; start += 2 * width)  { // (2 * width) == sum of lengths of both subarrays.

            algolib::iter_merge(first, start - width, start, std::min<decltype(start)>(start + width, length), comparer, work_buffer); 
        }
    }
    
    delete [] work_buffer;
    
    return first;
}

template<typename T, typename Iterator, typename Comparator > static void iter_merge(Iterator input, int start, int middle, int end, Comparator comparer, T *work_buffer)
{
    auto length = end - start;

    auto left = 0, right = 0, current = 0;

    while (left < middle - start && right < end - middle)     {
         
        if ( comparer(input[start + left], input[middle + right]) ) {

           work_buffer[current++] = input[start + left++];

        } else {  

            work_buffer[current++] = input[middle + right++];

        }
    }
 
    while (right < end - middle) {

         work_buffer[current++] = input[middle + right++];
    }
 
    while (left < middle - start) {

         work_buffer[current++] = input[start + left++];
    }
 
    std::copy(work_buffer, work_buffer + length, input + start); // copy to start
   
}


} // end namespace algolib
#endif
