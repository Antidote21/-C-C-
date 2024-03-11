#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> Card(n);
    vector<int> N(n);
    for(int i=0; i<n; i++){
        cin>>Card[i];
    }
    
    for(int i=0; i<k; i++){
        N[i]=1;
    }
    int cnt=0;
    sort(Card.begin(), Card.end());
    do{
        for(int i=0; i<Card.size(); i++){
            if(N[i]==1){
                cnt++;
            }
        }
        
    }while(prev_permutation(N.begin(), N.end()));
    cout<<cnt;
    return 0;
}
