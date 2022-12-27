#include<stdio.h>
#include<algorithm>
int a[60], b[60];
int main(){
	//freopen("input.txt", "rt", stdin);
	int i=0, j=0, k ;
	char p[100];
	char q[100];
	scanf("%s", p);
	while(p[i] != '\0'){	
		if(p[i]>=65 && p[i]<=90){
			a[p[i]-64]++;
			i++;
		}
		else {
			a[p[i]-70]++;
			i++;
		}
		
	}
	scanf("%s", q);
	i=0;
	while(q[i] != '\0'){
	if(q[i]>=65 && q[i]<=90){
			b[q[i]-64]++;
			i++;
		}
		else{
			b[q[i]-70]++;
			i++;
		} 
	}
	
	for(k=0; k<=52; k++){
		if(a[k]!=b[k]) {
			printf("NO"); 
			exit(0);
		}
	}

	printf("YES");
	return 0;
}
