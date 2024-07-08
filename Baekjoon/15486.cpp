#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> TP(N);
    vector<int> dp(N + 1, 0);  

    for (int i = 0; i < N; ++i) {
        int T, P;
        cin >> T >> P;
        TP[i] = {T, P};
    }

    for (int i = 0; i < N; ++i) {
        if (i + TP[i].first <= N) { 
            dp[i + TP[i].first] = max(dp[i + TP[i].first], dp[i] + TP[i].second);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);  
    }

    cout << dp[N] << endl;  
    return 0;
}
