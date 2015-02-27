#include <cstdlib>
#include "count-inversions.h" // within algolib namespace
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

  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", ")); 
  
  auto inversions = algolib::count_inversions<int>(a.begin(), a.end() - 1, c);

  cout << "\n" <<  "Count of array inversions = " << inversions << "\n";

  cout << endl;

  return 0;
}
