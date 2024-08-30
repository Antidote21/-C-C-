#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

vector<int> graph[101];
bool visited[101];

int dfs(int node) {
    visited[node] = true;
    int count = 1;  // 현재 노드 포함
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            count += dfs(neighbor);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int min_diff = n;  // 최대 송전탑 개수 차이의 초기값은 n으로 설정
    
    // 그래프 구성
    for (const auto& wire : wires) {
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }
    
    // 각 간선을 하나씩 제거하고 트리 분할
    for (const auto& wire : wires) {
        // 초기화
        memset(visited, false, sizeof(visited));
        
        // 간선 제거
        int u = wire[0], v = wire[1];
        
        // u와 v 간의 간선을 끊음
        graph[u].erase(remove(graph[u].begin(), graph[u].end(), v), graph[u].end());
        graph[v].erase(remove(graph[v].begin(), graph[v].end(), u), graph[v].end());
        
        // 두 서브트리의 크기를 계산
        int subtree_size = dfs(u);
        int other_subtree_size = n - subtree_size;
        
        // 차이의 절대값 계산
        min_diff = min(min_diff, abs(subtree_size - other_subtree_size));
        
        // 간선 복구
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    return min_diff;
}
