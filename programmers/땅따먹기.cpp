#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[100000][4];

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();
    
    for (int i = 0; i < 4; i++) {
        dp[0][i] = land[0][i];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = land[i][j] + max({ dp[i-1][(j+1)%4], dp[i-1][(j+2)%4], dp[i-1][(j+3)%4] });
        }
    }
    
    for (int i = 0; i < 4; i++) {
        answer = max(answer, dp[n-1][i]);
    }

    return answer;
}
