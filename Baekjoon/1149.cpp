#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < 3; j++) {
        dp[0][j] = a[0][j];
    }
    int k = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = a[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
        }
    }

    int min_val = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

    cout << min_val << endl;
    
    return 0;
}
