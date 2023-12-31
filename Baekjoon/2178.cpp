#include<iostream>
using namespace std;
int n,m,cnt;
int map[101][101];
int visited[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void dfs(int x, int y){
    if(x==n&&y==m){
        cout<<cnt;
        return;
    }
    for(int i=0; i<4; i++){
        int nextX, nextY;
        nextX=x+dx[i];
        nextY=y+dy[i];
        if(map[nextX][nextY]==1&&visited[nextX][nextY]==0&&nextX>=1&&nextX<=n&&nextY>=1&&nextY<=m){
            visited[nextX][nextY]=1;
            cnt++;
            dfs(nextX,nextY);
            visited[nextX][nextY]=0;
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>map[i][j];
        }
    }
    visited[1][1] = 1;
    dfs(1,1);
    cout<<cnt;
}
