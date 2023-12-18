#include<iostream>
using namespace std;
int A[101][101];
int B[101][101];
int n, m;
int main(){
    cin>>n>>m;
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>B[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<A[i][j]+B[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
