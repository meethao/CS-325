CS - 325        
Assignment-2
Name: Jia Hao
Student ID: 9336363448
E-mail: jiaha@oregonstate.edu


1. My ZIP file includes two sort code files, merge sort and merge sort 3. I
implement the algorithms in C++. My programs can read inputs from a file called
“data.txt” where the first value of each line is the number of integers that to
be sorted, followed by the integers. Then, the number os integers that to be
sorted is be write to insert.txt and mergesort.txt.

2. Implement the Mergesort3 algorithm to sort an array/vector of integers. My
project implement the algorithm in same language you used in homework 1. Name
the program “Mergesort3”. Your program should be able to read inputs from a file
called “data.txt” where the first value of each line is the number of integers
that need to be sorted, followed by the integers.

3. Merge sort involves recursively splitting the array into 2 parts, sorting and
finally merging them. A variant of merge sort is called 3-way merge sort where
instead of splitting the array into 2 parts we split it into 3 parts.Merge sort
recursively breaks down the arrays to subarrays of size half. Similarly, 3-way
Merge sort breaks down the arrays to subarrays of size one third.

4. Merge Sort is a Divide and Conquer algorithm. It divides input array in two
halves, calls itself for the two halves and then merges the two sorted halves.
The merge() function is used for merging two halves. The merge(arr, l, m, r) is
key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges
the two sorted sub-arrays into one. See following C implementation for details.


5. I verified that my code that from question 3, and the code can to collect
running time data. Instead of reading arrays from the file data.txt and sorting,
this code can generate arrays of size n containing random integer values from 0
to 10,000 to sort. Use the system clock to record the running times of each
algorithm for ten different values of n for example: n = 5000, 10000, 15000,
20,000, ..., 50,000. Output the array size n and time to the terminal. Name
these new programs insertTime and mergeTime.

6. reference:
   https://www.geeksforgeeks.org/
