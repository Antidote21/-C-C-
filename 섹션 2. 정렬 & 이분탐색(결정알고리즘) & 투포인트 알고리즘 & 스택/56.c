#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
void recursion(int a){
	if(a==1) printf("%d", a); 
	else{
		printf("%d", a);
		a--;
		return recursion(a);
	};
}
int main(){
	freopen("input.txt","rt", stdin);
	int n;
	scanf("%d",&n);
	recursion(n);
	return 0; 
}

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
//재귀함수는 조건을 설정하지 않의면 무한루프에 빠지기 쉽다. 
//재귀는 스택을 이용하여 저장된다.  
void recur(int x){
	if(x==0) return;
	else{
		recur(x-1);
		printf("%d ", x);
	}
}

int main(){
	freopen("input.txt","rt", stdin);
	int n;
	scanf("%d",n);
	recur(n);
	return 0; 
}
