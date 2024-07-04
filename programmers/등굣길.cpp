#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0; i<puddles.size(); i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
        
    }
    dp[1][1] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dp[i][j] == -1) { 
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    answer = dp[n][m];
    return answer;
}
