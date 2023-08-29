#include <bits/stdc++.h>
using namespace std;
int t, n;
int res[21];
pair<int,int> score[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> score[j].first >> score[j].second;
        }
    sort(score, score + n);
    
    int limit_score = score[0].second;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(score[i].second <= limit_score){
            cnt++;
            limit_score = score[i].second;
        }
    }
        res[i] = cnt;
    }
    
    for(int i=0; i<t; i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
