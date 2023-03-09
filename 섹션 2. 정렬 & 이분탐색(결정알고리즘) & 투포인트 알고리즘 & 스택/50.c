#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	int H,W,h,w,i,j,k,l,sum,max=0;
	scanf("%d %d",&H,&W);
	int a[H][W];
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d",&h,&w);

	for(i=0;i<H-h+1;i++){
		for(j=0;j<W-w+1;j++){
			sum=0;		
			for(k=0;k<h;k++){
				for(l=0;l<w;l++){
					sum+=a[i+k][j+l];
				}
			}
			if(max<sum)max=sum;
		}
	}
	printf("%d",max);
	return 0;
}
