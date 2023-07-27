#include<stdio.h>
#include<vector> 
#include<queue>
#include<algorithm>
using namespace std;  
int ch[10001], d[3]={1,-1,5};//1칸 앞, 1칸 뒤, 5칸 앞으로 이동
int main() {
	freopen("input.txt", "rt", stdin);
	int start,end,x,pos,i;
	scanf("%d %d",&start,&end);
	queue<int> Q;
	ch[start]=1;// 출발점과 연결된 노드들의 ch 값이 모두 0으로 남아 있게되면 출발점과 연결된 노드들이 아직 방문되지 않았다는 의미이므로 1로 초기화  
	Q.push(start);
	while(!Q.empty()){
		x = Q.front();
		Q.pop();
		for(i=0;i<3;i++){
			pos=x+d[i];//x에서 이동할 수 있는 모든 방향을 탐색
			if(pos<=0 || pos>=10000)continue;//1에서 9999 사이의 범위를 벗어나면, 다음 방향을 탐색
			if(pos==end){
				ch[pos]=ch[x]+1;
				printf("%d\n", ch[end]-ch[start]);
				exit(0);
			}
			if(ch[pos]==0){
				ch[pos]=ch[x]+1;//이동할 수 있는 위치가 아직 방문하지 않은 곳이라면, ch 배열을 이전에 방문한 노드의 ch 값에 1을 더한 값으로 갱신 
				Q.push(pos); 
			}
		}
	}
	return 0;
}


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int ch[10000], d[3]={1, -1, 5};
int main(){
	freopen("input.txt", "rt", stdin);
	int s, e, x, pos;
	cin>>s>>e;
	queue<int> Q;
	Q.push(s);
	ch[s]=1;
	while(!Q.empty()){	
		x = Q.front();
		Q.pop();
		for(int i=0; i<3; i++){
			pos=x+d[i];
			if(pos<=0 || pos > 10000)continue;
			if(pos==e){
				cout<<ch[x];
				exit(0);
			}
			else{
				if(ch[pos]==0){
					ch[pos]=ch[x]+1;
					Q.push(pos);
				}
			}
	
		}
	
	}
	return 0;
}
