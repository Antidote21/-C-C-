#include <iostream>
#include <cstring>

using namespace std;

int N;
int dp[10001][4];

void solution() {
    dp[1][1] = 1;

    dp[2][1] = 1;
    dp[2][2] = 1;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i <= 10000; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    solution();

    while (T--) {
        cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << endl;
    }

    return 0;
}
