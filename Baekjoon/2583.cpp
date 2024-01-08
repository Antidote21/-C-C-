#include<iostream>
#include<vector>
using namespace std;

int m, n, k, cnt;
int map[101][101];
int visited[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
vector<int> res;
void dfs(int x, int y){
 
    if(visited[x][y]==0){
        visited[x][y]=1;
        cnt=0;
        for(int i=0; i<4; i++){
            int xx, yy;
            xx=x+dx[i];
            yy=y+dy[i];
            if(xx>n&&xx<0&&yy<0&&yy>m)continue;
            if(visited[xx][yy]==0&&map[xx][yy]==0){
                cnt++;
                dfs(xx,yy);
            }
        }
        res.push_back(cnt);
        
    }
}
int main(){
    cin>>m>>n>>k;
    for(int i=0; i<k; i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;      
        for(int j=y1; j<=y2; j++){
            for(int h=x1; h<=x2; h++){
                map[j][h] = 1;
            }
        }
    }
    dfs(0,0);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<' ';
    }
}
