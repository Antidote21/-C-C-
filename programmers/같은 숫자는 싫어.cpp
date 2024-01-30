#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    stack<int> st;
    st.push(arr[0]);
    
    for(auto element:arr){
        if(element!=st.top()){
            st.push(element);
        }
    }
    
    while (!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
