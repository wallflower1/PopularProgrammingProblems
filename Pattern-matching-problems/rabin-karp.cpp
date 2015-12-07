#include<iostream>
#include<string>
using namespace std;
#define d 256
#define q 101
int main(){
 string text, pattern;
 getline(cin, text);
 getline(cin, pattern);
 int m=pattern.length();
 int n=text.length();
 int p=0, t=0, h=1;
 int flag=0;
 
 //calculate hash
 for(int i=0;i<m-1;i++){
     h = (h*d)%q;
 }
 
 //calculate hash values for pattern and first m-length substring
 for(int i=0; i<m; i++){
     p = (p*d + pattern[i])%q;
     t = (t*d + text[i])%q;
 }
 
 //check over all m-windows in text against pattern
 int i=0;
 while(i<=n-m){
     if(p==t){
       int j;
       for(j=0; j<m; j++){
       if(text[i+j]!=pattern[j]){
         break;
         }
       }
       if(j==m){
         cout<<"Match found at: "<<i<<endl;
         flag=1;
         }
       }
 
       if(i<n-m){
         t = (d*(t - text[i]*h) + text[i+m])%q;
         if(t<0) t += q;
       }
       i++; 
 }
 if(flag==0) cout<<"No match exists!" ;
 return 0;
}