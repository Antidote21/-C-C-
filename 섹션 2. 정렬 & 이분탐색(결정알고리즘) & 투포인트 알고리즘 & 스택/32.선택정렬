#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n,i,j,idx=0,tmp=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		printf("%d ", a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			idx=i;
			if(a[j]<a[idx]){
				idx=j;
			}
			tmp = a[i];
			a[i] = a[idx];
			a[idx] = tmp;
		}
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
