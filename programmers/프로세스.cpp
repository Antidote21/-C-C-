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
