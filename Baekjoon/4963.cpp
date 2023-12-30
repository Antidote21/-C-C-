
#include<iostream>
#include<string.h> 
using namespace std;
int n, m, cnt;
int A[51][51];
int ch[51][51];
//4방향이 아닌 8방향으로 이동 변경 
int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};
void dfs(int y, int x){
    // dfs(y,x)
    //이중 for문이 아닌 for문으로 이동
    for(int i=0; i<8; i++){
        if(x+dx[i]<n && x+dx[i]>=0 && y+dy[i]<m && y+dy[i]>=0 && ch[y+dy[i]][x+dx[i]]==0&&A[y+dy[i]][x+dx[i]]==1){
            ch[y+dy[i]][x+dx[i]]=1;
            dfs(y+dy[i],x+dx[i]);
        }
    }

}
int main(){
    while(true){
        int cnt=0;
        cin>>n>>m;
        //입력 첫번째 for문 m 두번째 for문 n 으로 변경
        if(n==0&&m==0)break;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>A[i][j];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!ch[i][j]&&A[i][j]){
                    ch[i][j]=1;
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
        memset(ch,0,sizeof(ch));//memset으로 ch 초기화(헤더 추가)
    }
}
