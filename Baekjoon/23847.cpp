#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }

    int sum = 0;

    for (int i = 0; i < n-1; i++) {
        if ((s[i][0] == s[i+1][0] || s[i][0] == s[i+1][1] || s[i][1] == s[i+1][0] || s[i][1] == s[i+1][1])) {
            sum += t[i] + t[i+1];
        }
    }
    cout << sum;

    return 0;
}
