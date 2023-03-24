#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
void recur(int n){
	if(n<=0)return;
	else{
		recur(n/2);
		printf("%d",n%2);
	}
}
int main(){
	freopen("input.txt","rt", stdin);
	int n;
	scanf("%d",&n);
	recur(n);
	return 0; 
}

