#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > pz;
vector<pair<int, int> > hs;
int ch[20], m, res=2147000000, dis, sum=0;
void DFS(int L, int s){
	if(L==m){
		sum=0;
		for(int i=0; i<hs.size(); i++){
			int x1=hs[i].first;
			int y1=hs[i].second;
			dis=2147000000;
			for(int j=0; j<m; j++){
				int x2=pz[ch[j]].first;
				int y2=pz[ch[j]].second;
				dis=min(dis, abs(x1-x2)+abs(y1-y2));
			}
			sum=sum+dis;
		}
		if(sum<res) res=sum;
	}
	else{
		for(int i=s; i<pz.size(); i++){
			ch[L]=i;
			DFS(L+1, i+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, a;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>a;
			if(a==1) hs.push_back(make_pair(i, j));
			else if(a==2) pz.push_back(make_pair(i, j));
		}
	}
	DFS(0, 0);
	cout<<res;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n, m, res=100, dis;
int a[50][50];
int ch[30];
vector<pair<int, int > >home;
vector<pair<int, int > >pizza;
void DFS(int s, int L){
	if(L==m){
		int sum=0;
		for(int i=0; i<home.size(); i++){
			int x1 = home[i].first;
			int y1 = home[i].second;
			dis=100;
			for(int j=0; j<m; j++){
				int x2 = pizza[ch[j]].first;
				int y2 = pizza[ch[j]].second;
				dis = min(dis, abs(x1-x2) + abs(y1-y2));
			}
			sum+=dis;//현재 선택한 피자집들과 모든 집들과의 거리의 합			
		}
		res = min(res, sum);
	}else{
		for(int i=s; i<pizza.size(); i++){
			ch[L]=i;
			DFS(i+1, L+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
			if(a[i][j]==1)home.push_back(make_pair(i,j));
			if(a[i][j]==2)pizza.push_back(make_pair(i,j));
		}
	}
	DFS(0, 0);
	cout<<res;
	return 0;
}
