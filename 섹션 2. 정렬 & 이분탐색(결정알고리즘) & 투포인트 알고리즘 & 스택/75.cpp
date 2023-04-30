#include<iostream>
#include<vector> 
#include<queue>
#include<algorithm>
using namespace std;  
/*
Data 구조체 
money와 when 두 개의 멤버 변수 
money 변수는 데이터의 가치를 나타내며, when 변수는 데이터가 처리되기를 기다리는 시간
Data 구조체 내부에 생성자가 정의 
생성자는 두 개의 인자를 받아 money와 when 변수를 초기화
< 연산자 오버로딩 구현 
*/
struct Data{
	int money;
	int when;
	Data(int a, int b){
		money=a;
		when=b;
	}
	bool operator<(Data &b){ //when 멤버 변수를 기준으로 정렬 when 값이 작을수록
		return when>b.when; //우선순위가 높게 설정
	}
};
int main() {
	freopen("input.txt", "rt", stdin);
	int n, i, j, a, b, res=0, max=-2147000000;
	vector<Data> T;
	priority_queue<int> pQ;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		T.push_back(Data(a, b));
		if(b>max) max=b;
	}
	sort(T.begin(), T.end());
	j=0;
	/*
	데이터를 처리해야하는 시간이 가장 늦은 시간부터 역순으로 반복문을 돌며 
	해당 시간에 처리 가능한 모든 데이터를 우선순위 큐(pQ)에 넣는다.
	*/
	for(i=max; i>=1; i--){
		for(; j<n; j++){
			if(T[j].when<i)break;
			pQ.push(T[j].money);
		}//그리고 pQ가 비어있지 않다면, pQ에서 가장 높은 이익을 가진 데이터를 꺼내어 
		//이익(res)에 더해주고, 처리한 데이터는 pQ에서 삭제한다.
		if(!pQ.empty()){
			res+=pQ.top();
			pQ.pop();
		}
	}
	printf("%d\n",res);
	return 0;
}
