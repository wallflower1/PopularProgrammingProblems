#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
	string a, b;
	cin>>a>>b;
	int x = a.length();
	int y = b.length();
	int sum = 0;
	
	int ones[y], zeroes[y];
	if(b[0]=='0'){
		zeroes[0]=1;
		ones[0]=0;
	}
	else {
		zeroes[0]=0;
		ones[0]=1;
	}
		
	for(int i=1; i<y; i++){
		if(b[i]=='1'){
			ones[i] = ones[i-1]+1;
			zeroes[i] = zeroes[i-1];
		} else{
			ones[i] = ones[i-1];
			zeroes[i] = zeroes[i-1]+1;
		}
	}
	
	for(int i=0; i<x; i++){
		if(a[i]=='0'){
			sum += ones[y-x+i]-ones[i];
		} else {
			sum += zeroes[y-x+i]-zeroes[i];
		}
		
	}
	cout<<sum;
}