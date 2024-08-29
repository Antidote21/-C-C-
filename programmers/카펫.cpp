#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown+yellow;
    for(int i=1; i<=sum; i++){
        for(int j=1; j<=sum; j++){
            if(i*j==sum){
                if(i>=j){
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }
    }
    return answer;
}

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {

    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while(w >= h){
        if(w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int height = 1; height <= (brown + yellow) / height; height++) {
        int width = (brown + yellow) / height;
        if ((width - 2) * (height - 2) == yellow) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }

    return answer;
}
