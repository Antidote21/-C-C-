#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> v;

int partition(int left, int right) {
    int pivot = v[right];
    int pivot_index = right;

    right--;

    while (1) {
        while (v[left] < pivot) left++;
        while (v[right] > pivot) right--;

        if (left >= right) break;
        else {
            swap(v[left], v[right]);
            left++;
        }
    }
    swap(v[left], v[pivot_index]);

    return left;
}

void quick_sort(int left, int right) {
    if (left >= right) return;

    int pivot = partition(left, right);

    quick_sort(left, pivot - 1);
    quick_sort(pivot + 1, right);
}

int main() {
    int n;
    cin >> n;

    v.resize(n); // 벡터의 크기를 n으로 설정

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    quick_sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << v[i] << " "; // 공백으로 구분하여 출력
    }
    return 0;
}
