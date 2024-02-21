#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int N, M;
    unordered_map<int, int> um;
    vector<int> res;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        int num1;
        cin >> num1;
        um[num1]++;
    }
    
    cin >> M;
    for(int i = 0; i < M; i++){
        int num2;
        cin >> num2;
        res.push_back(um[num2]);
    }
    
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    
    return 0;
}
