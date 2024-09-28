#include <string>
#include <vector>
#include <cmath>  
#include <cstring>  
#include <algorithm>

using namespace std;

int dfs(int node, vector<vector<int>>& graph, bool visited[]) {
    visited[node] = true;
    int size = 1;  
    
    for(int next : graph[node]) {
        if (!visited[next]) {
            size += dfs(next, graph, visited);
        }
    }
    
    return size;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    
  
    for(int i = 0; i < wires.size(); i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int min_diff = n;

    for(int i = 0; i < wires.size(); i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        
       
        graph[a].erase(find(graph[a].begin(), graph[a].end(), b));
        graph[b].erase(find(graph[b].begin(), graph[b].end(), a));
        
       
        bool visited[n + 1];
        memset(visited, false, sizeof(visited));
        
        
        int subtree_size = dfs(a, graph, visited);  
        int other_subtree_size = n - subtree_size;  
        
  
        int diff = abs(subtree_size - other_subtree_size);
        min_diff = min(min_diff, diff);
        
     
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    return min_diff;
}

#include <string>
#include <vector>
#include <algorithm>
#include <climits>  // for INT_MAX

using namespace std;

int dfs(int start, vector<vector<int>>& graph, vector<bool>& visited){
    int size = 1;
    visited[start] = true;
    
    for (int node : graph[start]) {
        if (!visited[node]) {
            size += dfs(node, graph, visited);
        }
    }
    
    return size;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    vector<vector<int>> graph(n+1); 
    
    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        
        graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
        graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());
        
        vector<bool> visited(n+1, false);
        int tree_size_a = dfs(a, graph, visited);  // Size of the subtree containing node a
        
        int tree_size_b = n - tree_size_a;
        
        answer = min(answer, abs(tree_size_a - tree_size_b));
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    return answer;
}

