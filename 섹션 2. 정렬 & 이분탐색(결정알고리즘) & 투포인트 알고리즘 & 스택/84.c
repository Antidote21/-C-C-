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

#include<bits/stdc++.h>
using namespace std;
int n, res=0;
vector< vector<int> > a(20);
void DFS(int L, int sum){
	if(L>n+1)return;
	if(L==n+1){
		res = max(res, sum);
	}else{
		DFS(L+a[L][0], sum+a[L][1]);	
		DFS(L+1, sum);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int t, p;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>t>>p;
		a[i].push_back(t);
		a[i].push_back(p);
	}
	DFS(1,0);
	cout<<res;
	return 0;
}
