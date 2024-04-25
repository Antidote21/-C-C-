#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_profit(int N, vector<pair<int, int>>& schedules) {
    vector<int> dp(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        if (i + schedules[i].first <= N) {  
            dp[i] = max(schedules[i].second + dp[i + schedules[i].first], dp[i + 1]);
        } else {  
            dp[i] = dp[i + 1];
        }
    }

    return dp[0];
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> schedules(N);
    for (int i = 0; i < N; i++) {
        int Ti, Pi;
        cin >> Ti >> Pi;
        schedules[i] = make_pair(Ti, Pi);
    }

    cout << max_profit(N, schedules) << endl;

    return 0;
}
