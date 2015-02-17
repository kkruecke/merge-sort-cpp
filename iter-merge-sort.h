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
 * Code below from http://www.sinbadsoft.com/blog/a-recursive-and-iterative-merge-sort-implementations/
 *
public static T[] Iter_Merge_Sort(T[] array, IComparer<T> comparer)
{
    for (int i = 1; i <= array.Length / 2 + 1; i *= 2) {

        for (int j = i; j < array.Length; j += 2 * i)  {

            Merge(array, j - i, j, Math.Min(j + i, array.Length), comparer);
        }
    }
 
    return array;
}
*/

// Function above converted by Kurt

template<typename T, typename Comparator> T *iter_merge_sort(T *input, int length, Comparator comparer)
{
    /*
     * Traverse array input from beginning to end, sorting adjacent subarrays from the bottom up. Subarrays are always a power of 2 in size, starting 
     * with size one (2 to the zero), then 2 (2 to the first), 4 (2 to the second) and so on. The number of iterations is:
     * 
     *   log base 2(length) rounded up. 
     */
    for (int width = 1; width <= length / 2 + 1; width *= 2) {
        
        /*
         * merge adjacent subarrays of size width
         */  
        for (int start = width; start < length; width += 2 * width)  {

            algolib::iter_merge(input, start - width, start, std::min(start + width, length), comparer); 
        }
    }
 
    return input;
}

/*
static void Merge(T[] array, int start, int middle, int end, IComparer<T> comparer)
{
    T[] merge = new T[end - start];

    int l = 0, r = 0, i = 0;

    while (l < middle - start && r < end - middle)     {
         
        merge[i++] = comparer.Compare(array[start + l], array[middle + r]) < 0 ? array[start + l++] : array[middle + r++];
    }
 
    while (r < end - middle) {

         merge[i++] = array[middle + r++];
    }
 
    while (l < middle - start) {

         merge[i++] = array[start + l++];
    }
 
    Array.Copy(merge, 0, array, start, merge.Length);
}
*/
// Converted version
template<typename T, typename Comparator > static void iter_work_buffer(T *input, int start, int middle, int end, Comparator comparer)
{
    auto length = end - sart;

    T *work_buffer = new T[length];

    auto left = 0, right = 0, i = 0;

    while (left < middle - start && right < end - middle)     {
         
        if ( comparer(input[start + left], input[middle + right]) ) {

           work_buffer[i++] = input[start + left++];

        } else {  

            work_buffer[i++] = input[middle + right++];

        }
    }
 
    while (right < end - middle) {

         work_buffer[i++] = input[middle + right++];
    }
 
    while (left < middle - start) {

         work_buffer[i++] = input[start + left++];
    }
 
    std::copy(work_buffer, work_buffer + length, array);

    delete [] work_buffer;
}


} // end namespace
#endif
