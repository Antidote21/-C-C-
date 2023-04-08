#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;  
int map[20][20];
int cnt=0; //ch[]배열을 생각하지 못함? map이라는 이차원 배열만으로도 가능하다고 생각함 
void DFS(int start, int end){
	int i;
	if(start==end){
		cnt++;
		return;
	}
	else{
		//재귀함수에는 for문을 못쓴다고 생각함 아직도 DFS에 대한 이해도가 부족함 
		DFS(start++,end);
	}
	
}
int main() {
	freopen("input.txt", "rt", stdin);
	int n, m, i, j, a, b, cnt;
	scanf("%d %d",&n, &m);
	for(i=1;i<=m;i++){
		scanf("%d %d", &a, &b);
		map[a][b] = 1;	
	}
	DFS(1,n);
	printf("%d",cnt);
	
	return 0;
}



#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;  
int map[21][21];
int n, cnt=0;//DFS 함수에서 사용해야 하므로 전역변수로 선언  
int ch[30];//방문을 했는지 확인하는 배열  
void DFS(int v){
	int i;
	if(v==n){//원하는 정점 n  
		cnt++;
	}else{
		for(i=1;i<=n;i++){//다른 정점으로 갈 수 있는지를 판단하기 위한 for문 
			if(map[v][i]==1&&ch[i]==0){//인접행렬에서 연결되어 있고 아직 방문하지 않은 경우  
				ch[i]=1;
				DFS(i);//v가 아닌 i인 경우에 대해 아직 확실하게 이해하지 못함
				ch[i]=0;
			}
		}
	}
}  
int main() {
	freopen("input.txt", "rt", stdin);
	int  m, i, a, b;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a][b]=1;//인접행렬에서 연결됨을 나타내기 위해 1을 대입
	}
	ch[1]=1;//처음 시작은 1부터 방문하므로 
	DFS(1);
	printf("%d", cnt);
	return 0;
}


