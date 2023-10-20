#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main(){
    cin>>n;
    vector<int> team(n*2);
    int res=9999999;
    for(int i=0; i<n*2; i++){
        cin>>team[i];
    }
    
    sort(team.begin(), team.end());
    

    for(int i=0; i<n; i++){
        res = min(res, team[i]+team[n*2-1-i]);
    }
    
    cout<<res;
}
