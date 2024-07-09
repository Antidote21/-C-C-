#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, Ti, Pi;
    cin >> N;
    vector<pair<int, int>> schedule(N);
    vector<int> dp(N + 1, 0);
    for(int i = 0; i < N; i++){
        cin >> Ti >> Pi;
        schedule[i] = {Ti, Pi};
    }
    
    for(int i = N - 1; i >= 0; i--){
        if(i + schedule[i].first <= N){
            dp[i] = max(schedule[i].second + dp[i + schedule[i].first], dp[i + 1]);
        }else{
            dp[i] = dp[i + 1];
        }
    }
    cout << dp[0] << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> TP(N);
    vector<int> dp(N+1, 0); 

    for(int i = 0; i < N; i++){
        int T, P;
        cin >> T >> P;
        TP[i] = {T, P};
    }

    for(int i = 0; i < N; i++){
        int T = TP[i].first;
        int P = TP[i].second;
        if (i + T <= N) {
            dp[i + T] = max(dp[i + T], dp[i] + P);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
