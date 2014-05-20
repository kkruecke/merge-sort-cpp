/* 
 * File:   print-array.h
 * Author: kurt
 *
 * Created on May 12, 2014, 11:37 AM
 */

#ifndef PRINT_ARRAY_H
#define	PRINT_ARRAY_H
#include <iostream>

inline void print_array(int *a, int start, int end)
{
    for (int i = start; i <= end; i++) {
        
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}
  

#endif	/* PRINT_ARRAY_H */

