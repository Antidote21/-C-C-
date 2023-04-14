#include<stdio.h>
#include<vector> 
#include<queue>
#include<algorithm>
using namespace std;  
int ch[30], dis[30]; //dis 간선의 최소값 
int main() {
	freopen("input.txt", "rt", stdin);
	int n, m, a, b, x, i;
	vector<int> map[30];
	queue<int> Q;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b);//map 인접리스트에 값을 추가   
	}
	Q.push(1);
	ch[1]=1;
	while(!Q.empty()){
		x=Q.front();  
		Q.pop(); 
		for(i=0; i<map[x].size(); i++){ //리스트 탐색  
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q.push(map[x][i]);
				dis[map[x][i]]=dis[x]+1;//최소간선 값에 +1 
			}
		}
	}
	for(i=2; i<=n; i++){
		printf("%d : %d\n", i, dis[i]);
	} 
	
	return 0;
}


//큐에서 하나의 정점(x)을 꺼낸다. 
//정점x와 이어진 간선들을 모두 탐색한다. 인접 리스트를 통해 이어진 정점들(map[x][i])을 확인하고, 방문 여부를 확인한다.
//방문하지 않았다면 해당 정점을 큐에 넣고 방문 표시를 한다. 또한, 이전에 방문한 정점(x)까지의 최소간선(dis[x])에 1을 더한 값으로 해당 정점(map[x][i])까지의 최소간선(dis[map[x][i]])을 저장한다.
//모든 간선에 대한 탐색이 끝난 후, 큐에 남아있는 정점이 없을 때까지 위 과정을 반복한다.
