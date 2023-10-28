#include <iostream>
using namespace std;
int n;
long long factorial(int a){
    if(a==0)return 1;
    else{
        return a * factorial(a-1);    
    }
}
int main(){
    cin>>n;
    long long res = factorial(n); 
    cout<<res;
}
