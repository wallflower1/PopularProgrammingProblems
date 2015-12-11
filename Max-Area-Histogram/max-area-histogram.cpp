#include<iostream>
#include<stack>
using namespace std;

int maxAreaHistogram(int *hist, int n){
	stack<int> s;
	int top, area, maxarea=0, i=0;
	while(i<n){
		if(s.empty() || hist[s.top()]<hist[i])
			s.push(i++);
		else{
			top = s.top();
			s.pop();
			area = hist[top] * (s.empty()? i: i-s.top()-1);
			
			if(area > maxarea)
				maxarea = area;
		}
	}
	while(!s.empty()){
		top = s.top();
		s.pop();
		area = hist[top] * (s.empty()? i: i-s.top()-1);
		
		if(area > maxarea)
			maxarea = area;
	}
	return maxarea;
}

int main(){
	int hist[] = {6,2,5,4,5,1,6};
	int n = sizeof(hist)/sizeof(hist[0]);
	cout<<maxAreaHistogram(hist, n);
	
}
