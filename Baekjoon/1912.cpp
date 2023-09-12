#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
int dp[100000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int res = arr[0];
    dp[0] = arr[0];
    for(int i=1; i<n; i++){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        res = max(res, dp[i]);
    }
    cout<<res;
}
