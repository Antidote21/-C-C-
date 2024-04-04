#include <iostream>

using namespace std;

char A[100][100];
int main(){
    int N, M;
    cin>>N>>M;
    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>A[i][j];
            cnt++;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j]=='-'&&A[i][j+1]=='-'){
                cnt--;
            }
            if(A[i][j]=='|'&&A[i+1][j]=='|'){
                cnt--;
            }
        }
    }
    cout<<cnt;
}
