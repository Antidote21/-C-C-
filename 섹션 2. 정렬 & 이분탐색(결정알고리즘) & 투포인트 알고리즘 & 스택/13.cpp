#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);	
	int n, a, b, score;
	cin>>n;
	vector<vector<int> > dis(n+1, vector<int>(n+1,100));
	vector<int> res(n+1);
	for(int i=1; i<=n; i++)dis[i][i] = 0;
	while(1){
		cin>>a>>b;
		if(a!=-1&&b!=-1){
			dis[a][b] = 1;
			dis[b][a] = 1;
		}else break;
	}	
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	score=100;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			res[i]=max(res[i],dis[i][j]);
		}
		score=min(score,res[i]);
	}
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(score==res[i]){
			cnt++;
		}
	}
	cout<<score<<" "<<cnt<<endl;
	for(int i=1; i<=n; i++){
		if(score==res[i]){
			cout<<i<<" ";
		}
	}
	return 0;
}    
