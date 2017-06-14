#ifndef TRACED_MERGE_SORT_H
#define TRACED_MERGE_SORT_H

#include <string>
#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>
#include <map>
#include <utility>
#include <memory>

namespace algolib {

class Animator { 
 public:    
    enum section {all, left, right };
    
 private:
    static  std::map<section, std::string> mapping;

    static std::string get_string(section s)
    {
       return Animator::mapping[s];
    } 

  public:    
    
    template<typename Iterator> static void print_stdout(Iterator start_of_array, Iterator first, Iterator last, int depth,
                                                  Animator::section s, std::string suffix = std::string{}) noexcept;
  };
       
std::map<Animator::section, std::string>  Animator::mapping { {all, std::string("  all")}, 
                         {left, std::string(" left half")},
                         {right, std::string("right half")}
                            };
                            
template<typename Iterator> void Animator::print_stdout(Iterator start_of_array, Iterator first, Iterator last, int depth, Animator::section sec, \
                         std::string suffix) noexcept
{
  std::string part = Animator::get_string(sec);
 
  std::cout << "At depth " << depth << ". "; 
  
  std::cout << part << " range: " << "[" << first - start_of_array << ", " << last - start_of_array << "] " << ". {" ;
    
  // Since last is the actual last element (and not one pass it), we  add one because copy() requires "one past".                          
  std::copy(first, last + 1, std::ostream_iterator<decltype(*first)>(std::cout, " "));

  std::cout << '\b';   // output backspace to overwrite extra space. 

  std::cout << '}' << suffix << std::endl;
}

/*
 * Parameter end must be one past the actual end.
 */
template<typename Iterator> void print_array(Iterator start, Iterator end) noexcept
{
    // print out merged array
    std::cout << std::string(" {"); 
            
    std::copy(start, end, std::ostream_iterator<decltype(*start)>(std::cout, " "));
    
    std::cout << '\b'; // backspace character (or overwrite extra space).

    std::cout << std::string("}"); 
}

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

   std::unique_ptr<T[]> temp_array { new T[length] };  

   merge_sort(first, last, temp_array.get(), c);
}

//} // end namespace algolib

template<typename Iterator, typename Comparator> static void merge_sort(Iterator first, Iterator last,
                                                                  Iterator buffer, Comparator c, int depth, Animator::section sec) noexcept 
{
static Iterator orig_data_struct_first;
static Iterator orig_data_struct_last;

  if (depth == 0) {

    orig_data_struct_first = first;
    orig_data_struct_last = last;

  } 

  auto size_of = sizeof(*first);

  // base case: the range [first, last] can no longer be subdivided.
  if (first < last) {
      
      Animator::print_stdout(orig_data_struct_first, first, last, depth, sec);

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
      
      // print the result of the merge
      print_array(first, last + 1); 
      
      std::cout << std::endl;
      
  } else {

      Animator::print_stdout(orig_data_struct_first, first, last, depth, sec, std::string(" <-- Recursion ends."));
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

    std::cout << "At depth " << depth << ". Merging";

    print_array(first1, last1 +  1);

    std::cout << "\n            and    ";

    print_array(first2, last2 +  1);

    std::cout <<  std::string("\n            --->   "); // << "\n                    ";

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

} // end namespace algolib
#endif
