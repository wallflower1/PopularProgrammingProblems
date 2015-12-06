#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

struct subset{
	int parent;
	int rank;
};

void makesets(struct subset *subsets, int n){
	for(int i=0; i<n; i++){
    	subsets[i].parent = i;
    	subsets[i].rank = 0;
	}
	return;
}

int find(struct subset subsets[], int i){
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	
	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y){
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	
	if(xroot != yroot){
		if(subsets[xroot].rank < subsets[yroot].rank)
			subsets[xroot].parent = yroot;
		else if(subsets[xroot].rank > subsets[yroot].rank)
			subsets[yroot].parent = xroot;
		else {
			subsets[yroot].rank++;
			subsets[xroot].parent = yroot;
		}	
	}
	return;
}

void makeDisjointSets(string con[][3], struct subset *subsets, int n){
	map<string, int> mp;
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			if(mp.find(con[i][j]) != mp.end()){
				Union(subsets, i, mp[con[i][j]]);
			}
			else {
				mp[con[i][j]] = i;
			}
		}
	}
	return;
}

void printContacts(struct subset *subsets){

	map<int, vector<int> > lists;

	for(int i=0; i<n; i++){
		vector<int> temp;
		int k = subsets[i].parent;
		if(lists.find(k)!=lists.end())	temp = lists[k];
		temp.push_back(i);
		lists[k] = temp;
	}

	map<int, vector<int> >::iterator it = lists.begin();

	for(; it != lists.end(); ++it){
		vector<int> temp;
		temp = it->second;
		for(int i=0; i<temp.size(); i++){
			cout<<temp[i]<<" ";
		}
		cout<<endl;
	}
	return;
}

int main(){
	string con[][3] = {{"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"},
                     {"Lucky", "lucky@gmail.com", "+1234567"},
                     {"gaurav123", "+5412312", "gaurav123@skype.com"},
                     {"gaurav1993", "+5412312", "gaurav@gfgQA.com"},
                     {"raja", "+2231210", "raja@gfg.com"},
                     {"bahubali", "+878312", "raja"}
                    };
    
    int n = sizeof(con)/sizeof(con[0]);
    struct subset subsets[n];
    makesets(subsets, n);
    makeDisjointSets(con, subsets, n);
    printContacts(subsets);
	
	return 0;
}
