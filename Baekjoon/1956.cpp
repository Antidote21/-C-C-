#include <iostream>
#include <algorithm>
#define INF 99999

using namespace std;

int arr[401][401];

int main() {
	int V, E;
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}
	int ans = INF;
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) continue;
			ans = min(ans, arr[i][j]+ arr[j][i]);
		}
	}
	ans = ans == INF ? -1 : ans;
	cout << ans << "\n";

	return 0;
}
