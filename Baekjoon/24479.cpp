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
