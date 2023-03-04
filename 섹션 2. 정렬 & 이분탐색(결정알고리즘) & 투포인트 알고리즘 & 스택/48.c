#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

int a[9][9];
int main(){
	freopen("input.txt","rt", stdin);
	int i,j,target,temp,min;
	float sum, avg=0;
	for(i=0;i<9;i++){
		sum=0;
		for(j=0;j<9;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
		avg=floor(sum/9+0.5);
		min=999;
		for(j=0;j<9;j++){
			temp=a[i][j];
			if(abs(avg-temp)<min){
				min=abs(avg-temp);
				target=temp;
			}
		}
		printf("%0.f %d\n",avg,target);
	}
	return 0;
}
