#include <iostream>
using namespace std;

int maxProfit(int arr[], int n, int k){
    int dp[k+1][n];
    
    for(int i=0; i<n; i++)
        dp[0][i] = 0;
    for(int i=0; i<=k; i++)
        dp[i][0] = 0;
        
    for(int i=1; i<=k; i++){
        for(int j=1; j<n; j++){
            //no transaction on jth day
            int profit_wo = dp[i][j-1];
            
            //sell on jth day
            int profit_w = 0;
            for(int d=0; d<j; d++ ){
                int p = arr[j]-arr[d] + dp[i-1][d];
                if(profit_w < p){
                    profit_w = p;   
                }
            }
            //set max profit
            dp[i][j] = max(profit_wo, profit_w);
        }
    }
    return dp[k][n-1];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int k, n;
	    cin>>k>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	    cin>>arr[i];
	    cout<<maxProfit(arr, n, k)<<"\n";
	}
	return 0;
}