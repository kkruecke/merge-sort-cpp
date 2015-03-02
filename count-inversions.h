#ifndef COUNT_INVERSIONS_H
#define COUNT_INVERSIONS_H

#include <algorithm>

namespace algolib {

// forward references
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



// count is running total of number of array inversions.
/*
 * Prior code
 *
template<typename Iterator, typename Comparator> static int merge_sort_count_inversions(Iterator first, Iterator last,
 *                                                                Iterator buffer, Comparator C, int& total_inversions);
 */

/*
 * array[last] is last element in array
 */
/*
template<typename T, typename Iterator, typename Comparator> int count_inversions(Iterator first, Iterator last, Comparator C)
{
   // allocate a working buffer for our merges
   T *work_buffer = new T[last + 1 - first];

   int inversions = 0; 

   merge_sort_count_inversions(first, last, work_buffer, C, inversions);
    
   delete [] work_buffer;

   return inversions;
}
*/
template<typename T, typename Iterator, typename Comparator> int count_inversions(Iterator first, Iterator last, Comparator C)
{
   // allocate a working buffer for our merges
   T *work_buffer = new T[last + 1 - first];

   int inversions = merge_sort_count_inversions(first, last, work_buffer, C);
    
   delete [] work_buffer;

   return inversions;
}
// Returns number of array inversions
/*
template<typename Iterator, typename Comparator> static int merge_sort_count_inversions(Iterator first, Iterator last,
                                                                  Iterator buffer, Comparator c, int& total_inversions)
{
    // Base case: the range [first, last] can no longer be subdivided; it is of length one.
    if (first < last) {

        //
        // 1. Divide data structure in a left, first half and second, right half.
        // 

        int half_distance = (last - first) / 2; 
        
        Iterator mid = first + half_distance;

         //
         // Recurse on the left half.
         // 
        algolib::merge_sort_count_inversions(first, mid, buffer, c, total_inversions);

         //
         // When left half recursion ends, recurse on right half of [first, last], which is [mid + , last]. 
         // Note: Both left and right descents implictly save the indecies of [first, mid] and [mid+1, last] on the stack.
         // 
        algolib::merge_sort_count_inversions(mid + 1, last, buffer, c, total_inversions);

         //
         // 2. When recursion ends, merge the two sub arrays [first, mid] and [mid+1, last] into a sorted array in [first, last]
         // 
        total_inversions += algolib::merge_count_inversions(first, mid, last, buffer, c);
    }

    return total_inversions;
}
*/

// Returns number of array inversions
template<typename Iterator, typename Comparator> static int merge_sort_count_inversions(Iterator first, Iterator last,
                                                                  Iterator work_buffer, Comparator c)
{
 int inversions = 0;

    // Base case: the range [first, last] can no longer be subdivided; it is of length one.
    if (first < last) {

        int half_distance = (last - first) / 2; 
        
        Iterator mid = first + half_distance;

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
             inversions += (last1 + 1 - first1); // TODO: Check this line per comments above.
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
