#include<iostream>
#include<set>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<vector<int> > &graph, int u, int v){
	graph[u].push_back(v);
}

void DFS(vector<vector<int> > &graph, set<int> &visited, stack<int> &finish, int v){
	if(visited.find(v) == visited.end()){
		visited.insert(v);
		for(int i=0; i<graph[v].size(); i++){
			DFS(graph, visited, finish, graph[v][i]);
		}
		finish.push(v);
	}
	return;
}

void transposeGraph(vector<vector<int> > graph, vector<vector<int> > &revGraph){
	for(int i=0; i<graph.size(); i++){
		for(int j=0; j<graph[i].size(); j++){
			revGraph[graph[i][j]].push_back(i);
		}
	}
	return;
}

void reverseGraphDFS(vector<vector<int> > &graph, set<int> &visited, int v){
	if(visited.find(v) == visited.end()){
		visited.insert(v);
		cout<<v<<" ";
		for(int i=0; i<graph[v].size(); i++){
			reverseGraphDFS(graph, visited, graph[v][i]);
		}
	}
}

void findSCCs(vector<vector<int> > &graph, int V){
	set<int> visited;
	stack<int> finish;
	for(int i=0; i<graph.size(); i++){
			DFS(graph, visited, finish, i);
	}
	visited.clear();
	
	vector<vector<int> > reverseGraph(V);
	transposeGraph(graph, reverseGraph);
	
	while(!finish.empty()){
		int v = finish.top();
		finish.pop();
		if(visited.find(v) == visited.end()){
			reverseGraphDFS(reverseGraph, visited, v);
			cout<<"\n";
		}
	}
	

}

int main(){
	int V = 5;
	vector<vector<int> > graph(V);
	addEdge(graph, 1, 0);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 4);
    
    findSCCs(graph, V);
	return 0;
}