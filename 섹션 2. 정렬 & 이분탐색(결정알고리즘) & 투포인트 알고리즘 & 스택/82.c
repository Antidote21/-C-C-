#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, r, cnt=0;
int a[20], res[20], ch[20];// 선택된 원소는 다시 선택되지 않도록 하는 ch배열  
int DFS(int L){
	int i,j;
	if(L==r){ 
		for(j=0; j<L; j++){
			printf("%d ", res[j]);
		}
		cnt++;
		puts("");
	}
	else{
		for(i=1;i<=n;i++){
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
	int i, k;
	scanf("%d %d",&n, &r);
	for(i=1;i<=n; i++){
		scanf("%d", &a[i]);
	}
	DFS(0);
	printf("%d",cnt);
	return 0;
}
