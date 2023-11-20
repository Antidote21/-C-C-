#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // hash에 듣도 못한 사람 반영
    unordered_map<string, int> hash;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        hash[name] = 1;
    }

    // hash에 보도 못한 사람이 존재하는지 확인
    vector<string> answer;
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        if (hash.find(name) != hash.end()) {
            answer.push_back(name);
        }
    }

    // 출력
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (auto name : answer) {
        cout << name << '\n';
    }

    return 0;
}
