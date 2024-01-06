#include<iostream>
#include<queue>
#include<vector>
using namespace std;
char map[101][101];
int ch[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int blue, white, n, m;  
queue<pair<int, int>> Q;
void bfs(int x, int y, char c){
    Q.push({x, y});
    ch[x][y] = 1;
    
    int cnt = 0;
    while(!Q.empty()){
        pair<int, int> now = Q.front();
        Q.pop();
        cnt++;
        
        for(int i = 0; i < 4; i++){
            int xx = now.first + dx[i];
            int yy = now.second + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && ch[xx][yy] != 1 && map[xx][yy] == c){
                ch[xx][yy] = 1;
                Q.push({xx, yy});
            }
        }
    }
    if(c == 'W'){
        white += cnt * cnt;
    } else {
        blue += cnt * cnt;
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];  
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ch[i][j] != 1){
                bfs(i, j, map[i][j]);
            }
        }
    }

    cout << white << ' ' << blue;
    return 0;
}
