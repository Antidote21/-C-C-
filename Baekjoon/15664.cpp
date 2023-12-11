#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> a;
vector<int> res;

void sol(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = k; i < n; i++) {
            res.push_back(a[i]);
            sol(k + 1);
            res.pop_back(); 
        }
    }
}

int main() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sol(0);

    return 0;
}
