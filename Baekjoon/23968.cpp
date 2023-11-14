#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int count = 0;
    string answer = "-1";

    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j + 1]) {
                count++;
                swap(nums[j], nums[j + 1]);

                if (count == k) {
                    answer = to_string(nums[j]) + " " + to_string(nums[j + 1]);
                    break;
                }
            }
        }
        if (count == k) {
            break;
        }
    }

    cout << answer << endl;

    return 0;
}


