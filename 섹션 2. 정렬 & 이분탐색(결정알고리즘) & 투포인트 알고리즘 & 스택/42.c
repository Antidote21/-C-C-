#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	int n, key, lt, rt, mid, i;
	scanf("%d %d",&n, &key);
	vector<int> a(n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	lt=0, rt=n-1;
	mid=(lt+rt)/2;
	while(key!=a[mid]){
		if(a[mid]==key){
			break;
		}
		else if(a[mid]>key){
			rt=mid-1;
		}
		else if(a[mid]<key){
			lt=mid+1;
		}
		mid=(lt+rt)/2;
	}
	printf("%d",mid+1);
}


#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	int n, i, key, lt=0, rt, mid, tmp;
	scanf("%d %d", &n, &key);
	vector<int> a;
	for(i=0; i<n; i++){
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	rt=n-1;
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(a[mid]==key){
			printf("%d\n", mid+1);
			return 0;
		}
		else if(a[mid]>key)rt=mid-1;
		else lt=mid+1;
	}
	return 0;
}
