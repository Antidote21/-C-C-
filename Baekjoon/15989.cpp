#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001][4];

int main(){
    int T, N;
    cin>>T;
    
    for(int i=1; i<=3; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = 1;
        }
    }
    
    for(int i=4; i<=10000; i++){
        dp[i][1] = 1;
        dp[i][2] = dp[i-2][1]+dp[i-2][2];
        dp[i][3] = dp[i-3][1]+dp[i-3][2]+dp[i-3][3];
    }
    
    while (T--) {
        cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << endl;
    }
}
