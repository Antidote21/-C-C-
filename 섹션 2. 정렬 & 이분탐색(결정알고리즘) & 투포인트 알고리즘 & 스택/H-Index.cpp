#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    //내림차순 정렬을 하는 이유는 H-index 이상인 값을 구하기 위해서 
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        if (citations[i] >= i + 1) {//H-index값 안에 있는 경우 
            answer = i + 1;
        } else {//H-index값을 초과하는 경우 
            break;
        }
    }

    return answer;
}
