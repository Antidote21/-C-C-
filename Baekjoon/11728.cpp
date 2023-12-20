#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<int> A(n+m);
    vector<int> B(m);
    //vector<int> C(n+m);
    for(int i=0; i<n; i++){
        cin>>A[i];
        //C[i]=A[i];
    }
    for(int i=0; i<m; i++){
        cin>>B[i];
        A[i+n]=B[i];
    }
    
    sort(A.begin(), A.end());
    
    for(int i=0; i<n+m; i++){
        cout<<A[i]<<' ';
    }
}
