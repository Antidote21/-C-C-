#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int ch[100000];
struct Edge{
	int e, val;
	Edge(int a, int b){
		e = a;//간선의 목적지 
		val = b;//간선의 가중치  
	}
	bool operator < (const Edge &b) const {//연산자 오버로딩 함수  
		return val>b.val;//최소힙 -> 가중치 값이 작은 간선 먼저 처리 
	}
};

int main(){

	int v,e,i,a,b,c,res=0;
	priority_queue <Edge> Q;
	vector<pair<int, int> > map[100000];
	scanf("%d %d", &v, &e);
	for(i=1; i<=e; i++){
		scanf("%d %d %d",&a, &b, &c);
		map[a].push_back(make_pair(b,c)); //a->b무방향 가중치 인접리스트 
		map[b].push_back(make_pair(a,c)); //b->a무방향 가중치 인접리스트 
	}
	Q.push(Edge(1,0));//시작 지점  
	while(!Q.empty()){
		Edge tmp=Q.top();
		Q.pop();
		int v=tmp.e;
		int cost=tmp.val;
		if(ch[v]==0){
			res+=cost;
			ch[v]=1;
			for(i=0; i<map[v].size(); i++){
				Q.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
	} 
	printf("%d", res);
	return 0;
}
