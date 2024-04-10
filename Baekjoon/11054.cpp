#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp_up(n, 1);    // 증가하는 부분 수열의 길이를 저장하는 DP 배열
    vector<int> dp_down(n, 1);  // 감소하는 부분 수열의 길이를 저장하는 DP 배열

    // 증가하는 부분 수열을 찾는 DP
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp_up[i] = max(dp_up[i], dp_up[j] + 1);
            }
        }
    }

    // 감소하는 부분 수열을 찾는 DP
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j]) {
                dp_down[i] = max(dp_down[i], dp_down[j] + 1);
            }
        }
    }

    int max_bitonic_len = 0;

    // 각 위치에서 증가하는 부분 수열과 감소하는 부분 수열의 길이를 합한 후 중복되는 중간 값 1을 빼줍니다.
    for (int i = 0; i < n; i++) {
        max_bitonic_len = max(max_bitonic_len, dp_up[i] + dp_down[i] - 1);
    }

    cout << max_bitonic_len << endl;

    return 0;
}
