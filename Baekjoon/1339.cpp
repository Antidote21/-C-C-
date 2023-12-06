#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> words;
vector<int> alphabets(26);
vector<int> digits;

int main() {
    int n;
    cin >> n;

    words.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < n; i++) {
        int weight = 1;
        for (int j = words[i].size() - 1; j >= 0; j--) {
            alphabets[words[i][j] - 'A'] += weight;
            weight *= 10;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alphabets[i] > 0) {
            digits.push_back(alphabets[i]);
        }
    }

    sort(digits.begin(), digits.end(), greater<int>());

    int result = 0;
    int value = 9;
    for (int i = 0; i < digits.size(); i++) {
        result += digits[i] * value;
        value--;
    }

    cout << result << endl;

    return 0;
}
