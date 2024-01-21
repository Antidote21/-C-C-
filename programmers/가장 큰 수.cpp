#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    return (s1 + s2) > (s2 + s1);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    if(all_of(numbers.begin(), numbers.end(), [](int num) { return num == 0; })) {
        return "0";
    }
    

    sort(numbers.begin(), numbers.end(), compare);

    for(int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }

    return answer;
}
