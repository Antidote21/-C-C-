#include <iostream>
using namespace std;
int n,s,cnt;
int arr[20];
void solve(int k, int sum){
    if(k==n)return;
    if(sum+arr[k]==s)cnt++;
  
    solve(k+1, sum);
    solve(k+1, sum+arr[k]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    solve(0,0);
    cout<<cnt;
    return 0;
    
}
