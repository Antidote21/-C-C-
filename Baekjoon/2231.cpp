#include <iostream>

using namespace std;

int calculateSumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int sum = calculateSumOfDigits(i);
        if (i + sum == n) {
            cout << i << endl;
            return 0;
        }
    }
    
    // 생성자를 찾지 못한 경우
    cout << 0 << endl;
    
    return 0;
}
