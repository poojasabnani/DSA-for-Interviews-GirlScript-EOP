# DSA DAY 12 & 13

## Topics Covered

Graph Algorithms

## Theory

[Graphs Part 1](https://github.com/py93/DSA-for-Interviews-GirlScript-EOP/blob/master/Day%2012-13/Graphs.pptx?raw=true)

[Graphs Part 2]()

## Quiz

[Take the Quiz](https://forms.gle/vCqb3QGuBCPahLp5A)

## Code Snippets

Implementation of graphs and DFS using adjacency list

```c
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

```

Transitivity property of graphs

```c
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int n, m, x, y;
int visited[10];
int cnt = 0;
vector< vector<int> > graph(10);

void dfs(int node)
{
	visited[node]=1;
	cnt++;
	for (int i=0; i<graph[node].size(); i++)
	{
		if(visited[graph[node][i]]==0)
		{
			dfs(graph[node][i]);
		}
	}
}

int main(){
	cin>>n>>m;
	for (int i=0;i<m; i++)
	{
		scanf("%ld %ld", &x, &y);
		graph[x].push_back(y);
	}
	
	int sum = 0;
	for(int i=1; i<=n; i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
			sum += (cnt*(cnt-1))/2;
			cnt = 0;
		}
	}
	if(sum == n)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}

```
