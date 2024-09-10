#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
int ch[100];

int dfs(string st, string end, vector<string> words){
    if(st==end)return cnt;
    else{
        for(int i=0; i<words.size(); i++){
            int len=0;
            for(int j=0; j<words[i].size(); j++){   
                if(words[i][j]==st[j]){
                    len+=1;
                }
            }
            if(len == words[i].size()-1 && ch[i]==0){
                ch[i]=1;
                cnt+=1;
                dfs(words[i], end, words);
            }
        }
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(), words.end(), target) != words.end()){
        answer =  dfs(begin, target, words);
        return answer;
    }else{
        return 0;   
    }
}

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>


using namespace std;

bool canTransform(const string& a, const string& b) {
    int diff = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;
        }
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0; 
    }

    queue<pair<string, int>> q;
    q.push({begin, 0});
    unordered_set<string> visited; 
    visited.insert(begin);

    while (!q.empty()) {
        pair<string, int> currentPair = q.front(); 
        string current = currentPair.first;        
        int steps = currentPair.second;            
        q.pop();

        if (current == target) {
            return steps; 
        }

        for (const string& word : words) {
            if (visited.find(word) == visited.end() && canTransform(current, word)) {
                visited.insert(word);
                q.push({word, steps + 1});
            }
        }
    }

    return 0; 
}
