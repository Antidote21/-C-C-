#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

int l, c;
vector<char> chars;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void backtracking(int index, string password, int vowelCount, int consonantCount) {
    if (password.length() == l) {
        if (vowelCount >= 1 && consonantCount >= 2) {
            cout << password << endl;
        }
        return;
    }

    for (int i = index; i < c; i++) {
        char ch = chars[i];
        if (isVowel(ch)) {
            backtracking(i + 1, password + ch, vowelCount + 1, consonantCount);
        } else {
            backtracking(i + 1, password + ch, vowelCount, consonantCount + 1);
        }
    }
}

int main() {
    cin >> l >> c;
    chars.resize(c);
    for (int i = 0; i < c; i++) {
        cin >> chars[i];
    }

    sort(chars.begin(), chars.end());

    backtracking(0, "", 0, 0);
    return 0;
}
