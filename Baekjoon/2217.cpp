#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
    int n, w;
    vector<int> rope;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>w;
        rope.push_back(w);
    }
    sort(rope.begin(), rope.end());
    
    int res, sum;
    res = rope[0] * n;
    for(int i=1; i<n; i++){
        sum = rope[i] * (n-i);
        if(sum > res) res = sum;
    }
    cout<<res;
}
