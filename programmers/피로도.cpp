#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> v;

    for (int i = 0; i < dungeons.size(); i++) {
        v.push_back(i);
    }

    do {
        int tmp = k;
        int cnt = 0;

        for (int i = 0; i < v.size(); i++) {
            int j = v[i];
            if (tmp >= dungeons[j][0]) {
                tmp -= dungeons[j][1];
                cnt++;
            }
        }

        answer = max(answer, cnt);
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> v;

    for (int i = 0; i < dungeons.size(); i++) {
        v.push_back(i);
    }

    do {
        int tmp = k;
        int cnt = 0;

        for (int i = 0; i < v.size(); i++) {
            int j = v[i];
            if (tmp >= dungeons[j][0]) {
                tmp -= dungeons[j][1];
                cnt++;
            }
        }

        answer = max(answer, cnt);
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}
