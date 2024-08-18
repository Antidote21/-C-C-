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
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int idx = 0; idx < prices.size(); ++idx){ 
        int chk = 0;
        for(int i = idx+1; i < prices.size(); ++i){
            chk++;
            if(prices[idx] > prices[i]) 
                break;
            }
        answer.push_back(chk); 
    }

    #include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> st;
    for(int i=0; i<prices.size(); i++){
        while(!st.empty() && prices[st.top()] > prices[i]){
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        answer[st.top()] = prices.size() - st.top() -1;
        st.pop();
    }
    return answer;
}
    return answer;
}
