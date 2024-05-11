#include <iostream>
#include <string>

using namespace std;

string str[16][16];

int main(){
    string s;
    for(int i=0; i<5; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            str[i][j] = s[j];
        }
    }
    
    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            cout<<str[j][i];
        }
    }
}
