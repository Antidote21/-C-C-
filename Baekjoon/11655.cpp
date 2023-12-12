#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string res;

    for (int i = 0; i < s.size(); i++) {
        char tmp = s[i];

        if (tmp == ' ') {
            res += ' ';
            continue;
        }

        if ('a' <= tmp && tmp <= 'z') {
            tmp += 13;
            if (tmp > 'z') {
                tmp = tmp - 'z' + 'a' - 1;
            }
        } else if ('A' <= tmp && tmp <= 'Z') {
            tmp += 13;
            if (tmp > 'Z') {
                tmp = tmp - 'Z' + 'A' - 1;
            }
        }

        res += tmp;
    }

    cout << res;
    return 0;
}
