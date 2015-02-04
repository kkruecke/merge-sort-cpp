#ifndef GERNEIC_MERGE_SORT_H
#define GERNEIC_MERGE_SORT_H

/*
 * An array iterator, which temp_buffer is, is different potentially that the iterator type of first, mid and last--all of which could be \
 * different data structures. Therefore two iterator types might be needed.
 */
template<typename Iterator, typename Comparator> static void merge(Iterator first, Iterator mid, Iterator last, Iterator buffer_start, Comparator C);
template<typename Iterator, typename Comparator> static void do_merge_sort(Iterator first, Iterator last, Iterator buffer, Comparator C);

template<typename T, typename Iterator, typename Comparator> void merge_sort(Iterator first, Iterator last, Comparator C)
{
    // allocate a working buffer for our merges
    T *temp_buffer = new T[last + 1 - first];
    
    /*
     * The line below makes explicit the fact that the buffer iterator (as noted in the comment at top of file) must be of the same type as the 
     * template parameters first and last.
     */
    Iterator buffer_iterator = temp_buffer;
                                            
   
    //--do_merge_sort<Iterator, Comparator>(first, last, temp_buffer, C);
    do_merge_sort(first, last, buffer_iterator, C);
    
    delete [] temp_buffer;
}

template<typename Iterator, typename Comparator> static void do_merge_sort(Iterator first, Iterator last, Iterator buffer, Comparator c)
{
    // base case: the range [first, last] can no longer be subdivided.
    if (first < last) {
        
        int mid = (last - first) / 2; // index of mid point
        
        Iterator mid_iterator = first + mid;
        Iterator mid_iterator_plus1 = mid_iterator + 1;
        
        do_merge_sort(first, mid_iterator, buffer, c);    // sort left half
        
        
        do_merge_sort(mid_iterator_plus1, last, buffer, c); // sort right half
        
        // merge the two halves
        merge(first, mid_iterator, last, buffer, c);
    }
}

template<typename Iterator, typename Comparator> static void merge(Iterator first, Iterator mid, Iterator last, Iterator buffer_start, Comparator compare)
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
            
            *buffer_cursor = *first1;
            first1++;

        } else {
            
            *buffer_cursor = *first2;
            first2++;
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
         
   // copy the temp array to the original array
   int length = last + 1 - first;
   Iterator start = buffer_start;
   
    for (Iterator end = start + length; start != end; ++start) {
        
        *first++ = *start;
    }
}
#endif
