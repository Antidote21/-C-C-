#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers, int target, int sum, int index, int& answer) {
    if (index == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }

    dfs(numbers, target, sum + numbers[index], index + 1, answer);

    dfs(numbers, target, sum - numbers[index], index + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}


#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers, int target, int total, int index, int& answer){
    if(index == numbers.size()){
        if(target == total){
            answer++;
        }
        return;
    }
    
    dfs(numbers, target, total + numbers[index], index + 1, answer);  
    dfs(numbers, target, total - numbers[index], index + 1, answer);  

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}
