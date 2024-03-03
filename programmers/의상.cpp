#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> um;
    
    for(auto cloth:clothes){
        um[cloth[1]]++;
    }
    
    for(auto elem:um){
        answer *= (elem.second + 1); 
    }

    return answer-1;
}
