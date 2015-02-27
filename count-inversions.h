#ifndef COUNT_INVERSIONS_H
#define COUNT_INVERSIONS_H

#include <algorithm>

namespace algolib {
/*
 * Iterator here is a random access iterator
 */
template<typename Iterator, typename Comparator> static int merge_count_inversions(Iterator first, Iterator mid,
        Iterator last,
        Iterator buffer_start,
        Comparator C);

// count is running total of number of array inversions.
template<typename Iterator, typename Comparator> void merge_sort_count_inversions(Iterator first, Iterator last,
                                                                  Iterator buffer, Comparator C, int& total_inversions);

/*
 * array[last] is last element in array
 */
template<typename T, typename Iterator, typename Comparator> int count_inversions(T *array, int first, int last, Comparator C)
{
   // allocate a working buffer for our merges
   T *work_buffer = new T[last + 1 - first];

   int inversions = 0; 

   merge_sort_count_array_inversions(array + first, array + last, work_buffer, C, inversions);
    
   delete [] work_buffer;

   return inversions;
}

// Returns number of array inversions
template<typename Iterator, typename Comparator> int merge_sort_count_inversions(Iterator first, Iterator last,
                                                                  Iterator buffer, Comparator c, int& total_inversions)
{
    // Base case: the range [first, last] can no longer be subdivided; it is of length one.
    if (first < last) {

        /*
         * 1. Divide data structure in a left, first half and second, right half.
         */ 

        int half_distance = (last - first) / 2; 
        
        Iterator mid = first + half_distance;

        /*
         * Recurse on the left half.
         */
        algolib::merge_sort_count_inversions(first, mid, buffer, c, total_inversions);

        /*
         * When left half recursion ends, recurse on right half of [first, last], which is [mid + , last]. 
         * Note: Both left and right descents implictly save the indecies of [first, mid] and [mid+1, last] on the stack.
         */
        algolib::merge_sort_count_inversions(mid + 1, last, buffer, c, total_inversions);

        /*
         * 2. When recursion ends, merge the two sub arrays [first, mid] and [mid+1, last] into a sorted array in [first, last]
         */ 
        total_inversions += algolib::merge_count_inversions(first, mid, last, buffer, c);
    }

    return total_inversions;
}

/*
 * Merges subarrays  [first, mid] and [mid + 1, last] into a sorted array in working buffer, buffer_start. Then copies
 * the working buffer over the original segement [first, last]
 */

template<typename Iterator, typename Comparator> static void merge_count_inversions(Iterator first, Iterator mid, Iterator last,
                                                                  Iterator buffer_start, Comparator compare, int& counter)
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
            // inversion found: second array element is larger.
            *buffer_cursor = *first2++;
             counter++; // TODO: check for correctness
        }
    }
    
    //TODO: add the inversions encountered below to counter

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
