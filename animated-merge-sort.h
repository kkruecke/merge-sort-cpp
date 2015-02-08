#ifndef ANIMATED_MERGE_SORT_H
#define ANIMATED_MERGE_SORT_H

#include <string>
#include <iostream>
#include <functional>
#include <iterator>
#include <map>

class Animator { 

public:    
    
  enum section {none, left, right };
  static template<typename Iterator> void print_stdout(Iterator first, Iterator last, int depth, Animator::section s, std::string suffix =std::string{}); 

private:

    static  std::map<section, std::string> mapping;

    static std::string get_string(section s)
    {
       return Animator::mapping[s];
    } 
};
       
std::map<Animator::section, std::string>  Animator::mapping { {none, std::string("none")}, 
                         {left, std::string("left")},
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
 * Two iterator types are needed. The data structure being sorted may not an array.
 */
template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void merge(Iterator_type1 first, Iterator_type1 mid,
        Iterator_type1 last,
        Iterator_type2 buffer_start,
        Comparator C, int depth);

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator C, int depth = 0, Animator::section sec = Animator::none);


template<typename T, typename Iterator, typename Comparator> void merge_sort(Iterator first, Iterator last, Comparator C)
{
   // allocate a working buffer for our merges
   T *temp_buffer = new T[last + 1 - first];
    
   do_merge_sort(first, last, temp_buffer, C);
    
   delete [] temp_buffer;
}

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void do_merge_sort(Iterator_type1 first, Iterator_type1 last,
                                                                  Iterator_type2 buffer, Comparator c, int depth, Animator::section sec) 
{

    // base case: the range [first, last] can no longer be subdivided.
    if (first < last) {

        Animator::print_stdout(first, last, depth + 1, sec);
                
        int mid = (last - first) / 2; // index of mid point
        
        Iterator_type1 mid_iterator = first + mid;
        Iterator_type1 mid_iterator_plus1 = mid_iterator + 1;

        do_merge_sort(first, mid_iterator, buffer, c, depth + 1, Animator::section::left);    // sort left half

        do_merge_sort(mid_iterator_plus1, last, buffer, c, depth + 1, Animator::section::right); // sort right half
        
        // merge the two halves
        merge(first, mid_iterator, last, buffer, c, depth);

    } else {

        Animator::print_stdout(first, last, depth, sec, std::string(" <--Recursion ends."));
    }
}

template<typename Iterator_type1, typename Iterator_type2, typename Comparator> static void merge(Iterator_type1 first, Iterator_type1 mid, Iterator_type1 last,
                                                                  Iterator_type2 buffer_start, Comparator compare, int depth)
{
    Iterator_type1 first1 = first;
    Iterator_type1 last1 = mid;
    
    Iterator_type1 first2 = mid + 1;
    Iterator_type1 last2 = last;

    std::cout << "merging : [ ";

    std::copy(first1, last1 + 1, std::ostream_iterator<decltype(*first1)>(std::cout, " "));

    std::cout << "], [ ";

    std::copy(first2, last2 + 1, std::ostream_iterator<decltype(*first1)>(std::cout, " "));

    std::cout << "] " <<  std::string(" ---> ");

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

    std::cout << std::string(" [ "); 
    
    // TODO: range is wrong.
    // TODO: USe range syntax with iterators (in this case pointers).

    std::copy(first_extra, first_extra + length, std::ostream_iterator<decltype(*first)>(std::cout, " "));

    std::cout << std::string(" ] ") << std::endl;
}
#endif
