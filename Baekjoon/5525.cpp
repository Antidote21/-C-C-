#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; 
	string str;
	cin >> n >> m >> str;
    
	int res = 0;
	for (int i = 0; i < m; i++) {
		int k = 0; 
		if (str[i] == 'O') continue;
		while (str[i + 1] == 'O' && str[i + 2] == 'I') {
			k++;
			if (k == n) {
				res++;
				k--; 
			}
			i += 2; 
		}
	}

	cout << res << '\n';
}
