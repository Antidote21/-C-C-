#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, k, A[500000], cnt;

void merge(int p, int q, int r)
{
    int tmp[r+1];
    int i = p, j = q+1, t = 1;
    while(i <= q && j <= r)
    {
        if(A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while(i <= q) tmp[t++] = A[i++];
    while (j <= r) tmp[t++] = A[j++];
    i = p, t = 1;
    while (i <= r)
    {
        A[i++] = tmp[t++];
        if(++cnt == k)
        {
            cout << tmp[t-1];
            exit(0);
        }
    }
}

void merge_sort(int p, int r)
{
    if(p < r)
    {
        int q = (p+r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> A[i];
    merge_sort(0, n-1);
    cout << -1;

    return 0;
}
