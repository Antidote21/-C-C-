#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int cnt=0;
    for(int i=0; i<phone_book.size()-1; i++){
        for(int j=i+1; j<phone_book.size(); j++){
            for(int k=0; k<phone_book[i].size(); k++){
                if(phone_book[i][k]==phone_book[j][k]){
                    answer=true;
                }else answer = false;   
            }
            if(answer)cnt++;
        }
    }
    if(cnt>0)answer=false;
    else answer=true;
    return answer;
}
