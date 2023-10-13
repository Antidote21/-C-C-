#include <iostream>
#include <string>

using namespace std;

bool has666(int n) {
    string str_num = to_string(n);
    return str_num.find("666") != -1;
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    int number = 0;

    while (count < n) {
        number++;
        if (has666(number)) {
            count++;
        }
    }

    cout << number << endl;
    
    return 0;
}
