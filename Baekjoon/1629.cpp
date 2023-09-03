#include <iostream>
using namespace std;

long long int a, b, c;

long long int power(long long int x, long long int m) {
    if (m == 0)
        return 1;
    else if (m == 1)
        return x;
    if (m % 2 > 0)
        return power(x, m - 1) * x;
    long long int half = power(x, m / 2);
    half %= c;
    return (half * half) % c;
}

int main() {
    cin >> a >> b >> c;

    cout << power(a, b) % c;

    return 0;
}
