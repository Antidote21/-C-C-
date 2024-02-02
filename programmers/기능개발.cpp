#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;
    for(int i = 0; i < progresses.size(); i++) {
        int tmp = ceil((float(100 - progresses[i])) / float(speeds[i]));
        s.push(tmp);
    }
    int cnt = 0;
    while (!s.empty()) {
        int currentTop = s.top();
        s.pop();
        
        if (s.empty()) {
            cnt += 1;
            answer.push_back(cnt);
            break;
        }

        int nextTop = s.top();
        if (currentTop <= nextTop) {
            cnt += 1;
        } else {
            cnt += 1;
            answer.push_back(cnt);
            cnt = 0; 
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int size = speeds.size();
    for (int i = 0; i < size; ++i)
        q.push(i);
    while(!q.empty()){
        int cnt = 0;
        for(int j = 0; j < size; ++j)
            progresses[j] += speeds[j]; 
        while(!q.empty() && progresses[q.front()] >= 100){
            ++cnt;
            q.pop();
        }
        if(cnt != 0)
            answer.push_back(cnt);  
    }
    return answer;
}

