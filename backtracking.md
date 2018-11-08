# Backtarcking

### 概念
	回溯法的场景是这样的：你要在很多个选择里面选一个，当你做完选择之后，又会出现新的一组选项供你选择，这组选项取决于/也可以不依赖于你之前做的选择。你重复上面的"做选择"的动作，直到找到一个符合条件的一组选择，或者你一直走到头也没发现符合条件的选择，说明查找失败。
	
	在上述过程中，会遇到两种情况需要回溯：
	1. 你遇到了坏的子叶（即坏的一组选择），你需要回溯到该子叶的父节点，然后继续尝试该父节点基于上述节点的下一个选择；
	2. 你在途中（不在子叶上），当你尝试完了某个节点的所有子节点后，你需要回溯到该节点的父节点，然后继续尝试该父节点基于上述节点的下一个选项；

### 一般回溯的问题有三种类型：
1. Find a path to success 有没有解
2. Find all path to success 求所有解
	* 求所有解的个数
	* 求所有解的具体信息
3. Find the best path to success 求最优解

### 三类问题的模板

1. 第一类问题的模板：返回值是true/false
```
bool solve(Node n){
	if n is leaf node{
		if the leaf is a goal node
			return true;
		else return false;
	}
	else{
		for each child c of n{
			if solve(c) succeeds, return true;
		}
		return false;
	}
}
```

2. 第二类问题：1)求个数，设全局counter，返回值是void; 2)求所有解信息，设result，返回值void;

```
void solve(Node n){
	if n is a leaf node{
		if the leaf is a goal node
			count++, return;
			// update result;
		else return;
	}
	else{
		for each child c of n{
			solve(c);
		}
	}
}
```

3. 第三类问题：设全局变量best，返回值void。

```
void solve(Node n){
	if n is a leaf node{
		if the leaf is a goal node
			update best result, return;
		else return;
	}
	else{
		for each child c of n{
			solve(c);
		}
	}
}
```

### 关键问题：

1. 设置跳出的条件，子叶是否是好子叶(good leaf)；
2. 设置helper函数的参数；

3. 如何能很好的考虑中间态(状态空间树)的情况；
	1. i进来的时候，前面的i-1个选择已经做好了，对于i来说;
		* 可能不符合，如果不符合就“剪枝”(他的所有孩子都不需要尝试了)，然后回溯到它的父节点，继续尝试父节点孩子的下一个选项；
		* 可能符合，就继续递归的探索，以该节点为父节点继续探索他的所有孩子，做第i+1个选择；
	2. i 节点实际上是一种未知状态，它有多种选择可以选，每一种选择组成的状态就是i节点的子节点。

4. 如何实现对于第n个节点的m种情况进行取舍；
	* 剪枝：If there is any way to eliminate children(reduce the set of choices), do so!


### Stack Algorithms of Backtracking.
	Backtracking is a rather typical recursive algorithm, and any recursive algorithm can be rewritten as a stack algorithm. In fact, that is how your recursive algorithms are translated into machine or assembly language. 

* 第一类问题

```
bool solve(Node n){
	if n is leaf node{
		if the leaf is a goal node
			return true;
		else return false;
	}
	else{
		for each child c of n{
			if solve(c) succeeds, return true;
		}
		return false;
	}
}
```

* 第一类问题，recursive实现转化为stack实现

```
bool solve(Node n){
	put node n on the stack
	while the stack is not empty{
		if the node at the top of stack is a leaf{
			if it is a goal node, return true
			else pop it off the stack
		}
		else{
			if the node at the top of the stack has untried children
				push the next untried child onto the stack
			else 
				pop the node off the stack
		}
		return false
	}
}
```

### 回溯法在树上面的应用：DFS
* 模板：
```
bool solvable(BiTree node){
	if node is a goal node
		return true;
	if(node.left != NULL && solvable(node.left))
		return true;
	if(node.right != NULL && solvable(node.right))
		return true;
	return false;
}
```

### Debugging techniques
Trick 1: Indent when you print method entries and exits.
Trick 2: Use specialized print methods for debugging.
Trick 3: Never discard your debugging statement. The simple solution is to make your debugging statements conditional. 
Trick 4: Create an Exception.


### leetcode 题目汇总

1. Letter Combinations of a Phone Number	/电话号码的字母组合
2. Permutation I/II							/全排列 I/II
3. Generate Parentheses						/括号生成
4. Sudoku Solver							/解数独
5. Combination Sum I/II						/组合总和 I/II
6. N-Queeen	I/II							/N皇后 I/II
7. Permutation Sequence						/第k个排列
8. Combination								/组合
9. Subset I/II								/子集 I/II
10. Word Search								/单词搜索
11. Restore IP Addresses					/复原IP地址
12. Palindrome Partitioning (II)			/分隔回文串
13. Word Break I/II							/单词拆分 I/II




// 思路举例

幂集/排列(Permutation)问题
```
void PowerSet(int i, int n){
	// 求含n个元素的集合A的幂集。进入函数时已对A中前i-1个元素做了取舍处理，
	// 现从第i个元素起进行取舍处理。若 i>n, 则求得幂集的一个元素，并输出之。
	// 初始调用: PowerSet(1, n);
	if(i > n) 输出幂集的一个元素;
	else{									// 此处有两种选择，取/舍
		取第i个元素;
		PowerSet(i+1, n);
		舍第i个元素;
		PowerSet(i+1, n);
	}
}

```


N皇后问题
```
void Trail(int i, int n){
	// 进入本函数时，在n*n的棋盘前i-1行已经放置了互不攻击的i-1个棋子。
	// 现从第i行起继续为后续棋子选择合适位置。
	// 当 i>n 时，求得一个合法布局，输出之。
	if(i > n) 
		输出当前棋盘的布局;
	else{									// 此处有8种选择
		for(j = 1; j <= n; ++j){			// n = 8, 即为八皇后问题
			在第i行，第j列放置一个棋子;
			if(当前布局合法) Trail(i+1, n);
			移除第i行，第j列的棋子;
		}
	}
}

```

参考资料：
1. https://www.cis.upenn.edu/~matuszek/cit594-2012/Pages/backtracking.html , refer to pdf named by "Backtracking_DavidMatuszek_notation". 
2. https://blog.csdn.net/varyall/article/details/811603562. https://blog.csdn.net/varyall/article/details/81160356, refer to pdf named by "Backtracking_CSDN". 

