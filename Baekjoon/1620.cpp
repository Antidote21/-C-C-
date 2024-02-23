#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    unordered_map<string, int> name_to_number;
    unordered_map<int, string> number_to_name;

    for (int i = 0; i < N; ++i) {
        string pokemon;
        cin >> pokemon;
        name_to_number[pokemon] = i + 1;
        number_to_name[i + 1] = pokemon;
    }

    for (int i = 0; i < M; ++i) {
        string question;
        cin >> question;
        
        if (isdigit(question[0])) { 
            int num = stoi(question);
            cout << number_to_name[num] << '\n';
        } else { 
            cout << name_to_number[question] << '\n';
        }
    }

    return 0;
}
