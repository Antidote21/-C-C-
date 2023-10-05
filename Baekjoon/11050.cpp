#include <iostream>
using namespace std;

const long MOD = 1000000007;

long binomialCoefficient(long n, long k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return (binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k)) % MOD;
}

int main() {
    long n, k;
    cin >> n >> k;
    long res = binomialCoefficient(n, k);
    cout << res << endl;
    return 0;
}
