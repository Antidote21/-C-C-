#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    char A[50][50];
    queue<pair<int, int> > Q;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>A[i][j];
            Q.push({i,j});
        }
    }
    for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(A[i][j]=='-'&&A[i][j+1]=='-'){
                    Q.pop();
                }
                if(A[i][j]=='|'&&A[i+1][j]=='|'){
                    Q.pop();
                }
            }
        }
    cout<<Q.size();
}
