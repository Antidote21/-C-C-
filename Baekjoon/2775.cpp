#include <iostream>
#include <vector>


using namespace std;

int main() {
    int T;
    cin >> T;

    vector<vector<int>> residents(15, vector<int>(15, 0)); 
    
    for (int i = 0; i <= 14; ++i) {
        residents[0][i] = i;
    }

    for (int i = 1; i <= 14; ++i) {
        for (int j = 1; j <= 14; ++j) {
            residents[i][j] = residents[i - 1][j] + residents[i][j - 1];
        }
    }

    for (int t = 0; t < T; ++t) {
        int k, n;
        cin >> k >> n;
        cout << residents[k][n] << endl;
    }

    return 0;
}
