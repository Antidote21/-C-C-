#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum=0;
    int idx=0;
    queue<int> Q;
    
    while(idx!=truck_weights.size()){
        if(weight>=sum+truck_weights[idx]){
            sum+=truck_weights[idx];
            Q.push(truck_weights[idx]);
            idx+=1;
        }else{
            sum-=Q.front();
            Q.pop();
            answer += bridge_length;
        }
    }

    return answer;
}
