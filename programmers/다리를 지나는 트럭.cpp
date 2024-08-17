#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int next_truck = 0;     
    int weight_sum = 0;    
    queue<int> on_bridge;  
 
    for (int i = 0; i < bridge_length; i++)
        on_bridge.push(0);
 
    while (!on_bridge.empty()) {
        answer++;
        weight_sum -= on_bridge.front();
        on_bridge.pop();
 
        if (next_truck < truck_weights.size()) {
            if (weight_sum + truck_weights[next_truck] <= weight) {
                weight_sum += truck_weights[next_truck];
                on_bridge.push(truck_weights[next_truck]);
                next_truck++;
            }
            else {
                on_bridge.push(0);
            }
        }
        
    }
 
    return answer;
}

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_sum = 0;
    int next_truck = 0;
    queue<int> on_bridge;
    
    for(int i=0; i<bridge_length; i++){
        on_bridge.push(0);
    }
    
    while(!on_bridge.empty()){
        answer++;
        
        weight_sum -= on_bridge.front();
        on_bridge.pop();
        
        if(next_truck < truck_weights.size()){
            if(weight_sum + truck_weights[next_truck] <= weight){
                on_bridge.push(truck_weights[next_truck]);
                weight_sum += truck_weights[next_truck];
                next_truck++;
            }else{
                on_bridge.push(0);
            }
        }
    }
    return answer;
}

