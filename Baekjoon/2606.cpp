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


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    vector<int> com[100];
    bool visited[100] = {false}; // 각 노드의 방문 여부를 저장하는 배열
    int n, m, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    queue<int> Q;
    Q.push(1);
    visited[1] = true; // 시작 노드를 방문 처리
    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();
        for(int i = 0; i < com[tmp].size(); i++){
            int neighbor = com[tmp][i];
            if(!visited[neighbor]){ // 방문하지 않은 이웃 노드라면
                Q.push(neighbor);
                visited[neighbor] = true; // 방문 처리
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
