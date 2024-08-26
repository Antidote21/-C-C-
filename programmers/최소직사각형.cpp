#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_height = 0;

    for (auto card : sizes) {
        max_width = max(max_width, max(card[0], card[1]));
        max_height = max(max_height, min(card[0], card[1]));
    }

    return max_width * max_height;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_height = 0;

    for (auto& size : sizes) {
        if (size[0] < size[1]) {
            swap(size[0], size[1]);
        }
        max_width = max(max_width, size[0]);
        max_height = max(max_height, size[1]);
    }

    return max_width * max_height;
}
