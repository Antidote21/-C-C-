#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[51][51];
int main(){
	freopen("input.txt","rt", stdin);
	int n, i, j, cnt=0;
	scanf("%d",&n);
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

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[51][51];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
int main(){
	freopen("input.txt","rt", stdin);
	int  n, i, j, k, cnt=0, flag;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d", &a[i][j]);	
		}
	}
	
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			flag=0;
			for(k=0; k<4; k++){
				if(a[i][j]<=a[i+dx[k]][j+dy[k]]){
					flag=1;
					break;
				}
			}
			if(flag==0)cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
