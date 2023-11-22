#include <iostream>
using namespace std;
int a[100000];

int main(){
    int n;
    cin>>n;
    a[1] = 1;
    for(int i=2; i<=n; i++){
        a[i] = i;
        int tmp = a[i];
        a[i] = a[i-1];
        a[i-1] = tmp;
        
        for(int j=i-1; j>1; j/=2){
            int tmp = a[j];
            a[j] = a[j/2];
            a[j/2] = tmp;
        }
    }
    
    for(int i=1;i<=n;i++)
        cout<< a[i]<<" ";
    return 0;
}
