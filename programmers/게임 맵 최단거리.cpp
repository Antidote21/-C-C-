#include<vector>
#include<algorithm>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int ch[100][100];
int res = 1000;

void dfs(vector<vector<int> > maps, int x, int y, int ans){
    int n = maps.size();
    int m = maps[0].size();
    if(x==n-1&&y==m-1){
        res = min(res, ans);
        return;
    }
    for(int i=0; i<4; i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx<0 || xx>=n || yy<0 || yy>=m || ch[xx][yy] == 1 || maps[xx][yy] == 0)continue;
        
        ch[xx][yy]=1;
        dfs(maps, xx, yy, ans+1);
        ch[xx][yy]=0;
    
    }
}

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    ch[0][0]=1;
    dfs(maps, 0, 0, 1);
    return res == 1000 ? -1 : res;
}
