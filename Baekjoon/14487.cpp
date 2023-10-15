#include <iostream>
using namespace std;
int n;
int main(){
    cin>>n;
    int minCost=0, max=0, v;
    for(int i=0; i<n; i++){
        cin>>v;
        minCost += v;
        if(max<v)max = v;
    }
    cout<<minCost-max;
}
