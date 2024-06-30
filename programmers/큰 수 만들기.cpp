#include <string>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int cnt = 0;
    int i = 1;
    
    while (cnt < k && i < number.size()) {
        if (number[i] > number[i - 1]) {
            number.erase(number.begin() + (i - 1));
            ++cnt;
            if (i > 1)
                --i;
        } else {
            ++i;
        }
    }
    
    while (cnt < k) {
        number.pop_back();
        ++cnt;
    }
    
    return number;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<string> result;
    vector<bool> v(number.size());
    fill(v.begin(), v.begin() + number.size() - k, true);

    do {
        answer = "";
        for (int i = 0; i < number.size(); i++) {
            if (v[i]) {
                answer += number[i];
            }
        }
        if (answer!="") {
            result.push_back(answer);
        }
    } while (prev_permutation(v.begin(), v.end()));

    sort(result.begin(), result.end(), greater<>());

    answer = result[0];
    return answer;
}
