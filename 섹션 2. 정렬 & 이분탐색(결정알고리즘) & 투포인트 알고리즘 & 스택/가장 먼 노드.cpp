#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> vertex) {
    vector<vector<int>> graph(n + 1);
    for (const auto& v : vertex) {
        int a = v[0], b = v[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> levels(n + 1, 0);

    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));

    while (!q.empty()) {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        visited[node] = true;
        levels[node] = level;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(make_pair(neighbor, level + 1));
                visited[neighbor] = true;
            }
        }
    }

    int max_level = *max_element(levels.begin(), levels.end());
    int answer = count(levels.begin(), levels.end(), max_level);
    return answer;
}
