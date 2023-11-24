#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> choice(6);
int num_cnt[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

void DFS(int cnt, int sum) {
    if (cnt == 6) {
        if (sum + 4 == n) {
            int n1 = choice[0] * 10 + choice[1];
            int n2 = choice[2] * 10 + choice[3];
            int n3 = choice[4] * 10 + choice[5];
            if (n1 + n2 == n3) {
                cout << choice[0] << choice[1] << "+"
                     << choice[2] << choice[3] << "="
                     << choice[4] << choice[5];
                exit(0);
            }
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {
        choice[cnt] = i;
        DFS(cnt + 1, sum + num_cnt[i]);
    }
}

int main() {

    cin >> n;
    DFS(0, 0);
    cout << "impossible";

    return 0;
}
