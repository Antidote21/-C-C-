#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

unordered_map<string, int> um;

void dfs(int idx, string tmp, string order){
    um[tmp]++;
    for(int i=idx; i<order.size(); i++){
        dfs(i+1, tmp+order[i], order);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto order: orders){
        sort(order.begin(), order.end());
        cout<<order<<endl;
        dfs(0,"",order);
    }
    
    for(auto size:course){
        int maxOrdered = 0;
        for(auto m:um){
            if(m.first.size() == size){
                maxOrdered = max(m.second, maxOrdered);
            }
        }
        if(maxOrdered <= 1)continue;
        for(auto m:um){
            if(m.first.size() == size &&  m.second == maxOrdered){
                answer.push_back(m.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
