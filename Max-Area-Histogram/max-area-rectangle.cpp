#include<iostream>
#include<stack>
using namespace std;
#define R 4
#define C 6

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

int maxSizeRectangle(int (*matrix)[C]){
	int hist[C]={0};
	int area, maxarea = 0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			hist[j] = (matrix[i][j]==0?0:matrix[i][j]+hist[j]);
		}
		area = maxAreaHistogram(hist, C);
		if(area > maxarea)
			maxarea = area;
	}
	return maxarea;
}

int main(){
	int matrix[R][C]={{1,0,0,1,1,1},{1,0,1,1,0,1},{0,1,1,1,1,1},{0,0,1,1,1,1}};
	cout<<maxSizeRectangle(matrix);
	
}