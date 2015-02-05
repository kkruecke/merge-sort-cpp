#ifndef GERNEIC_MERGE_SORT_H
#define GERNEIC_MERGE_SORT_H

/*
 * In this code end is one past the actual last value. 
 */
template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void merge(Iterator_type1 first, Iterator_type1 mid,
        Iterator_type1 last,
        Iterator_type2 buffer_start,
        Comparator C);

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator C);

template<typename T, typename Iterator, typename Comparator> void merge_sort(Iterator first, Iterator last, Comparator C)
{
   // allocate a working buffer for our merges
   //--T *temp_buffer = new T[last + 1 - first];
   T *temp_buffer = new T[last - first];
    
   do_merge_sort(first, last, temp_buffer, C);
    
   delete [] temp_buffer;
}

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator c) 
{
    // base case: the range [first, last] can no longer be subdivided.
    //--if (first < last) {
    if (last - first > 1) {
    
        
        int mid = (last - first) / 2; // index of mid point
        
        Iterator_type1 mid_iterator = first + mid; // mid is one past the last element in first half of partition of array
        //--Iterator_type1 mid_iterator_plus1 = mid_iterator;
        
        do_merge_sort(first, mid_iterator, buffer, c);    // sort left half
         
        //--do_merge_sort(mid_iterator_plus1, last, buffer, c); // sort right half
        do_merge_sort(mid_iterator, last, buffer, c); // sort right half
        
        // merge the two halves
        merge(first, mid_iterator, last, buffer, c);
    }
}

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void merge(Iterator_type1 start, Iterator_type1 mid, Iterator_type1 end,
                                                                  Iterator_type2 buffer_start, Comparator compare)
{
    Iterator_type1 first1 = start;
    Iterator_type1 last1 = mid;
    
    Iterator_type1 first2 = mid + 1;
    Iterator_type1 last2 = end;
        
    int index = 0;
    
    /* 
     * While both sub-arrays are not empty, copy the smaller item into the 
     * temporary array buffer.
     */
    Iterator_type2 buffer_cursor = buffer_start;
    
    for (; first1 < last1 && first2 < last2; ++buffer_cursor) {
        
        if ( compare(*first1, *first2) ) {
            
            *buffer_cursor = *first1++;

        } else {
            
            *buffer_cursor = *first2++;
        }
    }
    
    // finish off the first sub-array, if necessary
    for (;first1 < last1; ++first1, ++buffer_cursor) {
        
        *buffer_cursor = *first1;
    }
    
    // finish off the second sub-array, if necessary
    for (;first2 < last2; ++first2, ++buffer_cursor) {
        
        *buffer_cursor = *first2;
    }
         
    // copy the temp array to the original array
    for (;start != end; ++buffer_start, ++start) {
        
        *start = *buffer_start;
    }
}
#endif
