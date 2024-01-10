 #include<iostream>
#include<vector>
using namespace std;
int n, a, b, m;
vector<int> relation[100];
int ch[100];
int res[100];
int cnt;
void dfs(int v){
    ch[v] = 1;
    for(int i=0; i<relation[v].size(); i++){
        int next = relation[v][i];
        if(ch[next]==0){
            cnt+=1;
            res[next]=cnt;
            dfs(next);    
        }
        //res[v].push_back(cnt);
    }
}

int main(){
    cin>>n>>a>>b>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        relation[x].push_back(y);
    }
    dfs(1);
    for(int i=0; i<n; i++){
        cout<<res[i]<<endl;
    }
}
