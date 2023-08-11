#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>adj;
void makeGraph(vector<string>& words) {
	adj = vector<vector<int>>(26);
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1;
		int len = min(words[i].length(), words[j].length());
		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';//이전 단어의 현재 글자를 알파벳 인덱스로 변환하여 a에 저장
				int b = words[j][k] - 'a';
				adj[a].push_back(b);
				break;
			}
		}
	}
}

vector<int> seen, order;//seen 노드의 방문 여부 order 방문 노드의 순서를 역순으로 저장
void dfs(int here) {
	seen[here] = 1;//현재 노드 방문 
	for (int i = 0; i < adj[here].size(); i++)
		if (!seen[adj[here][i]])//아직 방문되지 않은 경우를 확인
			dfs(adj[here][i]);
	order.push_back(here);//현재 노드 here를 order 벡터에 역순으로 추가
}

vector<int> topologicalSort() {
	int m = adj.size();
	seen = vector<int>(m, 0);
	order.clear();
	for (int i = 0; i < m; i++) if (!seen[i]) dfs(i);
	reverse(order.begin(), order.end());

	//위상 정렬 검증 과정
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = 0; k < adj[order[j]].size(); k++)
				if (adj[order[j]][k] == order[i])//위상 정렬 순서를 어김
					return vector<int>();//빈 벡터를 반환하여 위상 정렬이 아니라고 알림
		}
	}
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
