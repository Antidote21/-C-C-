#include <bits/stdc++.h>
using namespace std;
int x, y;
int main(){
    cin>>x>>y;
    int left=0, right=0;
    float xbit=float(1)/float(x);
    float ybit=float(1)/float(y);

    while(left<x && right<y){
        if(xbit>ybit){
            cout<<2;
            right++;
            ybit+=float(1)/float(y);
        }else if(xbit<ybit){
            cout<<1;
            left++;
            xbit+=float(1)/float(x);
        }else{
            cout<<3;
            left++;
            right++;
            xbit+=float(1)/float(x);
            ybit+=float(1)/float(y);
        }
    }
}
