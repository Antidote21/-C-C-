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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, S;
    cin >> N >> S;
    
    vector<int> subSum(N);
    
    for(int i = 0; i < N; i++){
        cin >> subSum[i];
    }
    
    int start = 0, end = 0, sum = 0, minLength = N + 1;
    
    while (true) {
        if (sum >= S) {
            minLength = min(minLength, end - start);
            sum -= subSum[start++];
        } else if (end == N) {
            break;
        } else {
            sum += subSum[end++];
        }
    }
    
    if (minLength == N + 1) {
        cout << 0 << endl;
    } else {
        cout << minLength << endl;
    }
    
    return 0;
}
