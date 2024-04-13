#include <iostream>

using namespace std;

int fib1, fib2;
int f[100];

int Recurfib(int n){
    if(n==1 || n==2)return 1;
    else {
        fib1++;
        return Recurfib(n-1)+Recurfib(n-2);
    }
}

int DPfib(int n){
    f[1] = 1;
    f[2] = 1;
    for(int i=3; i<n; i++){
        f[i] = f[i-1]+f[i-2];
        fib2++;
    }
    return f[n];
}

int main(){
    int n;
    cin>>n;
    Recurfib(n);
    DPfib(n);
    cout<<fib1+1<<' '<<fib2+1;
}
