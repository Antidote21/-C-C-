#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimes(vector<int>& numbers) {
    int count = 0;
    for (int num : numbers) {
        if (isPrime(num)) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    int primeCount = countPrimes(numbers);
    cout << primeCount << endl;

    return 0;
}
