#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T; 

    for (int i = 0; i < T; ++i) {
        string str;
        cin >> str; 
        
        cout << str.front() << str.back() << endl;
    }

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        string s;
        cin>>s;
        cout<<s[0]<<s[s.size()-1]<<endl;
    }
}
