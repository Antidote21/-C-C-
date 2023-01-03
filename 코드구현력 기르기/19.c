#include<stdio.h>

int main() {
	freopen("input.txt", "rt", stdin);
	int n, a, i, j, cnt, total=0;
	scanf("%d", &n);
    int angry[n] = {0};
	for(i=0;i<n;i++){
		scanf("%d", &a);
		angry[i] = a;
	}
	for(i=0;i<n; i++){
		cnt = 0;
		for(j=i+1; j<n; j++){
			if(angry[i]>angry[j]){
				cnt++;
			}
		}
		if(cnt == n-i-1){
			total++;
		}
	}
	total--;
	printf("%d",total);
	return 0;
}

#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, a, i , cnt=-1, max=0;
	scanf("%d", &n);
    int angry[n] = {0};
	for(i=0;i<n;i++){
		scanf("%d", &a);
		angry[i] = a;
	}
	for(i=n-1;i>=0; i--){
		if(max<angry[i]){
			max = angry[i];
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}

