#include<iostream>
#include<vector>
#include<map>
using namespace std;

int no_of_ways(int n, int *change, int m){
	int memo[n+1][m];

	for(int i=0; i<m; i++)
		memo[0][i] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int x = (change[j]<=i) ? memo[i-change[j]][j] : 0;
			int y = (j >= 1) ? memo[i][j-1] : 0;
			memo[i][j] = x+y;
		}
	}
	return memo[n][m-1];
}

int main(){
	int N, change[] = {1, 2, 3};
	N = 5;
	int size = sizeof(change)/sizeof(change[0]);
	cout<<no_of_ways(N, change, size)<<endl;
	return 0;
}