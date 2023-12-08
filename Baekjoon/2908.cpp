#include<iostream>
#include<string>
using namespace std;

int main(){
    string a, b;
    char tmp;
    cin>>a>>b;
    
    tmp = a[0];
    a[0]=a[2];
    a[2] = tmp;
    
    tmp = b[0];
    b[0]=b[2];
    b[2]=tmp;
    
    int A, B;
    A = stoi(a);
    B = stoi(b);
    
    if(A>B)cout<<A;
    else cout<<B;
}
