#include<iostream>
#include<string>
using namespace std;
#define SIZE 26
bool isPermPalindrome(string str){
	int countArray[SIZE] = {0};
	for(int i=0; i<str.length(); i++){
		int index = str[i] - 'a';
		if(countArray[index]==0){
			countArray[index]++;
		} else {
			countArray[index]--;
		}
	}
	int count=0;
	for(int i=0; i<SIZE; i++){
		count+=countArray[i];
	}
	cout<<endl<<str.length()<<"count: "<<count;
	if((str.length()%2==0 && count==0) || (str.length()%2!=0 && count==1)) return true;
	else return false;
}

int main(){
	int len, q;
	cin>>len>>q;
	string str;
	cin>>str;
	while(q--){
		int a;
		cin>>a;
		if(a==1){
			int b;
			char c;
			cin>>b>>c;
			str[b-1] = c; 
		} else{
			int b, c;
			cin>>b>>c;
			cout<<str.substr(b-1,c-b+1);
			if(isPermPalindrome(str.substr(b-1,c-b+1)) == true){
				cout<<"yes"<<endl;
			} else 
			{
				cout<<"no"<<endl;
			}
		}
	}
	return 0;
}
