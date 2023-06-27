#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n, res, max;
	cin>>n;
	int a[n][3];
	vector<int> dy(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin>>a[i][j];
		}
	}
	dy[0] = a[0][1];
	res = dy[0];
	for(int i=0; i<n; i++){
		max=0;
		for(int j=i; j>=0; j--){
			if(a[i][0]<a[j][0] && a[i][2]<a[j][2] && dy[j]>max){
				max = dy[j];
			}
		}
		dy[i] = max+a[i][1];
		if(res<dy[i]) res=dy[i];
	}
	cout<<res;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct Brick{
	int s, h, w;
	Brick(int a, int b, int c){
		s=a, h=b, w=c;
	}
	bool operator<(const Brick &b)const{
		return s>b.s; //내림차순 
	} 
};
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n, a, b, c, max_h=0, res=0;
	cin>>n;
	vector<Brick> Bricks;
	vector<int> dy(n, 0);
	for(int i=0; i<n; i++){
		cin>>a>>b>>c;
		Bricks.push_back(Brick(a, b, c)); 
	}
	sort(Bricks.begin(), Bricks.end());
	dy[0] = Bricks[0].h;
	res = dy[0];
	for(int i=1; i<n; i++){
		max_h=0;
		for(int j=i-1; j>=0; j--){
			if(Bricks[j].w>Bricks[i].w && dy[j]>max_h){
				max_h=dy[j];
			}
		}
		dy[i]=max_h+Bricks[i].h;
		res=max(res, dy[i]);
	}
	cout<<res;
}
