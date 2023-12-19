#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, s, cnt;
vector<int> A;
// void sol(int sum, int idx){
//     if(s<A[idx]){
//         return;
//     }
//     if(sum>s){
//         return;
//     }
//     if(sum==s){
//         cout<<cnt;
//     }else{
//         sum+=A[idx];
//         sol(sum, idx++);
//     }
// }

int main(){
    cin>>n>>s;
    A.resize(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    for(int i=0; i<n; i++){
        int sum=0;
        cnt=0;
        for(int j=0; j<n; j++){
           sum+=A[i];
           cnt++;
           if(sum==s)cout<<cnt;
        }
    }
    
}
