#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	int n,i,j;
	scanf("%d",&n);
	vector<int> a(n);
	vector<int> b(n);
	b.assign(n,1);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(a[j]>=a[i]){
				b[i]++;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	printf("\n"); 

	return 0;
}
