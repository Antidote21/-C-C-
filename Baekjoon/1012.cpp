#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, M;

void dfs(int x, int y, vector<vector<int>> &farm, vector<vector<bool>> &visited){
    visited[y][x] = true;
    
    for(int i=0; i<4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        if (xx >= 0 && xx < M &&yy >= 0 && yy < N && farm[yy][xx] == 1 && !visited[yy][xx]) {
            dfs(xx, yy, farm, visited);
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int K;
        cin >> M>>N>>K;
        vector<vector<int>> farm(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            farm[y][x] = 1;  // 배추가 심어진 곳은 1로 표시
        }
        
        int wormCount = 0;
        
        for(int y=0; y<N; y++){
            for(int x = 0; x < M; x++){
                if(farm[y][x] == 1 && !visited[y][x]){
                    dfs(x,y,farm, visited);
                    wormCount++;
                }
            }
        }
        cout<< wormCount << endl;
    }
    return 0;
}
