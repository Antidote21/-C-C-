#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2000000000
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int p = 0, q = 1, res, min = INF, res1, res2;

    while (p < q && q < n) {
        res = a[p] + a[q];

        if (min > abs(res)) {
            min = abs(res);
            res1 = a[p];
            res2 = a[q];

            if (res == 0) {
                break;
            }
        }
        q++;

        if (q == n) {
            p++;
            q = p + 1;
        }
    }

    cout << res1 <<' '<< res2;
    return 0;
}
