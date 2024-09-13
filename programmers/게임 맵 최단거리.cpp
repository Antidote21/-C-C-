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


#include<vector>
#include<algorithm>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int minDist = 1e9;

void dfs(vector<vector<int>>& maps, vector<vector<int>>& visited, int x, int y, int dist) {
    int n = maps.size();
    int m = maps[0].size();
    
    // 목표 지점에 도달했을 경우 최단 거리 갱신
    if (x == n - 1 && y == m - 1) {
        minDist = min(minDist, dist);
        return;
    }
    
    // 4방향 탐색
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        // 경계를 벗어나지 않고, 방문하지 않았으며, 길인 경우만 진행
        if (xx >= 0 && yy >= 0 && xx < n && yy < m && maps[xx][yy] == 1 && visited[xx][yy] == 0) {
            visited[xx][yy] = 1;
            dfs(maps, visited, xx, yy, dist + 1);
            visited[xx][yy] = 0; // 백트래킹
        }
    }
}

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> visited(n, vector<int>(m, 0));  // 방문 여부 저장
    
    visited[0][0] = 1;  // 시작점 방문
    dfs(maps, visited, 0, 0, 1);  // DFS 탐색 시작
    
    return minDist == 1e9 ? -1 : minDist;  // 최단 경로 반환, 없으면 -1
}
