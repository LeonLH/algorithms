#include<string>
#include<vector>
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


void getNext(string pat, vector<int> &next){
	int m = pat.size();
	int len = 0;
	int i = 1;
	while(i < m){
		if(pat[i] == pat[len]){
			len++;
			next[i] = len;
			i++;
		}
		else{
			if(len != 0)
				len = next[len-1];
			else{
				next[i] = 0;
				i++;
			}
		}
	}

}

int indexKMP(string txt, string pat, int pos = 0){
	int n = txt.size();
	int m = pat.size();
	vector<int> next;
	next.resize(m);

	// create next that will hold the longest prefix and suffix
	// values for pattern. 
	// Vector next's value means that when pat[j+1] != txt[i] and 
	// j need to back off, at this time the length of substring
	// which don't need to compare any more. This length is the 
	// value of next[j]. 
	// next 中的值是，如果它下一个不匹配，j回退的时候，前面有
	// 几个字母不需要再比较了，这个数字就是next中的值。
	getNext(pat, next);
	int i = pos, j = 0;
	while(i < n){
		if(txt[i] == pat[j]){
			j++;
			i++;
		}

		if(j == m){
			return i-j;
			// cout << "Found pattern at index: " << i-j;
			// j = next[j-1];	// There are more than one matches
		}
		else if(i < n && txt[i] != pat[j]){
			if(j != 0)
				j = next[j-1];
			else
				i = i + 1;
		}
	}
	return -1;
}
int main(){
	string txt = "acabaabaabcacaabc";
	string pat =      "abaabc";
	int idx = indexKMP(txt, pat, 3);
	cout << "The position begins at "<< idx+1 << endl;
	return 0;
}

// pattern "aabaabaaa"
// next    "010123452"

/* c 
void computeLPSArray(char* pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		 } 

		if (j == M) { 
			printf("Found pattern at index %d ", i - j); 
			j = lps[j - 1]; 
		 } 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		 } 
	 } 
 } 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		 } 
		else // (pat[i] != pat[len]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) { 
				len = lps[len - 1]; 

				// Also, note that we do not increment 
				// i here 
			 } 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			 } 
		 } 
	 } 
 } 

// Driver program to test above function 
int main() 
{ 
	char txt[] = "ABABDABACDABABCABAB"; 
	char pat[] = "ABABCABAB"; 
	KMPSearch(pat, txt); 
	return 0; 
 } 
*/
