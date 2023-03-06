#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	int n,i,j, cnt=0;
	scanf("%d", &n);
	int c[n][n];
	int a[n];
	int b[n];
	//int c[n][n]={0};
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
		for(j=0;j<n;j++){
			c[j][i]=a[i];
		}	
	}
	for(i=0;i<n;i++){
		scanf("%d", &b[i]);	
		for(j=0;j<n;j++){
			if(c[i][j]>b[i])c[i][j]=b[i];
		}	
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cnt+=c[i][j];
		}	
	}
	printf("%d",cnt);
	return 0;
}
