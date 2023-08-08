#include<bits/stdc++.h>
using namespace std;
int Map[30][30]; //먹이의 크기나 장애물에 관한 정보 
int ch[30][30];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct State{
	int x, y, dis;
	State(int a, int b, int c){
		x = a;
		y = b;
		dis = c;
	}
	bool operator<(const State &b)const {
		if(dis != b.dis) return dis > b.dis;//거리가 더 작을수록 우선순위가 높아짐 
		if(x != b.x) return x > b.x;// x 좌표 값이 더 작을수록 우선순위가 높아짐 
		else return y > b.y;// y 좌표 값이 더 작을수록 우선순위가 높아짐 
	}
};

struct Lion{
	int x, y, s, ate; 
	void sizeUp(){
		ate = 0;//먹이를 먹은 횟수
		s++;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, i, j, res=0;
	priority_queue<State> Q;
	Lion simba;
	cin>>n;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			cin>>Map[i][j];
			if(Map[i][j] == 9){
				simba.x = i;
				simba.y = j;
				Map[i][j] = 0;
			}
		}
	}
	Q.push(State(simba.x, simba.y, 0));
	simba.s = 2;
	simba.ate = 0;
	while(!Q.empty()){
		State tmp = Q.top();//우선순위 큐에서 가장 우선순위가 높은 상태를 가져옴 
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;
		if(Map[x][y] != 0 && Map[x][y] < simba.s){
			simba.x = x;
			simba.y = y;
			simba.ate++;
			if(simba.ate >= simba.s) simba.sizeUp();
			Map[x][y] = 0; //해당 위치의 먹이 정보를 없앤다 
			for(i=1; i<=n; i++){
				for(j=1; j<=n; j++){
					ch[i][j] = 0;//방문 배열 ch를 모두 0으로 초기화합니다. 
				}
			}
			while(!Q.empty())Q.pop();//현재까지 처리되지 않은 모든 상태를 우선순위 큐에서 제거
			res = tmp.dis;
		}
		for(i=0; i<4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx<1 || xx>n || yy<1 || yy>n || Map[xx][yy]>simba.s || ch[xx][yy]>0) continue;
			//이동할 위치가 격자 범위를 벗어나거나, 먹이의 크기가 라이온의 크기보다 크거나, 이미 방문한 위치인 경우
			Q.push(State(xx, yy, z+1));
			ch[xx][yy] = 1;
		}
	}
	cout<<res;
	return 0;
}


