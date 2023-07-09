#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); 
	freopen("input.txt", "rt", stdin);
	int n, m, v, t;
	cin>>n>>m;
	vector<int> dy(m+1);
	for(int i=0; i<n; i++){
		cin>>v>>t;
		for(int j=m; j>=t; j--){
			dy[j] = max(dy[j], dy[j-t]+v);	
		}
	}
	cout<<dy[m];
	return 0;
}
