#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int cnt = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
            cout<<s[i]<<endl;
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
