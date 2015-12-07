#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
 string pattern, text;
 getline(cin, text);
 getline(cin, pattern);
 vector<int> prefix(pattern.length(),0);
 int m = pattern.length();
 cout<<"pattern lenth: "<<m<<endl;
 int n = text.length();
 
 //build prefix array
 prefix[0]=0;
 int j=1,i=0;
 while(j<m){
     if(pattern[i]==pattern[j]){
       prefix[j]=i+1;
       i++;
       j++;
     }
     else if(i==0){
       prefix[j]=0;
       j++;
     } 
     else {
       i = prefix[i-1];
     }
 }
 
 //pattern matching
 i=0; j=0; 
 int index=-1;
 while(true){
     if(pattern[i]==text[j]){
       i++; j++;
       if(i==m){
         index = j-i;
         break;
       }
     } else if(j<n) {
       if(i>0){
         i = prefix[i-1];
       } else{
       j++;
     }
     continue;
     } else {
       break;
     }
 }
 (index>-1) ? cout<<"Pattern matched at: "<<index : cout<<"Pattern not found!";
 return 0;
}