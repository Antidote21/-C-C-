#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>adj;
// 인접리스트 만들기
void makeGraph(vector<string>& words) {
	adj = vector<vector<int>>(26);
	// 주어진 차례대로 두개씩 비교
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1;
		int len = min(words[i].length(), words[j].length());
		for (int k = 0; k < len; k++) 
			// 사전순서가 다른 이유가 되는 k번째 문자
			if (words[i][k] != words[j][k]) {
				// 계산하기 쉽게 문자를 정수로 변환
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				// a가 나타내는 문자가 b가 나타내는 문자보다 우선순위가 높음
				adj[a].push_back(b);
				break;
			}
	}
}
// 탐색 유무, 알파벳 사전 순서
vector<int> seen, order;
void dfs(int here) {
	seen[here] = 1;
	for (int i = 0; i < adj[here].size(); i++)
		// 현재 알파벳보다 뒤에 나와야 하는게 있으면 dfs재귀
		if (!seen[adj[here][i]])
			dfs(adj[here][i]);
	// 현재 알파벳보다 뒤에 나와야하는 알파벳을 모두 dfs완료했으면 자신도 order.push
	order.push_back(here);
}
vector<int> topologicalSort() {
	int m = adj.size();
	seen = vector<int>(m, 0);
	order.clear();
	for (int i = 0; i < m; i++) if (!seen[i]) dfs(i);
	// dfs를 실행하면 order가 사전순의 역순으로 정렬되 있으므로 뒤집어 준다.
	reverse(order.begin(), order.end());
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			for(int k=0; k<adj[order[j]].size(); k++)
				// 자신보다 뒤에 나와야하는 알파벳이 자신보다 먼저 나와야 하면 모순
				if (adj[order[j]][k]==order[i])
					return vector<int>();
	return order;
}
int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n;
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++) 
			cin >> words[i];
		makeGraph(words);
		vector<int> result = topologicalSort();
		if (result.empty())
			cout << "INVALID HYPOTHESIS" << endl;
		else {
			for (int i = 0; i < result.size(); i++)
				cout << char(result[i] + 'a');
			cout << endl;
		}			
	}
}
