### 递归
1. 如果递归能将问题的规模缩小，那就是好递归。
2. 缩小后，问题的性质没有发生变化，如，二分查找缩小规模后，问题的仍然是在数组中查找数据。
3. 递归是一种通用方法，正如迭代(iterative)一样，它可以用在很多的不同算法中，比如分治，回溯，动态规划等等。我需要多练习用递归的思维方式来思考问题，这样来逐步掌握递归，正如掌握迭代的思维方式一样。


### Best way to master:

1. Figure out the base case first.
	1. First, you focus on what needs to be solved at its simplest form(the simpler cases) and this somehow drews a road map for the future algorithm;
	2. Second, you make sure the algorithm stops. Maybe doesn't return the expected result, but at least stops, which is always encouraging.

2. Also, It always help figuring out how a small instance of a problem will help you finding the solution of a bigger instance of the problem. This is for example, how can you build the solution for input n having already the solution of input n-1.

3. **Solve every problem you can think of recursively.** Yes, Hanoi Towers isn't a very good example, its recursive solutions is a very clever solution. Try easier problems, almost elemental problems.

### Some advice:

1. **Most Importantly, begin with simple problems.**
2. One last advice, if you can't find a solution to a problem, search for it on the internet or call for help, **understand what is does compeletly** and move on to the other. Don't let them bypass you, because what you're trying to do is **incorporate the way of thingking to your heaad.** 


### 递归程序的几条法则：
1. 基准情况
	* 就是递归的终止条件。例如，在二分查找中是找到我们要找的数，或者查找失败；
2. 不断演进
	* 演进的过程就是我们思考的过程。例如，二分查找中就是继续查找剩下一半的数组；
3. 用人的思考方式设计
	* 
4. 不要做重复的事情
	* 由于在递归中，一次多余的递归会使算法的复杂度成指数级改变，所以要尽可能不做重复的事。

### 尾递归
1. 递归调用后仅仅返回了返回值，尾递归。递归函数的调用过程可以分为递和归两部分。在递归调用之前的部分称作递，调用之后的部分称作归。而为递归在归的过程中实际上不做任何事，这种情况很容易将这个递归程序转换为非递归程序。


### Reference:
1. https://blog.csdn.net/u010697982/article/details/45875913
2. https://en.wikipedia.org/wiki/Recursion_(computer_science)
 
