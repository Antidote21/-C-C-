#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> tmp;
    queue<int> Q;
    int mx = priorities[location];
    priorities.erase(priorities.begin()+location);
    int size=priorities.size();
    
    for(int i=0; i<size; i++){
        if(mx<=priorities[i]){
            tmp.push_back(priorities[i]);
            Q.push(i);
        }
    }
    cout<<Q.front();
    
    if(Q.empty())return answer;
    
    while(!Q.empty()){
        Q.pop();
        answer++;
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq;
queue<pair<int, int>> q;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0; i<priorities.size(); i++){
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    int cnt=1;
    while(true){
        pair<int, int> QFront = q.front();
        q.pop();
        if(QFront.second==pq.top()){
            if(QFront.first==location){
                answer = cnt;
                break;
            }else{
                pq.pop();
                cnt++;
            }  
        }else if(QFront.second!=pq.top()){
            q.push({QFront.first, QFront.second});
        }
        
    }
    return answer;
}


#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> Q;
    priority_queue<int> pq;

    // 큐와 우선순위 큐에 요소를 삽입
    for(int i = 0; i < priorities.size(); i++) {
        Q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    while(!Q.empty()) {
        pair<int, int> current = Q.front();
        Q.pop();

        // 현재 요소가 우선순위 큐의 가장 큰 값과 동일한 경우
        if(current.first == pq.top()) {
            pq.pop(); // 우선순위 큐에서 해당 요소 제거
            answer++; // 출력 순서 증가

            // 만약 위치가 우리가 찾고자 하는 위치라면 답을 반환
            if(current.second == location) {
                return answer;
            }
        } else {
            // 우선순위가 높지 않다면 다시 큐의 끝에 넣기
            Q.push(current);
        }
    }

    return answer;
}
