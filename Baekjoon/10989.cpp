#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    int A[10001] = {0};

    for(int i = 0 ; i < n; i++){
        int k;
        cin >> k;
        A[k] += 1;
    }

    for(int i = 1 ; i <= 10000; i++)
        for (int j = 0; j < A[i]; j++)
            cout << i << "\n";
}
