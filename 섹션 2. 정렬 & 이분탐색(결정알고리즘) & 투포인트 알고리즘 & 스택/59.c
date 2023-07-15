#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int l=1;//전역변수를 잘못 설정  
int ch[10];
void recur(int n){
	//int ch[n+1];
	if(l==n+1){
		for(int i=1; i<=n; i++){
			if(ch[i]==1){
				printf("%d",i);
			}
		}
	}else{//->재귀문에서 스택 과정을 이해하지 못한 코드  
		if(l%2==1){
			ch[l]=1;
			recur(l++);
		}else{
			ch[l]=0;
		}	recur(l++);
		
	}
}

int main(){
	freopen("input.txt","rt", stdin);
	int a;
	scanf("%d",&a); //트리는 1부터 시작해야 한다.  
	recur(a);  
	return 0; 
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, ch[11];
void DFS(int L){
	int i;
	if(L==n+1){
		for(i=1; i<=n; i++){
			if(ch[i]==1) printf("%d ", i);
		}
		puts("");
	}else{
		ch[L]=1;
		DFS(L+1);
		ch[L]=0;
		DFS(L+1);
	}
}

int main(){
	freopen("input.txt","rt", stdin);
	scanf("%d", &n);
	DFS(1);
	return 0;
}

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n, ch[10];
void D(int L){
	if(L == n+1){
		for(int i=1; i<=n; i++){
			if(ch[i]==1)printf("%d ", i);
		}
		printf("\n");	
	}
	else{
		ch[L]=1;
		D(L+1);
		ch[L]=0;
		D(L+1);	
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n); 
	D(1);
	return 0;
}
