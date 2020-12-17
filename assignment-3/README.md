CS - 325        
Assignment-3
Name: Jia Hao
Student ID: 9336363448
E-mail: jiaha@oregonstate.edu

1. My ZIP file includes a knapsack.cpp, shopping.cpp, results.txt, and shopping.txt.

2. First, you can run my "knapsack.cpp" which shows the code that how can I collect the data.
Second, you can run my "shopping.cpp". This file can read the data from the "shopping.txt". Then, the program can determine the maximum total price of items for each family and the items that each family member should select. In the last, the program can output the maximum total price of all goods that the family can carry out during their shopping spree and for each the family member

3. knapsack.cpp : This program randomly generate test cases that are solved using both the DP and Recursive algorithm. And it output to the terminal: n, W, time for the DP algorithm, max for the DP, time for the Recursive algorithm, max for Recursive. The max values should be the same.

4. shopping.txt: Input: The input file named “shopping.txt” consists of T test cases
 T (1 ≤ T ≤ 100) is given on the first line of the input file.
 Each test case begins with a line containing a single integer number N that indicates the number of items (1 ≤ N ≤ 100) in that test case
 Followed by N lines, each containing two integers: P and W. The first integer (1 ≤ P ≤ 5000) corresponds to the price of object and the second integer (1 ≤ W ≤ 100) corresponds to the weight of object.
 The next line contains one integer (1 ≤ F ≤ 30) which is the number of people in that family.
 The next F lines contains the maximum weight (1 ≤ M ≤ 200) that can be carried by the ith person in the family (1 ≤ i ≤ F).


5. results.txt: each test case your program should output the maximum total price of all goods that the family can carry out during their shopping spree and for each the family member, numbered 1 ≤ i ≤ F, list the item numbers 1 ≤ N ≤ 100 that they should select.

6. shopping.cpp: Acme Super Store is having a contest to give away shopping sprees to lucky families. If a family wins a shopping spree each person in the family can take any items in the store that he or she can carry out, however each person can only take one of each type of item. For example, one family member can take one television, one watch and one toaster, while another family member can take one television, one camera and one pair of shoes. Each item has a price (in dollars) and a weight (in pounds) and each person in the family has a limit in the total weight they can carry. Two people cannot work together to carry an item. Your job is to help the families select items for each person to carry to maximize the total price of all items the family takes. Write an algorithm to determine the maximum total price of items for each family and the items that each family member should select.
