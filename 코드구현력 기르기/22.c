#include <stdio.h>
#include <vector>
int main(){
	freopen("input.txt", "rt", stdin);
	int i,n,k,sum=0,max;
	scanf("%d %d",&n,&k);
	std::vector<int> a(n);
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	for(i=0; i<k; i++){
		sum += a[i];
	}
	max=sum;
	for(i=k;i<n;i++){
		sum=sum+a[i]-a[i-k];
		if(sum>max)max=sum;
	}
	printf("%d",max);
	return 0;
}

