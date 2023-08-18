#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    queue<string> Q;
    Q.push("ICN");
    int cnt=0;
    while(!Q.empty()){
        string s = Q.front();
        Q.pop();
        if(cnt==tickets.size()){
            answer.push_back(s);
        }
        for(int i=0; i<tickets.size(); i++){
            if(s==tickets[i][0]){
                Q.push(tickets[i][1]);
                answer.push_back(tickets[i][0]);
               
                break;
            }
        }
        cout<<answer[cnt];
        cnt++;
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
int visited[10000]; 
bool isFlag;

void dfs(string route, vector<vector<string>> tickets, int cnt){
    if(cnt == tickets.size()){
        isFlag = true;
    } 
    answer.push_back(route);
    
    for(int i=0; i<tickets.size(); i++){
        if(visited[i]==0 && tickets[i][0] == route){
            visited[i] = 1;
            dfs(tickets[i][1], tickets, cnt+1);
            
            if(!isFlag){
                answer.pop_back();
                visited[i] = 0;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, 0);
    return answer;
}
