#include <iostream>
#include <vector>

using namespace std;

int dp[12];

int main() {
    int T;
    cin >> T;
    vector<int> A(T);
    vector<int> res(T);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
   
    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    
    for (int i = 1; i <= T; i++) {
        int n;
        cin>>n;
        cout << dp[n] << endl;
    }
    
    return 0;
}
