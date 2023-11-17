#include <iostream>
using namespace std;

void selection_sort(int A[], int n, int k, int &cnt) {
    for (int last = n; last >= 2; last--) {
        int maxNum = 0;
        int i=0;
        for (int j = 1; j <= last; j++) {
            if (maxNum < A[j]) {
                maxNum = A[j];
                i = j;
            }
        }
        if (last != i) {
            int tmp = A[last];
            A[last] = A[i];
            A[i] = tmp;
            cnt++;
            if(cnt==k){
                for (int i = 1; i <= n; i++) {
                cout << A[i] << " ";
                }
                return;
            }
        }
    }
    cout<<"-1";
}

int main() {
    int n, k;
    cin >> n >> k;

    int A[10000];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    selection_sort(A, n, k, cnt);

    return 0;
}
