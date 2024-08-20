#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0; // 현재 시간
    int index = 0; // jobs 인덱스
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 
    
    sort(jobs.begin(), jobs.end());
    
    while(index < jobs.size() || !pq.empty()) {
        if(index < jobs.size() && time >= jobs[index][0]) { 
            pq.push({jobs[index][1], {jobs[index][0], index}});
            index++;
            continue;
        }
        
        if(!pq.empty()) {
            auto cur = pq.top(); 
            pq.pop();
            time += cur.first; 
            answer += time - cur.second.first; 
        } else {
            time = jobs[index][0]; 
        }
    }
    
    return answer / jobs.size(); 
}

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; 
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0; 
    int index = 0;
    int total_time = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    sort(jobs.begin(), jobs.end());

    while (index < jobs.size() || !pq.empty()) {
        while (index < jobs.size() && jobs[index][0] <= time) {
            pq.push({jobs[index][0], jobs[index][1]});
            index++;
        }

        if (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();

            time += cur.second; 
            total_time += (time - cur.first); 
        } else {
            time = jobs[index][0]; 
        }
    }

    answer = total_time / jobs.size(); 
    return answer;
}
