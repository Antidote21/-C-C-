#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {2,1,2,3,2,4,2,5};
    vector<int> c = {3,3,1,1,2,2,4,4,5,5};

    int cnt1=0, cnt2=0, cnt3=0;
    
    for(int i=0; i<answers.size(); i++){
        if(a[i%5] == answers[i]) cnt1++;  
        if(b[i%8] == answers[i]) cnt2++; 
        if(c[i%10] == answers[i]) cnt3++;
    }
    
    int result = max(max(cnt1, cnt2), cnt3);
    
    if(cnt1 == result) answer.push_back(1);
    if(cnt2 == result) answer.push_back(2);
    if(cnt3 == result) answer.push_back(3);
    
    return answer;
}
