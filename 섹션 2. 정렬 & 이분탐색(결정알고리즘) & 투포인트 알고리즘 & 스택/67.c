#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;  
int map[30][30], ch[30];
int n, minCost=2147000000;
void DFS(int s){
	int i, sum;
	if(s==n){
		if(minCost>sum){
			minCost=sum;
		}	
		return;
	}
	else{
		for(i=1; i<=n; i++){
			sum+=map[s][i];
			ch[s]=1;
			DFS(s);
			ch[s]=0;
		
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	int m,i,a,b,c;
	scanf("%d %d",&n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d",&a, &b, &c);
		map[a][b]=c;
	}
	DFS(1);
	printf("%d", minCost);
	return 0;
}

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;  
int map[30][30], ch[30], n, cost=2147000000;
void DFS(int v, int sum){
	int i;
	if(v==n){
		if(cost>sum){
			cost=sum;
			return;
		}
	}else{
		for(i=1; i<=n; i++){
			if(map[v][i]>0 && ch[i]==0){//방문이 되지 않았고 연결되었는지를 판단 
				ch[i]=1;
				DFS(i, sum+map[v][i]);
				ch[i]=0;		
			}
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	int m, i, a, b, c;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a][b]=c;
	}
	ch[1]=1;
	DFS(1, 0);
	printf("%d", cost);
	return 0;
}



