#include<iostream>
using namespace std;

char chess[8][8];

int main(){
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> chess[i][j];
            if((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)){
                if(chess[i][j] == 'F'){
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
