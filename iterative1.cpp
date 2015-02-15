/*
 * For an excellent explanation of this algorithm see:
   http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/7-Sort/merge-sort5.html
 */
template<typename T, Comparator comparer> T *merge_sort(T *a, Comaparator comparer)
{
 int length = sizeof(a) / sizeof(T);

    for (int i = 1; i <= length / 2 + 1; i *= 2)  {

        for (int j = i; j < length; j += 2 * i) {
            
            /*
             * input: array, left, middle, right, comparator.
             *
             *
             *
             */ 
            Merge(a, j - i, j, Math.Min(j + i, array.Length), comparer);
        }
    }
 
    return a;
}
