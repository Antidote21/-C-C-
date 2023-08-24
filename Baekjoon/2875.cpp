#include <bits/stdc++.h>

using namespace std;

int n,m,k;

int main(){
    int res=0;
    cin>>n>>m>>k;
    while(true){
        if(n-2>=0&&m-1>=0&&k<=(n-2+m-1)){
            n -= 2;
            m -= 1;
            res++;
        }else break;
    }
    cout<<res;
    
}
