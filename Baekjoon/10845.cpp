#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            Q.push(x);
        } else if (s == "front") {
            if (Q.empty())
                cout << -1 << endl;
            else
                cout << Q.front() << endl;
        } else if (s == "back") {
            if (Q.empty())
                cout << -1 << endl;
            else
                cout << Q.back() << endl;
        } else if (s == "empty") {
            if (Q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else if (s == "pop") {
            if (!Q.empty()) {
                cout << Q.front() << endl;
                Q.pop();
            } else {
                cout << -1 << endl;
            }
        } else if (s == "size") {
            cout << Q.size() << endl;
        }
    }
    return 0;
}
