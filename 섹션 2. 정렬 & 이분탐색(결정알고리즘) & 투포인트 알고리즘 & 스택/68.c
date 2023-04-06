//pair자료구조 
//	//두 개의 데이터형을 하나로 묶는 것이 pair 자료형이다.  
//	pair<int, char> p; //p.first p.second
//	p=make_pair(10,'T');
//	printf("%d %c\n",p.first, p.second);  
//인첩 행렬이 인접 리스트는 시간 복잡도나 메모리 관리 측면에서 더 우수하다. 
#include<stdio.h>
#include<vector>
#include<algorithm>
//#define x first y second 
using namespace std;  
int ch[30];
int n, cost=2147000000;
vector<pair<int, int> > map[30]; //가중치 방향 인접리스트 
void DFS(int v, int sum){
	int i;
	if(v==n){
		if(cost>sum)cost=sum;
	}
	else{
		for(i=0;i<map[v].size();i++){ //map[v][i].first 정점 map[v][i].second 가중치 
			if(ch[map[v][i].first]==0) { //방문을 하지 않은 것 
				ch[map[v][i].first]=1;
				DFS(map[v][i].first,sum+map[v][i].second);
				ch[map[v][i].first]=0;
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
		map[a].push_back(make_pair(b, c)); //map[a]의 first=b 정점 second=c 가중치 
	} 
	ch[1]=1;
	DFS(1, 0); 
	printf("%d\n", cost); 
	return 0;
}





