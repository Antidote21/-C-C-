#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//작은 것부터 채워가는 것이 아니라 가장 작은 요소와 가장 큰 요소를 동시에 고려해야 함 
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int idx=0;
    while(idx<people.size()){
        int back = people.back();
        people.pop_back();
        if(people[idx]+back<=limit){
            answer++;
            idx++;
        }else{
            answer++;
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); 
    int i = 0; 
    int j = people.size() - 1;
    
    while (i <= j) { 
        if (people[i] + people[j] <= limit) {
            i++;
            j--;
        } else {
            j--;
        }
        answer++; 
    }
    
    return answer;
}
