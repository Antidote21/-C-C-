//복면산 문제는 숫자들과 연산자를 조합하여 수식을 만족시키는 문제 
//각 숫자는 알파벳 대문자로 표시되어 있으며 동일한 알파벳은 동일한 숫자 
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int a[10], ch[10];
//send, more, money 함수는 각각 SEND, MORE, MONEY를 숫자로 변환하는 함수
// 각 자리의 숫자를 곱해서 합을 계산하고 반환
int send() {
	return a[6]*1000+a[1]*100+a[3]*10+a[0];
}
int more() {
	return a[2]*1000+a[4]*100+a[5]*10+a[1];
}
int money() {
	return a[2]*10000+a[4]*1000+a[3]*100+a[1]*10+a[7];
}
void DFS(int L){
	int i, j;
	if(L==8){ // 모든 숫자가 선택된 상태
		if(send()+more()==money()){
			if(a[2] == 0 || a[6] == 0) return; //S와 M은 0이 될 수 없다는 제약
			printf("  %d %d %d %d\n", a[6], a[1], a[3], a[0]);
			printf("+ %d %d %d %d\n", a[2], a[4], a[5], a[1]);
			printf("---------\n");
			printf("%d %d %d %d %d\n", a[2], a[4], a[3], a[1], a[7]);
		}
	}
	else{
		for(i=0; i<10; i++){
			if(ch[i]==0){
				a[L]=i;
				ch[i]=1;
				DFS(L+1);
				ch[i]=0;
			}
		}
	}
}

int main(){
	//freopen("input.txt", "rt", stdin);
	DFS(0);	
	return 0;
}
