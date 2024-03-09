#include <iostream>
using namespace std;

int countZero(int N, int M) {
    int count = 0;
    for (int i = N; i <= M; ++i) {
        int num = i;
        while (num > 0) {
            if (num % 10 == 0) {
                count++;
            }
            num /= 10;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, M;
        cin >> N >> M;
        if (N == 0) {  
            cout << countZero(1, M) + 1 << endl;
        } else {
            cout << countZero(N, M) << endl;
        }
    }
    return 0;
}
