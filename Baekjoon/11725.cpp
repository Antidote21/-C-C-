#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[100001];
int visited[100001];
int res[100001];

void dfs(int k) {
    visited[k] = 1;
    for (int i = 0; i < tree[k].size(); i++) {
        int next = tree[k][i];
        if (visited[next] == 0) {
            res[next] = k;
            dfs(next);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << res[i] << endl;
    }

    return 0;
}
