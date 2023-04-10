//이 문제를 풀지 못한 이유 
//상하좌우를 어떻게 탐색할지 구상하지 못했다. 
 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;  
int map[8][8], ch[8][8], cnt=0; //ch[] 방문했던 곳 

void DFS(int v, int w){
	int i;
	if(v==7 && w==7)cnt++;
	else{
		for(i=1; i<=7; i++){
			if(map[v][w]==0 && ch[v][w]==0){
				ch[v][i]=1;
				DFS(v,w++);
				ch[v][i]=0;
				DFS(v++,w);
				ch[v][i]=0;
			}
		}
	}
	
} 

int main() {
	freopen("input.txt", "rt", stdin);
	int i, j, n;
	for(i=1; i<=7; i++){
		for(j=1;j<=7; j++){
			scanf("%d", &map[i][j]);
		}
	}
	ch[1][1]=1;
	DFS(1, 1);
	printf("%d",cnt);
	return 0;
}

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;  
int map[8][8], ch[8][8], cnt=0; //ch[] 방문했던 곳 
int dx[4]={-1,0,1,0}; 
int dy[4]={0,1,0,-1}; //상하좌우를 가기위한 배열  

void DFS(int x, int y){
	int i, xx, yy;//xx, yy는 다음에 갈 좌표  
	if(x==7 && y==7){ //결국 목적지는 (7,7) 
		cnt++;
	}else{
		for(i=0; i<4; i++){
			xx=x+dx[i];//좌우 
			yy=y+dy[i];//상하 
			if(xx<1 || xx>7 || yy<1 || yy>7)continue;//격자판을 벗어난 좌표는 건너뛴다.  
			if(map[xx][yy]==0 && ch[xx][yy]==0){//통로인 곳과 아직 가지 않은 곳  
				ch[xx][yy]=1;
				DFS(xx,yy);
				ch[xx][yy]=0;
			}
		}
	}
}


int main() {
	freopen("input.txt", "rt", stdin);
  	int i, j;
	for(i=1; i<=7; i++){
		for(j=1;j<=7; j++){
			scanf("%d", &map[i][j]);
		}
	} 
	ch[1][1]=1;
	DFS(1,1);
	printf("%d\n", cnt);
	return 0;
}

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;  
int map[8][8];
int cnt=0;//DFS 함수에서 사용해야 하므로 전역변수로 선언  
int ch[8][8];//방문을 했는지 확인하는 배열  
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
void DFS(int s, int e){
	int i;
	int p,q;
	if(s==e && s==7){
		cnt++;
	}else{
		for(i=0;i<4;i++){
			p=s+x[i];
			q=e+y[i];
			if((p>0&&q>0)&&(p<8&&q<8)){
				if(map[p][q]==0 && ch[p][q]==0){
					ch[p][q] = 1;
					DFS(p,q);
					ch[p][q] = 0;
				}	
			}
		}		
	}
}  
int main() {
	freopen("input.txt", "rt", stdin);
	int i, j;
	for(i=1; i<=7; i++){
		for(j=1; j<=7; j++){
			scanf("%d",&map[i][j]);
		}
	}
	ch[1][1]=1;
	DFS(1,1);
	printf("%d\n",cnt);
	return 0;
}

