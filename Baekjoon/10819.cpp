#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main(){
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    int res = 0; 
    for(int i=0; i<n; i++){
        res += abs(A[i]-A[n-i-1]);
    }
    cout<<res;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int n[9];
int result;
vector<int> v;
int visit[9];
int cnt = 0;

void solve() { //브루트포스 
	if (v.size() == N) {
		int tmp = 0;
		for (int i = 0; i < N-1; i++) {
			tmp += abs(v[i + 1] - v[i]);
		}
		result = max(result, tmp);
		return;
	}
	for (int i = 1; i <= N; i++) { //백트래킹
		if (!visit[i]) {
			visit[i] = 1;
			v.push_back(n[i]);
			solve();
			v.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
	}

	solve();
	cout << result << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    
    vector<int> B(N/2);
    
    for(int i=N/2; i<N; i++){
        B[i-N/2] = A[i];
    }
    sort(B.begin(), B.end(), greater<int>());
    
    int sum=0;
    for(int i=0; i<N/2; i++){
        sum += abs(A[i]-B[i]) + abs(B[i+1]-A[i]);
        cout<<A[i]<<' '<<B[i]<<' '<<B[i+1]<<' '<<endl;
    }
    cout<<sum;
}
