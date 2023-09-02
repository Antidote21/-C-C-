#include<bits/stdc++.h>
using namespace std;
int a,b,c,n;
int paper[2187][2187];
void divide(int x, int y, int k){
    int first_num = paper[x][y];
    bool cut = false;
    for(int i=x; i<x+k; i++){
        for(int j=y; j<y+k; j++){
            if(first_num != paper[i][j]){
                cut = true;
                break;
            }
        }
        if(cut) break;
    }
    if(cut){
        divide(x, y, k/3);
        divide(x+k/3, y, k/3);
        divide(x+2*k/3, y, k/3);
        divide(x, y+k/3, k/3);
        divide(x+k/3, y+k/3, k/3);
        divide(x+2*k/3, y+k/3, k/3);
        divide(x, y+2*k/3, k/3);
        divide(x+k/3, 2*k/3+y, k/3);
        divide(x+2*k/3 ,y+2*k/3, k/3);
    }else{
        if(first_num == -1) a++;
        else if(first_num == 0) b++;
        else c++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>paper[i][j];
        }
    }
    divide(0, 0, n);
    cout<<a<<endl<<b<<endl<<c;
}
