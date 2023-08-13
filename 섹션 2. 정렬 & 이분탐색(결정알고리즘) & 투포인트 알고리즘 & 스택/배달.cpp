#include <iostream>
#include <vector>
#include <queue>
#define MAX 2147483647
using namespace std;
struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex = a;
        dis = b;
    }
    bool operator<(const Edge &b) const{
        return dis>b.dis;
    }
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> dist(N+1, MAX);
    priority_queue<Edge> Q;
    vector<pair <int, int> > graph[N+1];
    for(int i=0; i<road.size(); i++){
        graph[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        graph[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    Q.push(Edge(1, 0));
    dist[1] = 0;
    while(!Q.empty()){
        int now = Q.top().vex;
        int cost = Q.top().dis;
        Q.pop();
        for(int i=0; i<graph[now].size(); i++){
            int next = graph[now][i].first;
            int nextDis = cost + graph[now][i].second;
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                Q.push(Edge(next, nextDis));
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(dist[i]<=K)answer++;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;
    return answer;
}
