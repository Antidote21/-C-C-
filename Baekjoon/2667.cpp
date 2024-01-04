#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int map[26][26];
int ch[26][26];
int total_n;
int n, cnt;
vector<int> result;
void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int xx=dx[i]+x;
        int yy=dy[i]+y;
        if(xx<0||xx>n-1||yy<0||yy>n-1)continue;
        if(ch[xx][yy]==0&&map[xx][yy]==1){
            cnt+=1;
            ch[xx][yy]=1;
            dfs(xx,yy);
        }
    }

}
int main(){
  cin>>n;
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          scanf("%1d",&map[i][j]);//공백 없이 숫자가 입력되면 cin으로 받을 수 없음
      }
  }
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          if(map[i][j]==1 && ch[i][j]==0){
              ch[i][j]=1;
              cnt=1;
              dfs(i,j);
              result.push_back(cnt);
              total_n++;
          }
      }
  }
   
  sort(result.begin(), result.end());
  cout<<total_n<<"\n";
  for(int i=0; i<result.size(); i++){
      cout<<result[i]<<"\n";
  }
  return 0;
}

