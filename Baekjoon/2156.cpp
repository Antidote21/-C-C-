#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> wine(n);
    vector<int> dp(n);
    for(int i=0; i<n; i++){
        cin>>wine[i];
    }
    
    dp[0] = wine[0];
    dp[1] = max(wine[0]+wine[1], wine[1]);
    dp[2] = max(dp[1], max(wine[0] + wine[2], wine[1]+wine[2]));
    
    for(int i=3; i<n; i++){
        dp[i] = max(dp[i-1], max(dp[i-2]+wine[i], dp[i-3]+wine[i-1]+wine[i]));
    }
    
    cout<<dp[n-1];
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> glass(n);
    vector<int> dp(n);

    for(int i = 0; i < n; i++){
        cin >> glass[i];
    }

    if (n == 1) {
        cout << glass[0];
        return 0;
    } else if (n == 2) {
        cout << glass[0] + glass[1];
        return 0;
    }

    dp[0] = glass[0];
    dp[1] = glass[0] + glass[1];
    dp[2] = max({glass[0] + glass[2], glass[1] + glass[2], dp[1]});

    for (int i = 3; i < n; i++) {
        dp[i] = max({dp[i-1], dp[i-2] + glass[i], dp[i-3] + glass[i-1] + glass[i]});
    }

    cout << dp[n-1];

    return 0;
}
