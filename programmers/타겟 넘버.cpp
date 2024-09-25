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

#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    queue<pair<int, int>> q; // Pair of (current total, index)
    q.push({0, 0});
    int answer = 0;

    while (!q.empty()) {
        auto [total, index] = q.front();
        q.pop();

        if (index == numbers.size()) {
            if (total == target) {
                answer++;
            }
            continue;
        }

        
        q.push({total + numbers[index], index + 1});
        
        q.push({total - numbers[index], index + 1});
    }

    return answer;
}
