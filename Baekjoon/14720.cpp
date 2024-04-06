#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N; 

    vector<int> milkStores(N); 

    for (int i = 0; i < N; ++i) {
        cin >> milkStores[i];
    }

    int milkToDrink = 0; 
    int currentMilk = 0; 

    for (int store : milkStores) {
        if (store == currentMilk) { 
            milkToDrink++;
            currentMilk = (currentMilk + 1) % 3;
        } else if (store == (currentMilk + 1) % 3) { 
            currentMilk = (currentMilk + 1) % 3; 
        }
    }

    cout << milkToDrink << endl; 

    return 0;
}
