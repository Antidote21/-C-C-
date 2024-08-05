#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> um;
    bool answer = true;
    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 1; j <= phone_book[i].size(); j++) {
            string substring = phone_book[i].substr(0, j);
            um[substring]++;
        }
    }

    for (int i = 0; i < phone_book.size(); i++) {
        if (um[phone_book[i]] > 1) {
            return answer = false;
        }
    }

    return answer;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
   sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i+1].find(phone_book[i])==0){
            return false;
        }
    }
    return true;
}
