#include <stdio.h>
int main(){
	//freopen("input.txt", "rt", stdin);
	int i, a[10], b[10], acnt=0, bcnt=0, flag=0, total=0;
	
	for(i=0;i<10;i++){
		scanf("%d", &a[i]);
	}
	
	
	for(i=0;i<10;i++){
		scanf("%d", &b[i]);
	}
	
	for(i=0; i<10; i++){
		if(a[i]>b[i]){
			acnt+=3;
			flag=1;
		}
		else if(a[i]<b[i]){
			bcnt+=3;
			flag=2;
		}
		else{
			acnt++;
			bcnt++;
			total++;
		}
	}
	printf("%d %d\n", acnt, bcnt);
	if(acnt<bcnt)printf("B\n");
	else if(acnt>bcnt)printf("A\n");
	else{
		if(total==10)printf("D\n");
		if(flag==1)printf("A\n");
		else if(flag==2)printf("B\n");
	}
	return 0;
}

