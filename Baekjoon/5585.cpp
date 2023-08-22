#include <bits/stdc++.h>

using namespace std;

int coin_types[6] = {500, 100, 50, 10, 5, 1};

int main(void) {
    int price, money = 1000, change, cnt = 0;
    cin >> price;
    change = money - price;

    for (int i = 0; i < 6; i++) {
        if (change >= coin_types[i]) {
            int tmp = change / coin_types[i];
            change -= coin_types[i] * tmp;
            cnt += tmp;
        }
    }

    cout << cnt << endl;  
    return 0;
}
