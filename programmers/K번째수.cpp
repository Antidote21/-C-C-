#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> partialVector(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(partialVector.begin(), partialVector.end());
        answer.push_back(partialVector[commands[i][2] - 1]);
    }
    return answer;
}

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    if(array.size()==1){
        answer.push_back(array[0]);
        return answer;
    }
    for(int i = 0; i < commands.size(); i++) {
        int p = commands[i][0];
        int q = commands[i][1];
        int r = commands[i][2];

        vector<int> tmp(array.begin() + (p - 1), array.begin() + q);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[r - 1]);
    }
    
    return answer;
}
