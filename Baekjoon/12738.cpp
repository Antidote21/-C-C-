#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> lis;

    for (int i = 0; i < N; i++) {
        // A[i]가 들어갈 위치를 찾음 (이분 탐색으로 진행)
        auto pos = lower_bound(lis.begin(), lis.end(), A[i]);

        // 만약 위치가 lis의 끝이라면 새로 추가
        if (pos == lis.end()) {
            lis.push_back(A[i]);
        } else {
            // 그렇지 않으면 기존 값을 A[i]로 치환
            *pos = A[i];
        }
    }

    // LIS의 길이를 출력
    cout << lis.size() << endl;

    return 0;
}
