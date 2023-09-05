#include <iostream>
using namespace std;
int dy[40];
int cnt1 = 0, cnt2 = 0;
int fib(int n)
{
    if (n == 1 || n == 2)
    {
        cnt1++;
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}

int fibonacci(int n)
{
    dy[1] = 1;
    dy[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        cnt2++;
        dy[i] = dy[i - 1] + dy[i - 2];
    }
    return dy[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fib(n);
    fibonacci(n);
    cout << cnt1 << ' ' << cnt2;
    return 0;
}
