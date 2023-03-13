#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int stack[100];
int top=-1;
void push(int x){
	stack[++top]=x;
}
int pop(){
	return stack[top--];
}
int main(){
	freopen("input.txt","rt", stdin);
	int n,k,tmp1,tmp2;
	scanf("%d %d",&n,&k);
	tmp1=n;
	while(true){
		if(tmp1==0)break;
		tmp2=tmp1%k;
		tmp1=tmp1/k;
		push(tmp2);
	}
	while(top!=-1){
		printf("%d",pop());
	}
	return 0;
}

//위 코드의 문제점 16진수 출력 불가 

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int stack[100];
int top=-1;

void push(int x){
	stack[++top]=x;
}

int pop(){
	return stack[top--];
}

int main(){
	freopen("input.txt","rt", stdin);
	int n,k;
	char str[20]="0123456789ABCDEF";
	scanf("%d %d",&n,&k);
	while(n>0){
		push(n%k);
		n=n/k;
	}
	while(top!=-1){
		printf("%c",str[pop()]);
	}
	return 0;
}
