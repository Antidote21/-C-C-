#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin>>str;
    int res=0;
    for(int i=0; i<str.size()/2; i++){
        if(str[i]!=str[str.size()-i-1]){
            cout<<"0";
            exit(0);
        }
    }
    cout<<"1";
}
