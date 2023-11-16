#include <iostream>
using namespace std;

int data[10], tmp[10];

void mergeSort(int lt, int rt){
	int mid;
	int p1, p2, p3;
	if(lt<rt){
		mid=(lt+rt)/2;
		mergeSort(lt,mid);
		mergeSort(mid+1,rt);
		p1=lt;
		p2=mid+1;
		p3=lt;
		while(p1<=mid && p2<=rt){
			tmp[p3++] = (data[p1] < data[p2]) ? data[p1++] : data[p2++]; 
		}

		while(p1 <= mid) tmp[p3++] = data[p1++];
		while(p2 <= rt) tmp[p3++] = data[p2++];

		for(int i=lt; i<=rt; i++){
			data[i] = tmp[i];
		}
	}
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << data[i] << endl;
    }

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

void radix_sort(int a[], int n) {
    int maxValue = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0 || a[i] > maxValue) {
            maxValue = a[i];
        }
    }

    int radix = 1;
    while (radix < maxValue) {
        radix *= 10;
    }

    for (int i = 1; i < radix; i *= 10) {
        queue<int> Q[10];
        for (int j = 0; j < n; j++) {
            int k;
            if (a[j] < i) k = 0;
            else k = (a[j] / i) % 10;
            Q[k].push(a[j]);
        }

        int idx = 0;
        for (int j = 0; j < 10; j++) {
            while (!Q[j].empty()) {
                a[idx] = Q[j].front();
                Q[j].pop();
                idx++;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int a[n]; 
    radix_sort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}

