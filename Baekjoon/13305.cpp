#include <iostream>
#include <vector>
using namespace std;
int n;
int main(){

    cin>>n;

    vector<long long> way(n-1);
    vector<long long > price(n);

    
    for(int i=0; i<n-1; i++){
        cin>>way[i];
    }
    
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    
    long long minPrice = way[0]*price[0];
    long long v=price[0];
    for(int i=1; i<n-1; i++){
        v = min(v, price[i]);
        minPrice += way[i]*v;
    }
    cout<<minPrice;
}
