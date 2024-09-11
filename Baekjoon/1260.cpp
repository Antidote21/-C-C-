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


#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int visited1[1001];
int visited2[1001];
vector<int> graph[10001];

void dfs_iterative(int start){
    stack<int> S;
    S.push(start);
    visited1[start] = 1;
    while(!S.empty()){
        int x = S.top();
        S.pop();
        cout << x << ' ';
        for(int i = graph[x].size() - 1; i >= 0; --i){
            int next = graph[x][i];
            if(!visited1[next]){
                S.push(next);
                visited1[next] = 1;
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
    dfs_iterative(v);
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ch1[1000];  
int ch2[1000];  

void dfs(vector<vector<int>>& graph, int start, int cnt, int N){
    if(cnt == N) return;
    else {
        cout << start << " ";
        for(int i = 0; i < graph[start].size(); i++){
            int next = graph[start][i];
            if(ch1[next] == 0){
                ch1[next] = 1;
                dfs(graph, next, cnt + 1, N);
            }
        }
    }
}

void bfs(vector<vector<int>>& graph, int start){
    queue<int> Q;
    Q.push(start);
    ch2[start] = 1;
    
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        cout << node << " "; 
        
        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if(ch2[next] == 0){
                ch2[next] = 1;
                Q.push(next);
            }
        }
    }
}

int main(){
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); 
    }

    ch1[V] = 1;  
    dfs(graph, V, 0, N);
    cout << endl;

    bfs(graph, V);

    return 0;
}
