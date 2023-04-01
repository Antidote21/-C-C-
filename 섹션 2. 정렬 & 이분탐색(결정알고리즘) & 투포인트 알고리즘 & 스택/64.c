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
int map[30][30], ch[30], cnt=0, n; //ch[] 방문했던 곳 

void DFS(int v){
	int i;
	if(v==n){
		cnt++;
	}else{
		for(i=1; i<=n; i++){
			if(map[v][i]==1 && ch[i]==0){ //그곳이 갈 수 있고, 아직 가지 않은 곳인지 확인 
				ch[i]=1;
				DFS(i);
				ch[i]=0;//마지막에 5를 0으로 바꿔줘야 다시 5로 갈 수 있다. 
			}
		}
		
	}	
} 

int main() {
	freopen("input.txt", "rt", stdin);
	int n, m, i, a, b;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a][b]=1;
	}
	ch[1]=1;
	DFS(1);
	printf("%d\n", cnt);
	return 0;
}
