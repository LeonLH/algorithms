# Backtarcking


## leetcode 题目汇总

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


总结：
	1. 递归函数的开头要写好跳出条



幂集/排列(Permutation)问题
```
void PowerSet(int i, int n){
	// 求含n个元素的集合A的幂集。进入函数时已对A中前i-1个元素做了取舍处理，
	// 现从第i个元素起进行取舍处理。若 i>n, 则求得幂集的一个元素，并输出之。
	// 初始调用: PowerSet(1, n);
	if(i > n) 输出幂集的一个元素;
	else{
		取第i个元素;
		PowerSet(i+1, n);
		舍第i个元素;
		PowerSet(i+1, n);
	}
}

```


八皇后问题
```
void Trail(int i, int n){
	// 进入本函数时，在n*n的棋盘前i-1行已经放置了互不攻击的i-1个棋子。
	// 现从第i行起继续为后续棋子选择合适位置。
	// 当 i>n 时，求得一个合法布局，输出之。
	if(i > n) 
		输出当前棋盘的布局;
	else{
		for(j = 1; j <= n; ++j){			// n = 8, 即为八皇后问题
			在第i行，第j列放置一个棋子;
			if(当前布局合法) Trail(i+1, n);
			移除第i行，第j列的棋子;
		}
	}
}

```

