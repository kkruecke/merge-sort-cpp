/*
 * For an excellent explanation of this algorithm see:
   http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/7-Sort/merge-sort5.html
 */
namespace algolib {
/*
 * Two different iterator types might not actually needed. It may be that a random access iterator type is always required for both.
 */
template<typename Iterator, typename Comparator> static void merge(Iterator first, Iterator mid,
        Iterator last,
        Iterator buffer_start,
        Comparator C);


template<typename Iterator, typename T, Comparator comparer> T *merge_sort(Iterator first, Iterator last, Comaparator comparer)
{
    auto length = last + 1 - first;

    T  *temp_buffer = new decltype(*first)[length];

    Iterator first_tmp = first;

    for (int i = 1; i <= length / 2 + 1; i *= 2)  {
          
        /*
         * TODO: Use calculated iterators in the inner loop 
         */

        for (int j = i; j < length; j += 2 * i) {
            
            /*
             * input: array, left, middle, right, comparator.
             *
             */

            do_merge(a, j - i, j, Math.Min(j + i, array.Length), temp_buffer, comparer);
        }
    }
 
    return a;
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


} // end namespace
