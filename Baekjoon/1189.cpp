#include <iostream>

using namespace std;
char map[10][10];
int ch[10][10];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int cnt, res;
int R, C, K;

void dfs(int x, int y, int dist){
    if(dist == K && x == 0 && y == C - 1){
        res++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < R && ny >= 0 && ny < C && ch[nx][ny] == 0 && map[nx][ny] != 'T') {
            ch[nx][ny] = 1;
            dfs(nx, ny, dist+1);
            ch[nx][ny] = 0;
        }
    }
}

int main(){
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }

    ch[R-1][0] = 1; 
    dfs(R - 1, 0, 1);

    cout << res;
}
