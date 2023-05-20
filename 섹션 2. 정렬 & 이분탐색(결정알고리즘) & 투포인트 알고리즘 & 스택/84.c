#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, res=-2147000000;
vector<int> T, P;
void DFS(int L, int sum){
	if(L==n+1){
		if(sum>res) res=sum;
	}else{
		if(L+T[L]<=n+1) DFS(L+T[L], sum+P[L]);
		DFS(L+1, sum);
	}	
}

int main(){
	freopen("input.txt", "rt", stdin);
	int a,b,i;
	scanf("%d", &n);
	T.push_back(0);
	P.push_back(0);
	for(i=0;i<n;i++){
		scanf("%d %d", &a,&b);
		T.push_back(a);
		P.push_back(b);
	}
	DFS(1,0);	
	printf("%d",res);
	return 0;
}
