#include "merge-sort.h"
#include "print-array.h"
using namespace std;

void merge_sort(int *a, int first, int last)
{
    if (first < last) {
        
        int mid = (first + last) / 2;
        
        merge_sort(a, first, mid);
        merge_sort(a, mid + 1, last);
        
        // merge the two halves
        merge(a, first, mid, last);
        
        // debug
        cout << "\n array sorted from " << first << " to " << last << "\n";
        print_array(a, first, last);
    }
}

void merge(int *a, int first, int mid, int last)
{
    int array_size = last + 1 - first;
    int *temp = new int[array_size];
    
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    
    int index = 0;
    /* 
     * while both subarrays are not empty, copy the smaller item into the 
     * temporary array.
     */
    for (; first1 <= last1 && first2 <= last2; ++index) {
        
        if (a[first1] < a[first2]) {
            
            temp[index] = a[first1];
            first1++;
        } else {
            
            temp[index] = a[first2];
            first2++;
        }
    }
    // finish off the first subarray, if necessary
    
    for (;first1 <= last1; first1++, index++) {
        
        temp[index] = a[first1];
    }
    
    // finish off the second subarray, if necessary
    
    for (;first2 <= last2; first2++, index++) {
        
        temp[index] = a[first2];
    }
    
    cout << "\n temp array is: \n";
    print_array(temp, 0, array_size - 1);
    cout << endl;
    
    // copy the temp array to the original array
    int start = first;
    for (int index = 0; index < array_size; ++index, ++start) {
        
        a[start] = temp[index];
    }
    
    cout << "\n array sorted from " << first << " to " << last << "\n";
    print_array(a, first, last);
        
    delete [] temp;
}
