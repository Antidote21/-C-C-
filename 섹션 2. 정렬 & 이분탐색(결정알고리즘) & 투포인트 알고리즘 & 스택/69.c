/*
넓이 우선 탐색
큐를 사용하여 구현
front rear 변수 필요  
*/
#include<stdio.h>
#include<vector> 
#include<algorithm>
using namespace std;  
int Q[100], front=-1, rear=-1, ch[10];
vector<int> map[10];
int main() {
	freopen("input.txt", "rt", stdin);
	int i, a, b, x;
	for(i=1; i<=6; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	Q[++rear]=1;//root노드 1을 Q에 넣는다. 
	ch[1]=1;
	while(front<rear){ //Q에 자료가 남아있다. 
		x=Q[++front];
		printf("%d ", x);
		for(i=0; i<map[x].size(); i++){
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q[++rear]=map[x][i];
			}
		}
	}
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Q[100], front=-1, back=-1, ch[10];
vector<int> map[10];
int main(){
	freopen("input.txt", "rt", stdin);
	int i, a, b, x;
	for(i=1; i<=6; i++){
		cin>>a>>b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	Q[++back]=1;
	ch[1]=1;
	while(front<back){
		x=Q[++front];
		cout<<x<<' ';
		for(i=0; i<map[x].size(); i++){
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q[++back]=map[x][i];
			}
		}
	}
	return 0;
}





