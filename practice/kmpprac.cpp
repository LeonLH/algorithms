#include<vector>
#include<string>
#include<iostream>
using namespace std;

void getNext(string pat, vector<int> &next){
	int len = 0;
	int i = 1;
	next[0] = 0;
	int n = pat.size();
	while(i < n){
		if(pat[i] == pat[len]){
			len++;
			next[i] = len;
			i++;
		}
		else if( pat[i] != pat[len] ){
			if(len != 0){
				len = next[len-1];
			}
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

	getNext(pat, next);

	int i = pos, j = 0;
	while(i < n){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}

		if(j == m){
			return i-j;
		}
		else if(j < m && txt[i] != pat[j]){
			if(j == 0)
				i++;
			else
				j = next[j-1];
		}
	}
	return -1;
}

int main(){
	string txt = "acabaabaabcacaabc";
	string pat =      "abaabc";
	int idx = indexKMP(txt, pat);
	cout << "The position is at: " << idx+1 << endl;
	return 0;

}
