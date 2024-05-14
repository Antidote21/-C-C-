#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    priority_queue<pair<int, int>> Room;
    for(int i=0; i<N; i++){
        int S,T;
        cin>>S>>T;
        Room.push({S,T});
    }
    int cnt=0;
    while(!Room.empty()){
        pair<int,int> top = Room.top();
        Room.pop();
        pair<int,int> top2 = Room.top();
        if(top.second>=top2.first){
            cnt++;
        }
    }
    cout<<cnt;
}
