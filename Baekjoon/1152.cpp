#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    getline(cin, s);  

    int cnt = 1;  

    for(int i = 0; i < s.length(); i++){  
        if(s[i] == ' ') cnt++;
    }

    cout << cnt;
    return 0;  
}
