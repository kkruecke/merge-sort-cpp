#include <cstdlib>
#include "animated-merge-sort.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char** argv)
{
  int a[32]; 

  int n = 32;
  
  int array_size = sizeof(a)/sizeof(int);
  
  generate(a, a + array_size, [&]{ return n--; }); 
    
  std::less<int> c; 
 
  merge_sort<int>(&a[0], &a[0] + array_size - 1, c);

  cout << "\n" <<  "Output of merge sort: " << "\n";
  copy(a, a + array_size, ostream_iterator<int>(cout, ", ")); 
  
  return 0;
}
