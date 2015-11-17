#include<iostream>
using namespace std;

int max(int a, int b){
	if (a>b) return a;
	return b;
}

void lis(int arr[], int n){
	int curr_max=1;
	int currlis[n];
	//getting LIS for each element in its prefix array
	for(int i=0; i<n; i++){
		currlis[i] = 1;
		for(int j=0; j<i; j++){
			if(arr[j]<arr[i]){
				currlis[i] = max(currlis[i], 1+currlis[j]);
				curr_max = max(currlis[i], curr_max);
			}
		}
	}

	//printing the LIS
	int max_index;
	for(int i=n; i>=0; i--) {
		if(currlis[i]==curr_max){
		 max_index = i; break;}
	}
	cout<<arr[max_index]<<" ";
	int nextval = curr_max-1;
	int prev_index = max_index;
	for(int i=max_index-1; i>=0; i--){
		if(nextval == currlis[i] && arr[i]<arr[prev_index]){
			nextval--;
			prev_index = i;
			cout<<arr[i]<<" ";
		}
	}
	return;
}

int main(){
	int n = 11;
	int arr[] = {3,4,-1,5,8,2,3,12,7,9,10};
	return 0;
}