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

#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int dist[100][100];

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int> > Q;
    Q.push({0, 0});
    dist[0][0]=1;
    
    while(!Q.empty()){
        pair<int, int> A = Q.front();
        Q.pop();
        
        for(int i=0; i<4; i++){
            
            int xx = A.first+dx[i];
            int yy = A.second+dy[i];
            
            if(xx < 0 || yy < 0 || xx >= n || yy >= m|| dist[xx][yy] != 0 || maps[xx][yy] == 0) continue;
            
            dist[xx][yy] = dist[A.first][A.second]+1;
            Q.push({xx,yy});
        }
    }
    return dist[n-1][m-1] == 0 ? -1 : dist[n-1][m-1];
}

#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int dist[100][100];

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> Q;
    Q.push({0,0});
    dist[0][0] = 1;
    
    while(!Q.empty()){
        pair<int, int> tmp = Q.front();
        Q.pop();
        
        for(int i=0; i<4; i++){
            
            int xx = tmp.first+dx[i];
            int yy = tmp.second+dy[i];
            
            if(xx < 0 || yy < 0 || xx >= n || yy>=m || dist[xx][yy] != 0 || maps[xx][yy] == 0)continue;
            
            dist[xx][yy] = dist[tmp.first][tmp.second]+1;
            Q.push({xx, yy});
            
        }
    }
    return dist[n-1][m-1] == 0 ? -1 : dist[n-1][m-1];
}
