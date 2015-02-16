#ifndef ITER_MERGE_SORT_H
#define ITER_MERGE_SORT_H

#include <algorithm>

// TODO: First just get it running for arrays using indecies, then, convert it to use iterators.

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


//--template<typename Iterator, typename T, Comparator comparer> T *merge_sort(Iterator first, Iterator last, Comparator comparer)

template<typename T, Comparator comparer> T *merge_sort(T *array, int first, int last, Comparator comparer)
{
    auto length = last + 1 - first;

    T  *temp_buffer = new T[length];

    for (int width = 1; i <= length / 2 + 1; width *= 2)  { /
          
        for (int i = 0; i < length; i += 2 * width) {
            
            /*
             * input: array, first, mid, last, comparator -- where mid is an inclusive endpoint.
             *
             */

            //--algo::merge(a, j - i, j, Math.Min(j + i, array.Length), temp_buffer, comparer);
            int   start = i; 

            int     mid = i + width - 1;

            int tmp_end = i + 2 * width; 

            --tmp_end;

            int     end = std::min(tmp_end, length - 1); 

            algo::merge(array, start, mid, end, temp_buffer, comparer);
        }
    }
 
    return a;
}

/*
 * Merges subarrays  [first, mid] and [mid + 1, last] into a sorted array in working buffer, buffer_start. Then copies the working buffer 
 * over the original segement [first, last]
 */

template<typename T, typename Comparator> static void merge(T *array, int first, int mid, int last,
                                                                  T *buffer_start, Comparator compare)
{
    int first1 = first;
    int last1 = mid;
    
    int first2 = mid + 1;
    int last2 = last;
        
    int index = 0;
    
    /* 
     * While both sub-arrays are not empty, copy the smaller item into the 
     * temporary array buffer.
     */
    int buffer_cursor = buffer_start;
    
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

   int start = buffer_start;
   
    for (int end = start + length; start != end;) {
        
        *first++ = *start++;
    }
}


} // end namespace
#endif
