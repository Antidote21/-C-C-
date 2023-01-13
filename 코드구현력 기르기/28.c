#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	int n,i,j,tmp;
	scanf("%d",&n);
	//vector<int> a(n+1);
	vector<int> a(2);
	for(i=2;i<=n;i++){
		tmp=i;
		j=2;
		while(true){
			if(tmp%j==0){
				tmp/=j;
				if(j==2)a[0]++;
				if(j==5)a[1]++;
			}
			else {
				j++;
			}
			if(tmp==1)break;
		}
	}
	if(a[0]>=a[1]){
		printf("%d ",a[1]);
	}
	else{
		printf("%d",a[0]);
	}
	
	return 0;
}
