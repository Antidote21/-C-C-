#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph; 
vector<int> visited;
int n, m, r;

void dfs(int start){
    if(start > n) return;
    
    if(visited[start] != 1){
        visited[start] = 1;
        int next = graph[start][1];
        if(next==0)cout<<0<<endl;
        else{
          cout<<next<<endl;    
        }
        dfs(next);
    } else {
        dfs(start + 1);
    }
}

int main(){

    cin >> n >> m >> r;
    graph.resize(n + 1);
    visited.resize(n + 1, 0);
    cout<<r<<endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(r);
    return 0;
}
//방문여부를 기준으로 정점 순서 증가를 고려하지 않음, 인접 정점이 오름차순이라는 제한 사항을 고려하지 않음, cin과 cout 사용시 시간 초과 
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };
int result[100001];
int cnt = 0;

void dfs(int r) {
	if (visited[r] == 1) {
		return;
	}

	visited[r] = 1; 
	cnt++;
	result[r] = cnt;

	for (int i = 0; i < graph[r].size(); i++) {
		dfs(graph[r][i]); 
	}
}
int main() {
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b); 
		graph[b].push_back(a); 
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(r);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}
	
}
