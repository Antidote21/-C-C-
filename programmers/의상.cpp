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

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> um;
    
    for(int i = 0; i < clothes.size(); i++) {
        string type = clothes[i][1]; // 의상의 종류를 키로 사용
        if(um[type] >= 1) {
            um[type]++;
        } else {
            um[type] = 1; 
        }
    }
    
    for(auto elem : um) {
        answer *= (elem.second + 1); 
    }

    return answer - 1; 
}
