#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, a, b;
    cin >> A >> B;
    a = A;
    b = B;
    for (int i=0; i<A.size(); i++) {
        if (a[i] == '6') {
            a[i] = '5';
        }
    }
    for (int i=0; i<B.size(); i++) {
        if (b[i] == '6') {
            b[i] = '5';
        }
    }
    int minSum = stoi(a) + stoi(b);
    
    a = A;
    b = B;
    for (int i=0; i<A.size(); i++) {
        if (a[i] == '5') {
            a[i] = '6';
        }
    }
    for (int i=0; i<B.size(); i++) {
        if (b[i] == '5') {
            b[i] = '6';
        }
    }
    int maxSum = stoi(a) + stoi(b);

    cout << minSum << " " << maxSum << endl;

    return 0;
}
