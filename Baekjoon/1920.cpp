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
