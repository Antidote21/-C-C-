#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int Alphabet[26] = {0};
    
    for(char c : s){
        if(isalpha(c)){
            char uc = toupper(c);
            Alphabet[uc - 'A']++;
        }
    }
    
    int maxCnt = 0, maxIndex = 0;
    bool isUnique = true;
    
    for(int i=0; i<26; i++){
        if(Alphabet[i] > maxCnt){
            maxCnt = Alphabet[i];
            maxIndex = i;
            isUnique = true;
        }else if(Alphabet[i] == maxCnt){
            isUnique = false;
        }
    }
    
    if(isUnique){
        cout<<(char)('A' + maxIndex)<<endl;
    }else{
        cout<<"?"<<endl;
    }
    return 0;
}
