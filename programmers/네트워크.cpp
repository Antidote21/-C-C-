#include <vector>

using namespace std;

int ch[200];

void dfs(int current, int n, vector< vector<int> > computers){
    ch[current] = 1;
    
    for(int i=0; i<n; i++){
        if(ch[i]==0 && computers[current][i] == 1){
            dfs(i, n, computers);
        }
    }
}

int solution(int n,  vector< vector<int> > computers){
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(ch[i]==0){
            dfs(i, n, computers);
            
            answer++;
        }
    }
    return answer;
}
