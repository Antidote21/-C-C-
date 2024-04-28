#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string numbers;
    cin >> numbers;
    
    int total = 0;
    for (char digit : numbers) {
        total += digit - '0';
    }
    
    cout << total << endl;
    
    return 0;
}
