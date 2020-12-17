CS - 325        Assignment-1  
My name is Jia Hao, and the Student ID is 9336363448
E-mail: jiaha@oregonstate.edu

1. My ZIP file includes two sort code files, merge sort and insertion sort. I
implement the algorithms in C++. My programs can read inputs from a file called
“data.txt” where the first value of each line is the number of integers that to
be sorted, followed by the integers. Then, the number os integers that to be
sorted is be write to insertsort.txt and mergesort.txt.

2. Merge Sort is a Divide and Conquer algorithm. It divides input array in two
halves, calls itself for the two halves and then merges the two sorted halves.
The merge() function is used for merging two halves. The merge(arr, l, m, r) is
key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges
the two sorted sub-arrays into one. See following C implementation for details.

3. Insertion sort is a simple sorting algorithm that builds the final sorted
array (or list) one item at a time. It is much less efficient on large lists
than more advanced algorithms such as quicksort, heapsort, or merge sort.

4. I verified that my code that from question 3, and the code can to collect
running time data. Instead of reading arrays from the file data.txt and sorting,
this code can generate arrays of size n containing random integer values from 0
to 10,000 to sort. Use the system clock to record the running times of each
algorithm for ten different values of n for example: n = 5000, 10000, 15000,
20,000, ..., 50,000. Output the array size n and time to the terminal. Name
these new programs insertTime and mergeTime.

5. reference:
   https://www.geeksforgeeks.org/
