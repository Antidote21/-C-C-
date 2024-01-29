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
