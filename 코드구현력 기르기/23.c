#include <stdio.h>
#include <vector>
int main(){
	//freopen("input.txt", "rt", stdin);
	int i,n,cnt,max;
	scanf("%d",&n);
	std::vector<int> a(n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	cnt=1;
	for(i=0;i<n;i++){
		if(a[i]<=a[i+1]){
			cnt++;
			if(cnt>max){
				max = cnt;
			}
		//	printf("%d ",cnt);
		}else cnt=1;
	}
	printf("%d", max);
	return 0;
}

