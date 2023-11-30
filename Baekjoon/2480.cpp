#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int cnt=1;
    vector<int> dice(3);
    for(int i=0; i<3; i++){
        int n;
        cin>>n;
        dice[i]=n;
    }
    sort(dice.begin(), dice.end());
    for(int i=0; i<2; i++){
        if(dice[i]==dice[i+1])cnt++;
    }
    int res=0;
    if(cnt==1){
        res = dice[2]*100;
    }else if(cnt==2){
        res = 1000 + dice[1]*100;
    }else if(cnt==3){
        res = 10000 + dice[0]*1000;
    }
    cout<<res;
}
