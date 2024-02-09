#include <string>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int cnt = 0;
    int i = 1;
    
    while (cnt < k && i < number.size()) {
        if (number[i] > number[i - 1]) {
            number.erase(number.begin() + (i - 1));
            ++cnt;
            if (i > 1)
                --i;
        } else {
            ++i;
        }
    }
    
    while (cnt < k) {
        number.pop_back();
        ++cnt;
    }
    
    return number;
}
