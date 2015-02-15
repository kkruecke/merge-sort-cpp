/*
 * For an excellent explanation of this algorithm see:
   http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/7-Sort/merge-sort5.html
 */
template<typename Iterator, typename T, Comparator comparer> T *merge_sort(Iterator first, Iterator last, Comaparator comparer)
{
    int length = last + 1 - first;

    T temp_buffer = new T[length];

    Iterator first_tmp = first;

    for (int i = 1; i <= length / 2 + 1; i *= 2)  {

        for (int j = i; j < length; j += 2 * i) {
            
            /*
             * input: array, left, middle, right, comparator.
             *
             */
            // TODO: express j - i, j in term of iterators  
            do_merge(a, j - i, j, Math.Min(j + i, array.Length), temp_buffer, comparer);
        }
    }
 
    return a;
}
