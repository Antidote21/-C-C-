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

#include<iostream>
#include<vector> 
#include<queue>
#include<algorithm>
using namespace std;  
//이항 계수를 구하는 함수인 BC 함수를 재귀적으로 구현  
int dy[21][21];//이항 계수의 값을 저장하는 배열
int BC(int n, int r){
	if(dy[n][r]>0) return dy[n][r]; //배열의 값이 0보다 크면 이미 계산한 값이므로 저장된 값을 반환
	if(n==r || r==0 ){
		return 1;
	}else{
		return dy[n][r] = BC(n-1, r) + BC(n-1, r-1);
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d",BC(n, r));
	return 0;
}
