#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >> N;
    deque<int> dq;

    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        } else if (cmd == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        } else if (cmd == "pop_front") {
            if (dq.empty()) cout << -1 << endl;
            else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dq.empty()) cout << -1 << endl;
            else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        } else if (cmd == "size") {
            cout << dq.size() << endl;
        } else if (cmd == "empty") {
            cout << dq.empty() << endl;
        } else if (cmd == "front") {
            if (dq.empty()) cout << -1 << endl;
            else cout << dq.front() << endl;
        } else if (cmd == "back") {
            if (dq.empty()) cout << -1 << endl;
            else cout << dq.back() << endl;
        }
    }

    return 0;
}
