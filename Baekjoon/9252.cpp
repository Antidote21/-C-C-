#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s1, s2, res;
    cin>>s1>>s2;
    vector<int> dp(s1.length());

    for(int i=0; i<s1.length(); i++){
        for(int j=i; j<s2.length(); j++){
            if(s1[i]==s2[j]){
                dp[i]++;
                res+=s1[i];
                break;
            }
        }
    }
    cout<<res.size()<<endl<<res;
}
