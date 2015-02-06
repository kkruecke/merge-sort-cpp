#ifndef ANIMATED_MERGE_SORT_H
#define ANIMATED_MERGE_SORT_H

#include <string>
#include <iostream>
#include <functional>
#include <iterator>

template<typename Iterator> static void print_stdout(Iterator first, Iterator last, int depth, std::string prefix_msg)
{
    std::cout << prefix_msg << depth << ": ";
                              
    std::copy(first, last, std::ostream_iterator<decltype(*first)>(std::cout, " "));
        
    std::cout << std::endl;
}

/*
 * An array iterator, which temp_buffer is, is different potentially of a different type than that the iterator types of parameters first, mid and last--all of
 * which could be different data structures. Therefore two iterator types are needed in the event that the data structure being sorted is not an array.
 */
template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void merge(Iterator_type1 first, Iterator_type1 mid,
        Iterator_type1 last,
        Iterator_type2 buffer_start,
        Comparator C);

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator C, int depth = 0);

template<typename T, typename Iterator, typename Comparator> void merge_sort(Iterator first, Iterator last, Comparator C)
{
   // allocate a working buffer for our merges
   T *temp_buffer = new T[last + 1 - first];
    
   do_merge_sort(first, last, temp_buffer, C);
    
   delete [] temp_buffer;
}

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator c, int depth) 
{
    // base case: the range [first, last] can no longer be subdivided.
    if (first < last) {
        
                
        int mid = (last - first) / 2; // index of mid point
        
        Iterator_type1 mid_iterator = first + mid;
        Iterator_type1 mid_iterator_plus1 = mid_iterator + 1;

        print_stdout(first, mid_iterator, depth + 1, std::string("Calling merge_sort on left half at depth "));
 
        do_merge_sort(first, mid_iterator, buffer, c, depth + 1);    // sort left half

        print_stdout(mid_iterator_plus1, last, depth + 1, std::string("Calling merge_sort on right half at depth "));
 
        do_merge_sort(mid_iterator_plus1, last, buffer, c, depth + 1); // sort right half
        
        // merge the two halves
        merge(first, mid_iterator, last, buffer, c);
        
        print_stdout(first, last, depth, std::string("Merged Output at depth "));
    }
}

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void merge(Iterator_type1 first, Iterator_type1 mid, Iterator_type1 last,
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
         
   // copy the temp array to the original array
   int length = last + 1 - first;
   Iterator_type2 start = buffer_start;
   
    for (Iterator_type1 end = start + length; start != end; ++start) {
        
        *first++ = *start;
    }
}
#endif
