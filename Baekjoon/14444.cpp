#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
    cin>>s;
    int len, res=0;
    for(int i=1; i<s.size(); i++){
        len=0;
        for(int j=1; j<s.size()/2; j++){
            if(s[i-j]==s[i+j]){
                len=i+1;
            }
            if(s[i]==s[i-1]){
                len=2;
            }
        }
        res = max(res, len);
    }
    cout<<res;
}
