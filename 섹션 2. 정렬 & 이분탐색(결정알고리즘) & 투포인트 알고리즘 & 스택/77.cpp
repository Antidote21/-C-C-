/*
 Disjoint-Set 자료구조를 이용한 Union-Find 알고리즘을 구현
 입력된 두 노드가 같은 집합에 속하는지 검사하는 코드
*/
#include<iostream>
using namespace std;
int unf[1001];
//v가 속한 집합의 대표값을 반환하는 함수 
int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}
//a와 b가 속한 두 집합을 합치는 함수 
void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, m, a, b;
	cin>>n>>m; // n과 m을 입력
	for(int i=1; i<=n; i++){
		unf[i]=i;// disjoint-set 초기화 
	}
	for(int i=1; i<=m; i++){
		cin>>a>>b;
		Union(a, b);
	}
	cin>>a>>b;
	a=Find(a);
	b=Find(b);
	if(a==b) cout<<"YES";// 두 노드가 같은 집합에 속해있다면 "YES"를 출력 
	else cout<<"NO";// 두 노드가 같은 집합에 속해있지 않다면, "NO"를 출력
	return 0;
}
