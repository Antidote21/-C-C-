#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> um; 
    for(int i = 0; i < clothes.size(); i++){
        um[clothes[i][1]]++; 
    }

    int answer = 1; 

    for(auto it = um.begin(); it != um.end(); it++){
        answer *= (it->second + 1); 
    }

    return answer - 1; 
}
