#include<iostream>
using namespace std;

int find_ceil(int arr[], int T[], int x, int l, int h){
	int m;
	while(h-l > 1){
		m = l + (h-l)/2;
		if(arr[T[m]] >= x){
			h=m;
		} else l=m;
	}
	return h;	
}

void lis(int arr[], int n){
	int T[n], R[n], len=0;
	for(int i=0; i<n; i++) R[i] = -1;
	T[len] = 0; 
	for(int i=1; i<n; i++){
		if(arr[i]>arr[T[len]]){
			len++;
			T[len] = i;
			R[i] = T[len-1]; 
		}
		else if(arr[i]<arr[T[0]]){
			T[0] = i;
		} else{
			int k = find_ceil(arr, T,arr[i], 0, len);
			T[k] = i;
			R[i] = T[k-1];
		}
	}
	
	int num = T[len];
	while(num != -1){
		cout<<arr[num]<<" ";
		num = R[num];
	}
	return;
}

int main(){
	int n = 11;
	int arr[] = {3,4,-1,5,8,2,3,12,7,9,10};
	lis(arr, n);
	return 0;
}