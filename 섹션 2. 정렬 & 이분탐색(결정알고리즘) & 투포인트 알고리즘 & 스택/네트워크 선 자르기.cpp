#include<bits/stdc++.h>
using namespace std;
int dy[101];
int DFS(int n){
	if(dy[n]>0) return dy[n];
	if(n==1 || n==2) return n;
	else return dy[n]=DFS(n-1)+DFS(n-2);
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n;
	cin>>n;
	cout<<DFS(n);
	return 0;
}

#include<iostream>
using namespace std;
int dy[50];
int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	dy[1] = 1;
	dy[2] = 2;
	for (int i = 3; i <= n; i++) {
		dy[i] = dy[i - 1] + dy[i - 2];
	}
	cout << dy[n];
	return 0;
}
