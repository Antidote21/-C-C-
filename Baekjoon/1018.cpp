#include <iostream>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    char chessboard[100][100];
    bool isBlack;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>chessboard[i][j];
        }
    }
    
    
    int res1=0;  
    isBlack=true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(isBlack){
                if(chessboard[i][j]=='W')res1++;
            }else if(!isBlack){
                if(chessboard[i][j]=='B')res1++;
            }
            isBlack=!isBlack;
        }
    }

    int res2=0;
    isBlack=false;
    for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(!isBlack){
                if(chessboard[i][j]=='B')res2++;
                //isBlack=!isBlack;
            }else if(isBlack){
                if(chessboard[i][j]=='W')res2++;
               
            }
            isBlack=!isBlack;
        }
    }
    cout<<res1<<res2;
    cout<<min(res1, res2);
}
