#include<string>
#include<iostream>
using namespace std;

// general pattern matching solution
int index(string s, string t, int pos){
	unsigned int i = pos-1, j = 0;
	while(i < s.size() && j < t.size()){
		if(s[i] == t[j])
			i++, j++;	
		else{
			i = i-j+1;		// i back off j-1 steps, and then add 1
			j = 0;			// j back off j-1 steps
		}
	}
	if(j >= t.size())		// j > t.size() shows cmped all char of t
		return i - t.size()+1;
	else
		return 0;
}

// KMP algorigthm
// j don't need to back off to 0, only need to back to next[j] 


void getNext(string t, int* next){
	int n = t.size();
	for(int i = 0; i < n+1; i++)
		next[i] = 0;
	for(int i = 1; i < n; i++){
		int j = next[i+1];
		while(j > 0 && t[j] != t[i])
			j = next[j];
		if(j > 0 || t[j] == t[i])
			next[i+1] = j+1;
	}
//	unsigned int i = 1, j = 0;
//	next[1] = 0;
//	while(i < t.size()){
//		if(j == 0 || t[i] == t[j]){
//			++i, ++j;
//			next[i] = j;
//		}
//		else
//			j = next[j];
//	}
}

int indexKMP(string s, string t, int pos){
	int next[t.size()+1] ;
	for(int i = 0; (unsigned)i < t.size()+1; ++i)
		next[i] = 0;
	getNext(t, next);

	unsigned int i = pos, j = 0;
	while(i < s.size() && j < t.size()){
		if(j == 0 || s[i] == t[j]){
			++i, ++j;
		}
		else
			j = next[j];
	}
	if(j >= t.size())
		return i-t.size()+1;
	else
		return 0;
}
int main(){
	string s = "acabaabaabcacaabc";
	string t =      "abaabc";
	int idx = indexKMP(s, t, 1);
	cout << "The position begins at "<< idx << endl;
	return 0;
}

// pattern "aabaabaaa"
// next    "010123452"
/* c 
#include<stdio.h>
#include<bits/stdc++.h>
void computeLPSArray(char* pat, int M, int* lps){
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i < M){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len != 0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char* pat, char* txt){
	int M = strlen(pat);
	int N = strlen(txt);
	int lps[M];
	computeLPSArray(pat, M, lps);
	int i = 0;
	int j = 0;
	while(i < N){
		if(pat[j] == txt[i]){
			i++;
			j++;
		}
		if(j == M){
			printf("Found pattern at index %d", i-j);
			j = lps[j-1];
		}
		else if(i < N && pat[j] != txt[i]){
			if(j != 0)
				j = lps[j-1];
			else
				i = i + 1;
		}
	}
}
*/
