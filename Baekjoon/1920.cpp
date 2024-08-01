#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<int, int> um;
    
    int N, M;
    cin>>N;
    
    for(int i=0; i<N; i++){
        int A;
        cin>>A;
        um.insert({A, i});
    }
    
    cin>>M;
    for(int i=0; i<M; i++){
        int B;
        cin>>B;
        cout<<um.count(B)<<'\n';
    }
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin>>N;
    unordered_map<int, int> A;
    vector<int> B;

    for(int i=0; i<N; i++){
        int p;
        cin>>p;
        A.insert({p,i});
    }
    
    int M;
    cin>>M;
    for(int i=0; i<M; i++){
        int q; 
        cin>>q;
        B.push_back(q);
    }
    
    string result;
    for(auto elem:B){
        if(A.count(elem)){
            result += "1\n";
        }else{
            result += "0\n";
        }
    }
    cout << result;
  
    return 0;
}
