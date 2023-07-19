#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;  
int a[20][20];//인접행렬 
int main() {
	freopen("input.txt", "rt", stdin);
	int i, j, n, m, p,q;//정점 개수 n 간선 개수  
	scanf("%d %d",&n,&m); //정점 개수와 간선 개수를 읽는다.  
	for(i=1;i<=m;i++){//간선의 개수만큼 반복  
		scanf("%d %d",&p,&q); //scanf("%d %d %d", &p, &q, &a[i][j]); 불가  
		scanf("%d",&a[p][q]);		
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;   
int map[51][51]; 
int main() {
	freopen("input.txt", "rt", stdin);
	int n, m, i, j, a, b, c;
	scanf("%d %d", &n, &m);
	for(i=1;i<=m;i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a][b]=c;//방향 그래프 map[a][b]=1 
	} 				//무방향 그래프	map[a][b]=1 map[b][a]=1 
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

#include<iostream>
using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
	int n, m;
	cin>>n>>m;
	int map[n+1][n+1]={0};
	for(int i=1; i<=m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=c;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<map[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}


