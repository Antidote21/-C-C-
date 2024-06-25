#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ch[10];

void dfs(vector<string> words, string begin, string target, int currentSteps, int& minSteps){
    if(begin == target){
        minSteps = min(minSteps, currentSteps);
        return;
        }
    else{
        for(int i=0; i<words.size(); i++){
            if(ch[i]==0){
                int cnt=0;
            for(int j=0; j<words[i].size(); j++){
                if(begin[j]!=words[i][j])cnt++;
            }
            if(cnt==1){
                    ch[i]=1;
                    dfs(words, words[i], target, currentSteps+1, minSteps);
                    ch[i]=0;
                } 
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    auto it = find(words.begin(), words.end(), target);
    if(it == words.end())return 0;
    int minSteps = 1000;
    dfs(words, begin, target, 0, minSteps);
    return minSteps;
}
