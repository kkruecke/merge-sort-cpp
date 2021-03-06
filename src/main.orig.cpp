#include <cstdlib>
#include "merge-sort.h" 
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;

int main(int argc, char** argv)
{ 
  array<int, 32> a;
  
  auto n = a.size();

  generate(a.begin(), a.end(), [&]{ return n--; }); 
    
  less<int> c; 
 
  cout << "=============== Sort of std::array<int, 32> below ================\n";

  algolib::merge_sort<int>(a.begin(), a.end() - 1, c);
  
  cout << "\n" <<  "Output of merge sort: " << "\n";

  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", ")); 

  cout << endl;
  
  return 0;

// Sort built-in array using iterative merge sort

  cout << "\n=============== Sort of built-int array below ================\n" << endl;
  
  int a2[32]; 

  n = 32;
  
  int array_size = sizeof(a2)/sizeof(int);
  
  generate(a2, a2 + array_size, [&]{ return n--; }); 
    
  less<int> compare; 
 
  //algolib::iter_merge_sort<int>(&a2[0], &a2[31], compare);
  algolib::merge_sort<int>(&a2[0], &a2[31], compare);

  cout << "\n------------------\n" <<  "Output of iterative merge sort: " << "\n";

  copy(a2, a2 + array_size, ostream_iterator<int>(cout, ", ")); 

  cout << endl;
  
  return 0;
}
