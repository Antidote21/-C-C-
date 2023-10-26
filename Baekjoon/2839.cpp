#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p, q, tmp, res, cnt;
    if (n >= 3) {
        p = n / 5;
        res = 999999; 
    } else {
        cout << -1;
        return 0; 
    }
    for (int i = 0; i <= p; i++) {
        tmp = n;
        cnt = 0;
        tmp -= i * 5;
        cnt += i;
        while (tmp >= 0) { 
            if (tmp == 0) {
                res = min(res, cnt);
                break; 
            } else {
                tmp -= 3;
                cnt++;
            }
        }
    }

    if (res == 999999) {
        cout << -1; 
    } else {
        cout << res;
    }

    return 0;
}
