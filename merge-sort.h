#ifndef MERGE_SORT_H
#define MERGE_SORT_H

namespace algolib {
/*
 * Two different iterator types might not actually needed. It may be that a random access iterator is always required for both.
 */
template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge(Iterator_type1 first, Iterator_type1 mid,
        Iterator_type1 last,
        Iterator_type2 buffer_start,
        Comparator C);

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator C);

template<typename T, typename Iterator, typename Comparator> void merge_sort(Iterator first, Iterator last, Comparator C)
{
   // allocate a working buffer for our merges
   T *temp_buffer = new T[last + 1 - first];
    
   do_merge_sort(first, last, temp_buffer, C);
    
   delete [] temp_buffer;
}

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator c) 
{
    // Base case: the range [first, last] can no longer be subdivided, i.e., it is of length one.
    if (first < last) {

        /*
         * 1. Divide: Subdivide into left and right halves, saving the indecies of [first, mid] and [mid+1, last] on the stack.
         */ 

        int mid = (last - first) / 2; // index of mid point
        
        Iterator_type1 mid_iterator = first + mid;

        Iterator_type1 mid_iterator_plus1 = mid_iterator + 1;

        /*
         * Recurse on left half
         */
        do_merge_sort(first, mid_iterator, buffer, c);    

        /*
         * Recurse on right half
         */
        do_merge_sort(mid_iterator_plus1, last, buffer, c);

        /*
         * 2. Conquer: merge sub arrays into sorted array [first, last]
         */ 
        
        do_merge(first, mid_iterator, last, buffer, c); // merge/sort step
    }
}

/*
 * Merges subarrays  [first, mid] and [mid + 1, last] into a sorted array in working buffer, buffer_start. Then copies the working buffer 
 * over the original segement [first, last]
 */

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge(Iterator_type1 first, Iterator_type1 mid, Iterator_type1 last,
                                                                  Iterator_type2 buffer_start, Comparator compare)
{
    Iterator_type1 first1 = first;
    Iterator_type1 last1 = mid;
    
    Iterator_type1 first2 = mid + 1;
    Iterator_type1 last2 = last;
        
    int index = 0;
    
    /* 
     * While both sub-arrays are not empty, copy the smaller item into the 
     * temporary array buffer.
     */
    Iterator_type2 buffer_cursor = buffer_start;
    
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

   Iterator_type2 start = buffer_start;
   
    for (Iterator_type1 end = start + length; start != end;) {
        
        *first++ = *start++;
    }
}

} // end namespace algolib
#endif
