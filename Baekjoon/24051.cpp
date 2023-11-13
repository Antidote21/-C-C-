#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k, cnt=0;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i=1; i<n; i++){
        int loc = i-1; 
        int newItem = a[i];
        while(0 <=loc && newItem < a[loc]){
            a[loc + 1] = a[loc];
            loc--;
        }
        if(loc+1 != i){
            a[loc + 1] = newItem;
        }
    }
    
    for(int i=0; i<n; i++){
        cout<<a[i];
    }
    
}
