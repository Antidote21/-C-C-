#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s;
    stack<int> st;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push") {
            cin >> m;
            st.push(m);
        } else if (s == "pop") {
            if (!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            } else {
                cout << "-1" << endl;
            }
        } else if (s == "size") {
            cout << st.size() << endl;
        } else if (s == "empty") {
            if (!st.empty()) {
                cout << "0" << endl;
            } else {
                cout << "1" << endl;
            }
        } else if (s == "top") {
            if (!st.empty()) {
                cout << st.top() << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }
}
