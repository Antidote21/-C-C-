#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main(){
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    int res = 0; 
    for(int i=0; i<n; i++){
        res += abs(A[i]-A[n-i-1]);
    }
    cout<<res;
}
