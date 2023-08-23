#include <iostream>
using namespace std;

int n, k;
int coin_types[11];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin_types[i];
    }

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (k >= coin_types[i]) {
            cnt += k / coin_types[i];
            k %= coin_types[i];
        }
    }

    cout << cnt << endl;
    return 0;
}
