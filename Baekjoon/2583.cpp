#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int m, n, k, cnt, total_n;
int map[101][101];
int visited[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
vector<int> res;

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int xx, yy;
        xx = x + dx[i];
        yy = y + dy[i];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && visited[yy][xx] == 0 && map[yy][xx] == 0){
            cnt += 1;
            visited[yy][xx] = 1;
            dfs(xx, yy);
        }
    }
}

int main(){
    cin >> m >> n >> k;
    for(int i=0; i<k; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;      
        for(int j=y1; j<y2; j++){
            for(int h=x1; h<x2; h++){
                map[j][h] = 1;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 0 && visited[i][j] == 0){
                visited[i][j] = 1;
                cnt = 1;
                dfs(j, i); 
                res.push_back(cnt);
                total_n++;
            }
        }
    }
    cout << total_n << '\n';
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++){
        cout << res[i] << ' ';
    }
    return 0;
}
