#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> wine(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> wine[i];
    }

    dp[0] = wine[0];
    dp[1] = max(wine[0] + wine[1], wine[1]);
    dp[2] = max(dp[1], max(wine[0] + wine[2], wine[1] + wine[2]));

    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]));
    }
    //현재 위치에서 포도주를 마시지 않고 이전까지의 최대 양
    //i - 2에서 최대로 마실 수 있는 양을 가져와서 현재 위치의 포도주 양 wine[i]을 더하는 경우
    //i - 3에서 최대로 마실 수 있는 양을 가져와서 현재 위치의 포도주 양 wine[i]과 그 이전 위치의 포도주 양 wine[i - 1]을 더하는 경우

    cout << dp[n - 1];

    return 0;
}
