//벨만-포드 알고리즘은 그래프에서 최단 경로를 찾는 알고리즘 중 하나  
//벨만-포드 알고리즘은 시작 정점에서부터 다른 모든 정점까지의 최단 경로를 차례로 계산
//음의 가중치를 가진 그래프에서도 사용 
//음수 가중치를 가지는 그래프에서 최단 경로를 찾는 알고리즘  
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct Edge{
	int s, e, dist;
	Edge(int a, int b, int c){
		s = a;
		e = b;
		dist = c;	
	}
};
int main(){
	freopen("input.txt", "rt", stdin);	
	vector<Edge> Ed;
	int n, m, a, b, c, i, j, s, e;
	scanf("%d %d",&n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	}
	for(i=1; i<=n; i++){
		dist[i]=2147000000;//시작 정점을 제외한 모든 정점의 거리를 무한대로 초기화
	}
	scanf("%d %d", &s, &e);
	dist[s]=0;//시작 정점 0으로 초기화  
	/*
		외부 for문은 1부터 n-1까지 값을 순회  
		최단 거리를 구하는 과정에서 최대 n-1번의 간선 이용가능  
	*/
	for(i=1;i<n; i++){
		for(j=0; j<Ed.size(); j++){
			int u=Ed[j].s;
			int v=Ed[j].e;
			int w=Ed[j].val;
			if(dist[u]!=2147000000 && dist[u]+w<dist[v]){//기존의 최단 거리보다 작을 때 
				dist[v]=dist[u]+w;
			}
		}
	}
	for(j=0;j<Ed.size(); j++){//음수 사이클 확인  
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

#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std; 

int res[100];

struct Edge{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c){
		s = a;
		e = b;
		val = c;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;
	int n, m, a, b, c, s, e;
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		cin>>a>>b>>c;
		Ed.push_back(Edge(a,b,c));
	}
	for(int i=1; i<=n; i++){
		res[i] = MAX;
	} 
	cin>>s>>e;
	res[s] = 0;
	for(int i=1; i<n; i++){
		for(int j=0; j<Ed.size(); j++){
			int u = Ed[j].s;
			int v = Ed[j].e;
			int w = Ed[j].val;
			if(res[u]!=MAX && res[u]+w<res[v]){
				res[v] = res[u] + w;
			} 
		}
	}	
	for(int j=0; j<Ed.size(); j++){
		int u = Ed[j].s;
		int v = Ed[j].e;
		int w = Ed[j].val;
		if(res[u]!=MAX && res[u]+w<res[v]){
			cout<<-1;
			exit(0);
		}
	}
 	cout<<res[e];
	return 0;
} 


