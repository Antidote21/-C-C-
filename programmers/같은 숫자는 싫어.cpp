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

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    
    for(auto elem:arr){
        if(st.empty()){st.push(elem);}
        if(st.top() != elem){
            st.push(elem);
        }
    }

    while(true){
        if(st.empty())break;
        int tmp;
        tmp = st.top();
        answer.push_back(tmp);
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
