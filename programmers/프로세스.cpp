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
