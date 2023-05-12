//벨만-포드 알고리즘은 그래프에서 최단 경로를 찾는 알고리즘 중 하나  
//벨만-포드 알고리즘은 시작 정점에서부터 다른 모든 정점까지의 최단 경로를 차례로 계산
//음의 가중치를 가진 그래프에서도 사용 
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int dist[101];
struct Edge{
	int s, e, val;
	Edge(int a, int b, int c){
		s = a;
		e = b;
		val = c; 
	}
};

int main(){
	freopen("input.txt", "rt", stdin);	
	vector<Edge> Ed;
	int n, m, a, b, c, i, j;
	scanf("%d %d",&n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d",&a, &b, &c);
		Ed.push_back(Edge(a,b,c)); 
	}
	//vector<n+1, 2147000000> dist;
	for(i=1; i<=n; i++){
		dist[i]=2147000000;
	}
	int s,e;
	scanf("%d %d", &s, &e);
	dist[s]=0;
	for(i=1; i<n; i++){
		for(j=0; j<Ed.size(); j++){
			int u=Ed[j].s;
			int v=Ed[j].e;
			int w=Ed[j].val;
			if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
			}
		}
	}
	for(j=0; j<Ed.size(); j++){
		int u=Ed[j].s;
		int v=Ed[j].e;
		int w=Ed[j].val;
		if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
			printf("-1\n");
			exit(0);
		}
	}
	printf("%d\n", dist[e]);
	return 0;
}
