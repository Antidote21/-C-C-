#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a[11], cnt=0;
bool flag=false;
void DFS(int L, int sum){
	//if(flag==true) return;
	if(L==n+1){
		if(sum==m){
			flag=true;
			cnt++;
		}
	}else{
		DFS(L+1, sum+a[L]);
		DFS(L+1, sum);
		DFS(L+1, sum-a[L]);
	}
}

int main(){
	//freopen("input.txt","rt", stdin);
	int i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	DFS(1, 0);
	if(flag)printf("%d",cnt);
	else printf("-1");
	return 0; 
}

#include <iostream>
int a[11], n, m, cnt=0, path[11];
using namespace std;

void DFS(int L, int val){
	if(L==n+1){
		if(val==m){
			cnt++;
			for(int i=1; i<L; i++){
				printf("%d ", path[i]);
			}
			puts("");
		}
	}else{
		path[L]=a[L];
		DFS(L+1, val+a[L]);
		path[L]=-a[L];
		DFS(L+1, val-a[L]);
		path[L]=0;
		DFS(L+1, val);
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	int i;
	cin>>n>>m;
	for(i=1; i<=n; i++){
		cin>>a[i];
	}
	DFS(1, 0);
	if(cnt==0)cout<<"-1";
	else cout<<cnt;
	return 0;
}
