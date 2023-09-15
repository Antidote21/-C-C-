#include <iostream>
#include <string>
using namespace std;

int main() {
    string exp;
    cin >> exp;
    
    int result = 0; // 결과 값을 저장할 변수
    int num = 0; // 현재 숫자를 저장할 변수
    int sign = 1; // 현재 숫자의 부호를 나타내는 변수 (+1 또는 -1)
    bool sub = false; // 다음 숫자는 빼야 하는지 여부를 나타내는 변수
    
    for (char c : exp) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0'); // 숫자를 누적해서 구성
        } else {
            if (sub) {
                result -= num; // '-' 연산자 다음에 나오는 숫자는 괄호로 묶음
            } else {
                result += num; // '+' 연산자 다음에 나오는 숫자는 무조건 더함
            }
            
            if (c == '-') {
                sub = true; // 다음 숫자는 빼야 함
            }
            
            num = 0; // 숫자 초기화
        }
    }
    
    if (sub) {
        result -= num; // 마지막 숫자 처리
    } else {
        result += num; // 마지막 숫자 처리
    }
    
    cout << result << endl;
    
    return 0;
}
