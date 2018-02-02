#include <iostream>
using namespace std;

int minLenSubarray(int arr[], int n, int x){
    int min_len = 9999;
    int beg = 0, end = 0;
    int curr = 0;
    
    while(end < n){
        curr += arr[end];

        if(curr > x){
            while(curr-arr[beg] > x){
                curr -= arr[beg];
                beg++;
            }
            
            if((end - beg + 1) < min_len)
                min_len = end - beg + 1;
        }
        end++;
    }
    
    return min_len;
}

int main() {
    //code
    int t;
    cin>>t;
    while(t-- != 0){
        int n, val;
        cin>>n>>val;
        int arr[n];
        for(int i=0; i<n ;i++)
            cin>>arr[i];
        cout<<minLenSubarray(arr, n, val)<<"\n";
    }
    return 0;
}