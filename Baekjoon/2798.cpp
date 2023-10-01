#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    int closestSum = 0;

    sort(cards.begin(), cards.end());

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;

        while (left < right) {
            int currentSum = cards[i] + cards[left] + cards[right];
            
            if (currentSum <= M) {
                closestSum = max(closestSum, currentSum);
                left++;
            } else {
                right--;
            }
        }
    }

    cout << closestSum << endl;

    return 0;
}

