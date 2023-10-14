#include <iostream>
#include <vector>
using namespace std;
int n;

int main(){
    cin>>n;
    vector<double> energyDrink(n, 0);
    double res=0;
    int k;
    for(int i=0; i<n; i++){
        cin>>energyDrink[i];
        if(res<energyDrink[i]){
            res = energyDrink[i];
            k = i;
        }
    }
    for(int i=0; i<n; i++){
        if(i==k)continue;
        else{
            res += energyDrink[i]/2;
        }
    }
    
    cout<<res;
}
