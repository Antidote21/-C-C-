#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> // for std::max
using namespace std;

int map[100][100];
int ch[100][100];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main(){
    int N, M, K, res=0;
    queue<pair<int, int>> Q;
    cin >> N >> M >> K;
    
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = 1; 
    }
    
    // BFS
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 1 && ch[i][j] == 0){
                int cnt = 1; 
                ch[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    pair<int, int> tmp = Q.front();
                    Q.pop();
                    for(int k = 0; k < 4; k++){
                        int xx = dx[k] + tmp.first;
                        int yy = dy[k] + tmp.second;
                        if(xx >= 0 && xx < N && yy >= 0 && yy < M){
                            if(map[xx][yy] == 1 && ch[xx][yy] == 0){
                                Q.push({xx, yy});
                                ch[xx][yy] = 1;
                                cnt++; 
                            }
                        }
                    }
                }
                res = max(res, cnt); 
            }
        }
    }
    cout << res;
    return 0;
}
