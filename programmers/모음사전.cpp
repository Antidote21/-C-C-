#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string target = "";
string aeiou = "AEIOU";

void dfs(string word) {
     cnt++;
    
    if (word == target) {
        answer = cnt;
        return;
    }
    
    if (word.length() >= 5) return;
    
    for (int i=0; i<5; i++) {
        dfs(word + aeiou[i]);
    }
}

int solution(string word) {   
    target = word;
    dfs("");
    
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string word) {
    vector<char> aeiou = {'A', 'E', 'I', 'O', 'U'};
    vector<int> weights = {781, 156, 31, 6, 1};
    
    int answer = 0;
    
    for(int i=0; i<word.length(); i++){
        int idx = find(aeiou.begin(), aeiou.end(), word[i]) - aeiou.begin();
        answer += idx * weights[i] + 1;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string target = "";
string aeiou = "AEIOU";

void dfs(string word) {
     cnt++;
    
    if (word == target) {
        answer = cnt;
        return;
    }
    
    if (word.length() >= 5) return;
    
    for (int i=0; i<5; i++) {
        dfs(word + aeiou[i]);
    }
}
int solution(string word) {   
    target = word;
    dfs("");
    
    return answer;
}
