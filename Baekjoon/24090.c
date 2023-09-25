#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (arr[j] <= x) {
            int tmp = arr[i + 1];
            arr[++i] = arr[j];
            arr[j] = tmp;
        }
    }
    if (i + 1 != r) {
        int tmp = arr[i + 1];
        arr[i + 1] = arr[r];
        arr[r] = tmp;
    }
    return i + 1;
}

void quick_sort(int *arr, int p, int r, int k, int* cnt, int* result) {
    if (p < r) {
        int q = partition(arr, p, r);
        (*cnt) += (q - p + 1); // 분할된 부분 배열의 길이만큼 cnt 증가
        if (*cnt >= k) {
            result[0] = arr[q];
            result[1] = arr[q - (*cnt) + k]; // k번째 교환 위치 계산
            return;
        }
        if (*cnt < k) {
            quick_sort(arr, q + 1, r, k, cnt, result);
        }
    }
}

int main() {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    int result[2] = {-1, -1};
    quick_sort(a, 0, n - 1, k, &cnt, result);
    if (result[0] != -1) {
        printf("%d %d", result[0], result[1]);
    } else {
        printf("-1");
    }
    free(a);
    return 0;
}
