#include <iostream>

using namespace std;

int dy[3] = {1, 1, 1};
int dx[3] = {-1, 0, 1};  
int map[10000][500];
int dp[10000][500];
int R, C, cnt;

bool dfs(int x, int y){
    if(y == C-1){
        cnt++;
        return true;
    }
    
    map[x][y] = 1;
    
    for(int i = 0; i < 3; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 0 && xx < R && yy >= 0 && yy < C && !map[xx][yy]){
            if(dfs(xx, yy)) return true;
        }
    }
    
    return false;
}

int main(){
    cin >> R >> C;
    string s;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < C; j++){
            if(s[j] == '.') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }

    for(int i = 0; i < R; i++){
        dfs(i, 0);
    }
    cout << cnt;
}
