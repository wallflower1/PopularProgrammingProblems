#include <iostream>
#include <string> 
using namespace std;
void swap(char &a, char &b){
    char c = b;
    b=a;
    a=c;
}

void allAdjPerms(string str, int n){
    if(n==0 || n==1)
        {cout<<str<<" "; return;}
    
    allAdjPerms(str, n-1);
    swap(str[n-1], str[n-2]);
    allAdjPerms(str, n-2);
    
}

// Driver Code
int main()
{
	string str = "12345";
	allAdjPerms(str, 5);
	
	return 0;
}

