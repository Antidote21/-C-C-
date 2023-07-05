#include<bits/stdc++.h>
using namespace std;
//dy[i]테이블의 의미 = 가방에 j무게를 담을 때,  보석의 최대 가치  
int main(){
	ios_base::sync_with_stdio(false); 
	freopen("input.txt", "rt", stdin);
	int n, m, w, v;
	cin>>n>>m;
	vector<int> dy(m+1, 0);
	for(int i=0; i<n; i++){
		cin>>w>>v;
		for(int j=w; j<=m; j++){
			dy[j]=max(dy[j], dy[j-w]+v);//기존값과 w라는 무게를 가방에 담는다는 가정 
		}
	}
	
	cout<<dy[m];
	return 0;
}
