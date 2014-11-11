#include <cstdlib>
#include "merge-sort.h"
#include "print-array.h"
using namespace std;

int main(int argc, char** argv)
{
  int a[] = { 9, 8, 7, 5, 0, 4, 10, 2, 3, 1};

  int size = sizeof(a)/sizeof(int);

  merge_sort(a, 0, size - 1);

  print_array(a, 0, size - 1);

  return 0;
}
