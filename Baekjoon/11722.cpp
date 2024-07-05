#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(N, 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] < A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int len = 0;
    for (auto elem : dp) {
        len = max(len, elem);
    }

    cout << len << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    vector<int> dp(n, 1);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[j] > A[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max_len = *max_element(dp.begin(), dp.end());
    cout << max_len << endl;

    return 0;
}
