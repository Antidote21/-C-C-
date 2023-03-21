#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	int n, i, j;
	stack<int> s;
	vector<char> ch;
	scanf("%d",&n);
	int a[n];
	int b[n]; //사실상 불필요한 배열 
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]; //1부터 N까지의 번호순이라 생각해서 sort를 사용해 오름차순 정렬로 바꾸려고 잘못생각 
	}
	sort(b,b+n); //sort할 필요없이 for문을 사용하면 됨  
	j=0; 
	while(true){ //구조가 for문 안에 while문이 있어야 함  
		if(i==n)break;
		s.push(a[i]);//스택에 집어넣는 과정은 scanf 다음에 있어야 스택안에 있는 값을 비교하며 if(s.top()==b[j])		                   
		ch.push_back('P'); //과정이 올바르게 수행됨  
		if(s.top()==b[j]){
			j++;
			ch.push_back('O');
			s.pop();	
		}else{
			i++;
		}

	}
	if(!s.empty())printf("impossible");
	else{
		for(i=0;i<6;i++){//vector의 for문 조건식은 size() 함수를 사용할 수 있음  
		printf("%c",ch[i]);              
		}
	}
	return 0; 
}


#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	stack<int> s;
	int i, j=1, n, m;
	scanf("%d", &n);
	vector<int> a(n+1);
	vector<char> str;  
	for(i=1; i<=n; i++){
		a[i]=i;
	}
	for(i=1;i<=n; i++){
		scanf("%d", &m);
		s.push(m);
		str.push_back('P');
		while(1){
			if(s.empty())break;
			if(j==s.top()){
				s.a[j]op();
				j++;
				str.push_back('O');
			}
			else break;
		}
	}
	if(!s.empty()) printf("impossible\n");
	else{
		for(i=0; i<str.size(); i++) printf("%c", str[i]);
	}
	return 0; 
}
