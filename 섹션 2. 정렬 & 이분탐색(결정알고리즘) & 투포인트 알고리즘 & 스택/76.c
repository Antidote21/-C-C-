#include<iostream>
#include<vector> 
#include<queue>
#include<algorithm>
using namespace std;  
//이항 계수를 구하는 함수인 BC 함수를 재귀적으로 구현  

int BC(int n, int k){
	if(n==k || k == 0) {
		return 1;
	}
	else return BC(n-1, k-1)+BC(n-1, k);
}

int main() {
	freopen("input.txt", "rt", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", BC(n, k));
	return 0;
}
