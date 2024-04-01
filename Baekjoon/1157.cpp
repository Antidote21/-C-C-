#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string s;

int Alphabet[26];

int main() {
    cin >> s;

    memset(Alphabet, 0, sizeof(Alphabet)); 

    for(int i = 0; i < s.size(); i++) {
        char c = toupper(s[i]); 
        if(c >= 'A' && c <= 'Z') 
            Alphabet[c - 'A']++;
    }

    int maxCnt = 0;
    int maxIndex = -1;

    for(int i = 0; i < 26; i++) {
        if(Alphabet[i] > maxCnt) {
            maxCnt = Alphabet[i];
            maxIndex = i;
        }
    }

    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(Alphabet[i] == maxCnt) {
            cnt++;
        }
    }

    if(cnt > 1) {
        cout << "?" << endl;
    } else {
        cout << (char)(maxIndex + 'A') << endl;
    }

    return 0;
}
