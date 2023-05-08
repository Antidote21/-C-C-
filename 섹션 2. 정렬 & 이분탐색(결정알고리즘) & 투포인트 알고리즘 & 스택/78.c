/*크루스칼 알고리즘을 사용하여 최소 신장 트리를 구하는 코드
최소 비용 신장 트리(Minimum Spanning Tree, MST)를 구하는 알고리즘 중 하나
MST란 그래프에서 모든 정점을 연결하되 사이클을 만들지 않으면서 가중치의 합이 최소가 되는 트리
크루스칼 알고리즘은 간선을 가중치의 오름차순으로 정렬하고, 가장 작은 가중치부터 간선을 하나씩
선택하여 그래프를 만들어 나가는 방식으로 동작
*/
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int unf[10001];//노드의 부모
//입력받은 간선 정보를 저장하는 Edge 구조체 
struct Edge{
	int s; //간선 시작점  
	int e; //간선 끝점 
	int val;//간선 가중치  
	Edge(int a, int b, int c){//생성자 
		s=a;
		e=b;
		val=c;
	}
	bool operator<(const Edge &b)const{//연산자 오버로딩 함수 
		return val<b.val; //오름차순 정렬  
	}
};

int Find(int v){ //부모를 찾아 반환하는 함수  
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){//노드를 연결하는 함수  
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main(){
	//freopen("input.txt", "rt", stdin);
	vector<Edge> Ed; //간선들의 정보를 저장하는 벡터  
	int i, n, m, a, b, c, cnt=0, res=0;//n 노드 개수, m 간선 개수 
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		unf[i]=i;
	}
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));	
	}
	sort(Ed.begin(), Ed.end());//가중치 값에 따른 오름차순 정렬  
	for(i=0; i<m; i++){
		int fa=Find(Ed[i].s);//간선의 시작점 부모 
		int fb=Find(Ed[i].e);//간전의 끝점 부모  
		if(fa!=fb){//사이클이 생성되지 않으면 간선을 연결  
			res+=Ed[i].val;//간선의 가중치를 더함  
			Union(Ed[i].s, Ed[i].e);//간선의 시작점과 끝점을 연결  
		}
	}
	printf("%d\n", res);
	return 0;
}
