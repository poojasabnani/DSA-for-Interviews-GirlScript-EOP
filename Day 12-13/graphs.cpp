#include<bits/stdc++.h>
using namespace std;



vector <vector <int> > adj; //adjacency list
const int N=10;
bool visited[N];

void dfs(int node){
	if(visited[node])
		return;
	visited[node]=1;
	cout<<"Reached node: "<<node<<endl;
	for(int j=0; j<adj[node].size(); j++){
		dfs(adj[node][j]);
	}
	cout<<"Done with node: "<<node<<endl;
}

int main(){
	
	int n, m;		//n->no. of nodes, m->no. of edges
	cin>>n >>m;
	adj.resize(n+1);
	for (int i=1, u, v; i<=m; i++){
		cin>>u>>v;		//u is starting node and v is ending node of the edge.
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	
	dfs(1);
	
	return 0;
}
