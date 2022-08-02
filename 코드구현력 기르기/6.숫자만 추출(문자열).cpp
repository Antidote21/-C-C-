#include<stdio.h>
int main(){
	freopen("input.txt","rt",stdin);
	char a[100];
	int res=0, cnt=0, i;
	scanf("%s",&a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]>=48 && a[i]<=57){ //a[i] 아스키 코드 값 0~9
			res = res*10 + (a[i]-48); // ex) 028 0 = 0 x 10 + 0 
		}							  //         2 = 0 x 10 + 2
	}								 //          28 = 2 x 10 + 8
	printf("%d\n",res);
	for(i=1;i<=res;i++){
		if(res%i==0){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
