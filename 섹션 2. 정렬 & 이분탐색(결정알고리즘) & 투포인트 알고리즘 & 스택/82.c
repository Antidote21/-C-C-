#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, r, cnt=0;  
int ch[20], res[20], a[20];
int DFS(int L){//L은 현재까지 만들어진 순열 길이  
	int i, j;
	if(L==r){//r길이의 순열이 완성
		for(j=0; j<r; j++){
			printf("%d ",res[j]);//결과 출력  
		}
		cnt++;
		puts("");//빈 줄 출력  
	}
	else{
		for(i=1; i<=n; i++){//아직 사용되지 않은 숫자를 찾는다. 
			if(ch[i]==0){//각 숫자의 사용 여부 파악 
				res[L]=a[i];
				ch[i]=1;//숫자 i가 사용
				DFS(L+1);//재귀 호출을 통해 모든 가능한 순열을 생성
				ch[i]=0;//재귀 호출이 완료되면, ch[i]를 다시 0으로 설정하여 숫자 i를 다른 순열에서 사용
				//백트래킹(Backtracking) 해결해야 할 문제의 가능한 모든 경우의 수를 탐색하면서 해를 찾는 기법
			}
		}
	}
}

int main(){
	freopen("input.txt", "rt", stdin);	
	scanf("%d %d", &n, &r); 
	int i;
	for(i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	DFS(0);
	printf("%d", cnt);
	return 0;
}

#include<iostream>
int a[15], ch[15], res[15];
int n, r, cnt=0;
using namespace std;
int DFS(int L){
	if(L==r){
		cnt++;
		for(int i=0; i<r; i++){
			cout<<res[i];
		}
		cout<<endl;
	}else{
		for(int i=1; i<=n; i++){
			if(ch[i]==0){
				res[L]=a[i];
				ch[i]=1;
				DFS(L+1);
				ch[i]=0;
			}
		}
	}
}


int main(){
	freopen("input.txt", "rt", stdin);
	cin>>n>>r;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	DFS(0);
	cout<<cnt;
	return 0;
}
