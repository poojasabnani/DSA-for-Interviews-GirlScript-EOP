#include<bits/stdc++.h>
#include<vector>
using namespace std;

int n, m, x, y;
int visited[10];
int cnt = 0;
vector< vector<int> > graph(10);

void dfs(int node){
	visited[node]=1;
	cnt++;
	for (int i=0; i<graph[node].size(); i++){
		if(visited[graph[node][i]]==0){
			dfs(graph[node][i]);
		}
	}
}

int main(){
	cin>>n>>m;
	for (int i=0;i<m; i++){
		scanf("%ld %ld", &x, &y);
		graph[x].push_back(y);
	}
	
	int sum = 0;
	for(int i=1; i<=n; i++){
		if(visited[i]==0){
			dfs(i);
			sum += (cnt*(cnt-1))/2;
			cnt = 0;
		}
	}
	if(sum == n){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}
