#include <iostream>
#include <string>
using namespace std;
char draw[51][51];
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>draw[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(draw[i][j] != '.'){
                draw[i][m-j-1] = draw[i][j];
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<draw[i][j];
        }
        cout<<endl;
    }
    
}
