#include <iostream>
#include <vector>
#include <queue>
#define INF 9999999
using namespace std;

int n, e, v1, v2;
vector<pair<int, int>> graph[801];
vector<int> dist(801, INF);

void Dijkstra(int s) {
    dist.assign(n + 1, INF);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});

    while (!pq.empty()) {
        int x = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (x + w < dist[v]) {
                dist[v] = x + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> e;
    int a, b, c; 

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    long long v1_1, v1_v2, v1_n, v2_1, v2_n;

    /*v1_1: 정점 1에서 v1까지의 최단 거리
      v1_v2: v1에서 v2까지의 최단 거리
      v1_n: v1에서 정점 n까지의 최단 거리
      v2_1: v2에서 정점 1까지의 최단 거리
      v2_n: v2에서 정점 n까지의 최단 거리
    */

    Dijkstra(v1);
    v1_1 = dist[1];
    v1_v2 = dist[v2];
    v1_n = dist[n];
    Dijkstra(v2);
    v2_1 = dist[1];
    v2_n = dist[n];

    long long res1 = v1_1 + v1_v2 + v2_n;
    long long res2 = v2_1 + v1_v2 + v1_n;
    long long res = res1 < res2 ? res1 : res2;

    if (res >= INF) res = -1;

    cout << res;

    return 0;
}
