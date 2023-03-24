#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//이진트리를 구성하는 자식노드 (전위순회) 
void recur(int node){
	if(node>7) return;
	else{
		printf("%d", node);
		recur(node*2);//왼쪽 자식 노드 
		recur(node*2+1);//오른쪽 자식 노드 
	}
}

int main(){
	recur(1); 
	return 0; 
}

