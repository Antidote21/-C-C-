#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };


void dfs(int r) {
	if (visited[r] == 1) {
		return;
	}else{
    	visited[r] = 1; 
    	for (int i = 0; i < graph[r].size(); i++) {
	    	dfs(graph[r][i]); 
	    }       
    }

}
int main() {
	int n, m;
	int cnt = 0;
	cin>>n>>m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b); 
		graph[b].push_back(a); 
	}
	
	dfs(1);
	
	for(int i=2; i<=n; i++){
	    if(visited[i]==1)cnt++;
	}
	cout<<cnt;

}
