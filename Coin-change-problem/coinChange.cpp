#include<iostream>
#include<vector>
#include<climits>
#include<map>
using namespace std;

int sum, change[] = {5, 4, 3, 2};

int ccMin(){
	map<int, int> memo;
	memo[0] = 0;
	for(int i=1; i<=sum; i++){
		memo[i] = INT_MAX;
		cout<<memo[i]<<endl;
	}
	int size = sizeof(change)/sizeof(change[0]);
	cout<<"size: "<<size<<endl;
	for(int i=1; i<= sum; i++){
		int flag = 0;
		for(int j=0; j<size; j++){
			if(change[j]<= i && memo[i-change[j]]!=-1){
				flag = 1;
				memo[i] = min(memo[i], 1+memo[i-change[j]]);
			}
		}
		if(flag == 0) memo[i]=-1;
	}
for(int i=0; i<=sum; i++)
	cout<<memo[i]<<endl;
	return memo[sum];
}

int main(){ 
	sum = 10;
	cout<<"Min possible coins: "<<ccMin();
	return 0;
}