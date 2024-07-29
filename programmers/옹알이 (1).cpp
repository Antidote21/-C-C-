#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string Pronounce[4] = {"aya", "ye", "woo", "ma"};

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i=0; i<babbling.size(); i++){
        string tmp = "";
        if(babbling[i].size()<=1)continue;
        for(int j=0; j<4; j++){  
            int position = babbling[i].find(Pronounce[j]);
            if(position == string::npos){
                continue;
            }else{
                tmp+=Pronounce[j];
                cout<<tmp<<endl;
            }
        }
        if(tmp.size() == babbling[i].size()){
            answer++;
        }
    }
    return answer;
}
