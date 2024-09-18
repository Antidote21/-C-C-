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


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<pair<int, int> > TP(N+1);
    vector<int> dp(N+2, 0);
    
    for(int i=1; i<=N; i++){
       int t, p;
       cin>>t>>p;
       TP[i] = {t, p};
    }
    
    for(int i=1; i<= N; i++){
            if(i+TP[i].first <= N+1){
                dp[i+TP[i].first] = max(dp[i + TP[i].first], dp[i] + TP[i].second);
            }
            dp[i+1] = max(dp[i], dp[i+1]);
    }

    cout<<dp[N+1];
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> T(N + 1);  // 상담 기간
    vector<int> P(N + 1);  // 상담 금액
    vector<int> dp(N + 1); // dp[i]는 i번째 날부터 퇴사일까지 벌 수 있는 최대 수익

    // 상담 기간과 금액 입력 받기
    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }

    // 역순으로 DP 테이블 채우기
    for (int i = N; i > 0; --i) {
        if (i + T[i] - 1 > N) { // 상담 기간이 퇴사일을 넘으면 상담 불가
            dp[i] = dp[i + 1];
        } else {
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
        }
    }

    // 첫째 날부터 시작했을 때의 최대 이익 출력
    cout << dp[1] << endl;

    return 0;
}

