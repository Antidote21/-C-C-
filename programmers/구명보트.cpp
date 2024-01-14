#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int sum = 0;
    sort(people.begin(), people.end());
    for(int i=0; i<people.size(); i++){
        if(sum+people[i]<=limit){
            sum+=people[i];
        }else if(sum+people[i]>limit){
            sum=people[i];
            answer++;
        }
    }
    answer+=1;
    return answer;
}
