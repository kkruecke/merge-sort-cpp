#ifndef TRACED_MERGE_SORT_H
#define TRACED_MERGE_SORT_H

#include <string>
#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>
#include <map>

namespace algolib {

class Animator { 
  public:    
    enum section {all, left, right };
    template<typename Iterator> static void print_stdout(Iterator first, Iterator last, int depth, Animator::section s, std::string suffix = std::string{}) noexcept;
  private:
    static  std::map<section, std::string> mapping;

    static std::string get_string(section s)
    {
       return Animator::mapping[s];
    } 
};
       
std::map<Animator::section, std::string>  Animator::mapping { {all, std::string("  all")}, 
                         {left, std::string(" left")},
                         {right, std::string("right")}
                            };
                            
template<typename Iterator> void Animator::print_stdout(Iterator first, Iterator last, int depth, Animator::section sec, std::string suffix) noexcept
{
  std::string part = Animator::get_string(sec);

  std::cout << "At depth " << depth << ". Section:  " << part << ": ";
    
  // Since last is the actual last element (and not one pass it), we  add one because copy() requires "one past".                          
  std::copy(first, last + 1, std::ostream_iterator<decltype(*first)>(std::cout, " "));
        
  std::cout << suffix << std::endl;
}

/*
 * Parameter end must be one past the actual end.
 */
template<typename Iterator> void print_array(Iterator start, Iterator end) noexcept
{
    // print out merged array
    std::cout << std::string(" [ "); 
            
    std::copy(start, end, std::ostream_iterator<decltype(*start)>(std::cout, " "));

    std::cout << std::string("] "); 
}

/*
 * Two iterator types are needed. The data structure being sorted may not an array.
 */
template<typename Iterator, typename Comparator> static void merge(Iterator first, Iterator mid, Iterator last,
        Iterator buffer_start,
        Comparator C, int depth) noexcept;

// merge_sort() is overloaded
template<typename T, typename Iterator, typename Comparator> void merge_sort(Iterator first, Iterator last, Comparator c) noexcept;

template<typename Iterator, typename Comparator> static void merge_sort(Iterator first, Iterator last,
                                                                  Iterator buffer, Comparator C, int depth = 0, Animator::section sec = Animator::all) noexcept;


template<typename T, typename Iterator, typename Comparator> void merge_sort(Iterator first, Iterator last, Comparator c) noexcept
{
   // allocate a working buffer for our merges
   auto length = last + 1 - first;    //<-- Note: this requires a random access iterator
   auto temp_buffer = new T[length];  
    
   merge_sort(first, last, temp_buffer, c);
    
   delete [] temp_buffer;
}

template<typename Iterator, typename Comparator> static void merge_sort(Iterator first, Iterator last,
                                                                  Iterator buffer, Comparator c, int depth, Animator::section sec) noexcept 
{
static Iterator orig_data_struct_first;
static Iterator orig_data_struct_last;

  if (depth == 0) {

    orig_data_struct_first = first;
    orig_data_struct_last = last;

  } 

  // base case: the range [first, last] can no longer be subdivided.
  if (first < last) {

      Animator::print_stdout(first, last, depth, sec);

      /*
       * 1. Divide data structure in a left, first half and second or right half.
       */ 
      int half_distance = (last - first) / 2; // distance to mid point
        
      Iterator mid = first + half_distance;

      // recursively subdivide left half
      algolib::merge_sort(first, mid, buffer, c, depth + 1, Animator::section::left);    

      // when left half recursion end, recursively subdivide right half (of prior array on stack).
      algolib::merge_sort(mid + 1, last, buffer, c, depth + 1, Animator::section::right);
      
      // merge the two halves
      algolib::merge(first, mid, last, buffer, c, depth);

      // print out the original data structure to be sorted
      std::cout << "\nOutput so far: ";

      print_array(orig_data_struct_first, orig_data_struct_last + 1);

      std::cout << "\n" << std::endl;

  } else {

      Animator::print_stdout(first, last, depth, sec, std::string(" <-- Recursion ends."));
  }
}

template<typename Iterator, typename Comparator> static void merge(Iterator first, Iterator mid, Iterator last,
                                                                  Iterator buffer_start, Comparator compare, int depth) noexcept
{
    Iterator first1 = first;
    Iterator last1 = mid;
    
    Iterator first2 = mid + 1;
    Iterator last2 = last;
    
    /*
     * Print out input arrays to be merged....
     */

    std::cout << "Merging at depth " << depth << " : left half";

    print_array(first1, last1 +  1);

    std::cout << " right half";

    print_array(first2, last2 +  1);

    std::cout <<  std::string("  ---> ") << "\n                    ";

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
           
    // copy the temp array to the original array
    int length = last + 1 - first;
    Iterator start = buffer_start;

    Iterator first_extra = first; 

    for (Iterator end = start + length; start != end;) {
        
        *first++ = *start++;
    }
}

/*
 * Iterative version of Merge Sort 
 * ===============================
 *
 * Java code below is from http://www.sinbadsoft.com/blog/a-recursive-and-iterative-merge-sort-implementations/
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

// Fwd reference
// Java routine above converted to C++11 below
template<typename T, typename Iterator, typename Comparator > static void iter_merge(Iterator first, int start, int middle, int end, Comparator comparer,
                              T *work_buffer) noexcept; 

template<typename T, typename Iterator, typename Comparator> Iterator iter_merge_sort(Iterator first, Iterator last, Comparator comparer) noexcept
{
    auto length = last + 1 - first;

    T *work_buffer = new T[length]; 

    /*
     * Traverse array input from beginning to end, sorting adjacent subarrays from the bottom up. Subarrays are always a
     * power of 2 in size, starting with size one--pow(2, 0)--then 2--pow(2, 1)--then 4--pow(2, 2)--and so on. The number
     * of iterations is:
     *   log base 2(length) rounded up. 
     */
    for (int width = 1; width <= length / 2 + 1; width *= 2) {
        
        /*
         * merge adjacent subarrays of size width
         */  
        for (int start = width; start < length; start += 2 * width)  { // (2 * width) == combined ength of both subarrays.

            std::cout << "\n Inner loop of iter_merge_sort: width =  " << width << "; start = " << start << "; start - width = " 
                     << start - width << "." << std::endl;

            algolib::iter_merge(first, start - width, start, std::min<decltype(start)>(start + width, length), comparer, work_buffer); 
        }

        // Display sorted input so far
        std::cout << std::string("\nThe currents the current input array: ");

        std::copy(first, first + length, std::ostream_iterator<decltype(*first)>(std::cout, ", "));
    }
    
    delete [] work_buffer;
    
    return first;
}

// C++11 version of above function
template<typename T, typename Iterator, typename Comparator > void iter_merge(Iterator input, int start, int middle,
                                                                                        int end, Comparator comparer, T *work_buffer) noexcept
{
    auto length = end - start;
    
    auto left = 0, right = 0, current = 0;

    while (left < middle - start && right < end - middle)     {
         
        if ( comparer(input[start + left], input[middle + right]) ) {

           work_buffer[current++] = input[start + left++];

        } else {  

            work_buffer[current++] = input[middle + right++];

        }
    }
 
    while (right < end - middle) {

         work_buffer[current++] = input[middle + right++];
    }
 
    while (left < middle - start) {

         work_buffer[current++] = input[start + left++];
    }
 
    std::copy(work_buffer, work_buffer + length, input + start); // copy to start

    std::cout << std::endl;
}


} // end namespace algolib
#endif
