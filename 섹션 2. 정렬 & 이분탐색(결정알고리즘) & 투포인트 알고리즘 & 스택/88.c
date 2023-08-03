#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	vector<vector<int> > board(7, vector<int>(7, 0));
	vector<vector<int> > dis(7, vector<int>(7, 0));
	queue<pair<int, int> > Q;
	for(int i=0; i<7; i++) {
		for(int j=0; j<7; j++) {
			cin>>board[i][j];
		}
	}
	Q.push(make_pair(0, 0));
	board[0][0]=1;
	while(!Q.empty()) {
		pair<int, int> tmp = Q.front();
		Q.pop();
		for(int i=0; i<4; i++) {
			int x=tmp.x+dx[i];
			int y=tmp.y+dy[i];
			if(x>=0 && x<7 && y>=0 && y<7 && board[x][y]==0) {
				Q.push(make_pair(x, y));
				board[x][y]=1;
				dis[x][y] = dis[tmp.x][tmp.y] + 1;
			}
		}
	}
	if(dis[6][6]==0) cout<<"-1";	
	else cout<<dis[6][6];
	return 0;
}

#include<stdio.h>
#include<queue>
using namespace std;
int dx[4]={0, 1, 0, -1};
int dy[4]={-1, 0, 1, 0};
int n, map[10][10], dis[10][10];
struct Loc{
	int x;
	int y;
	Loc(int a, int b){
		x = a;
		y = b;
	}
};
queue<Loc> Q;

int main(){
	freopen("input.txt", "rt", stdin);
	int i,j;
	for(i=1; i<8; i++){
		for(j=1; j<8; j++){
			scanf("%d",&map[i][j]);
		}
	}
	Q.push(Loc(1, 1));
	map[1][1] = 1;
	while(!Q.empty()){
		Loc tmp = Q.front();
		Q.pop();
		for(int i=0; i<4; i++){
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			if(map[xx][yy] == 0 && xx>=1 && xx<=7 && yy>=1 && yy<=7) {
				Q.push(Loc(xx, yy));
				map[xx][yy] = 1;
				dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
			}
		}
	}
	printf("%d", dis[7][7]);
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
	for(int i=1; i<=7; i++){
		for(int j=1; j<=7; j++){
			cin>>Map[i][j];
		}	
	}
	Q.push(make_pair(1, 1));
	Map[1][1] = 1;
	while(!Q.empty()){
		pair <int, int> tmp = Q.front();
		Q.pop();
		for(int i=0; i<4; i++){
			int xx = tmp.first + dx[i];
			int yy = tmp.second + dy[i];
			if(Map[xx][yy] == 0 && xx>=1 && xx<=7 && yy>=1 && yy<=7){
				Q.push(make_pair(xx, yy));
				Map[xx][yy] = 1;
				dis[xx][yy] = dis[tmp.first][tmp.second] + 1;
			}
		}
	}
	cout<<dis[7][7];
	return 0;
}
