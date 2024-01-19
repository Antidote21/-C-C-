//해시를 사용하지 않고 풀이 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    if(participant.size()==1){
        answer=participant[0];
        return answer;   
    }
    
    for(int i=0; i<participant.size(); i++){
        if(participant[i]!=completion[i]){
            answer=participant[i];
            break;
        }
    }
    return answer;
}

//해시를 사용한 풀이
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> um;
    
    for (auto p : participant) {
        um[p]++;
    }
    
    for (auto c : completion) {
        um[c]--;
    }

    for (auto entry : um) {
        if (entry.second > 0) {
            return entry.first;
        }
    }

    return "";
}
  

