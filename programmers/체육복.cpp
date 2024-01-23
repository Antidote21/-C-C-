#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    if(lost.size()==n && reserve.size()==n)return n;
    
    answer = n - lost.size();
    
    for(int i=0; i<reserve.size(); i++){
        for(int j=i; j<lost.size(); j++){
            if(lost[j]==reserve[i])continue;
            if(lost[j]==reserve[i]-1||lost[j]==reserve[i]+1){
                answer++;
                break;
            }
        }
    }
    return answer;
}
