#include<bits/stdc++.h>
using namespace std;

int arr[64][64];
int n;

string quadTree(int x, int y, int k){
    if (k == 1) {
        return (arr[x][y] == 1) ? "1" : "0";
    }
    
    bool cut = false;
    for(int i = x; i < x + k; i++){
        for(int j = y; j < y + k; j++){
            if(arr[i][j] != arr[x][y]) {
                cut = true;
                break;
            }
        }
        if (cut) break;
    }
    
    if (cut) {
        int half = k / 2;
        string upperLeft = quadTree(x, y, half);
        string upperRight = quadTree(x, y + half, half);
        string lowerLeft = quadTree(x + half, y, half);
        string lowerRight = quadTree(x + half, y + half, half);
        
        return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
    } else {
        return (arr[x][y] == 1) ? "1" : "0";
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string row;
        cin >> row;
        for(int j = 0; j < n; j++){
            arr[i][j] = row[j] - '0';
        }
    }
    
    string result = quadTree(0, 0, n);
    cout << result;
    
    return 0;
}
