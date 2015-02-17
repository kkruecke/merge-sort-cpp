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
     * with 2 to the first, then 2 to the second, 2 to the third and so on. The number of iteration is:
     * log base 2(length) rounded up. 
     */
    for (int width = 1; width <= length / 2 + 1; width *= 2) {

        for (int j = width; j < length; j += 2 * width)  {

            iter_merge(input, j - width, j, Math.Min(j + i, input.Length), comparer); // TODO: convert this line
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

} // end namespace
#endif
