#include <stdio.h>
#include <stdlib.h>
#include <vector>
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, i, num, cnt=0, res;
	scanf("%d",&n);
	int a[n] = {0};
	int b[n] = {0};
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		res = abs(a[i]-a[i+1]);
		if(b[res]==0){
			b[res]=1;
			cnt++;
		}else{
			printf("NO");
			break;
		}
	}
	if(cnt==n-1){
		printf("YES");
	}
	return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, now, pre, pos;
	scanf("%d", &n);
	vector<int> ch(n);
	scanf("%d", &pre);
	for(i=1; i<n; i++){
		scanf("%d", &now);
		pos=abs(pre-now);
		if(pos<n && ch[pos]==0) ch[pos]=1;
		else{
			printf("NO\n");
			return 0;
		}
		pre=now;
	}
	printf("YES\n");	
	return 0;
}
