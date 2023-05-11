#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int vex, dist;
	Edge(int a, int b){
		vex = a;//정점번호 
		dist = b;//거리비용 
	}
	bool operator < (const Edge &b) const {//연산자 오버로딩 함수  
		return dist>b.dist;//최소힙 -> 가중치 값이 작은 간선 먼저 처리 
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int a,b,c,i,n,m;
	priority_queue<Edge> Q;
	vector<int> dist(n+1, 2147000000);//이 코드는 크기가 n+1인 int형 벡터 dist를 선언하고, 모든 요소를 매우 큰 수인 2147000000으로 초기화
	vector<pair<int, int> > graph[30];//가중치 인접리스트  
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;i++){
		scanf("%d %d %d",&a, &b, &c);
		graph[a].push_back(make_pair(b, c));//make_pair 함수는 두 개의 값을 pair 클래스의 객체로 만들어 반환
	}
	Q.push(Edge(1, 0));
	dist[1]=0;
	while(!Q.empty()){
		int now=Q.top().vex;//현재 정점  
		int cost=Q.top().dist;//거리비용 
		Q.pop();
		if(cost>dist[now]) continue;//이미 now 노드까지의 최단 경로를 찾음 
		for(i=0; i<graph[now].size(); i++){
			int next=graph[now][i].first;//now에서 다음 노드 next로 연결되는 간선의 종착점
			int nextDis=cost+graph[now][i].second;//현재 노드 now를 거쳐서 다음 노드 next로 가는 거리 비용
			if(dist[next]>nextDis){
				dist[next]=nextDis;//dist[next] 값을 nextDis로 갱신
				Q.push(Edge(next, nextDis));// Q에 (next, nextDis) 쌍을 추가 ->next 노드까지의 최단 거리 비용을 갱신
			}
		} 
		
	}
	for(i=2; i<=n; i++){
		if(dist[i]!=2147000000)printf("%d : %d\n",i,dist[i]);
		else printf("%d : impossible\n",i);
	}
	return 0;
}

//우선순위 큐를 어떻게 활용하고 어떻게 값을 집어넣는지 -> 큐에 구조체 형식으로   
//pair 클래스는 두 개의 멤버 변수 first와 second을 가지며,
//각각 첫 번째 값과 두 번째 값 
