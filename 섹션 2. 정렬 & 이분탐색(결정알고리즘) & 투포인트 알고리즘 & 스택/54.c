#include <stdio.h>
#include <vector>
#include <stack>
#include<iostream>
#include <algorithm>
using namespace std;
int main(){
	//freopen("input.txt","rt", stdin);
	stack<char> a;
	char p;
	while(true){
		scanf("%c",&p);
		if(p=='(')a.push(p);
		else if(p==')')a.pop();
		else break;
	}
	if(a.empty())printf("YES");
	else printf("NO");
	return 0;
}

