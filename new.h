#ifndef GERNEIC_MERGE_SORT_H
#define GERNEIC_MERGE_SORT_H

template<typename T, typename Iterator, typename Comparator> static void merge(T *a, Iterator first, Iterator mid, Iterator last, T *buffer, Comparator C);
template<typename T, typename Iterator, typename Comparator> static void do_merge_sort(T *a, Iterator first, Iterator last, T *buffer, Comparator C);

template<typename T, typename Comparator> void merge_sort(T *a, Iterator first, Iterator last, Comparator C)
{
    // allocate a working buffer for our merges
    T *temp_buffer = new T[last + 1 - first];
   
    do_merge_sort<T, Comparator>(a, first, last, temp_buffer, C);
    
    delete [] temp_buffer;
}

template<typename T, typename Iterator, typename Comparator> static void do_merge_sort(T *a, Iterator first, Iterator last, T *buffer, Comparator C)
{
    // base case: the range [first, last] can no longer be subdivided.
    if (first < last) {
        
        int mid = (first + last) / 2; // index of mid point
        
        do_merge_sort<T, Comparator>(a, first, mid, buffer, C);    // sort left half
        do_merge_sort<T, Comparator>(a, mid + 1, last, buffer, C); // sort right half
        
        // merge the two halves
        merge<T, Comparator>(a, first, mid, last, buffer, C);
    }
}

template<typename T, typename Iterator, typename Comparator> static void merge(T *a, Iterator first, Iterator mid, Iterator last, T *buffer, Comparator compare)
{
    Iteratorfirst1 = first;
    Iteratorlast1 = mid;
    Iteratorfirst2 = mid + 1;
    Iteratorlast2 = last;
    
    int index = 0;
    /* 
     * While both sub-arrays are not empty, copy the smaller item into the 
     * temporary array buffer.
     */
    for (; first1 <= last1 && first2 <= last2; ++index) {
        
        if ( compare(a[first1], a[first2]) ) {
            
            buffer[index] = a[first1];
            first1++;

        } else {
            
            buffer[index] = a[first2];
            first2++;
        }
    }
    
    // finish off the first sub-array, if necessary
    for (;first1 <= last1; first1++, index++) {
        
        buffer[index] = a[first1];
    }
    
    // finish off the second sub-array, if necessary
    for (;first2 <= last2; first2++, index++) {
        
        buffer[index] = a[first2];
    }
         
   // copy the temp array to the original array
   int length = last + 1 - first;
    
    for (index = 0; index < length; ++index) {
        
        a[first++] = buffer[index];
    }
}
#endif
