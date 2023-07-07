#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, m;//n 동전의 종류 수, m 거스름돈의 금액
	cin>>n;
	vector<int> coin(n);//동전의 종류를 저장하는 벡터
	for(int i=0; i<n; i++) cin>>coin[i];
	cin>>m;
	vector<int> dy(m+1, 1000);//거스름돈의 최소 동전 개수를 저장하는 벡터
	dy[0]=0;//거스름돈이 0일 때의 최소 동전 개수
	for(int i=0; i<n; i++){//동전의 종류를 순회
		for(int j=coin[i]; j<=m; j++){//거스름돈을 순회
			dy[j]=min(dy[j], dy[j-coin[i]]+1);//dy[j-coin[i]]+1 현재 동전을 사용해서 거스름돈을 만들기 위해 필요한 동전 개수
		}
	}
	cout<<dy[m];
	return 0;
}
