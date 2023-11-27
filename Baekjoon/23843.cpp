#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    int n, m;
    int res = 0;
    cin>>n>>m;
    priority_queue<int, vector<int>, greater<int>>pq;
    vector<int> v(n);
    for(int i=0; i<m; i++){
        pq.push(0);
    }
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i=0; i<n; i++){
        int x = pq.top()+v[i];
        pq.pop();
        pq.push(x);
        
        res = max(x, res);
    }
    cout<<res;
}

