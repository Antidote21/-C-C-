#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> children(N);
    for (int i = 0; i < N; ++i) {
        cin >> children[i];
    }

    int moves = 0; 
    int expected = 1; 
    
    for (int i = 0; i < N; ++i) {
        if (children[i] == expected) { 
            ++expected;
        } else { 
            ++moves;
        }
    }

    cout << moves << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> row(N);

    for(int i=0; i<N; i++){
        cin>>row[i];
    }
    
    vector<int> dp(N);
    int res = 0;
    
    for(int i=0; i<N; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(row[i] > row[j] && dp[i] < dp[j]+1){
                dp[i]++;
            }
        }
        if(res<dp[i])res=dp[i];
    }
    cout<<N-res<<'\n';
    return 0;
}
