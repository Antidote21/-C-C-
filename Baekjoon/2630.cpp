#include <bits/stdc++.h>
using namespace std;
int white, blue, n;
int paper[128][128];
void divide(int x, int y, int k){
    bool cut = false;
    int first_color=paper[x][y];
    for(int i=x; i<x+k; i++){
        for(int j=y; j<y+k; j++){
            if(paper[i][j] != first_color){
                cut = true;
                break;
            }
        }
    }
    if(cut){
        divide(x, y, k/2);
        divide(x, y+k/2, k/2);
        divide(x+k/2, y, k/2);
        divide(x+k/2, y+k/2, k/2);
    }else{
        if(first_color==1)blue++;
        else white++;
    }
    
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> paper[i][j];
        }
    }
    divide(0, 0, n);
    cout<<white<<'\n';
    cout<<blue<<'\n';
    return 0;
}
