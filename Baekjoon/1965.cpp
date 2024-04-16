#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> boxs(n);
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> boxs[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (boxs[j] < boxs[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    sort(dp.begin(), dp.end());

    cout << dp[n-1] << endl;

    return 0;
}
