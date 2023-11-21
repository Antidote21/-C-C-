#include <bits/stdc++.h>
using namespace std;
int n, k, w, v, dp[100004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> w >> v;

    for (int j = k; j >= w; j--)
    {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }
  cout << dp[k] << "\n";
  return 0;
} 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int DP[101][100001];

int main()
{
	cin >> N >> K;
    vector<pair<int, int> > bag(N);
	for (int i = 1; i <= N; i++)
		cin >> bag[i].first >> bag[i].second;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{	 
			 if (j - bag[i].first >= 0) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - bag[i].first] + bag[i].second);
			 else DP[i][j] = DP[i - 1][j];
		}
	}
	cout << DP[N][K];

}
