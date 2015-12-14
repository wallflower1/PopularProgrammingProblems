#include<iostream>
#include<map>
using namespace std;

map<int, int> memo;

int playerWins(int n, int m1, int m2){
	if(n < m1 && n < m2){
		memo[n] = 0;
		return 0;		
	}
	else if (memo.find(n) != memo.end())
		return memo[n];
	else {
		int moveA = (n >= m1 && m1 != 0) ? playerWins(n-m1, m1, m2) : -1;
		int moveB = (n >= m2 && m2 != 0) ? playerWins(n-m2, m1, m2) : -1;
		
		if(moveA == 0 || moveB == 0){
			memo[n] = 1;
			return 1;
		} 
		memo[n] = 0;
		return 0;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n, m1, m2;
		cin>>n>>m1>>m2;
		memo.clear();
		if(m1 == 0 || m2 == 0){
			cout<<"1\n";
			continue;
		}
		cout<<playerWins(n, m1, m2)<<endl;
		
	}
	
	return 0;
}