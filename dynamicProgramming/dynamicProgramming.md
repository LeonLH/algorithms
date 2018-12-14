### Dynamic Programming 

##### Comparision with Divide-and-conquer

1. Divide-and-conquer algorithms split a problem into separate subproblems, solve the subproblems, and conbine the results for a solution to the original problem.
	* Example: Quicksort
	* Example: Mergesort
2. Divide-and-conquer algorithms can be thoutht of as **top-down** algorithms. 
3. In contrast, a dynamic programming algorithm proceeds by solving small problems, remembering the results, then combining them to find the solution to large problems. 
4. Dynamic programming can be thought of as **bottom-up**. 

##### The principle of optimality

1. Dynamic programming is a technique for finding an optimal sulution. 
2. The **principle of optimality** applies if the optimal solution to a problem always contains optimal solutions to all subproblems. 

##### Comments

1. Dynamic programming relies on working "from the bottom up" and saving the results of solving simpler problems
	* These solution to simpler problems are then used to compute the solution to more complex problems
2. Dynamic programming solutions can often be quite complex and tricky.
3. Dynamic programming is used for optimization problems, especially ones that would otherwise take exponential time.
	* Only problems that satisfy the principle of optimality are suitable for dynamic programming solutions. 
4. Since exponential time is unacceptable for all but the smallest problems, dynamic programming is sometimes essential. 



### Reference
1. ppt of 30-dynamic-programming from CIT 594 Programming Languages & Techniques II Spring 2015, David Matuszek.  
2. Introductions to the Design and analysis of algorithms (Third Edition), Anany Levitin, page 219-242. 
https://blog.csdn.net/u013309870/article/details/75193592
https://blog.csdn.net/littlehaes/article/details/80044738
