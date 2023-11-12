#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;

	for (int i = 0; i < 4; ++i) {
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());
	
	cout << v[0] * v[2] << endl;

	return 0;
}
