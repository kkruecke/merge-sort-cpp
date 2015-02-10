#ifndef ANIMATED_MERGE_SORT_H
#define ANIMATED_MERGE_SORT_H

#include <string>
#include <iostream>
#include <functional>
#include <iterator>
#include <map>

namespace algolib {

class Animator { 
  public:    
    enum section {none, left, right };
    template<typename Iterator> static void print_stdout(Iterator first, Iterator last, int depth, Animator::section s, std::string suffix =std::string{}); 
  private:
    static  std::map<section, std::string> mapping;

    static std::string get_string(section s)
    {
       return Animator::mapping[s];
    } 
};
       
std::map<Animator::section, std::string>  Animator::mapping { {none, std::string("  all")}, 
                         {left, std::string(" left")},
                         {right, std::string("right")}
                            };

template<typename Iterator> void Animator::print_stdout(Iterator first, Iterator last, int depth, Animator::section sec, std::string suffix)
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
template<typename Iterator> void print_array(Iterator start, Iterator end)
{
    // print out merged array
    std::cout << std::string(" [ "); 
            
    std::copy(start, end, std::ostream_iterator<decltype(*start)>(std::cout, " "));

    std::cout << std::string("] "); 
}

/*
 * Two iterator types are needed. The data structure being sorted may not an array.
 */
template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge(Iterator_type1 first, Iterator_type1 mid,
        Iterator_type1 last,
        Iterator_type2 buffer_start,
        Comparator C, int depth);

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator C, int depth = 0, Animator::section sec = Animator::none);


template<typename T, typename Iterator, typename Comparator> void merge_sort(Iterator first, Iterator last, Comparator c)
{
   // allocate a working buffer for our merges
   T *temp_buffer = new T[last + 1 - first];
    
   do_merge_sort(first, last, temp_buffer, c);
    
   delete [] temp_buffer;
}

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator c, int depth, Animator::section sec) 
{
static Iterator_type1 orig_data_struct_first;
static Iterator_type1 orig_data_struct_last;

  if (depth == 0) {

    orig_data_struct_first = first;
    orig_data_struct_last = last;

  } 

  // base case: the range [first, last] can no longer be subdivided.
  if (first < last) {

      Animator::print_stdout(first, last, depth, sec);
              
      int mid = (last - first) / 2; // index of mid point
      
      Iterator_type1 mid_iterator = first + mid;
      Iterator_type1 mid_iterator_plus1 = mid_iterator + 1;

      do_merge_sort(first, mid_iterator, buffer, c, depth + 1, Animator::section::left);    // recursively subdivide left half

      do_merge_sort(mid_iterator_plus1, last, buffer, c, depth + 1, Animator::section::right); // recursively subdivide right half
      
      // merge the two halves
      do_merge(first, mid_iterator, last, buffer, c, depth);

      // print out the original data structure to be sorted
      std::cout << "\nOutput so far: ";

      print_array(orig_data_struct_first, orig_data_struct_last + 1);

      std::cout << "\n" << std::endl;

  } else {

      Animator::print_stdout(first, last, depth, sec, std::string(" <-- Recursion ends."));
  }
}

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge(Iterator_type1 first, Iterator_type1 mid, Iterator_type1 last,
                                                                  Iterator_type2 buffer_start, Comparator compare, int depth)
{
    Iterator_type1 first1 = first;
    Iterator_type1 last1 = mid;
    
    Iterator_type1 first2 = mid + 1;
    Iterator_type1 last2 = last;
    
    /*
     * Print out input arrays to be merged....
     */

    std::cout << "merging : ";

    print_array(first1, last1 +  1);

    print_array(first2, last2 +  1);

    std::cout <<  std::string("  ---> ");

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

    Iterator_type2 first_extra = first; 
   
    for (Iterator_type1 end = start + length; start != end; ++start) {
        
        *first++ = *start;
    }

    // print out merged array
    print_array(first_extra, first_extra + length);

    std::cout << std::endl;
}

} // end namespace algolib
#endif
