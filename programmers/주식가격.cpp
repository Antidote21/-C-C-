#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && prices[i] < prices[s.top()]) {
            int j = s.top();
            s.pop();
            answer[j] = i - j;
        }
        s.push(i);
    }

    while (!s.empty()) {
        int j = s.top();
        s.pop();
        answer[j] = n - 1 - j;
    }

    return answer;
}
