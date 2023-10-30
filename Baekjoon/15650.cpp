#include <iostream>
#include <vector>
using namespace std;

void generate_sequences(int n, int m, vector<int>& current_sequence, int k) {
    if (current_sequence.size() == m) {
        for(int i=0; i<m; i++){
            cout << current_sequence[i]<<" ";
        }
        cout << endl;
        return;
    }

    for (int i=k; i<=n; i++) {
        current_sequence.push_back(i);
        generate_sequences(n, m, current_sequence, i+1);
        current_sequence.pop_back();
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> current_sequence;
    generate_sequences(n, m, current_sequence, 1);
    return 0;
}
