#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10000];
bool found = false;

void dfs(vector<vector<string>> tickets, string airport, int k, vector<string>& answer) {
    if (k == tickets.size()) {
        found = true;
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (airport == tickets[i][0] && !visited[i]) {
            visited[i] = true;
            answer[k + 1] = tickets[i][1];
            dfs(tickets, tickets[i][1], k + 1, answer);
            if (found) return; 
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end()); 
    vector<string> answer(tickets.size() + 1);
    answer[0] = "ICN";

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            fill(begin(visited), end(visited), false);
            visited[i] = true;
            answer[1] = tickets[i][1];
            dfs(tickets, tickets[i][1], 1, answer);
            if (found) break;
        }
    }

    return answer;
}
