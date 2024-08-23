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

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 비교 함수 정의
bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> str_numbers;
    
    // 정수를 문자열로 변환하여 벡터에 저장
    for(int num : numbers) {
        str_numbers.push_back(to_string(num));
    }
    
    // 비교 함수에 따라 정렬
    sort(str_numbers.begin(), str_numbers.end(), compare);
    
    // 정렬된 문자열들을 이어붙임
    string answer = "";
    for(string str : str_numbers) {
        answer += str;
    }
    
    // 모든 숫자가 0인 경우 "0"을 반환
    if(answer[0] == '0') {
        return "0";
    }
    
    return answer;
}

