#include<iostream>
using namespace std;
int n, m, cnt;
int A[51][51];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void dfs(int x, int y){
    if(x>n||y>m){
        cout<<cnt<<endl;
        return;
    }
    else{
        // int w,h;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                // cin>>w>>h;
                if(x+dx[i]<n && x+dx[i]>0 && y+dy[j]<m && y+dy[j]>0){
                    if(A[x+dx[i]][y+dy[j]]==1){
                        cnt++;
                        dfs(x+dx[i], y+dy[j]);
                    }
                }
              
            }
        }

    }
}
int main(){
    while(true){
        cin>>n>>m;
        if(n==0&&m==0)break;
        else{
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    cin>>A[i][j];
                }
            }
            dfs(1, 1);
        }
    }
}
