#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	int n, m, i, j,min=999;
	scanf("%d",&n);
	vector<int> a(n);
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	vector<int> b(m);
	for(i=0; i<m; i++){
		scanf("%d",&b[i]);
	}
	vector<int> c(n+m);
	
	for(i=0;i<m+n;i++){
		if(i<n){
			c[i]=a[i];
		}
		else{
			c[i]=b[i-n];
		}
	}
	sort(c.begin(),c.end());

	for(i=0;i<m+n;i++){
		printf("%d ", c[i]);
	}
	return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[101], b[101], c[300];
int main(){
	//freopen("input.txt","rt", stdin);
	int n, m, i, p1=1, p2=1, p3=1;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(i=1; i<=m; i++){
		scanf("%d", &b[i]);
	}
	while(p1<=n&&p2<=m){
		if(a[p1]<b[p2]){
			c[p3++]=a[p1++];
		}
		else{
			c[p3++]=b[p2++];
		}
	}
	
	for(i=p1+p2;i<m+n+2;i++){
		if(p1<=n){
			c[p3++] = a[p1++];
		}
		else if(p2<=m){
			c[p3++] = b[p2++];
		}
	}
		
	for(i=1;i<p3;i++){
		printf("%d ", c[i]);
	}
	return 0;
}
