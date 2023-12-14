#include <iostream>
#include <algorithm>
int A[50], B[50];
int ch[50];
int n;
using namespace std;
 
int main() {
    cin>>n;
 
    for(int i=0; i<n; i++) {
        cin>>A[i];
    }
 
    for(int i=0; i<n; i++) {
        cin>>B[i];
    }
 
    ch[n]={0,};
    sort(A, A+n);
 
    int sum=0;
    
    for(int i=0; i<n; i++) {
        int tmp=0;
        int idx=0;
        for(int i=0; i<n; i++) {
            if(tmp<B[i] && ch[i] == 0) {
                tmp=B[i];
                idx=i;
            }
        }
        ch[idx] = 1;
        sum+=A[i]*tmp;
    }
 
    cout<<sum;
 
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int res=0;
    for(int i=0; i<n; i++){
        res += a[i]*b[n-1-i];
    }
    cout<<res;
}
