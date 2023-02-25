#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("input.txt","rt", stdin);
	int n, k, i, pos=0, cnt=0, len=0;
	scanf("%d %d",&n, &k);
	vector<int> a(n+1);
	while(len<n-1){
		pos++;
		if(pos>n)pos=1;
		if(a[pos]==0){
			cnt++;		
			if(cnt==k){
				a[pos]=1;
				len++;
				cnt=0;
			}	
		}
	
	}
	for(i=1; i<=n; i++){
		if(a[i]==0){
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}
