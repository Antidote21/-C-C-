#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int visited1[1001];
int visited2[1001];
vector<int> graph[10001];

void dfs(int start){
    if(visited1[start]==1){
        return;
    }else{
        visited1[start] = 1;
        cout<<start<<' ';
        for(int i=0; i<graph[start].size(); i++){     
            dfs(graph[start][i]);
        }
    }
}

void bfs(int start){
    queue<int> Q;
    Q.push(start);
    visited2[start] = 1;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        cout<<x<<' ';
        for(int i=0; i<graph[x].size(); i++){
            if(!visited2[graph[x][i]]){
                Q.push(graph[x][i]);
                visited2[graph[x][i]] = 1;
            }
        }
    }
}
int main(){
    int n,m,v;
    cin>>n>>m>>v;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout<<endl;
    bfs(v);
}
