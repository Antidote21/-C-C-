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
