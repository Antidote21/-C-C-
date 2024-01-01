#include <iostream>
using namespace std;

int n, m, cnt;
int map[101][101];
int visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int Min = 10001;

void dfs(int x, int y, int cnt) {
    if (x == n && y == m) {
        if (cnt < Min)
            Min = cnt;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (map[nextX][nextY] == 1 && visited[nextX][nextY] == 0 && nextX >= 1 && nextX <= n && nextY >= 1 && nextY <= m) {
            visited[nextX][nextY] = 1;
            dfs(nextX, nextY, cnt + 1);
            visited[nextX][nextY] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0'; 
        }
    }
    visited[1][1] = 1;
    dfs(1, 1, 1);
    cout << Min;
}
