#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin>>n;
    vector<pair<int, int>> res;
    for(int i=0; i<n; i++){
        int p;
        cin>>p;
        res.push_back(make_pair(p,i));
    }
    sort(res.begin(), res.end());
    
    int total_time = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            total_time += res[j].first;
        }
    }
    cout<<total_time<<'\n';
    
}
