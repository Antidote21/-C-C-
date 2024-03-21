#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    
    vector<int> A(N);
    
    for(int i=0; i<N; i++){
        A[i]=i+1;
    }
    
    do{
        for(auto a: A){
            cout<<a<<' ';
        }
        cout<<'\n';
    }while(next_permutation(A.begin(), A.end()));
}
