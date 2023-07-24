#include <string>
#include <vector>
 
using namespace std;
 
int answer = 999999999;
vector<int> goc;    
vector<int> rem;
 
void dfs(int s, int cnt, vector<string> minerals, vector<int> picks) {                                                
    if(cnt == s) {
        int tired = 0;
        
        for(int i=0; i<minerals.size(); i++) {
            if(i/5 >= rem.size()) {
                break;
            }
            if(minerals[i] == "diamond") {
                if(rem[i/5] == 1) {
                    tired += 1;
                }
                else if(rem[i/5] == 2) {
                    tired += 5;
                }
                else if(rem[i/5] == 3) {
                    tired += 25;
                }
            }
            else if(minerals[i] == "iron") {
                if(rem[i/5] == 3) {
                    tired += 5;
                }
                else if(rem[i/5] == 2 || rem[i/5] == 1) {
                    tired += 1;
                }
            }
            else if(minerals[i] == "stone") {
                if(rem[i/5] == 3 || rem[i/5] == 2 || rem[i/5] == 1)
                tired += 1;
            }
        }
        
        answer = min(tired,answer);
        
        return;
    }
    
    for(int i=0; i<3; i++) {
        if(picks[i] == 0) continue;
        picks[i] = picks[i] - 1;
        rem.push_back(i+1);
        dfs(s,cnt+1,minerals,picks);
        rem.pop_back();
        picks[i] = picks[i] + 1;
    }
    
}
 
int solution(vector<int> picks, vector<string> minerals) {
    for(int i=1; i<=3; i++) {
        for(int j=0; j<picks[i-1]; j++) {
            goc.push_back(i);
        }
    }
    
    if(minerals.size() < goc.size() * 5) {
        dfs(minerals.size()/5+1, 0, minerals, picks);
    }
    else {
        dfs(goc.size(),0,minerals,picks);
    }
     
    return answer;
}
