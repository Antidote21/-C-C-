#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	//freopen("input.txt","rt", stdin);
	int n, k, i, pos=1, cnt=0, sum=0;
	scanf("%d", &n);
	vector<int> work(n);
	for(i=0;i<n;i++){
		scanf("%d", &work[i]);
		sum+=work[i];
	}
	scanf("%d", &k);
	while(1){
		if(sum==k){
			pos=-1;
			break;
		}
		if(pos>n-1){
			pos=0;
		}
		if(work[pos]!=0){
			work[pos]--;
			pos++;
			cnt++;
		}
		else pos++;
		if(cnt==k)break;
	}
	printf("%d",pos);
	return 0;
}
