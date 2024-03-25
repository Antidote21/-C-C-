#include  <bits/stdc++.h>

using namespace std;

bool isVisit[1001];
int arr[1001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    int ans = 0;
    int maxCnt = 0;
    for(int i = 1; i <= N; i++) {
        memset(isVisit, 0, sizeof(isVisit));

        int cnt = 0;
        int cur = i;
        while (!isVisit[cur]) {
            isVisit[cur] = true;
            cur = arr[cur];
            cnt++;
        }

        if(maxCnt < cnt){
            maxCnt = cnt;
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}
