#include <cstdlib>
#include "animated-merge-sort.h"
#include <iostream>
#include <functional>
#include <iterator>

using namespace std;

int main(int argc, char** argv)
{
  int a[] = { 15, 10, 3, 14, 2, 12, 4, 7, 1, 6, 11, 9, 8, 5, 13, 0}; 

  int array_size = sizeof(a)/sizeof(int);
  std::less<int> c; 
 
  merge_sort<int>(&a[0], &a[0] + array_size - 1, c);

  copy(a, a + array_size, ostream_iterator<int>(cout, ", ")); 
  return 0;
}
