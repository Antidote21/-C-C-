#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	int  i, j, cnt=0;
	scanf("%d",&n);
	int a[n+2][n+2]={0,};
	for(i=0; i<=n+1; i++){
		for(j=0; j<=n+1; j++){
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d",&a[i][j]);	
		}
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if((a[i][j]>a[i-1][j])&&(a[i][j]>a[i][j+1])&&(a[i][j]>a[i+1][j])&&(a[i][j]>a[i][j-1])){
				cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
