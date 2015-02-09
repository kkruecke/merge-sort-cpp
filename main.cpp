#include <cstdlib>
#include "animated-merge-sort.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;

int main(int argc, char** argv)
{
/*
  int a[32]; 

  int n = 32;
  
  int array_size = sizeof(a)/sizeof(int);
  
  generate(a, a + array_size, [&]{ return n--; }); 
    
  std::less<int> c; 
 
  merge_sort<int>(&a[0], &a[0] + array_size - 1, c);

  cout << "\n" <<  "Output of merge sort: " << "\n";
  copy(a, a + array_size, ostream_iterator<int>(cout, ", ")); 
*/ 
  array<int, 32> a;

  int n{32};

  generate(a.begin(), a.end(), [&]{ return n--; }); 
    
  std::less<int> c; 
 
  cout << "\n=============== Sort of std::array<int, 32> below ================\n";

  merge_sort<int>(a.begin(), a.end() - 1, c);

  cout << "\n" <<  "Output of merge sort: " << "\n";

  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", ")); 

// Sort built-in array

  cout << "\n=============== Sort of built-int array below ================\n";
  
  int a2[32]; 

  n = 32;
  
  int array_size = sizeof(a2)/sizeof(int);
  
  generate(a2, a2 + array_size, [&]{ return n--; }); 
    
  std::less<int> compare; 
 
  merge_sort<int>(&a2[0], &a2[0] + array_size - 1, compare);

  cout << "\n" <<  "Output of merge sort: " << "\n";
  copy(a2, a2 + array_size, ostream_iterator<int>(cout, ", ")); 

  return 0;
}
