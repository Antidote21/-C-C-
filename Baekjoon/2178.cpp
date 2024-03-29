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

#include <iostream>
#include <queue>

using namespace std;

int maze[100][100];
int dist[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            maze[i][j] = c - '0';
        }
    }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 1;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        if (cur.first == N - 1 && cur.second == M - 1) {
            cout << dist[cur.first][cur.second] << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int xx = cur.first + dx[i];
            int yy = cur.second + dy[i];

            if (xx < 0 || xx >= N || yy < 0 || yy >= M || maze[xx][yy] == 0 || dist[xx][yy] != 0) {
                continue;
            }

            dist[xx][yy] = dist[cur.first][cur.second] + 1;
            Q.push({xx, yy});
        }
    }

    return 0;
}


#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(vector<vector<int>>& maze) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == N - 1 && y == M - 1) break;

      
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || maze[nx][ny] == 0 || visited[nx][ny]) continue;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
            maze[nx][ny] = maze[x][y] + 1;
        }
    }

    return maze[N - 1][M - 1];
}

int main() {
    cin >> N >> M;
    vector<vector<int>> maze(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            maze[i][j] = c - '0';
        }
    }

    int shortestDistance = bfs(maze);
    cout << shortestDistance << endl;

    return 0;
}
