#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> electricWire(n);

    for (int i = 0; i < n; i++) {
        cin >> electricWire[i].first >> electricWire[i].second;
    }

    sort(electricWire.begin(), electricWire.end());

    int count = 0; // 삭제한 전깃줄의 개수

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (electricWire[i].second > electricWire[j].second && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            }
        }
        count = max(count, dp[i]);
    }

    // 전체 전깃줄 개수에서 최장 증가 부분 수열의 길이를 뺀 값이 삭제해야 하는 전깃줄의 최소 개수
    int result = n - count;

    cout << result << endl;

    return 0;
}
