#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n;
	cin>>n;
	int a[n][n];
	int dy[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		    dy[i][j] = a[i][j];
		}
	}
	for(int i=0; i<n; i++){
		dy[0][i] += dy[0][i-1];
		dy[i][0] += dy[i-1][0];
	}
	
	for(int i=1; i<n; i++){ 
		for(int j=1; j<n; j++){	
			if(dy[i-1][j]>dy[i][j-1]){
				dy[i][j] += dy[i][j-1];
			}else{
				dy[i][j] += dy[i-1][j];
			}
		}	
	}
	
	cout<<dy[n-1][n-1];
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int arr[21][21], dy[21][21];
int main(){
	ios_base::sync_with_stdio(false); 
	freopen("input.txt", "rt", stdin);
	int n, cnt =0;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	dy[0][0] = arr[0][0];
	for(int i=0; i<n; i++){
		dy[0][i] = arr[0][i] + dy[0][i-1];
		dy[i][0] = arr[i][0] + dy[i-1][0];
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			dy[i][j]=min(dy[i-1][j], dy[i][j-1])+arr[i][j];
		}
	}
	cout<<dy[n-1][n-1];
	return 0;
}
