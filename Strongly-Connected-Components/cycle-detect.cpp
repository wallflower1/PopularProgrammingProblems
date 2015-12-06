#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool detectCycle(int v, vector<vector<int> > graph, set<int> &visited, set<int> &grey){
	if(visited.find(v) == visited.end()){
		visited.insert(v);
		grey.insert(v);
		for(int i=0; i<graph[v].size(); i++){
			int u = graph[v][i];
			if((visited.find(u) == visited.end()) && detectCycle(u, graph, visited, grey))
				return true;
			else if(grey.find(v) != grey.end())
				return true;
		}
	}
	grey.erase(v);
	return false;
}

bool detectCycleUtil(vector<vector<int> > graph){
	set<int> visited, grey;
	
	for(int i=0; i<graph.size(); i++){
		if(detectCycle(i, graph, visited, grey))
			return true;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int> > graph(n);
	int e;
	cin>>e;
	while(e--){
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	
	if (detectCycleUtil(graph))
		cout<<"Cycle exists in the graph";
	else
		cout<<"No cycle exists!";
	
	return 0;
}