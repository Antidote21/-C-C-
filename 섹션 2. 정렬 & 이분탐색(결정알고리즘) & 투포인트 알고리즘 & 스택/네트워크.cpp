#include <string>
#include <vector>

#define MAX 200+1
using namespace std;

bool isVisited[MAX];

void DFS(int cur, int n, vector<vector<int>> com){
    isVisited[cur] = true;
    
    for(int i = 0; i < n; i++){
        if(!isVisited[i] && com[cur][i] == 1){
            DFS(i, n, com);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){ 
        if(!isVisited[i]){ 
            DFS(i, n, computers); 
            answer++; 
        }
    }
    return answer;
}
