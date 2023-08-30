#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int tmp, cnt;
    vector<int> res;
    while(true){
        int L, P, V;
        cin>>L>>P>>V;
        
        if(L==0&&P==0&&V==0) break;
        
        int tmp = (V / P) * L + min(V % P, L);
        res.push_back(tmp);
    }
    
    for(int i=0; i<res.size(); i++){
        cout<<"Case "<<i+1<<": "<<res[i]<<endl;
    }
    
    return 0; 
    
}
