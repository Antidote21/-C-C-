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

