#include<string>
#include<stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    int cnt = 0;
    int size = s.size();
    
    for(int i=0; i<s.size(); i++){
        st.push(s[i]);
    }
    
    if(st.top()=='('){
        answer=false;
        return answer;
    }
    
    while(!st.empty()){
        if(st.top()==')'){
            st.pop();
            cnt+=1;
        }else{
            st.pop();
        }
    }
    if((size-cnt)!=cnt)answer=false;
    else answer=true;
    
    return answer;
}
