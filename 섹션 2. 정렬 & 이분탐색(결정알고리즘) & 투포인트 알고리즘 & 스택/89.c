//BFS 알고리즘 활용 
#include<stdio.h>
#include<queue>
using namespace std;
int m, n, tom[1010][1010], res = -2147000000, dis[1010][1010]; 
//상하좌우로 이동할 때 사용할 벡터 
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {-1, 0, 1, 0};
struct Loc { //위치 정보를 저장하기 위한 구조체 
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};
queue<Loc> Q; //Loc 구조체를 저장하는 큐를 선언 
int main() {
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &tom[i][j]);
			if(tom[i][j] == 1) { //입력받은 상태가 1인 경우 해당 위치를 큐에 저장 
				Q.push(Loc(i, j));
			}
		}
	}
	while(!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++) {
			int xx=tmp.x+dx[i];
			int yy=tmp.y+dy[i];
			if(tom[xx][yy] == 0) {
				if(xx>=1 && xx<= n && yy>=1 && yy<= m) {
					Q.push(Loc(xx, yy));
					tom[xx][yy] = 1;
					dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
				}
			}
		}
	}
	int f = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(tom[i][j] == 0) f = 0;
		}
	}
	if(f == 1) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(res<dis[i][j]) res = dis[i][j];
			}
		}
		printf("%d\n", res);
	}
	else printf("-1");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int Map[30][30]; 
int dis[30][30];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int> > Q;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int m, n, res=-10000;
	cin>>m>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>Map[i][j];
			if(Map[i][j]==1){
				Q.push(make_pair(i,j));
			}
		}	
	}
	while(!Q.empty()){
		pair <int, int> tmp = Q.front();
		Q.pop();
		for(int i=0; i<4; i++){
			int xx = tmp.first + dx[i];
			int yy = tmp.second + dy[i];
		
			if(xx>=1 && xx<=n && yy>=1 && yy<=m && Map[xx][yy] == 0){
				Q.push(make_pair(xx, yy));
				Map[xx][yy]=1;
				dis[xx][yy]= dis[tmp.first][tmp.second] + 1;
			}	
		}
	}
	bool isFlag = true;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(Map[i][j]==0) isFlag = false;
		}	
	}
	
	if(isFlag){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(dis[i][j]>res)res=dis[i][j];
			}	
		}
		cout<<res;	
	}
	else cout<<-1;
	return 0;
}


