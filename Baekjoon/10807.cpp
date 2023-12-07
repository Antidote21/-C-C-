#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, v;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>v;
    int res=0;
    for(int i=0; i<n; i++){
        if(a[i]==v)res++;
    }
    cout<<res;
}

