#include<stdio.h>
#include<vector> 
#include<queue>
#include<algorithm>
using namespace std;  
int main() {
	freopen("input.txt", "rt", stdin);
	int a;
	priority_queue<int> pQ;
	while(true){
		scanf("%d", &a);
		if(a==-1)break;
		if(a==0){
			if(pQ.empty())printf("-1\n");
			else {
				printf("%d",pQ.top()); //큐에서 우선순위가 가장 높은 원소 출력  
				pQ.pop();
			}
		}
		else{
			pQ.push(a);	
		}
	}
	return 0;
}
