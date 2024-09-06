#include <iostream>
#include <vector>
using namespace std;
int n;
int main(){

    cin>>n;

    vector<long long> way(n-1);
    vector<long long > price(n);

    
    for(int i=0; i<n-1; i++){
        cin>>way[i];
    }
    
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    
    long long minPrice = way[0]*price[0];
    long long v=price[0];
    for(int i=1; i<n-1; i++){
        v = min(v, price[i]);
        minPrice += way[i]*v;
    }
    cout<<minPrice;
}

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> way(N - 1);  // N-1 개의 도로 길이
    vector<long long> price(N);    // N개의 주유소 가격

    for (int i = 0; i < N - 1; i++) {
        cin >> way[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    long long minPrice = price[0]; // 첫 번째 주유소 가격
    long long totalCost = 0;

    for (int i = 0; i < N - 1; i++) {
        // 현재까지의 최소 주유소 가격으로 계산
        if (price[i] < minPrice) {
            minPrice = price[i];
        }
        totalCost += minPrice * way[i]; // 최소 가격으로 도로 구간 계산
    }

    cout << totalCost << endl;  // 총 비용 출력
}
