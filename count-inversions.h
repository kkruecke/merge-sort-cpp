#ifndef COUNT_INVERSIONS_H
#define COUNT_INVERSIONS_H

#include <algorithm>

namespace algolib {

/* forward references */

template<typename T, typename Iterator, typename Comparator> int count_inversions(Iterator first, Iterator end, Comparator C);

/*
 * Iterator here is a random access iterator
 */
template<typename Iterator, typename Comparator> static int merge_count_inversions(Iterator first, Iterator mid,
        Iterator last,
        Iterator buffer_start,
        Comparator C);

template<typename Iterator, typename Comparator> static int merge_sort_count_inversions(Iterator first, Iterator last,
                                                                  Iterator work_buffer, Comparator c);


template<typename T, typename Iterator, typename Comparator> int count_inversions(Iterator first, Iterator last, Comparator C)
{
   // allocate a working buffer for our merges
   T *work_buffer = new T[last + 1 - first];

   int inversions = merge_sort_count_inversions(first, last, work_buffer, C);
    
   delete [] work_buffer;

   return inversions;
}

/* Returns number of array inversions */
template<typename Iterator, typename Comparator> static int merge_sort_count_inversions(Iterator first, Iterator last,
                                                                  Iterator work_buffer, Comparator c)
{
 int inversions = 0;

    // Base case: the range [first, last] can no longer be subdivided; it is of length one.
    if (first < last) {

        int half_distance = (last - first) / 2; 
        
        Iterator mid = first + half_distance;

        /* 
         * The variable inversions is a running total of the total number of inversions that occurs in each merge step, as we recursively
         * descend subdividing (first the right half and then the left) and then return and conquer by merging and counting inversions.

         * At the end of recursively subdividing the left half, we have a subarray of one element, the first value in the array. We
         * then return from subdividing the left half, and we recursively subdivide the right half of the previously-next-larger subarray, which is
         * of size two. This gives us the right-most element of the subarray of size two, consisting of the first two elements in the array.  
         * We then call merge_count_inversions(), which will be either one or zero.  
         *  
         */
        inversions = algolib::merge_sort_count_inversions(first, mid, work_buffer, c);

        inversions += algolib::merge_sort_count_inversions(mid + 1, last, work_buffer, c);

        inversions += algolib::merge_count_inversions(first, mid, last, work_buffer, c);
    }

    return inversions;
}

/*
 * Merges subarrays  [first, mid] and [mid + 1, last] into a sorted array in working buffer, buffer_start. Then copies
 * the working buffer over the original segement [first, last]
 */

template<typename Iterator, typename Comparator> static int merge_count_inversions(Iterator first, Iterator mid, Iterator last,
                                                                  Iterator buffer_start, Comparator compare)
{
 int inversions = 0;

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
            
            *buffer_cursor = *first1++; // not an inversion

        } else {

            // inversion found: element in first array is larger than element in second array.
            *buffer_cursor = *first2++;

            /* From: http://www.geeksforgeeks.org/counting-inversions/ 
             * How do we count the number of inversions in the merge step? In the merge process, let i is used for indexing left sub-array
             * and j for right sub-array. At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions, because
             * left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater
             * than a[j].
             */  
             inversions += (last1 + 1 - first1); 
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

   return inversions;
}

} // end namespace algolib
#endif
