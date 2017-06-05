=============== Sort of std::array<int, 32> below ================
At depth 0.   all range: [0, 31] . {32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 8}
At depth 1.  left half range: [0, 15] . {32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 8}
At depth 2.  left half range: [0, 7] . {32 31 30 29 28 27 26 25 8}
At depth 3.  left half range: [0, 3] . {32 31 30 29 8}
At depth 4.  left half range: [0, 1] . {32 31 8}
At depth 5.  left half range: [0, 0] . {32 8} <-- Recursion ends.
At depth 5. right half range: [1, 1] . {31 8} <-- Recursion ends.
At depth 4. Merge left array {32 8}
            with right array {31 8}
            --->  {31 32 8}
At depth 4. right half range: [2, 3] . {30 29 8}
At depth 5.  left half range: [2, 2] . {30 8} <-- Recursion ends.
At depth 5. right half range: [3, 3] . {29 8} <-- Recursion ends.
At depth 4. Merge left array {30 8}
            with right array {29 8}
            --->  {29 30 8}
At depth 3. Merge left array {31 32 8}
            with right array {29 30 8}
            --->  {29 30 31 32 8}
At depth 3. right half range: [4, 7] . {28 27 26 25 8}
At depth 4.  left half range: [4, 5] . {28 27 8}
At depth 5.  left half range: [4, 4] . {28 8} <-- Recursion ends.
At depth 5. right half range: [5, 5] . {27 8} <-- Recursion ends.
At depth 4. Merge left array {28 8}
            with right array {27 8}
            --->  {27 28 8}
At depth 4. right half range: [6, 7] . {26 25 8}
At depth 5.  left half range: [6, 6] . {26 8} <-- Recursion ends.
At depth 5. right half range: [7, 7] . {25 8} <-- Recursion ends.
At depth 4. Merge left array {26 8}
            with right array {25 8}
            --->  {25 26 8}
At depth 3. Merge left array {27 28 8}
            with right array {25 26 8}
            --->  {25 26 27 28 8}
At depth 2. Merge left array {29 30 31 32 8}
            with right array {25 26 27 28 8}
            --->  {25 26 27 28 29 30 31 32 8}
At depth 2. right half range: [8, 15] . {24 23 22 21 20 19 18 17 8}
At depth 3.  left half range: [8, 11] . {24 23 22 21 8}
At depth 4.  left half range: [8, 9] . {24 23 8}
At depth 5.  left half range: [8, 8] . {24 8} <-- Recursion ends.
At depth 5. right half range: [9, 9] . {23 8} <-- Recursion ends.
At depth 4. Merge left array {24 8}
            with right array {23 8}
            --->  {23 24 8}
At depth 4. right half range: [10, 11] . {22 21 8}
At depth 5.  left half range: [10, 10] . {22 8} <-- Recursion ends.
At depth 5. right half range: [11, 11] . {21 8} <-- Recursion ends.
At depth 4. Merge left array {22 8}
            with right array {21 8}
            --->  {21 22 8}
At depth 3. Merge left array {23 24 8}
            with right array {21 22 8}
            --->  {21 22 23 24 8}
At depth 3. right half range: [12, 15] . {20 19 18 17 8}
At depth 4.  left half range: [12, 13] . {20 19 8}
At depth 5.  left half range: [12, 12] . {20 8} <-- Recursion ends.
At depth 5. right half range: [13, 13] . {19 8} <-- Recursion ends.
At depth 4. Merge left array {20 8}
            with right array {19 8}
            --->  {19 20 8}
At depth 4. right half range: [14, 15] . {18 17 8}
At depth 5.  left half range: [14, 14] . {18 8} <-- Recursion ends.
At depth 5. right half range: [15, 15] . {17 8} <-- Recursion ends.
At depth 4. Merge left array {18 8}
            with right array {17 8}
            --->  {17 18 8}
At depth 3. Merge left array {19 20 8}
            with right array {17 18 8}
            --->  {17 18 19 20 8}
At depth 2. Merge left array {21 22 23 24 8}
            with right array {17 18 19 20 8}
            --->  {17 18 19 20 21 22 23 24 8}
At depth 1. Merge left array {25 26 27 28 29 30 31 32 8}
            with right array {17 18 19 20 21 22 23 24 8}
            --->  {17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 8}
At depth 1. right half range: [16, 31] . {16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 8}
At depth 2.  left half range: [16, 23] . {16 15 14 13 12 11 10 9 8}
At depth 3.  left half range: [16, 19] . {16 15 14 13 8}
At depth 4.  left half range: [16, 17] . {16 15 8}
At depth 5.  left half range: [16, 16] . {16 8} <-- Recursion ends.
At depth 5. right half range: [17, 17] . {15 8} <-- Recursion ends.
At depth 4. Merge left array {16 8}
            with right array {15 8}
            --->  {15 16 8}
At depth 4. right half range: [18, 19] . {14 13 8}
At depth 5.  left half range: [18, 18] . {14 8} <-- Recursion ends.
At depth 5. right half range: [19, 19] . {13 8} <-- Recursion ends.
At depth 4. Merge left array {14 8}
            with right array {13 8}
            --->  {13 14 8}
At depth 3. Merge left array {15 16 8}
            with right array {13 14 8}
            --->  {13 14 15 16 8}
At depth 3. right half range: [20, 23] . {12 11 10 9 8}
At depth 4.  left half range: [20, 21] . {12 11 8}
At depth 5.  left half range: [20, 20] . {12 8} <-- Recursion ends.
At depth 5. right half range: [21, 21] . {11 8} <-- Recursion ends.
At depth 4. Merge left array {12 8}
            with right array {11 8}
            --->  {11 12 8}
At depth 4. right half range: [22, 23] . {10 9 8}
At depth 5.  left half range: [22, 22] . {10 8} <-- Recursion ends.
At depth 5. right half range: [23, 23] . {9 8} <-- Recursion ends.
At depth 4. Merge left array {10 8}
            with right array {9 8}
            --->  {9 10 8}
At depth 3. Merge left array {11 12 8}
            with right array {9 10 8}
            --->  {9 10 11 12 8}
At depth 2. Merge left array {13 14 15 16 8}
            with right array {9 10 11 12 8}
            --->  {9 10 11 12 13 14 15 16 8}
At depth 2. right half range: [24, 31] . {8 7 6 5 4 3 2 1 8}
At depth 3.  left half range: [24, 27] . {8 7 6 5 8}
At depth 4.  left half range: [24, 25] . {8 7 8}
At depth 5.  left half range: [24, 24] . {8 8} <-- Recursion ends.
At depth 5. right half range: [25, 25] . {7 8} <-- Recursion ends.
At depth 4. Merge left array {8 8}
            with right array {7 8}
            --->  {7 8 8}
At depth 4. right half range: [26, 27] . {6 5 8}
At depth 5.  left half range: [26, 26] . {6 8} <-- Recursion ends.
At depth 5. right half range: [27, 27] . {5 8} <-- Recursion ends.
At depth 4. Merge left array {6 8}
            with right array {5 8}
            --->  {5 6 8}
At depth 3. Merge left array {7 8 8}
            with right array {5 6 8}
            --->  {5 6 7 8 8}
At depth 3. right half range: [28, 31] . {4 3 2 1 8}
At depth 4.  left half range: [28, 29] . {4 3 8}
At depth 5.  left half range: [28, 28] . {4 8} <-- Recursion ends.
At depth 5. right half range: [29, 29] . {3 8} <-- Recursion ends.
At depth 4. Merge left array {4 8}
            with right array {3 8}
            --->  {3 4 8}
At depth 4. right half range: [30, 31] . {2 1 8}
At depth 5.  left half range: [30, 30] . {2 8} <-- Recursion ends.
At depth 5. right half range: [31, 31] . {1 8} <-- Recursion ends.
At depth 4. Merge left array {2 8}
            with right array {1 8}
            --->  {1 2 8}
At depth 3. Merge left array {3 4 8}
            with right array {1 2 8}
            --->  {1 2 3 4 8}
At depth 2. Merge left array {5 6 7 8 8}
            with right array {1 2 3 4 8}
            --->  {1 2 3 4 5 6 7 8 8}
At depth 1. Merge left array {9 10 11 12 13 14 15 16 8}
            with right array {1 2 3 4 5 6 7 8 8}
            --->  {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 8}
At depth 0. Merge left array {17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 8}
            with right array {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 8}
            --->  {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 8}

Output of merge sort: 
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
