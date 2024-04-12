#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> Card(N+1);
    vector<int> dp(N+1, 100);
    for(int i=1; i<=N; i++){
        cin>>Card[i];
    }
    for(int i=1; i<=N; i++){
        if(N%i==0){
            dp[i] = Card[i]*N/i;
        }
    }
    
    sort(dp.begin(), dp.end());
    
    cout<<dp[0]<<endl;
}
