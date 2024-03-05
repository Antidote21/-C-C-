#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<int> nums(T);
    for (int i = 0; i < T; ++i) {
        cin >> nums[i];
    }

    // 삼각수 구하기
    vector<int> triangleNums;
    for (int i = 1; ; ++i) {
        int triangle = i * (i + 1) / 2;
        if (triangle > 1000) break; // 1000 이하의 삼각수만 필요
        triangleNums.push_back(triangle);
    }

    for (int i = 0; i < T; ++i) {
        int num = nums[i];
        bool found = false;

        // 삼각수 3개로 표현 가능한지 확인
        for (int a : triangleNums) {
            for (int b : triangleNums) {
                for (int c : triangleNums) {
                    if (a + b + c == num) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }

        cout << (found ? 1 : 0) << endl;
    }

    return 0;
}
