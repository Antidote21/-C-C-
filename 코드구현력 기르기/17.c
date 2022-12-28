#include<stdio.h>

int main(){
	//freopen("input.txt", "rt", stdin);
	int n,num,sum,res,i,j;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&num);
		scanf("%d",&res);
		sum = 0;
		for(j=1;j<=num;j++){
			sum += j;     
		}
		if(sum == res) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
