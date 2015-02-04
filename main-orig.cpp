#include <cstdlib>
#include "merge-sort-orig.h"
#include <iostream>
#include <functional>
#include <iterator>
using namespace std;

int main(int argc, char** argv)
{
  int a[] = { 9, 8, 7, 5, 0, 4, 10, 2, 3, 1};

  int size = sizeof(a)/sizeof(int);
  std::less<int> c; 

  merge_sort(a, 0, size - 1, c);
  
  copy(a, a + size, ostream_iterator<int>(cout, ", ")); 
  return 0;
}
