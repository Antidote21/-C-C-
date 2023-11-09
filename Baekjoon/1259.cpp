#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    while (true) {
        int n;
        cin >> n;
        string s = to_string(n);
        int k = s.size();
        bool flag = false;
        if (n == 0)
            break;
        for (int i = 0; i < k/2 ; i++) {
            if (s[i] != s[k-1-i]) {
                cout<<"no"<<endl;
                flag = true;
                break; 
            }
        }
        if (!flag) {
            cout << "yes" << endl;
        } 
    }

    return 0;
}
