#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b, c;
    cin >> n;

    vector<int> A;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    cin >> b >> c;
    
    long long cnt = 0; 
    for (int i = 0; i < n; i++) {
        int diff = A[i] - b; 
        cnt += 1 + max(0, (diff + c - 1) / c);
    }

    cout << cnt << '\n'; 

    return 0;
}
