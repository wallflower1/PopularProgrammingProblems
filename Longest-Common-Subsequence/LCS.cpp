#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int> > lcs;
int LCS_length(string a, string b, int n, int m){
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(i==0 || j==0){
				lcs[i][j] = 0;
			}
			else if(a[i-1] == b[j-1]){
				lcs[i][j] = 1+lcs[i-1][j-1];
			} 
			else {
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	
	return lcs[n][m];
} 

void print_LCS(string a, string b, int n, int m){
	int i=n, j=m;
	string c="";
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			c= a[i-1]+c;
			i--; j--;
		}
		else{
			if(lcs[i-1][j]>lcs[i][j-1]){
				i--;
			} else {
				j--;
			}
		} 
	}
	cout<<c;
}

int main(){
	string a="abcabd";
	string b="xaabcbad";
	string c="";
	int a_len = a.length();
	int b_len = b.length();
	lcs.resize(a_len+1);
	for(int i=0; i<=a_len; i++)
		lcs[i].resize(b_len+1);
	cout<<"Longest common subsequence\nlength: "<<LCS_length(a, b, a_len, b_len)<<"\nSubsequence: ";
	print_LCS(a, b, a_len, b_len);
	
}