#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int Count(int len, int x[]){
	int i, cnt=1, pos=x[1];
	for(i=2; i<=n; i++){
		if(len<=x[i]-pos){
			pos=x[i];
			cnt++;
		}
	}
	return cnt;
}

int main(){
	freopen("input.txt","rt", stdin);
	int m, i, lt=1, rt, mid, res;
	scanf("%d %d",&n, &m);
	int *x = new int[n+1];
	for(i=1; i<n; i++){
		scanf("%d",&x[i]);
	}
	sort(x+1,x+n+1);
	rt=x[n];	
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(Count(mid, x)>=m){
			res=mid;
			lt=mid+1;
		}
		else {
			rt= mid-1;
		}
	}
	printf("%d\n", res);
	delete[] x;
	return 0;
}



