#include<iostream>
#include<queue>
#include<vector>
using namespace std;
char map[101][101];
int ch1[101][101];
int ch2[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>> Q;
void bfs(int x, int y){
    
}
int main(){
    int n, m, cnt=0;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%c",&map[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]=='W'&&ch1[i][j]==0){
                Q.push(make_pair(i,j));
                ch1[i][j]=1;
                while(!Q.empty()){
                    pair<int, int> pos = Q.front();
                    Q.pop();
                    for(int i=0; i<4; i++){
                        int xx=pos.first+dx[i];
                        int yy=pos.second+dy[i];
                        if(xx>=0 && xx<n && yy>=0 && yy<m &&map[xx][yy]=='W'){
                            Q.push(make_pair(xx,yy));
                            ch1[xx][yy]=1;
                            cnt++;
                        }
                    }
                }
                cnt++;
            }
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}
