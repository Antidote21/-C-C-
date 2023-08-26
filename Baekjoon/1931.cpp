#include<bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    vector<pair<int, int>> meetings;

    for (int i=0; i<n; i++) {
        int start, end;
        cin >> start >> end;
        meetings.push_back(make_pair(end, start)); // 끝나는 시간을 기준으로 정렬하기 위해 순서를 바꾸어 저장
    }

    sort(meetings.begin(), meetings.end()); // 끝나는 시간을 기준으로 정렬

    int count = 0;
    int current_time = 0;

    for (int i=0; i<n; i++) {
        if (meetings[i].second >= current_time) {
            current_time = meetings[i].first;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
