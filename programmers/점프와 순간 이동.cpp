#include <iostream>
using namespace std;

int solution(int n) {
    int battery_usage = 0;
    
    while (n > 0) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n -= 1;
            battery_usage++;
        }
    }
    
    return battery_usage;
}
