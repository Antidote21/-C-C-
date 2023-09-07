#include <iostream>
using namespace std;
int n;
int dy[45];

int memoization(int k)
{
    if (dy[k] != 0){
        return dy[k];
    }
    else
    {
        for (int i = 3; i <= k; i++)
        {
            dy[i] = dy[i - 2] + dy[i - 1];
        }
    }
    return dy[k];
}

int main()
{
    cin >> n;
    dy[1] = 1;
    dy[2] = 2;
    memoization(n);
    cout << dy[n];
}
