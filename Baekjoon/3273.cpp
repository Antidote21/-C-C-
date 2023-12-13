#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int n, x;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> x;

    int cnt = 0;

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int complement = x - a[i];
        int complementIndex = binarySearch(a, complement, i + 1, n - 1);

        if (complementIndex != -1) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
