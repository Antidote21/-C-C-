#include <iostream>
using namespace std;
int change;
int main(){
    cin>>change;
    int coin=0;
    int tmp=0;

    coin = change / 5;
    tmp = change - coin*5;
    
    if(change == 1 || change == 3){
        cout<<-1;
        return 0;
    }
    
    if(tmp % 2 == 0){
        coin += tmp / 2;
    }else{
        coin--;
        tmp += 5;
        coin += tmp / 2;
    }
        
    cout<<coin;
}
