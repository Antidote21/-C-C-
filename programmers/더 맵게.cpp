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

#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    

    priority_queue<int, vector<int>, greater<int>> minHeap(scoville.begin(), scoville.end());
    

    while(minHeap.size() > 1 && minHeap.top() < K) {
        int first = minHeap.top(); 
        minHeap.pop();
        int second = minHeap.top(); 
        minHeap.pop();
        
       
        int newScoville = first + second * 2;
        minHeap.push(newScoville); 
        
        answer++; 
    }
    
    if(minHeap.top() < K) {
        return -1;
    }
    
    return answer;
}
