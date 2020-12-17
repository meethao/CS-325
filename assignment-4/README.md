CS - 325        
Assignment-3
Name: Jia Hao
Student ID: 9336363448
E-mail: jiaha@oregonstate.edu

1. My ZIP file includes a graph.txt, mstEuclid.cpp.

2. You can run my "mstEuclid.cpp" which shows the code.
      using Flip and enter g++ msttEuclid.cpp. Then, enter a.out graph.txt. You can get the result.

3. Implement an algorithm in the language of your choice (C, C++ or Python) that determines the MST in a graph G=(V,E) where the vertices are points (x,y) in the rectangular coordinate system and the weight of the edge between each pair of points is the Euclidean distance between those points. To avoid floating point precision problems in computing the square-root, we will always round the distance to the nearest integer.

4. Assume that the graph G=(V,E) is complete so that there is an edge between every two vertices.
Your program (mstEuclid) should read information about the graph from a file given in the command line. Each input file contains information about one graph: the first line in the file is the number of vertices in the graph (n ≤ 100) and the following lines contain the x,y coordinates of the vertices in the graph. The output should be displayed to the terminal and contain the edges (x1,y2) to (x2,y2) in the MST along with the edge distances and the total distance of the MST.
