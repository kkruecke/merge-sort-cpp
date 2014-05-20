#include "print-array.h"
#include <iostream>
void print_array(std::ostream& ostr, int *a, int length)
{
    for (int i = 0; i < length; i++) {
        
        ostr << a[i] << ", ";
    }
}
        
