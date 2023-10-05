#include <iostream>
using namespace std;

long binomialCoefficient(long n, long k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return (binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k));
}

int main() {
    long n, k;
    cin >> n >> k;
    long res = binomialCoefficient(n, k);
    cout << res << endl;
    return 0;
}
