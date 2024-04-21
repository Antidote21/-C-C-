#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> children(N);
    for (int i = 0; i < N; ++i) {
        cin >> children[i];
    }

    int moves = 0; 
    int expected = 1; 
    
    for (int i = 0; i < N; ++i) {
        if (children[i] == expected) { 
            ++expected;
        } else { 
            ++moves;
        }
    }

    cout << moves << endl;

    return 0;
}
