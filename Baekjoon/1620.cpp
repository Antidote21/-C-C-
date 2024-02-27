#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
        
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    unordered_map<string, int> stringToInt;
    unordered_map<int, string> intToString;

    for(int i=0; i<n; i++){
        string pokemon;
        cin>>pokemon;
        stringToInt.insert({pokemon, i+1});
        intToString.insert({i+1,pokemon});
    }
    
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        if(isdigit(s[0])){
            cout<<intToString[stoi(s)]<<'\n';
        }else{
            cout<<stringToInt[s]<<'\n';
        }
    }
}
