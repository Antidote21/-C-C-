#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);	
	int n, m, a, b, c;
	cin>>n>>m; //n은 정점의 개수 m은 간선의 개수  
	vector<vector<int> > dis(n+1, vector<int>(n+1, 5000)); //다이나믹 테이블 2차원 
	for(int i=1; i<=n; i++) dis[i][i]=0;//자기자신으로 가는 것(대각선)을 0으로 초기화  
	for(int i=1; i<=m; i++){
		cin>>a>>b>>c;
		dis[a][b]=c;//중간 노드를 거치지 않고 바로간 경우 	
	}
	//플루이드 와샬 알고리즘  
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){//i -> k -> j 가는 과정  
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dis[i][j]==5000){
				cout<<"M ";
			}
			else cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

#include <stdio.h>
int number = 4;
int INF = 1000000;
//자료 배열 초기화 
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall(){
	//결과 그래프 초기화 
	int d[number][number];
	
	for(int i=0; i<number; i++){
		for(int j=0; j<number; j++){
			d[i][j] = a[i][j];
		}
	} 
	
	// k = 거쳐가는 노드 
	for(int k = 0; k < number; k++){
		// i = 출발 노드 
		for(int i = 0; i < number; i++){
			// j = 도착 노드 
			for(int j = 0; j < number; j++){
				if(d[i][k] + d[k][j] < d[i][j]){
					d[i][j] = d[i][k] + d[k][j];
				}
			} 
		} 
	}
	
	// 결과 출력 
	for(int i=0; i<number; i++){
		for(int j=0; j<number; j++){
			printf("%d ", d[i][j]);
		}
		printf("\n");
	} 
}

int main(void){
	floydWarshall();
}
