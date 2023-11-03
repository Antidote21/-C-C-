#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000][1000];
int M[1000][1000];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            M[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    int maxSquareSize = 0; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                if (i == 0 || j == 0) {
                    M[i][j] = 1;
                } else {
                    M[i][j] = min({M[i-1][j], M[i][j-1], M[i-1][j-1]}) + 1;
                }
                maxSquareSize = max(maxSquareSize, M[i][j]);
            }
        }
    }
    
    int maxSquareArea = maxSquareSize * maxSquareSize;
    cout << maxSquareArea << endl;
    
    return 0;
}
