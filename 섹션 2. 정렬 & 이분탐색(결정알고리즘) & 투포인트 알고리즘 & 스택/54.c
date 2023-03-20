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

#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	stack<char> s;
	char a[50]; //입력을 받을 char배열 생성 
	int i, flag=1; //올바른 괄호를 확인하기 위한 flag 변수 
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){ //char 배열이 공백이 아닌 경우에만 for문 반복 
		if(a[i]=='(') s.push(a[i]); //여는 괄호면 스택 s에 push() 
		else { //닫는 괄호인 경우  
			if(s.empty()){ //닫는 괄호인데 비어있으면 잘못된 경우이므로  
				printf("NO\n"); //곧바로 NO를 출력  
				flag=0;
				break;
			}
			else s.pop(); //정상적인 경우 스택 s에서 pop() 
		}
	}
	if(s.empty() && flag == 1)printf("YES\n"); //스택 s가 비어있고 flag가 1인 경우에만  YES를 출력  
	else if(!s.empty() && flag==1) printf("NO\n"); //위에서 이미 NO를 출력했으므로 중복을 방지하기 위해 flag==1인 조건을 추가함 
	return 0;
}
