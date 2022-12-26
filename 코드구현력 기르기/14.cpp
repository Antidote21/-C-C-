#include <iostream>
using namespace std;
int reverse(int x) {
	int m = 0;
	while (x > 0) {
		m *= 10;
		m += x % 10;
		x /= 10;
	}
	return m;
}

bool isPrime(int x) {
	int i;
	if (x == 1) return false;
	bool flag = true;
	for (i = 2; i < x; i++) {
		if (x % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	int n, num, i, tmp;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> num;
		tmp = reverse(num);
		if (isPrime(tmp)) {
			cout << tmp << " ";
		}
	}
	return 0;
}
