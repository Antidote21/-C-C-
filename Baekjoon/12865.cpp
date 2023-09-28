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
