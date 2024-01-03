#include<iostream>
#include<vector>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int map[26][26];
int ch[26][26];
int total_n;
int n;
vector<int> result;
void dfs(int x, int y){
    if(x==n-1 && y==n-1){
        total_n++;
        return;
    }else{
        int cnt=0;
        for(int i=0; i<4; i++){
            int xx=dx[i]+x;
            int yy=dy[i]+y;
            if(xx<0||xx>n-1||yy<0||yy>n-1)return;
            if(ch[xx][yy]!=0&&map[xx][yy]==1){
                cnt++;
                ch[xx][yy]=1;
                dfs(xx,yy);
                ch[xx][yy]=0;
            }
        }
        result.push_back(cnt);
    }
}
int main(){
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           cin>>map[i][j];
       }
   }
   dfs(0,0);
   cout<<total_n<<"\n";
   for(int i=0; i<result.size(); i++){
       cout<<result[i]<<"\n";
   }
}
