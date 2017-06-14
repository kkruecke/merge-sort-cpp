=============== Sort of std::array<int, 32> below ================
At depth 0.   all range: [0, 31] . {32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 }
At depth 1.  left half range: [0, 15] . {32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 }
At depth 2.  left half range: [0, 7] . {32 31 30 29 28 27 26 25 }
At depth 3.  left half range: [0, 3] . {32 31 30 29 }
At depth 4.  left half range: [0, 1] . {32 31 }
At depth 5.  left half range: [0, 0] . {32 } <-- Recursion ends.
At depth 5. right half range: [1, 1] . {31 } <-- Recursion ends.
At depth 4. Merging {32 }
            and     {31 }
            --->    {31 32 }
At depth 4. right half range: [2, 3] . {30 29 }
At depth 5.  left half range: [2, 2] . {30 } <-- Recursion ends.
At depth 5. right half range: [3, 3] . {29 } <-- Recursion ends.
At depth 4. Merging {30 }
            and     {29 }
            --->    {29 30 }
At depth 3. Merging {31 32 }
            and     {29 30 }
            --->    {29 30 31 32 }
At depth 3. right half range: [4, 7] . {28 27 26 25 }
At depth 4.  left half range: [4, 5] . {28 27 }
At depth 5.  left half range: [4, 4] . {28 } <-- Recursion ends.
At depth 5. right half range: [5, 5] . {27 } <-- Recursion ends.
At depth 4. Merging {28 }
            and     {27 }
            --->    {27 28 }
At depth 4. right half range: [6, 7] . {26 25 }
At depth 5.  left half range: [6, 6] . {26 } <-- Recursion ends.
At depth 5. right half range: [7, 7] . {25 } <-- Recursion ends.
At depth 4. Merging {26 }
            and     {25 }
            --->    {25 26 }
At depth 3. Merging {27 28 }
            and     {25 26 }
            --->    {25 26 27 28 }
At depth 2. Merging {29 30 31 32 }
            and     {25 26 27 28 }
            --->    {25 26 27 28 29 30 31 32 }
At depth 2. right half range: [8, 15] . {24 23 22 21 20 19 18 17 }
At depth 3.  left half range: [8, 11] . {24 23 22 21 }
At depth 4.  left half range: [8, 9] . {24 23 }
At depth 5.  left half range: [8, 8] . {24 } <-- Recursion ends.
At depth 5. right half range: [9, 9] . {23 } <-- Recursion ends.
At depth 4. Merging {24 }
            and     {23 }
            --->    {23 24 }
At depth 4. right half range: [10, 11] . {22 21 }
At depth 5.  left half range: [10, 10] . {22 } <-- Recursion ends.
At depth 5. right half range: [11, 11] . {21 } <-- Recursion ends.
At depth 4. Merging {22 }
            and     {21 }
            --->    {21 22 }
At depth 3. Merging {23 24 }
            and     {21 22 }
            --->    {21 22 23 24 }
At depth 3. right half range: [12, 15] . {20 19 18 17 }
At depth 4.  left half range: [12, 13] . {20 19 }
At depth 5.  left half range: [12, 12] . {20 } <-- Recursion ends.
At depth 5. right half range: [13, 13] . {19 } <-- Recursion ends.
At depth 4. Merging {20 }
            and     {19 }
            --->    {19 20 }
At depth 4. right half range: [14, 15] . {18 17 }
At depth 5.  left half range: [14, 14] . {18 } <-- Recursion ends.
At depth 5. right half range: [15, 15] . {17 } <-- Recursion ends.
At depth 4. Merging {18 }
            and     {17 }
            --->    {17 18 }
At depth 3. Merging {19 20 }
            and     {17 18 }
            --->    {17 18 19 20 }
At depth 2. Merging {21 22 23 24 }
            and     {17 18 19 20 }
            --->    {17 18 19 20 21 22 23 24 }
At depth 1. Merging {25 26 27 28 29 30 31 32 }
            and     {17 18 19 20 21 22 23 24 }
            --->    {17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 }
At depth 1. right half range: [16, 31] . {16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 }
At depth 2.  left half range: [16, 23] . {16 15 14 13 12 11 10 9 }
At depth 3.  left half range: [16, 19] . {16 15 14 13 }
At depth 4.  left half range: [16, 17] . {16 15 }
At depth 5.  left half range: [16, 16] . {16 } <-- Recursion ends.
At depth 5. right half range: [17, 17] . {15 } <-- Recursion ends.
At depth 4. Merging {16 }
            and     {15 }
            --->    {15 16 }
At depth 4. right half range: [18, 19] . {14 13 }
At depth 5.  left half range: [18, 18] . {14 } <-- Recursion ends.
At depth 5. right half range: [19, 19] . {13 } <-- Recursion ends.
At depth 4. Merging {14 }
            and     {13 }
            --->    {13 14 }
At depth 3. Merging {15 16 }
            and     {13 14 }
            --->    {13 14 15 16 }
At depth 3. right half range: [20, 23] . {12 11 10 9 }
At depth 4.  left half range: [20, 21] . {12 11 }
At depth 5.  left half range: [20, 20] . {12 } <-- Recursion ends.
At depth 5. right half range: [21, 21] . {11 } <-- Recursion ends.
At depth 4. Merging {12 }
            and     {11 }
            --->    {11 12 }
At depth 4. right half range: [22, 23] . {10 9 }
At depth 5.  left half range: [22, 22] . {10 } <-- Recursion ends.
At depth 5. right half range: [23, 23] . {9 } <-- Recursion ends.
At depth 4. Merging {10 }
            and     {9 }
            --->    {9 10 }
At depth 3. Merging {11 12 }
            and     {9 10 }
            --->    {9 10 11 12 }
At depth 2. Merging {13 14 15 16 }
            and     {9 10 11 12 }
            --->    {9 10 11 12 13 14 15 16 }
At depth 2. right half range: [24, 31] . {8 7 6 5 4 3 2 1 }
At depth 3.  left half range: [24, 27] . {8 7 6 5 }
At depth 4.  left half range: [24, 25] . {8 7 }
At depth 5.  left half range: [24, 24] . {8 } <-- Recursion ends.
At depth 5. right half range: [25, 25] . {7 } <-- Recursion ends.
At depth 4. Merging {8 }
            and     {7 }
            --->    {7 8 }
At depth 4. right half range: [26, 27] . {6 5 }
At depth 5.  left half range: [26, 26] . {6 } <-- Recursion ends.
At depth 5. right half range: [27, 27] . {5 } <-- Recursion ends.
At depth 4. Merging {6 }
            and     {5 }
            --->    {5 6 }
At depth 3. Merging {7 8 }
            and     {5 6 }
            --->    {5 6 7 8 }
At depth 3. right half range: [28, 31] . {4 3 2 1 }
At depth 4.  left half range: [28, 29] . {4 3 }
At depth 5.  left half range: [28, 28] . {4 } <-- Recursion ends.
At depth 5. right half range: [29, 29] . {3 } <-- Recursion ends.
At depth 4. Merging {4 }
            and     {3 }
            --->    {3 4 }
At depth 4. right half range: [30, 31] . {2 1 }
At depth 5.  left half range: [30, 30] . {2 } <-- Recursion ends.
At depth 5. right half range: [31, 31] . {1 } <-- Recursion ends.
At depth 4. Merging {2 }
            and     {1 }
            --->    {1 2 }
At depth 3. Merging {3 4 }
            and     {1 2 }
            --->    {1 2 3 4 }
At depth 2. Merging {5 6 7 8 }
            and     {1 2 3 4 }
            --->    {1 2 3 4 5 6 7 8 }
At depth 1. Merging {9 10 11 12 13 14 15 16 }
            and     {1 2 3 4 5 6 7 8 }
            --->    {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 }
At depth 0. Merging {17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 }
            and     {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 }
            --->    {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 }

Output of merge sort: 
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
