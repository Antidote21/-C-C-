#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, N, M;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N;
        vector<int> coins(N);
        for (int i = 0; i < N; ++i) {
            cin >> coins[i];
        }
        cin >> M;
        vector<int> dp(M + 1, 0);
        dp[0] = 1; 

        for (int coin : coins) {
            for (int j = coin; j <= M; ++j) {
                dp[j] += dp[j - coin];
            }
        }
        cout << dp[M] << endl;
    }
    return 0;
}


#include <iostream>
#include <vector>


using namespace std;

int main(){
    int T, N, M;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        vector<int> coin(N, 0);
        
        for(int j=0; j<N; j++){
            cin>>coin[j];
        }
        cin>>M;
        vector<int> dp(M+1, 0);
        dp[0] = 1; 
        for(int j=0; j<N; j++){
            for(int k=coin[j]; k<=M; k++){
                dp[k] += dp[k-coin[j]];
            }
        }
        cout<<dp[M]<<endl;
    }
}
