#include<iostream>
using namespace std;
int A[9][9];
int main(){
    int max=0,x,y,i,j;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            cin>>A[i][j];
            if(max<=A[i][j]){
                max=A[i][j];
                x = i+1;
                y = j+1;
            }
        }
    }
    cout<<max<<endl;
    cout<<x<<' '<<y;
    return 0;
}
