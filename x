=============== Sort of std::array<int, 32> below ================
At depth 0. Subarray: [0, 31]   all. 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
At depth 1. Subarray: [0, 15]  left. 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 
At depth 2. Subarray: [0, 7]  left. 32 31 30 29 28 27 26 25 
At depth 3. Subarray: [0, 3]  left. 32 31 30 29 
At depth 4. Subarray: [0, 1]  left. 32 31 
At depth 5. Subarray: [0, 0]  left. 32  <-- Recursion ends. No merge.
At depth 5. Subarray: [1, 1] right. 31  <-- Recursion ends. No merge.
At depth 4. Merge left array {32 8} with right array {31 8} --->  {31 32 8}
At depth 4. Subarray: [2, 3] right. 30 29 
At depth 5. Subarray: [2, 2]  left. 30  <-- Recursion ends. No merge.
At depth 5. Subarray: [3, 3] right. 29  <-- Recursion ends. No merge.
At depth 4. Merge left array {30 8} with right array {29 8} --->  {29 30 8}
At depth 3. Merge left array {31 32 8} with right array {29 30 8} --->  {29 30 31 32 8}
At depth 3. Subarray: [4, 7] right. 28 27 26 25 
At depth 4. Subarray: [4, 5]  left. 28 27 
At depth 5. Subarray: [4, 4]  left. 28  <-- Recursion ends. No merge.
At depth 5. Subarray: [5, 5] right. 27  <-- Recursion ends. No merge.
At depth 4. Merge left array {28 8} with right array {27 8} --->  {27 28 8}
At depth 4. Subarray: [6, 7] right. 26 25 
At depth 5. Subarray: [6, 6]  left. 26  <-- Recursion ends. No merge.
At depth 5. Subarray: [7, 7] right. 25  <-- Recursion ends. No merge.
At depth 4. Merge left array {26 8} with right array {25 8} --->  {25 26 8}
At depth 3. Merge left array {27 28 8} with right array {25 26 8} --->  {25 26 27 28 8}
At depth 2. Merge left array {29 30 31 32 8} with right array {25 26 27 28 8} --->  {25 26 27 28 29 30 31 32 8}
At depth 2. Subarray: [8, 15] right. 24 23 22 21 20 19 18 17 
At depth 3. Subarray: [8, 11]  left. 24 23 22 21 
At depth 4. Subarray: [8, 9]  left. 24 23 
At depth 5. Subarray: [8, 8]  left. 24  <-- Recursion ends. No merge.
At depth 5. Subarray: [9, 9] right. 23  <-- Recursion ends. No merge.
At depth 4. Merge left array {24 8} with right array {23 8} --->  {23 24 8}
At depth 4. Subarray: [10, 11] right. 22 21 
At depth 5. Subarray: [10, 10]  left. 22  <-- Recursion ends. No merge.
At depth 5. Subarray: [11, 11] right. 21  <-- Recursion ends. No merge.
At depth 4. Merge left array {22 8} with right array {21 8} --->  {21 22 8}
At depth 3. Merge left array {23 24 8} with right array {21 22 8} --->  {21 22 23 24 8}
At depth 3. Subarray: [12, 15] right. 20 19 18 17 
At depth 4. Subarray: [12, 13]  left. 20 19 
At depth 5. Subarray: [12, 12]  left. 20  <-- Recursion ends. No merge.
At depth 5. Subarray: [13, 13] right. 19  <-- Recursion ends. No merge.
At depth 4. Merge left array {20 8} with right array {19 8} --->  {19 20 8}
At depth 4. Subarray: [14, 15] right. 18 17 
At depth 5. Subarray: [14, 14]  left. 18  <-- Recursion ends. No merge.
At depth 5. Subarray: [15, 15] right. 17  <-- Recursion ends. No merge.
At depth 4. Merge left array {18 8} with right array {17 8} --->  {17 18 8}
At depth 3. Merge left array {19 20 8} with right array {17 18 8} --->  {17 18 19 20 8}
At depth 2. Merge left array {21 22 23 24 8} with right array {17 18 19 20 8} --->  {17 18 19 20 21 22 23 24 8}
At depth 1. Merge left array {25 26 27 28 29 30 31 32 8} with right array {17 18 19 20 21 22 23 24 8} --->  {17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 8}
At depth 1. Subarray: [16, 31] right. 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
At depth 2. Subarray: [16, 23]  left. 16 15 14 13 12 11 10 9 
At depth 3. Subarray: [16, 19]  left. 16 15 14 13 
At depth 4. Subarray: [16, 17]  left. 16 15 
At depth 5. Subarray: [16, 16]  left. 16  <-- Recursion ends. No merge.
At depth 5. Subarray: [17, 17] right. 15  <-- Recursion ends. No merge.
At depth 4. Merge left array {16 8} with right array {15 8} --->  {15 16 8}
At depth 4. Subarray: [18, 19] right. 14 13 
At depth 5. Subarray: [18, 18]  left. 14  <-- Recursion ends. No merge.
At depth 5. Subarray: [19, 19] right. 13  <-- Recursion ends. No merge.
At depth 4. Merge left array {14 8} with right array {13 8} --->  {13 14 8}
At depth 3. Merge left array {15 16 8} with right array {13 14 8} --->  {13 14 15 16 8}
At depth 3. Subarray: [20, 23] right. 12 11 10 9 
At depth 4. Subarray: [20, 21]  left. 12 11 
At depth 5. Subarray: [20, 20]  left. 12  <-- Recursion ends. No merge.
At depth 5. Subarray: [21, 21] right. 11  <-- Recursion ends. No merge.
At depth 4. Merge left array {12 8} with right array {11 8} --->  {11 12 8}
At depth 4. Subarray: [22, 23] right. 10 9 
At depth 5. Subarray: [22, 22]  left. 10  <-- Recursion ends. No merge.
At depth 5. Subarray: [23, 23] right. 9  <-- Recursion ends. No merge.
At depth 4. Merge left array {10 8} with right array {9 8} --->  {9 10 8}
At depth 3. Merge left array {11 12 8} with right array {9 10 8} --->  {9 10 11 12 8}
At depth 2. Merge left array {13 14 15 16 8} with right array {9 10 11 12 8} --->  {9 10 11 12 13 14 15 16 8}
At depth 2. Subarray: [24, 31] right. 8 7 6 5 4 3 2 1 
At depth 3. Subarray: [24, 27]  left. 8 7 6 5 
At depth 4. Subarray: [24, 25]  left. 8 7 
At depth 5. Subarray: [24, 24]  left. 8  <-- Recursion ends. No merge.
At depth 5. Subarray: [25, 25] right. 7  <-- Recursion ends. No merge.
At depth 4. Merge left array {8 8} with right array {7 8} --->  {7 8 8}
At depth 4. Subarray: [26, 27] right. 6 5 
At depth 5. Subarray: [26, 26]  left. 6  <-- Recursion ends. No merge.
At depth 5. Subarray: [27, 27] right. 5  <-- Recursion ends. No merge.
At depth 4. Merge left array {6 8} with right array {5 8} --->  {5 6 8}
At depth 3. Merge left array {7 8 8} with right array {5 6 8} --->  {5 6 7 8 8}
At depth 3. Subarray: [28, 31] right. 4 3 2 1 
At depth 4. Subarray: [28, 29]  left. 4 3 
At depth 5. Subarray: [28, 28]  left. 4  <-- Recursion ends. No merge.
At depth 5. Subarray: [29, 29] right. 3  <-- Recursion ends. No merge.
At depth 4. Merge left array {4 8} with right array {3 8} --->  {3 4 8}
At depth 4. Subarray: [30, 31] right. 2 1 
At depth 5. Subarray: [30, 30]  left. 2  <-- Recursion ends. No merge.
At depth 5. Subarray: [31, 31] right. 1  <-- Recursion ends. No merge.
At depth 4. Merge left array {2 8} with right array {1 8} --->  {1 2 8}
At depth 3. Merge left array {3 4 8} with right array {1 2 8} --->  {1 2 3 4 8}
At depth 2. Merge left array {5 6 7 8 8} with right array {1 2 3 4 8} --->  {1 2 3 4 5 6 7 8 8}
At depth 1. Merge left array {9 10 11 12 13 14 15 16 8} with right array {1 2 3 4 5 6 7 8 8} --->  {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 8}
At depth 0. Merge left array {17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 8} with right array {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 8} --->  {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 8}

Output of merge sort: 
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
