#include <iostream>
using namespace std;
long long int dp[100];
int n;

long long int sequence(int k)
{

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= k; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    return dp[k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        cout << sequence(k) << '\n';
    }
}
