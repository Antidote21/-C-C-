#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> st;
    int K;
    cin>>K;
    
    for(int i=0; i<K; i++){
        int n;
        cin>>n;
        if(n==0){
            st.pop();
        }else{
            st.push(n);
        }
    }
    int sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    cout<<sum;
}
