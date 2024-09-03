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

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.size();
    stack<char> s;

    for (int i = 0; i < n; i++) {
        char c = number[i];
        // 스택의 top에 있는 문자보다 현재 문자가 크면 스택의 top을 pop하고 k를 줄인다.
        while (!s.empty() && s.top() < c && k > 0) {
            s.pop();
            k--;
        }
        // 스택에 현재 문자를 push한다.
        s.push(c);
    }
    
    // k가 남아있다면 스택의 top에서 k만큼 더 pop한다.
    while (k > 0) {
        s.pop();
        k--;
    }

    // 스택의 문자들을 모아 답을 만든다.
    while (!s.empty()) {
        answer = s.top() + answer;
        s.pop();
    }

    return answer;
}
