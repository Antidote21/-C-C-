#include <string>
#include <vector>

using namespace std;
int cnt=0; 

void DFS(int L, int sum, vector<int> numbers, int target){
    if(L==numbers.size()){
        if(sum == target) cnt++;
    }else{
        DFS(L+1,sum+numbers[L], numbers, target);
        DFS(L+1, sum-numbers[L], numbers, target);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(0, 0, numbers, target);
    answer = cnt;
    return answer;
}
