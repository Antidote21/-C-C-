#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int stair[300];
    int dp[300];

    for (int i = 0; i < n; i++) {
        cin >> stair[i];
    }

    // 초기값 설정
    dp[0] = stair[0];
    dp[1] = max(stair[0] + stair[1], stair[1]);
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    // 동적 프로그래밍을 통한 최대 점수 계산
    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
    }

    // 마지막 계단에서의 최대 점수 출력
    cout << dp[n - 1] << endl;

    return 0;
}
