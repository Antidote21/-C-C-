#include <stdio.h>
#include <vector>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	int size, n, i, j, pos, a;
	scanf("%d %d", &size, &n);
	vector<int> c(size);
	for(i=0;i<n; i++){
		scanf("%d",&a);
		pos=-1;	
		for(j=0;j<i;j++){
			if(c[j]==a)pos=j;
		}
		if(pos==-1){
			for(j=size-1;j>0;j--){
			c[j]=c[j-1];
			}
		}
		else{
			for(j=pos;j>0;j--){
			c[j]=c[j-1];
			}
		}
		c[0]=a;
	}
	
	for(i=0;i<size;i++){
		printf("%d ", c[i]);
	}
	return 0;
}
#include <stdio.h>
int C[20];
int main(){
	freopen("input.txt","rt", stdin);
	int s, n, a, i, j, pos;
	scanf("%d %d", &s, &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		pos=-1;
		for(j=0; j<s; j++){
			if(C[j]==a) pos=j;
		}
		if(pos==-1){
			for(j=s-1; j>=1; j--)C[j]=C[j-1];
		}
		else{
			for(j=pos; j>=1; j--)C[j]=C[j-1];
		}
		C[j] = a;
	}
	for(i=0; i<s; i++)printf("%d ", C[i]);
	return 0;
}
