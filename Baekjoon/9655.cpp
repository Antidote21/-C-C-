#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<string> dp(1001);
    dp[1]="SK";
    dp[2]="CY";
    dp[3]="SK";
    dp[4]="CY";
    for(int i=5; i<=N; i++){
        dp[i] = dp[i-2];
    }
    cout<<dp[N];
}
