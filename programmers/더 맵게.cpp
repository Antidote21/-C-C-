#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(pq.top()<K){
        int newScoville = 0;

        if(pq.size() == 1) {
            answer = -1;
            break;
        }

        answer++;
        newScoville += pq.top();
        pq.pop();
        newScoville += pq.top()*2;
        pq.pop();
        pq.push(newScoville);

    }
    return answer;
}
