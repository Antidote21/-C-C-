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

#include <iostream>
using namespace std;
int dy[100];
int n;

int DFS(int k)
{
    if (dy[k] != 0)
        return dy[k];
    if (k == 1 || k == 2)
        return dy[k];
    else
    {
        dy[k] = DFS(k - 1) + DFS(k - 2);
        return dy[k];
    }
}

int main()
{
    cin >> n;
    dy[1] = 1;
    dy[2] = 2;
    cout << DFS(n) << endl;
    return 0;
}

