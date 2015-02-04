/* 
 * Author: kurt
 *
 * Created on May 12, 2014, 11:37 AM
 */

#ifndef	PRINT_H_1234_90
#define	PRINT_H_1234_90
#include <iostream>

template<typename Iterator> inline void print_array(Iterator start, Iterator end)
{
    for (; start < end; ++start) {
        
        std::cout << *start << ", ";
    }

    std::cout << std::endl;
}
  

#endif	/* PRINT_ARRAY_H */

