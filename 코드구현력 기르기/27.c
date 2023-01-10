#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n,i,j,tmp;
	scanf("%d",&n);
	vector<int> a(n+1);
	for(i=2;i<=n;i++){
		tmp=i;
		j=2;
		while(true){
			if(tmp%j==0){
				tmp/=j;
				a[j]++;
			}
			else {
				j++;
			}
			if(tmp==1)break;
		}
	}
	printf("%d! = ",n);
	for(i=0;i<n;i++){
		if(a[i]!=0){
			printf("%d ",a[i]);
		}
	}
	return 0;
}
