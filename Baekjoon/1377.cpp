#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
 
    sort(v.begin(), v.end());
 
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (res < v[i].second-i) {
            res = v[i].second - i;
        }
    }
 
    cout << res + 1;
}
