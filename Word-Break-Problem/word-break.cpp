#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
#define it vector <string>::iterator

string words[] = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
set<string> dict(words,words+(sizeof(words)/sizeof(words[0])));
vector<string> list;
bool flag = false;

//recursive call for breaking suffix into words
void wordBreak(string text){
	int len = text.length();
	
	if(len==0){
		flag = true;
		for(it x= list.begin(); x!= list.end(); ++x){
			cout<<*x<<" ";
		}
		cout<<endl;
		return;
	}
	
	for(int j=0; j<len; j++){
		string prefix = text.substr(0,j+1);
		
		if(dict.find(prefix)!=dict.end()){
			list.push_back(prefix);
			wordBreak(text.substr(j+1, len-j-1));
			list.pop_back();
		}
	}
}

int main(){	
	wordBreak("ilikesamsung");
	if(!flag)	cout<<"cannot be broken.";
	return 0;
}