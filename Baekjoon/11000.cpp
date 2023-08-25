#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq_less;
    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());
    
    pq_less.push(v[0].second);
    for(int i=1; i<n; i++){
        pq_less.push(v[i].second);
        while (!pq_less.empty() && pq_less.top() <= v[i].first) {
            pq_less.pop();
        }
    }

    int res = pq_less.size();
    cout << res << endl;

    return 0;
}
