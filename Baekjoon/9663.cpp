#include <iostream>
using namespace std;
int col[16];
int cnt;
int n;
void solve(int x){
    if(n==x){
        cnt++;
    }else{
        for(int i=0; i<n; i++){
            col[x]=i;
            bool ch = true;
            for(int j=0; j<x; j++){
                if(col[x] == col[j] || abs(col[x]-col[j])==x-j){
                    ch=false;
                    break;
                }
            }
            if(ch){
                queen(x+1);
            }
        }
    }
}
int main(){
    cin>>n;
    queen(0);
    cout<<res;
    return 0;
}
