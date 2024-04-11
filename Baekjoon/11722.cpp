#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> dp(n, 1); 

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] > A[i]) { 
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
    }

    int res = *max_element(dp.begin(), dp.end());
    cout << res; 

    return 0;
}
