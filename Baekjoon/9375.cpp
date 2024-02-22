#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
       int n;
       cin>>n;
       
       unordered_map<string, int> um;
       
       for(int i=0; i<n; i++){
           string name, type;
           cin>>name>>type;
           um[type]++;
       }
       
       int total = 1;
       
       for(auto it = um.begin(); it!= um.end(); ++it){
           total *= (it->second + 1);
       }
       
       total--;
       
       cout<<total<<endl;
    }

    return 0;
}
