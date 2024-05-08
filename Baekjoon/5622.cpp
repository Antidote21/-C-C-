#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;
    int total=0;
    for(int i=0; i<s.size(); i++){
        if(65<=s[i]&&s[i]<=67){
            total+=3;
        }else if(68<=s[i]&&s[i]<=70){
            total+=4;
        }else if(71<=s[i]&&s[i]<=73){
            total+=5;
        }else if(74<=s[i]&&s[i]<=76){
            total+=6;
        }else if(77<=s[i]&&s[i]<=79){
            total+=7;
        }else if(80<=s[i]&&s[i]<=83){
            total+=8;
        }else if(84<=s[i]&&s[i]<=86){
            total+=9;
        }else{
            total+=10;
        }
    }
    cout<<total;
}
